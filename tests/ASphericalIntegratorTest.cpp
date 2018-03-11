//
// Created by Heuer on 10.03.18.
//

#include <gtest/gtest.h>
#include <Eigen/Core>
#include "SphericalIntegrator.h"
#include "sphere_lebedev_rule.h"

class ASphericalIntegratorTest : public ::testing::Test {
public:
    Lebedev::SphericalIntegrator sphericalIntegrator;
    void SetUp() override {}
};


TEST_F(ASphericalIntegrationTest, JBurkardtReferenceCheck) {

    for (const auto & order : Lebedev::allOrders) {
        sphericalIntegrator.changeGrid(order);
        auto nPts = sphericalIntegrator.totalNumberOfGridPoints();
        auto calculated = sphericalIntegrator.grid();

        double x[nPts], y[nPts], z[nPts], w[nPts];
        ld_by_order(nPts, x, y, z, w);

        Eigen::Matrix<double,Eigen::Dynamic,4> reference(nPts, 4);
        reference.col(0) = Eigen::VectorXd::Map(x, nPts);
        reference.col(1) = Eigen::VectorXd::Map(y, nPts);
        reference.col(2) = Eigen::VectorXd::Map(z, nPts);
        reference.col(3) = Eigen::VectorXd::Map(w, nPts);

        ASSERT_EQ(calculated.rows(),reference.rows());
        ASSERT_EQ(calculated.cols(),reference.cols());

        ASSERT_TRUE(calculated.isApprox(reference,0.0));
    }
}

TEST_F(ASphericalIntegrationTest, JBurkardtReferenceCheckElementWise) {

    // check all rules
    for (const auto & order : Lebedev::allOrders) {
        sphericalIntegrator.changeGrid(order);
        auto nPts = sphericalIntegrator.totalNumberOfGridPoints();
        auto calculated = sphericalIntegrator.grid();

        double x[nPts], y[nPts], z[nPts], w[nPts];
        ld_by_order(nPts, x, y, z, w);

        Eigen::Matrix<double,Eigen::Dynamic,4> reference(nPts, 4);
        reference.col(0) = Eigen::VectorXd::Map(x, nPts);
        reference.col(1) = Eigen::VectorXd::Map(y, nPts);
        reference.col(2) = Eigen::VectorXd::Map(z, nPts);
        reference.col(3) = Eigen::VectorXd::Map(w, nPts);

        ASSERT_EQ(calculated.rows(),reference.rows());
        ASSERT_EQ(calculated.cols(),reference.cols());

        for (int i = 0; i < nPts; ++i) {
            for (int j = 0; j < 4; ++j) {
                ASSERT_EQ(calculated.row(i)[j], reference.row(i)[j]);
            }
        }
    }
}

