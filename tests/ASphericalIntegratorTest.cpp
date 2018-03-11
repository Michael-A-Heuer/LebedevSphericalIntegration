//
// Created by Michael Heuer on 11.03.18.
//

#include <gtest/gtest.h>
#include <SphericalIntegration.h>
#include <iomanip>

class UnitSphere : public SpatialFunction{
public:
    double value(const Eigen::Vector3d &x) const override {
        return 1.0;
    };
};

using namespace Lebedev;

class ASphericalIntegratorTest : public ::testing::Test {
public:
    SphericalIntegrator sphericalIntegrator;
    void SetUp() override {}
};

TEST_F(ASphericalIntegratorTest, UnitSphereVolume) {

    UnitSphere f;
    //Volume of the unit sphere calculated symbolically with Mathematica
    double reference = 12.5663706143591730;


    for (const auto & order : Lebedev::allOrders) {
        sphericalIntegrator.changeGrid(order);
        double calculated = sphericalIntegrator.integrate(f);

        double relError = std::abs(calculated - reference) / (reference);
        ASSERT_LE(relError, 2.2052e-14);
    }
}
