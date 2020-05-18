/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          https://www.mrpt.org/                            |
   |                                                                           |
   | Copyright (c) 2005-2020, Individual contributors, see AUTHORS file        |
   | See: https://www.mrpt.org/Authors - All rights reserved.                  |
   | Released under BSD License. See details in https://www.mrpt.org/License   |
   +---------------------------------------------------------------------------+
 */

/** \defgroup mrpt_nav_grp [mrpt-nav]

Autonomous navigation, path planning

<small> <a href="index.html#libs">Back to list of all libraries</a> | <a
href="modules.html" >See all modules</a> </small> <br>

# Library `mrpt-nav`

This library is part of MRPT and can be installed in Debian-based systems with:

		sudo apt install libmrpt-nav-dev

See: \ref mrpt_from_cmake

This library implements:

- Reactive navigation:
  - Holonomic navigation algorithms: Virtual Force Fields (VFF), Nearness
Diagram (ND), ... See mrpt::nav::CAbstractHolonomicReactiveMethod
  - A complex reactive navigator: Using space transformations (PTGs) to drive a
robot using an internal simpler holonomic algorithm. See
mrpt::nav::CReactiveNavigationSystem
  - A number of different PTGs: See mrpt::nav::CParameterizedTrajectoryGenerator
  - See the full list of classes in mrpt::nav, or the online page
https://www.mrpt.org/list-of-mrpt-apps/application-reactivenavigationdemo/ for a
working application (see MRPT/apps/ReactiveNavigationDemo).

* Planned / hybrid navigation:
  * See mrpt::nav

*/
