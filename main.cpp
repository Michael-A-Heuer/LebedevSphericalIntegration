//
// Created by Michael Heuer on 10.03.18.
//

#include <iostream>
#include "SphericalIntegration.h"

int main() {
    Lebedev::SphericalIntegration sphericalIntegrator;
    
    auto arr = sphericalIntegrator.getGrid(Lebedev::RuleOrder::LD0014);

    std::cout << arr << std::endl;

    return 0;
}
