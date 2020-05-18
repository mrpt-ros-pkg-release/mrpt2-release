/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          https://www.mrpt.org/                            |
   |                                                                           |
   | Copyright (c) 2005-2020, Individual contributors, see AUTHORS file        |
   | See: https://www.mrpt.org/Authors - All rights reserved.                  |
   | Released under BSD License. See details in https://www.mrpt.org/License   |
   +---------------------------------------------------------------------------+
 */

// clang-format off

/** \defgroup mrpt_bayes_grp [mrpt-bayes]

Bayesian filtering algorithms

<small> <a href="index.html#libs">Back to list of all libraries</a> | <a
href="modules.html" >See all modules</a> </small> <br>

[TOC]

# Library `mrpt-bayes`

This C++ library is part of MRPT and can be installed in Debian-based systems with:

		sudo apt install libmrpt-bayes-dev

See: \ref mrpt_from_cmake

Refer to classes in the namespace mrpt::bayes and these examples:
 - [bayes_tracking_example](https://github.com/MRPT/mrpt/tree/master/samples/bayes_tracking_example)

## Kalman filters

A generic, templatized Kalman filter implementation (includes EKF,IEKF and in the future, UKF),
which only requires from the programmer to provide the system models and (optinally) the Jacobians.

See mrpt::bayes::CKalmanFilterCapable.

## Particle filters

A set of helper classes and functions to perform particle filtering. In this case the algorithms
are not as generic as in Kalman filtering, but the classes serve to organize and unify the interface
of different PF algorithms in MRPT.

See mrpt::bayes::CParticleFilter.


*/
