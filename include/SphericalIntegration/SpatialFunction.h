//
// Created by Michael Heuer on 11.03.18.
//

#ifndef SPHERICALINTEGRATION_INTEGRABLEPROBLEM_H
#define SPHERICALINTEGRATION_INTEGRABLEPROBLEM_H

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

#endif //SPHERICALINTEGRATION_INTEGRABLEPROBLEM_H
