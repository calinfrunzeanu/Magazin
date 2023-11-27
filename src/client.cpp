//
// Created by calin on 11/27/2023.
//

#include "../headers/client.h"

std::ostream &operator<<(std::ostream &os, const client &client) {
    os << "client: " << client.nume_;
    return os;
}