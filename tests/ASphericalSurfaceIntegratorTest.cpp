//
// Created by Michael Heuer on 11.03.18.
//

#include <gtest/gtest.h>
#include "LebedevSphericalIntegration/SphericalSurfaceIntegrator.h"
#include "LebedevSphericalIntegration/TestFunctions.h"

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
        double calculated = sphericalSurfaceIntegrator.integrate(&f);

        double relError = std::abs(calculated - reference) / (reference);
        ASSERT_LE(relError, 2.2052e-14);
    }
}

TEST_F(ASphericalSurfaceIntegratorTest, GaussSurface) {
    Gauss3d f;

    //Check over a range of equally spaced radii over the interval [0,rEnd]
    double rEnd = 5.0;
    unsigned numberOfRadii = 10;

    for (unsigned i = 0; i <= numberOfRadii; ++i) {

        double r = rEnd * double(i)/double(numberOfRadii);
        //Surface of the unit sphere

        //analytical solution
        double reference = 4.0*std::exp(-std::pow(r,2)) * M_PI * std::pow(r,2);

        // Check all lebedev orders
        for (const auto & order : Lebedev::allOrders) {
            sphericalSurfaceIntegrator.changeGrid(order);
            double calculated = sphericalSurfaceIntegrator.integrate(&f,r)* std::pow(r,2);

            double absError = std::abs(calculated - reference);

            ASSERT_NEAR(calculated,reference,1e-12); // low orders are expected to produce larger errors
        }
    }

}
