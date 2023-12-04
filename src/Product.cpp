//
// Created by calin on 12/4/2023.
//

#include "../headers/Product.h"
std::ostream &operator<<(std::ostream &os, const Product &product) {
    os << "Name: " << product.Brand << "\nDescription: " << product.Model << "\nPrice: " << product.Price << "\n";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Cart &cart) {
    os << "Cart:\n";
    for (const auto &product: cart.products) {
        os << *product;
    }
    return os;
}