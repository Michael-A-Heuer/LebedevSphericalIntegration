//
// Created by Michael Heuer on 11.03.18.
//

#include <gtest/gtest.h>
#include <LebedevSphericalIntegration/SphericalSurfaceIntegrator.h>

class UnitSphere : public SpatialFunction{
public:
    double value(const Eigen::Vector3d &x) const override {
        return 1.0;
    };
};

using namespace Lebedev;

class ASphericalSurfaceIntegratorTest : public ::testing::Test {
public:
    SphericalSurfaceIntegrator sphericalSurfaceIntegrator;
    void SetUp() override {}
};

TEST_F(ASphericalSurfaceIntegratorTest, UnitSphereVolume) {

    UnitSphere f;
    //Volume of the unit sphere calculated symbolically with Mathematica
    double reference = 12.5663706143591730;


    for (const auto & order : Lebedev::allOrders) {
        sphericalSurfaceIntegrator.changeGrid(order);
        double calculated = sphericalSurfaceIntegrator.integrate(f);

        double relError = std::abs(calculated - reference) / (reference);
        ASSERT_LE(relError, 2.2052e-14);
    }
}
