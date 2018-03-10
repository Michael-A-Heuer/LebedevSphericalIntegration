//
// Created by Michael Heuer on 10.03.18.
//

#include <iostream>
#include "SphericalIntegrator.h"

int main() {
    Lebedev::SphericalIntegrator sphericalIntegrator;

    auto arr = sphericalIntegrator.createGrid(Lebedev::Order::LD0014);

    std::cout << arr << std::endl;

    return 0;
}
