//
// Created by Michael Heuer on 11.03.18.
//

#ifndef LEBEDEVSPHERICALINTEGRATION_SPATIALFUNCTION_H
#define LEBEDEVSPHERICALINTEGRATION_SPATIALFUNCTION_H

#include <Eigen/Core>

class SpatialFunction {
public:
    virtual double value(const Eigen::Vector3d &rvec) const = 0;

    double operator()(const Eigen::Vector3d &rvec) const {
        return value(rvec);
    };
};

#endif //LEBEDEVSPHERICALINTEGRATION_SPATIALFUNCTION_H
