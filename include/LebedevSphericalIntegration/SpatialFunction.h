//
// Created by Michael Heuer on 11.03.18.
//

#ifndef LEBEDEVSPHERICALINTEGRATION_SPATIALFUNCTION_H
#define LEBEDEVSPHERICALINTEGRATION_SPATIALFUNCTION_H

#include <Eigen/Core>

class SpatialFunction {
public:

    SpatialFunction() = default;

    virtual ~SpatialFunction() = default;

    virtual double value(const Eigen::Vector3d &x) const = 0;

    double operator()(const Eigen::Vector3d &x) const {
        return value(x);
    };
};

#endif //LEBEDEVSPHERICALINTEGRATION_SPATIALFUNCTION_H
