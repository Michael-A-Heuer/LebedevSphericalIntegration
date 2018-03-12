//
// Created by Michael Heuer on 11.03.18.
//

#ifndef SPHERICALINTEGRATION_SUBGRIDTYPES_H
#define SPHERICALINTEGRATION_SUBGRIDTYPES_H

namespace Lebedev {
    // Octahedral subgrid types
    enum class SubgridType {
        SG001, // etc.
        SG0AA, // etc., A=1/sqrt(2)
        SGAAA, // etc., A=1/sqrt(3)
        SGAAB, // etc., B=sqrt(1-2 A^2)
        SGAB0, // etc., B=sqrt(1-A^2), A input
        SGABC, // etc., C=sqrt(1-A^2-B^2), A, B input
    };
}

#endif //SPHERICALINTEGRATION_SUBGRIDTYPES_H
