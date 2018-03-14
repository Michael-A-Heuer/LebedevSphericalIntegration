//
// Created by Michael Heuer on 11.03.18.
//

#ifndef LEBEDEVSPHERICALINTEGRATION_ORDERTYPE_H
#define LEBEDEVSPHERICALINTEGRATION_ORDERTYPE_H

#include <array>

namespace Lebedev {
    // Order of the Lebedev integration grid. The four digits indicate the total number of grid points.
    enum class OrderType {
        LD0006 = 3,
        LD0014 = 5,
        LD0026 = 7,
        LD0038 = 9,
        LD0050 = 11,
        LD0074 = 13,
        LD0086 = 15,
        LD0110 = 17,
        LD0146 = 19,
        LD0170 = 21,
        LD0194 = 23,
        LD0230 = 25,
        LD0266 = 27,
        LD0302 = 29,
        LD0350 = 31,
        //LD0386 = 33,
        LD0434 = 35,
        //LD0482 = 37,
        //LD0530 = 39,
        LD0590 = 41,
        //LD0650 = 43,
        //LD0698 = 45,
        LD0770 = 47,
        //LD0830 = 49,
        //LD0890 = 51,
        LD0974 = 53,
        //LD1046 = 55,
        //LD1118 = 57,
        LD1202 = 59,
        //LD1274 = 61,
        //LD1358 = 63,
        LD1454 = 65,
        //LD1538 = 67,
        //LD1622 = 69,
        LD1730 = 71,
        //LD1814 = 73,
        //LD1910 = 75,
        LD2030 = 77,
        //LD2126 = 79,
        //LD2222 = 81,
        LD2354 = 83,
        //LD2450 = 85,
        //LD2558 = 87,
        LD2702 = 89,
        //LD2810 = 91,
        //LD2930 = 93,
        LD3074 = 95,
        //LD3182 = 97,
        //LD3314 = 99,
        LD3470 = 101,
        //LD3590 = 103,
        //LD3722 = 105,
        LD3890 = 107,
        //LD4010 = 109,
        //LD4154 = 111,
        LD4334 = 113,
        //LD4466 = 115,
        //LD4610 = 117,
        LD4802 = 119,
        //LD4934 = 121,
        //LD5090 = 123,
        LD5294 = 125,
        //LD5438 = 127,
        //LD5606 = 129,
        LD5810 = 131,
        NumberOfOrders = 32, // out of 65
        NotAvailable = 0
    };

    // Array of all orderTypes to allow iteration
    const std::array<OrderType, static_cast<unsigned>(OrderType::NumberOfOrders)> allOrders = {
            OrderType::LD0006, OrderType::LD0014, OrderType::LD0026, OrderType::LD0038, OrderType::LD0050,
            OrderType::LD0074, OrderType::LD0086, OrderType::LD0110, OrderType::LD0146, OrderType::LD0170,
            OrderType::LD0194, OrderType::LD0230, OrderType::LD0266, OrderType::LD0302, OrderType::LD0350,
            OrderType::LD0434, OrderType::LD0590, OrderType::LD0770, OrderType::LD0974, OrderType::LD1202,
            OrderType::LD1454, OrderType::LD1730, OrderType::LD2030, OrderType::LD2354, OrderType::LD2702,
            OrderType::LD3074, OrderType::LD3470, OrderType::LD3890, OrderType::LD4334, OrderType::LD4802,
            OrderType::LD5294, OrderType::LD5810
    };

    static OrderType findAdequateRule(unsigned requiredPolynomialOrder){
        for (const auto & order : allOrders){
            if(static_cast<unsigned>(order) >= requiredPolynomialOrder)
                return order;
        }
        return OrderType::NotAvailable;
    };
}

#endif //LEBEDEVSPHERICALINTEGRATION_ORDERTYPE_H
