//
// Created by Michael Heuer on 10.03.18.
//

#ifndef SPHERICALSURFACEINTEGRATOR_H
#define SPHERICALSURFACEINTEGRATOR_H

#include "SpatialFunction.h"
#include "GridCreator.h"

namespace Lebedev {
    class SphericalSurfaceIntegrator{
    public:
        explicit SphericalSurfaceIntegrator(const OrderType& orderType = OrderType::LD0006)
                : gridCreator_(orderType){};

        double integrate(SpatialFunction* f, double r = 1) const {
            const auto& xyzw = gridCreator_.grid();
            double sum = 0.0;

            for (int i = 0; i < xyzw.rows(); ++i) {
                sum += f->value(r*xyzw.row(i).head(3)) * xyzw.row(i)[3];
            }
            return 4.0*M_PI*sum;
        };

        void changeGrid(const OrderType& orderType){
            gridCreator_.changeGrid(orderType);
        };

        private:
            GridCreator gridCreator_;
    };
};

#endif //SPHERICALSURFACEINTEGRATOR_H
