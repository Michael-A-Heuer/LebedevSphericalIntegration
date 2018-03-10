//
// Created by Michael Heuer on 10.03.18.
//

#include <iostream>
#include "SphericalIntegration.h"

int main() {
    auto arr = Lebedev::getGrid(Lebedev::RuleOrder::LD0014);

    std::cout << arr << std::endl;

    return 0;
}
