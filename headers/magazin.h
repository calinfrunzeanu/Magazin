//
// Created by calin on 11/27/2023.
//

#ifndef OOP_MAGAZIN_H
#define OOP_MAGAZIN_H

#include <iostream>
#include <vector>
#include "produs.h"
#include "client.h"

class magazin {
public:
    explicit magazin(std::string nume) : nume_(std::move(nume)) {}

    magazin(const magazin &other) : nume_(other.nume_) {}

    magazin &operator=(const magazin &other) {
        if (this != &other) {
            nume_ = other.nume_;
        }
        return *this;
    }

    ~magazin() = default;

    void adaugaProdus(const Produs &produs);

    void adaugaClient(const client &client);

    void vindeProdus(const client &client, const Produs &produs);

    friend std::ostream &operator<<(std::ostream &os, const magazin &magazin);

private:
    std::string nume_;
    std::vector<Produs> produse_;
    std::vector<client> clienti_;
};


#endif //OOP_MAGAZIN_H
