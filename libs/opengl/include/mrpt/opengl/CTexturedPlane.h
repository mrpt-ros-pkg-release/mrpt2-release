/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          https://www.mrpt.org/                         |
   |                                                                        |
   | Copyright (c) 2005-2020, Individual contributors, see AUTHORS file     |
   | See: https://www.mrpt.org/Authors - All rights reserved.               |
   | Released under BSD License. See: https://www.mrpt.org/License          |
   +------------------------------------------------------------------------+ */
#pragma once

#include <mrpt/math/TPolygonWithPlane.h>
#include <mrpt/opengl/CRenderizableShaderTexturedTriangles.h>

namespace mrpt::opengl
{
/** A 2D plane in the XY plane with a texture image.
 *  \sa opengl::COpenGLScene
 * \ingroup mrpt_opengl_grp
 */
class CTexturedPlane : public CRenderizableShaderTexturedTriangles
{
	DEFINE_SERIALIZABLE(CTexturedPlane, mrpt::opengl)

   protected:
	float m_xMin = -1.0f, m_xMax = 1.0f;
	float m_yMin = -1.0f, m_yMax = 1.0f;

	mutable bool polygonUpToDate{false};
	/** Used for ray-tracing */
	mutable std::vector<mrpt::math::TPolygonWithPlane> tmpPoly;
	void updatePoly() const;
	void unloadTexture();

   public:
	/** @name Renderizable shader API virtual methods
	 * @{ */
	virtual void onUpdateBuffers_TexturedTriangles() override;
	/** @} */

	CTexturedPlane(
		float x_min = -1, float x_max = 1, float y_min = -1, float y_max = 1);
	virtual ~CTexturedPlane() override = default;

	/** Set the coordinates of the four corners that define the plane on the XY
	 * plane. */
	void setPlaneCorners(float xMin, float xMax, float yMin, float yMax)
	{
		m_xMin = xMin;
		m_xMax = xMax;
		m_yMin = yMin;
		m_yMax = yMax;
		polygonUpToDate = false;
		CRenderizable::notifyChange();
	}

	/** Get the coordinates of the four corners that define the plane on the XY
	 * plane. */
	inline void getPlaneCorners(
		float& xMin, float& xMax, float& yMin, float& yMax) const
	{
		xMin = m_xMin;
		xMax = m_xMax;
		yMin = m_yMin;
		yMax = m_yMax;
	}

	bool traceRay(const mrpt::poses::CPose3D& o, double& dist) const override;
	void getBoundingBox(
		mrpt::math::TPoint3D& bb_min,
		mrpt::math::TPoint3D& bb_max) const override;
};

}  // namespace mrpt::opengl
