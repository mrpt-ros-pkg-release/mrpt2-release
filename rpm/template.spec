%bcond_without weak_deps

%global __os_install_post %(echo '%{__os_install_post}' | sed -e 's!/usr/lib[^[:space:]]*/brp-python-bytecompile[[:space:]].*$!!g')
%global __provides_exclude_from ^/opt/ros/noetic/.*$
%global __requires_exclude_from ^/opt/ros/noetic/.*$

Name:           ros-noetic-mrpt2
Version:        2.0.4
Release:        1%{?dist}%{?release_suffix}
Summary:        ROS mrpt2 package

License:        BSD
URL:            https://www.mrpt.org/
Source0:        %{name}-%{version}.tar.gz

Requires:       assimp-devel
Requires:       eigen3-devel
Requires:       ffmpeg-devel
Requires:       freeglut-devel
Requires:       glfw-devel
Requires:       libXrandr-devel
Requires:       libXxf86vm-devel
Requires:       libjpeg-turbo-devel
Requires:       libpcap-devel
Requires:       libudev-devel
Requires:       libusbx-devel
Requires:       opencv-devel
Requires:       suitesparse-devel
Requires:       wxGTK3-devel
Requires:       zlib-devel
BuildRequires:  assimp-devel
BuildRequires:  cmake
BuildRequires:  eigen3-devel
BuildRequires:  ffmpeg-devel
BuildRequires:  freeglut-devel
BuildRequires:  glfw-devel
BuildRequires:  libXrandr-devel
BuildRequires:  libXxf86vm-devel
BuildRequires:  libjpeg-turbo-devel
BuildRequires:  libpcap-devel
BuildRequires:  libudev-devel
BuildRequires:  libusbx-devel
BuildRequires:  opencv-devel
BuildRequires:  suitesparse-devel
BuildRequires:  wxGTK3-devel
BuildRequires:  zlib-devel
Provides:       %{name}-devel = %{version}-%{release}
Provides:       %{name}-doc = %{version}-%{release}
Provides:       %{name}-runtime = %{version}-%{release}

%description
Mobile Robot Programming Toolkit (MRPT) version 2.x

%prep
%autosetup

%build
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree that was dropped by catkin, and source it.  It will
# set things like CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/noetic/setup.sh" ]; then . "/opt/ros/noetic/setup.sh"; fi
mkdir -p obj-%{_target_platform} && cd obj-%{_target_platform}
%cmake3 \
    -UINCLUDE_INSTALL_DIR \
    -ULIB_INSTALL_DIR \
    -USYSCONF_INSTALL_DIR \
    -USHARE_INSTALL_PREFIX \
    -ULIB_SUFFIX \
    -DCMAKE_INSTALL_LIBDIR="lib" \
    -DCMAKE_INSTALL_PREFIX="/opt/ros/noetic" \
    -DCMAKE_PREFIX_PATH="/opt/ros/noetic" \
    -DSETUPTOOLS_DEB_LAYOUT=OFF \
    -DCATKIN_BUILD_BINARY_PACKAGE="1" \
    ..

%make_build

%install
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree that was dropped by catkin, and source it.  It will
# set things like CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/noetic/setup.sh" ]; then . "/opt/ros/noetic/setup.sh"; fi
%make_install -C obj-%{_target_platform}

%files
/opt/ros/noetic

%changelog
* Sun Jun 21 2020 Jose-Luis Blanco-Claraco <joseluisblancoc@gmail.com> - 2.0.4-1
- Autogenerated by Bloom

* Mon May 18 2020 Jose-Luis Blanco-Claraco <joseluisblancoc@gmail.com> - 2.0.3-1
- Autogenerated by Bloom

