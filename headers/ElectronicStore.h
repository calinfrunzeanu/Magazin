//
// Created by calin on 12/4/2023.
//

#ifndef OOP_ELECTRONICSTORE_H
#define OOP_ELECTRONICSTORE_H


#include <utility>
#include <string>
#include <memory>
#include "Product.h"

class ElectronicStore {
private:
    std::shared_ptr<ElectronicProduct> product;

public:
    explicit ElectronicStore(std::shared_ptr<ElectronicProduct> product)
            : product(std::move(product)) {}

    void displayProductInfo() const {
        product->displayProductInfo();
    }
};




#endif //OOP_ELECTRONICSTORE_H
