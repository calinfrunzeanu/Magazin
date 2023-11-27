//
// Created by calin on 11/27/2023.
//

#include "../headers/magazin.h"

void magazin::adaugaProdus(const Produs &produs) {
    produse_.push_back(produs);
}

std::ostream &operator<<(std::ostream &os, const magazin &magazin) {
    os << "magazin: " << magazin.nume_;
    return os;
}

void magazin::adaugaClient(const client &client) {
    clienti_.push_back(client);
}

void magazin::vindeProdus(const client &client, const Produs &produs) {
    std::cout << "Clientul " << client << " a cumparat " << produs << " din magazinul " << nume_ << std::endl;
}
