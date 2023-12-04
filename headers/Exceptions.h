//
// Created by calin on 12/4/2023.
//

#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H


#include "Customer.h"


// Adăugăm o clasă de bază pentru erori specifice
class loginError : public std::exception {
public:
    virtual const char *what() const noexcept override;
};

class nameError : public loginError {
public:
    const char *what() const noexcept override;
};

class cnpError : public loginError {
public:
    const char *what() const noexcept override;
};


#endif //OOP_EXCEPTIONS_H
