//
// Created by Michael Heuer on 10.03.18.
//

#include <iostream>
#include "SphericalIntegrator.h"

int main() {
    Lebedev::SphericalIntegrator sphericalIntegrator(Lebedev::Order::LD0014);

    std::cout << sphericalIntegrator.grid() << std::endl;

    return 0;
}
