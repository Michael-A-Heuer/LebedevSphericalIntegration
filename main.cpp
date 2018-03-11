//
// Created by Michael Heuer on 10.03.18.
//

#include <iostream>
#include "SphericalIntegration.h"

int main() {
    Lebedev::GridCreator gridCreator(Lebedev::OrderType::LD0014);

    std::cout << gridCreator.grid() << std::endl;

    return 0;
}
