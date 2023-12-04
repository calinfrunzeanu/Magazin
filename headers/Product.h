//
// Created by calin on 12/4/2023.
//

#ifndef OOP_PRODUCT_H
#define OOP_PRODUCT_H


#include <iostream>
#include <memory>
#include <vector>

class Product {
private:
    std::string Brand;
    std::string Model;
    double Price;

public:
    // Default constructor
    Product() : Price(0.0) {}

    Product(std::string brand, std::string model, double price)
            : Brand(std::move(brand)), Model(std::move(model)), Price(price) {}

    virtual void displayProductInfo() const = 0;

    virtual std::unique_ptr<Product> clone() const = 0;

    virtual ~Product() = default;

    friend std::ostream &operator<<(std::ostream &os, const Product &product);
};

class NonElectronicProduct : public Product {
public:
    NonElectronicProduct (std::string brand, std::string model, double price)
            : Product(std::move(brand), std::move(model), price) {}

    void displayProductInfo() const override = 0;

    virtual std::unique_ptr<Product> clone() const override = 0;

    ~NonElectronicProduct() override = default;
};

class Case : public NonElectronicProduct {
public:
    Case (std::string brand, std::string model, double price)
            : NonElectronicProduct(std::move(brand), std::move(model), price) {}

    void displayProductInfo() const override {
        std::cout << "Case\n";
    }

    std::unique_ptr<Product> clone() const override {
        return std::make_unique<Case>(*this);
    }
};

class GlassProtection : public NonElectronicProduct {
public:
    GlassProtection (std::string brand, std::string model, double price)
            : NonElectronicProduct(std::move(brand), std::move(model), price) {}

    void displayProductInfo() const override {
        std::cout << "GlassProtection\n";
    }

    std::unique_ptr<Product> clone() const override {
        return std::make_unique<GlassProtection>(*this);
    }
};

class ElectronicProduct : public Product {
public:
    ElectronicProduct (std::string brand, std::string model, double price)
            : Product(std::move(brand), std::move(model), price) {}

    virtual void displayProductInfo() const override = 0;

    virtual std::unique_ptr<Product> clone() const override = 0;

    virtual ~ElectronicProduct() = default;
};

class Smartphone : public ElectronicProduct {
public:
    // Default constructor
    Smartphone() : ElectronicProduct("", "", 0.0) {}

    Smartphone(std::string brand, std::string model, double price)
            : ElectronicProduct(std::move(brand), std::move(model), price) {}

    void displayProductInfo() const override {
        std::cout << "Smartphone\n";
    }

    std::unique_ptr<Product> clone() const override {
        return std::make_unique<Smartphone>(*this);
    }
};


class Laptop : public ElectronicProduct {
public:
    Laptop (std::string brand, std::string model, double price)
            : ElectronicProduct(std::move(brand), std::move(model), price) {}

    void displayProductInfo() const override {
        std::cout << "Laptop\n";
    }

    std::unique_ptr<Product> clone() const override {
        return std::make_unique<Laptop>(*this);
    }
};

class Tablet : public ElectronicProduct {
public:
    Tablet (std::string brand, std::string model, double price)
            : ElectronicProduct(std::move(brand), std::move(model), price) {}

    void displayProductInfo() const override {
        std::cout << "Tablet\n";
    }

    std::unique_ptr<Product> clone() const override {
        return std::make_unique<Tablet>(*this);
    }
};

class Cart {
private:
    std::vector<std::shared_ptr<Product>> products;

public:
    void addProduct(std::shared_ptr<Product> product) {
        products.push_back(std::move(product));
    }

    friend std::ostream &operator<<(std::ostream &os, const Cart &cart);
};


#endif //OOP_PRODUCT_H
