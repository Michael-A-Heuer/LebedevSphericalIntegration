# C++ Lebedev Spherical Integration

#####  A C++ header-only library for performing numerical integration over a surface of a sphere using Lebedev quadrature.

## Introduction

The Lebedev quadrature grid calculation is a complete remake of
John Burkardt's
[**sphere_lebedev_rule**](http://people.sc.fsu.edu/~jburkardt/f_src/sphere_lebedev_rule/sphere_lebedev_rule.html)
library using the **Eigen3** library and modern **C++11**.
The original code is included for testing purposes.

**Reference to the used algorithms and numerical values:**

    Vyacheslav Lebedev, Dmitri Laikov,
    A quadrature formula for the sphere of the 131st algebraic order of accuracy,
    Russian Academy of Sciences Doklady Mathematics,
    Volume 59, Number 3, 1999, pages 477-481.

## Requirements

* [Eigen3](http://eigen.tuxfamily.org/index.php?title=Main_Page)

## Installation

Just include the repository as a subdirectory in your CMake build or link to the `SphericalIntegration.h` file directly.