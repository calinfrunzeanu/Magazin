//
// Created by calin on 11/27/2023.
//

#ifndef OOP_PRODUS_H
#define OOP_PRODUS_H

#include <iostream>
#include <utility>

class Produs {
public:
    Produs(std::string nume, double pret, double profit) : nume_(std::move(nume)), pret_(pret), profit_(profit) {}

    Produs(const Produs &other) : nume_(other.nume_), pret_(other.pret_), profit_(other.profit_) {}

    Produs &operator=(const Produs &other) {
        if (this != &other) {
            nume_ = other.nume_;
            pret_ = other.pret_;
            profit_ = other.profit_;
        }
        return *this;
    }

    ~Produs() = default;

    friend std::ostream &operator<<(std::ostream &os, const Produs &produs);

private:
    std::string nume_;
    double pret_, profit_;

};


#endif //OOP_PRODUS_H
