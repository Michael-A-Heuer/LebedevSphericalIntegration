//
// Created by Michael Heuer on 10.03.18.
//

#ifndef SPHERICALINTEGRATION_H
#define SPHERICALINTEGRATION_H

#include <Eigen/Core>
#include <array>
#include <vector>

namespace Lebedev {
    enum class RuleOrder{
        LD0006 = 6,
        LD0014 = 14,
        LD0026 = 26,
        LD0038 = 38,
        LD0050 = 50,
        LD0074 = 74,
        LD0086 = 86,
        LD0110 = 110,
        LD0146 = 146,
        LD0170 = 170,
        LD0194 = 194,
        LD0230 = 230,
        LD0266 = 266,
        LD0302 = 302,
        LD0350 = 350,
        LD0434 = 434,
        LD0590 = 590,
        LD0770 = 770,
        LD0974 = 974,
        LD1202 = 1202,
        LD1454 = 1454,
        LD1730 = 1730,
        LD2030 = 2030,
        LD2354 = 2354,
        LD2702 = 2702,
        LD3074 = 3074,
        LD3470 = 3470,
        LD3890 = 3890,
        LD4334 = 4334,
        LD4802 = 4802,
        LD5294 = 5294,
        LD5810 = 5810,
        NumberOfRules = 32
    };


        enum class Oh {
            SG001, // etc.
            SG0AA, // etc., A=1/sqrt(2)
            SGAAA, // etc., A=1/sqrt(3)
            SGAAB, // etc., B=sqrt(1-2 A^2)
            SGAB0, // etc., B=sqrt(1-A^2), A input
            SGABC, // etc., C=sqrt(1-A^2-B^2), A, B input
        };

        static unsigned points(Oh sg){
            switch (sg) {
                case Oh::SG001:
                    return 6;
                case Oh::SG0AA:
                    return 12;
                case Oh::SGAAA:
                    return 8;
                case Oh::SGAAB:
                    return 24;
                case Oh::SGAB0:
                    return 24;
                case Oh::SGABC:
                    return 48;
            }
        }


    class Abv{
    public:
        Abv(const Oh sg, double a, double b, double v)
                : sg_(sg),a_(a),b_(b),v_(v){};
        Abv(const Oh sg, double a, double v)
                : sg_(sg),a_(a),b_(0),v_(v){};
        Abv(const Oh sg, double v)
                : sg_(sg),a_(0),b_(0),v_(v){};

        Oh symmetryGroup() const { return sg_;};
        double a() const { return a_;};
        double b() const { return b_;};
        double v() const { return v_;};

    private:
        Oh sg_;
        double a_,b_,v_;
    };

    std::vector<Abv> getSymmetryGroupChain(RuleOrder order){
        switch(order){
            case RuleOrder::LD0006:
                return {Abv(Oh::SG001,0.1666666666666667)};
            case RuleOrder::LD0014:
                return {Abv(Oh::SG001,0.6666666666666667e-1),
                        Abv(Oh::SGAAA,0.7500000000000000e-1)};
        }
    };

    Eigen::Matrix<double,6,4> getSG001(double v){
        double a = 1.0;
        Eigen::Matrix<double,6,4> xyzw;
        xyzw << \
          a, 0.0, 0.0, v,\
         -a, 0.0, 0.0, v,\
        0.0,   a, 0.0, v,\
        0.0,  -a, 0.0, v,\
        0.0, 0.0,   a, v,\
        0.0, 0.0,  -a, v;
        return xyzw;
    };

    Eigen::Matrix<double,12,4> getSG0AA(double v){
        double a = 1.0;
        Eigen::Matrix<double,12,4> xyzw;
        xyzw << \
        0.0,   a,   a, v,\
        0.0,   a,  -a, v,\
        0.0,  -a,   a, v,\
        0.0,  -a,  -a, v,\
          a, 0.0,   a, v,\
          a, 0.0,  -a, v,\
         -a, 0.0,   a, v,\
         -a, 0.0,  -a, v,\
          a,   a, 0.0, v,\
          a,  -a, 0.0, v,\
         -a,   a, 0.0, v,\
         -a,  -a, 0.0, v;
        return xyzw;
    };

    Eigen::Matrix<double,8,4> getSGAAA(double v){
        double a = 1.0 / sqrt ( 3.0 );
        Eigen::Matrix<double,8,4> xyzw;
        xyzw << \
          a,   a,   a, v,\
          a,   a,  -a, v,\
          a,  -a,   a, v,\
          a,  -a,  -a, v,\
         -a,   a,   a, v,\
         -a,   a,  -a, v,\
         -a,  -a,   a, v,\
         -a,  -a,  -a, v;
        return xyzw;
    };

    Eigen::Matrix<double,24,4> getSGAAB(double a ,double v){
        double b = std::sqrt( 1.0 - 2.0 * a * a );
        Eigen::Matrix<double,24,4> xyzw;
        xyzw << \
          a,   a,   b, v,\
          a,   a,  -b, v,\
          a,  -a,   b, v,\
          a,  -a,  -b, v,\
         -a,   a,   b, v,\
         -a,   a,  -b, v,\
         -a,  -a,   b, v,\
         -a,  -a,  -b, v,\
          a,   b,   a, v,\
          a,  -b,   a, v,\
          a,   b,  -a, v,\
          a,  -b,  -a, v,\
         -a,   b,   a, v,\
         -a,  -b,   a, v,\
         -a,   b,  -a, v,\
         -a,  -b,  -a, v,\
          b,   a,   a, v,\
         -b,   a,   a, v,\
          b,   a,  -a, v,\
         -b,   a,  -a, v,\
          b,  -a,   a, v,\
         -b,  -a,   a, v,\
          b,  -a,  -a, v,\
         -b,  -a,  -a, v;
        return xyzw;
    };

    Eigen::Matrix<double,24,4> getSGAB0(double a ,double v){
        double b = std::sqrt( 1.0 - a * a );
        Eigen::Matrix<double,24,4> xyzw;
        xyzw << \
          a,   b, 0.0, v,\
          a,  -b, 0.0, v,\
         -a,   b, 0.0, v,\
         -a,  -b, 0.0, v,\
          b,   a, 0.0, v,\
          b,  -a, 0.0, v,\
         -b,   a, 0.0, v,\
         -b,  -a, 0.0, v,\
          a, 0.0,   b, v,\
          a, 0.0,  -b, v,\
         -a, 0.0,   b, v,\
         -a, 0.0,  -b, v,\
          b, 0.0,   a, v,\
          b, 0.0,  -a, v,\
         -b, 0.0,   a, v,\
         -b, 0.0,  -a, v,\
        0.0,   a,   b, v,\
        0.0,   a,  -b, v,\
        0.0,  -a,   b, v,\
        0.0,  -a,  -b, v,\
        0.0,   b,   a, v,\
        0.0,   b,  -a, v,\
        0.0,  -b,   a, v,\
        0.0,  -b,  -a, v;
        return xyzw;
    };

    Eigen::Matrix<double,48,4> getSGABC(double a, double b, double v){
        double c = std::sqrt( 1.0 - a * a - b * b );
        Eigen::Matrix<double,48,4> xyzw;
        xyzw << \
          a,   b,   c, v,\
          a,   b,  -c, v,\
          a,  -b,   c, v,\
          a,  -b,  -c, v,\
         -a,   b,   c, v,\
         -a,   b,  -c, v,\
         -a,  -b,   c, v,\
         -a,  -b,  -c, v,\
          a,   c,   b, v,\
          a,   c,  -b, v,\
          a,  -c,   b, v,\
          a,  -c,  -b, v,\
         -a,   c,   b, v,\
         -a,   c,  -b, v,\
         -a,  -c,   b, v,\
         -a,  -c,  -b, v,\
          b,   a,   c, v,\
          b,   a,  -c, v,\
          b,  -a,   c, v,\
          b,  -a,  -c, v,\
         -b,   a,   c, v,\
         -b,   a,  -c, v,\
         -b,  -a,   c, v,\
         -b,  -a,  -c, v,\
          b,   c,   a, v,\
          b,   c,  -a, v,\
          b,  -c,   a, v,\
          b,  -c,  -a, v,\
         -b,   c,   a, v,\
         -b,   c,  -a, v,\
         -b,  -c,   a, v,\
         -b,  -c,  -a, v,\
          c,   a,   b, v,\
          c,   a,  -b, v,\
          c,  -a,   b, v,\
          c,  -a,  -b, v,\
         -c,   a,   b, v,\
         -c,   a,  -b, v,\
         -c,  -a,   b, v,\
         -c,  -a,  -b, v,\
          c,   b,   a, v,\
          c,   b,  -a, v,\
          c,  -b,   a, v,\
          c,  -b,  -a, v,\
         -c,   b,   a, v,\
         -c,   b,  -a, v,\
         -c,  -b,   a, v,\
         -c,  -b,  -a, v;
        return xyzw;
    };


    Eigen::MatrixX4d generateFromOctahedralSymmetry(const Abv& abv){
        switch (abv.symmetryGroup()){
            case Oh::SG001:
                return getSG001(abv.v());
            case Oh::SG0AA:
                return getSG0AA(abv.v());
            case Oh::SGAAA:
                return getSGAAA(abv.v());
            case Oh::SGAAB:
                return getSGAAB(abv.a(),abv.v());
            case Oh::SGAB0:
                return getSGAB0(abv.a(),abv.v());
            case Oh::SGABC:
                return getSGABC(abv.a(),abv.b(),abv.v());
        }
    };

    Eigen::MatrixX4d getGrid(RuleOrder order){
        Eigen::MatrixX4d xyzw(int(order),4);

        auto abvs = getSymmetryGroupChain(order);

        long start = 0;
        for (const auto& abv : abvs){
            auto pts = points(abv.symmetryGroup());
            xyzw.block(start,0,pts,4) = generateFromOctahedralSymmetry(abv);
            start += pts;
        }
        return xyzw;
    }
}
class SphericalIntegration{
public:
    SphericalIntegration();
};

#endif //SPHERICALINTEGRATION_H
