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


class ASphericalSurfaceIntegratorTest : public ::testing::Test {
public:
    Lebedev::SphericalSurfaceIntegrator sphericalSurfaceIntegrator;
    void SetUp() override {}
};

TEST_F(ASphericalSurfaceIntegratorTest, UnitSphereSurface) {

    UnitSphere f;
    //Surface of the unit sphere
    double reference = 4*M_PI;

    for (const auto & order : Lebedev::allOrders) {
        sphericalSurfaceIntegrator.changeGrid(order);
        double calculated = sphericalSurfaceIntegrator.integrate(f);

        double relError = std::abs(calculated - reference) / (reference);
        ASSERT_LE(relError, 2.2052e-14);
    }
}
