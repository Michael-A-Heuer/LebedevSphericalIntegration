//
// Created by Michael Heuer on 15.03.18.
//

#ifndef AMOLQCPP_TESTFUNCTIONS_H
#define AMOLQCPP_TESTFUNCTIONS_H

#include "SpatialFunction.h"

class UnitSphere : public SpatialFunction{
public:
    double value(const Eigen::Vector3d &direction) const override {
        return 1.0;
    };
};

class Gauss3d : public SpatialFunction{
public:
    double value(const Eigen::Vector3d &rvec) const override {
        return std::exp(-rvec.squaredNorm());
    };
};

#endif //AMOLQCPP_TESTFUNCTIONS_H
