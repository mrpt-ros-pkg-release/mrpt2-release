﻿/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          https://www.mrpt.org/                         |
   |                                                                        |
   | Copyright (c) 2005-2020, Individual contributors, see AUTHORS file     |
   | See: https://www.mrpt.org/Authors - All rights reserved.               |
   | Released under BSD License. See: https://www.mrpt.org/License          |
   +------------------------------------------------------------------------+ */

// This file contains portions of code from Assimp's example:
// "Sample_SimpleOpenGL.c"

#include "opengl-precomp.h"  // Precompiled header

#include <mrpt/opengl/CAssimpModel.h>

#if MRPT_HAS_ASSIMP
#if defined(MRPT_ASSIMP_VERSION_MAJOR) && MRPT_ASSIMP_VERSION_MAJOR < 3
#include <aiPostProcess.h>
#include <aiScene.h>
#include <assimp.h>
#else
#include <assimp/cimport.h>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <assimp/DefaultLogger.hpp>
#include <assimp/LogStream.hpp>
#endif
#endif

#include <mrpt/serialization/CArchive.h>
#include <mrpt/system/filesystem.h>

using namespace mrpt;
using namespace mrpt::opengl;
using namespace mrpt::math;
using namespace std;
using mrpt::img::CImage;

IMPLEMENTS_SERIALIZABLE(CAssimpModel, CRenderizable, mrpt::opengl)

struct RenderElements
{
	std::vector<mrpt::math::TPoint3Df>* lines_vbd = nullptr;
	std::vector<mrpt::img::TColor>* lines_cbd = nullptr;
	std::vector<mrpt::math::TPoint3Df>* pts_vbd = nullptr;
	std::vector<mrpt::img::TColor>* pts_cbd = nullptr;
	std::vector<mrpt::opengl::TTriangle>* tris = nullptr;
};

#if MRPT_HAS_OPENGL_GLUT && MRPT_HAS_ASSIMP
// Note: Look at older git versions to see pre-OpenGL3 version with more texture
// supports, etc. load_textures(), etc.
static void recursive_render(
	const aiScene* sc, const aiNode* nd, const mrpt::poses::CPose3D& transf,
	RenderElements& re);

// Just return the diffuse color:
static mrpt::img::TColor apply_material(const aiMaterial* mtl);
static void get_bounding_box(
	const aiScene* sc, aiVector3D* min, aiVector3D* max);
static void get_bounding_box_for_node(
	const aiScene* sc, const aiNode* nd, aiVector3D* min, aiVector3D* max,
	aiMatrix4x4* trafo);
#endif  // MRPT_HAS_OPENGL_GLUT && MRPT_HAS_ASSIMP

void CAssimpModel::render(const RenderContext& rc) const
{
	switch (rc.shader_id)
	{
		case DefaultShaderID::POINTS:
			CRenderizableShaderPoints::render(rc);
			break;
		case DefaultShaderID::TRIANGLES:
			CRenderizableShaderTriangles::render(rc);
			break;
		case DefaultShaderID::WIREFRAME:
			CRenderizableShaderWireFrame::render(rc);
			break;
	};
}
void CAssimpModel::renderUpdateBuffers() const
{
	// onUpdateBuffers_all: already called upon loading of the model from file.

	CRenderizableShaderPoints::renderUpdateBuffers();
	CRenderizableShaderTriangles::renderUpdateBuffers();
	CRenderizableShaderWireFrame::renderUpdateBuffers();
}

// special case for assimp: update all buffers within one run over the scene
// structure.
void CAssimpModel::onUpdateBuffers_all()
{
	auto& lines_vbd = CRenderizableShaderWireFrame::m_vertex_buffer_data;
	auto& lines_cbd = CRenderizableShaderWireFrame::m_color_buffer_data;
	lines_vbd.clear();
	lines_cbd.clear();

	auto& pts_vbd = CRenderizableShaderPoints::m_vertex_buffer_data;
	auto& pts_cbd = CRenderizableShaderPoints::m_color_buffer_data;
	pts_vbd.clear();
	pts_cbd.clear();

	auto& tris = CRenderizableShaderTriangles::m_triangles;
	tris.clear();

	if (!m_assimp_scene->scene) return;  // No scene

	RenderElements re;
	re.lines_vbd = &lines_vbd;
	re.lines_cbd = &lines_cbd;
	re.pts_vbd = &pts_vbd;
	re.pts_cbd = &pts_cbd;
	re.tris = &tris;

#if MRPT_HAS_OPENGL_GLUT && MRPT_HAS_ASSIMP
	auto* scene = reinterpret_cast<aiScene*>(m_assimp_scene->scene);

	const auto transf = mrpt::poses::CPose3D();

	recursive_render(scene, scene->mRootNode, transf, re);
#endif
}

// These 3: already done in onUpdateBuffers_all()
void CAssimpModel::onUpdateBuffers_Wireframe() {}
void CAssimpModel::onUpdateBuffers_Points() {}
void CAssimpModel::onUpdateBuffers_Triangles() {}

uint8_t CAssimpModel::serializeGetVersion() const { return 0; }
void CAssimpModel::serializeTo(mrpt::serialization::CArchive& out) const
{
	writeToStreamRender(out);

	const bool empty = m_assimp_scene->scene != nullptr;
	out << empty;

	if (!empty)
	{
#if MRPT_HAS_OPENGL_GLUT && MRPT_HAS_ASSIMP
		// aiScene *scene = (aiScene *) m_assimp_scene->scene;
		THROW_EXCEPTION("MRPT can't serialize Assimp objects yet!");
#else
		THROW_EXCEPTION("MRPT compiled without OpenGL and/or Assimp");
#endif
	}
}

void CAssimpModel::serializeFrom(
	mrpt::serialization::CArchive& in, uint8_t version)
{
	THROW_EXCEPTION("MRPT can't serialize Assimp objects yet!");

	switch (version)
	{
		case 0:
		{
			readFromStreamRender(in);

			clear();
		}
		break;
		default:
			MRPT_THROW_UNKNOWN_SERIALIZATION_VERSION(version);
	};
	CRenderizable::notifyChange();
}

CAssimpModel::CAssimpModel() : m_bbox_min(0, 0, 0), m_bbox_max(0, 0, 0)
{
	m_assimp_scene = std::make_shared<TImplAssimp>();
}

CAssimpModel::~CAssimpModel() { clear(); }
/*---------------------------------------------------------------
							clear
  ---------------------------------------------------------------*/
void CAssimpModel::clear()
{
	CRenderizable::notifyChange();
	m_assimp_scene = std::make_shared<TImplAssimp>();
	m_modelPath.clear();
	// m_textures_loaded = false;

#if MRPT_HAS_OPENGL_GLUT
#if 0
	if (!m_textureIds.empty())
	{
		glDeleteTextures(m_textureIds.size(), &m_textureIds[0]);
		m_textureIds.clear();
	}
	m_textureIdMap.clear();
#endif
#endif
}

void CAssimpModel::loadScene(const std::string& filepath)
{
#if MRPT_HAS_OPENGL_GLUT && MRPT_HAS_ASSIMP
	clear();
	CRenderizable::notifyChange();

	// we are taking one of the postprocessing presets to avoid
	// spelling out 20+ single postprocessing flags here.
	m_assimp_scene->scene = (void*)aiImportFile(
		filepath.c_str(), aiProcessPreset_TargetRealtime_MaxQuality);
	m_modelPath = filepath;

	if (m_assimp_scene->scene)
	{
		aiVector3D scene_min, scene_max;
		auto* scene = (aiScene*)m_assimp_scene->scene;
		get_bounding_box(scene, &scene_min, &scene_max);
		m_bbox_min.x = scene_min.x;
		m_bbox_min.y = scene_min.y;
		m_bbox_min.z = scene_min.z;
		m_bbox_max.x = scene_max.x;
		m_bbox_max.y = scene_max.y;
		m_bbox_max.z = scene_max.z;
	}

	// Process all elements at once:
	// This populates the structures that will be attached to opengl buffers
	const_cast<CAssimpModel&>(*this).onUpdateBuffers_all();

#else
	THROW_EXCEPTION("MRPT compiled without OpenGL and/or Assimp");
#endif
}

void CAssimpModel::getBoundingBox(
	mrpt::math::TPoint3D& bb_min, mrpt::math::TPoint3D& bb_max) const
{
	bb_min = m_bbox_min;
	bb_max = m_bbox_max;

	// Convert to coordinates of my parent:
	m_pose.composePoint(bb_min, bb_min);
	m_pose.composePoint(bb_max, bb_max);
}

CAssimpModel::TImplAssimp::TImplAssimp() = default;
CAssimpModel::TImplAssimp::~TImplAssimp()
{
#if MRPT_HAS_OPENGL_GLUT && MRPT_HAS_ASSIMP
	if (scene)
	{
		// cleanup - calling 'aiReleaseImport' is important, as the library
		// keeps internal resources until the scene is freed again. Not
		// doing so can cause severe resource leaking.
		aiReleaseImport((aiScene*)scene);
		scene = nullptr;
	}
#endif
}

bool CAssimpModel::traceRay(
	[[maybe_unused]] const mrpt::poses::CPose3D& o,
	[[maybe_unused]] double& dist) const
{
	// TODO
	return false;
}

#if MRPT_HAS_OPENGL_GLUT && MRPT_HAS_ASSIMP

static void get_bounding_box_for_node(
	const aiScene* scene, const aiNode* nd, aiVector3D* min, aiVector3D* max,
	aiMatrix4x4* trafo)
{
	aiMatrix4x4 prev;
	unsigned int n = 0, t;

	prev = *trafo;
	aiMultiplyMatrix4(trafo, &nd->mTransformation);

	for (; n < nd->mNumMeshes; ++n)
	{
		const aiMesh* mesh = scene->mMeshes[nd->mMeshes[n]];
		for (t = 0; t < mesh->mNumVertices; ++t)
		{
			aiVector3D tmp = mesh->mVertices[t];
			aiTransformVecByMatrix4(&tmp, trafo);

			min->x = std::min(min->x, tmp.x);
			min->y = std::min(min->y, tmp.y);
			min->z = std::min(min->z, tmp.z);

			max->x = std::max(max->x, tmp.x);
			max->y = std::max(max->y, tmp.y);
			max->z = std::max(max->z, tmp.z);
		}
	}

	for (n = 0; n < nd->mNumChildren; ++n)
	{
		get_bounding_box_for_node(scene, nd->mChildren[n], min, max, trafo);
	}
	*trafo = prev;
}

static void get_bounding_box(
	const aiScene* scene, aiVector3D* min, aiVector3D* max)
{
	aiMatrix4x4 trafo;
	aiIdentityMatrix4(&trafo);

	min->x = min->y = min->z = 1e10f;
	max->x = max->y = max->z = -1e10f;
	get_bounding_box_for_node(scene, scene->mRootNode, min, max, &trafo);
}

static mrpt::img::TColor color4_to_TColor(const aiColor4D& c)
{
	return mrpt::img::TColorf(c.r, c.g, c.b, c.a).asTColor();
}

static mrpt::img::TColor apply_material(const aiMaterial* mtl)
{
	aiColor4D diffuse;
	if (AI_SUCCESS ==
		aiGetMaterialColor(mtl, AI_MATKEY_COLOR_DIFFUSE, &diffuse))
	{
		return color4_to_TColor(diffuse);
	}
	else
	{
		// Default color:
		return {0xa0, 0xa0, 0xa0, 0xff};
	}
}

static mrpt::math::CMatrixDouble44 aiMatrix_to_mrpt(const aiMatrix4x4& m)
{
	mrpt::math::CMatrixDouble44 M;
	M(0, 0) = m.a1;
	M(0, 1) = m.a2;
	M(0, 2) = m.a3;
	M(0, 3) = m.a4;

	M(1, 0) = m.b1;
	M(1, 1) = m.b2;
	M(1, 2) = m.b3;
	M(1, 3) = m.b4;

	M(2, 0) = m.c1;
	M(2, 1) = m.c2;
	M(2, 2) = m.c3;
	M(2, 3) = m.c4;

	M(3, 0) = m.d1;
	M(3, 1) = m.d2;
	M(3, 2) = m.d3;
	M(3, 3) = m.d4;
	return M;
}

static mrpt::math::TPoint3Df to_mrpt(const aiVector3D& v)
{
	return {v.x, v.y, v.z};
}

static void recursive_render(
	const aiScene* sc, const aiNode* nd, const mrpt::poses::CPose3D& transf,
	RenderElements& re)
{
	const aiMatrix4x4& m = nd->mTransformation;

	// update transform
	const auto nodeTransf = mrpt::poses::CPose3D(aiMatrix_to_mrpt(m));
	const mrpt::poses::CPose3D curTf = transf + nodeTransf;

	// draw all meshes assigned to this node
	for (unsigned int n = 0; n < nd->mNumMeshes; ++n)
	{
		const struct aiMesh* mesh = sc->mMeshes[nd->mMeshes[n]];

		mrpt::img::TColor color =
			apply_material(sc->mMaterials[mesh->mMaterialIndex]);

		for (unsigned int t = 0; t < mesh->mNumFaces; ++t)
		{
			const struct aiFace* face = &mesh->mFaces[t];

			switch (face->mNumIndices)
			{
				case 1:
					// GL_POINTS ================
					for (unsigned int i = 0; i < face->mNumIndices; i++)
					{
						// get group index for current index
						int vertexIndex = face->mIndices[i];
						if (mesh->mColors[0] != nullptr)
							color =
								color4_to_TColor(mesh->mColors[0][vertexIndex]);

						re.pts_vbd->emplace_back(curTf.composePoint(
							to_mrpt(mesh->mVertices[vertexIndex])));
						re.pts_cbd->emplace_back(color);
					}
					break;

				case 2:
					// GL_LINES ================
					for (unsigned int i = 0; i < face->mNumIndices; i++)
					{
						// get group index for current index
						int vertexIndex = face->mIndices[i];
						if (mesh->mColors[0] != nullptr)
							color =
								color4_to_TColor(mesh->mColors[0][vertexIndex]);

						re.lines_vbd->emplace_back(curTf.composePoint(
							to_mrpt(mesh->mVertices[vertexIndex])));
						re.lines_cbd->emplace_back(color);
					}
					break;

				case 3:
				{
					// GL_TRIANGLES ================
					const unsigned int nTri = face->mNumIndices / 3;
					ASSERT_EQUAL_(face->mNumIndices % 3, 0);

					for (unsigned int iTri = 0; iTri < nTri; iTri++)
					{
						mrpt::opengl::TTriangle tri;
						for (unsigned int v = 0; v < 3; v++)
						{
							unsigned int i = iTri * 3 + v;
							// get group index for current index
							int vertexIndex = face->mIndices[i];
							if (mesh->mColors[0] != nullptr)
								color = color4_to_TColor(
									mesh->mColors[0][vertexIndex]);

							tri.r(v) = color.R;
							tri.g(v) = color.G;
							tri.b(v) = color.B;
							tri.a(v) = color.A;

							// texture_coordinates_set=0
							if (mesh->HasTextureCoords(0))
							{
								tri.vertices[v].uv.x =
									mesh->mTextureCoords[0][vertexIndex].x;
								tri.vertices[v].uv.y =
									mesh->mTextureCoords[0][vertexIndex].y;
							}

							if (mesh->mNormals)
								tri.vertices[v].normal = curTf.rotateVector(
									to_mrpt(mesh->mNormals[vertexIndex]));

							auto pt = curTf.composePoint(
								to_mrpt(mesh->mVertices[vertexIndex]));
							tri.x(v) = pt.x;
							tri.y(v) = pt.y;
							tri.z(v) = pt.z;
						}

						re.tris->emplace_back(std::move(tri));
					}
				}
				break;
				default:
					// GL_POLYGON ================
					THROW_EXCEPTION("ASSIMP polygons not implemented yet.");
					break;
			}
		}
	}

	// draw all children
	for (unsigned int n = 0; n < nd->mNumChildren; ++n)
		recursive_render(sc, nd->mChildren[n], curTf, re);
}

#endif  // MRPT_HAS_OPENGL_GLUT && MRPT_HAS_ASSIMP
