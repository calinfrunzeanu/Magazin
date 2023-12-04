//
// Created by calin on 12/4/2023.
//

#include "../headers/Exceptions.h"


const char *loginError::what() const noexcept {
    return "Login error";
}

const char *nameError::what() const noexcept {
    return "Name error";
}

const char *cnpError::what() const noexcept {
    return "CNP error";
}