//
// Created by Michael Heuer on 11.03.18.
//

#ifndef SPHERICALINTEGRATION_SUBGRIDINFO_H
#define SPHERICALINTEGRATION_SUBGRIDINFO_H

#include "SubgridType.h"

namespace Lebedev {
    class SubgridInfo {
    public:
        SubgridInfo(const SubgridType &sg, double v)
                : sg_(sg), a_(0), b_(0), v_(v) {};

        SubgridInfo(const SubgridType &sg, double a, double v)
                : sg_(sg), a_(a), b_(0), v_(v) {};

        SubgridInfo(const SubgridType &sg, double a, double b, double v)
                : sg_(sg), a_(a), b_(b), v_(v) {};

        const SubgridType &subgridType() const { return sg_; };

        double a() const { return a_; };

        double b() const { return b_; };

        double v() const { return v_; };

        unsigned numberOfPoints() const {
            switch (sg_) {
                case SubgridType::SG001:
                    return 6;
                case SubgridType::SG0AA:
                    return 12;
                case SubgridType::SGAAA:
                    return 8;
                case SubgridType::SGAAB:
                    return 24;
                case SubgridType::SGAB0:
                    return 24;
                case SubgridType::SGABC:
                    return 48;
            }
        };

    private:
        SubgridType sg_{};
        double a_, b_, v_;
    };
};

#endif //SPHERICALINTEGRATION_SUBGRIDINFO_H
