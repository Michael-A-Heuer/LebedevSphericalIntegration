//
// Created by Heuer on 10.03.18.
//

#include <gtest/gtest.h>
#include <Eigen/Core>
#include "SphericalIntegration.h"
#include "sphere_lebedev_rule.h"

class ASphericalIntegrationTest : public ::testing::Test {
public:
    Lebedev::SphericalIntegration sphericalIntegrator;
    void SetUp() override {}
};


TEST_F(ASphericalIntegrationTest, JBurkardtReferenceCheck) {

    for (const auto & rule : Lebedev::allRules) {
        auto order = static_cast<unsigned>(rule);
        auto calculated = sphericalIntegrator.getGrid(rule);

        Eigen::MatrixX4d reference(order, 4);

        double x[order], y[order], z[order], w[order];
        ld_by_order(order, x, y, z, w);

        auto xvec = Eigen::Map<Eigen::VectorXd>(x, order);
        auto yvec = Eigen::Map<Eigen::VectorXd>(y, order);
        auto zvec = Eigen::Map<Eigen::VectorXd>(z, order);
        auto wvec = Eigen::Map<Eigen::VectorXd>(w, order);

        reference.col(0) = xvec;
        reference.col(1) = yvec;
        reference.col(2) = zvec;
        reference.col(3) = wvec;

        ASSERT_TRUE(calculated.isApprox(reference,0.0));
    }
}

TEST_F(ASphericalIntegrationTest, JBurkardtReferenceCheckElementWise) {

    // check all rules
    for (const auto & rule : Lebedev::allRules) {
        auto order = static_cast<unsigned>(rule);
        auto calculated = sphericalIntegrator.getGrid(rule);

        Eigen::MatrixX4d reference(order, 4);

        double x[order], y[order], z[order], w[order];
        ld_by_order(order, x, y, z, w);
        auto xvec = Eigen::Map<Eigen::VectorXd>(x, order);
        auto yvec = Eigen::Map<Eigen::VectorXd>(y, order);
        auto zvec = Eigen::Map<Eigen::VectorXd>(z, order);
        auto wvec = Eigen::Map<Eigen::VectorXd>(w, order);

        reference.col(0) = xvec;
        reference.col(1) = yvec;
        reference.col(2) = zvec;
        reference.col(3) = wvec;


        ASSERT_EQ(reference.rows(), calculated.rows());
        ASSERT_EQ(reference.cols(), calculated.cols());

        for (int i = 0; i < order; ++i) {
            for (int j = 0; j < 4; ++j) {
                ASSERT_EQ(calculated.row(i)[j], reference.row(i)[j]);
            }
        }
    }
}

