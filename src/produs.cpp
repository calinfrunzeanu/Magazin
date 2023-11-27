//
// Created by calin on 11/27/2023.
//

#include "../headers/produs.h"


std::ostream &operator<<(std::ostream &os, const Produs &produs) {
    os << "Produs: " << produs.nume_ << ", Pret: " << produs.pret_ << ", Profit: " << produs.profit_;
    return os;
}