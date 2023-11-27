//
// Created by calin on 11/27/2023.
//

#ifndef OOP_CLIENT_H
#define OOP_CLIENT_H

#include "iostream"

class client {
public:
    explicit client(std::string nume) : nume_(std::move(nume)) {}

    client(const client &other) : nume_(other.nume_) {}

    client &operator=(const client &other) {
        if (this != &other) {
            nume_ = other.nume_;
        }
        return *this;
    }

    ~client() = default;

    friend std::ostream &operator<<(std::ostream &os, const client &client);

private:
    std::string nume_;
};


#endif //OOP_CLIENT_H
