//
// Created by calin on 12/4/2023.
//

#ifndef OOP_CUSTOMER_H
#define OOP_CUSTOMER_H


#include <utility>
#include <string>

class Customer {
private:
    std::string name;
    std::string address;
    std::string email;
    std::string phone;
    std::string cnp;

public:
    Customer(std::string name, std::string address, std::string email, std::string phone)
            : name(std::move(name)), address(std::move(address)), email(std::move(email)), phone(std::move(phone)) {}
};


#endif //OOP_CUSTOMER_H
