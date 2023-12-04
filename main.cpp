#include <iostream>
#include <memory>
#include "headers/ElectronicStore.h"
#include "headers/Exceptions.h"
#include "headers/Product.h"
#include <algorithm>

int main()
{
    unsigned int choice;
    unsigned int choice2;
    unsigned int choice3;
    unsigned int choice4;


    try
    {
        // Creare produse
        Smartphone Iphone("Apple", "Iphone 12", 1000);
        Smartphone Samsung("Samsung", "Galaxy S20", 900);
        Smartphone Huawei("Huawei", "P40 Pro", 800);
        Smartphone Xiaomi("Xiaomi", "Mi 10", 700);
        Smartphone OnePlus("OnePlus", "8 Pro", 600);

        Tablet iPad("Apple", "iPad Pro", 1000);
        Tablet SamsungTab("Samsung", "Galaxy Tab S7", 900);
        Tablet HuaweiTab("Huawei", "MatePad Pro", 800);
        Tablet XiaomiTab("Xiaomi", "Mi Pad 4", 700);
        Tablet OnePlusTab("OnePlus", "OnePlus Tab", 600);

        Laptop MacBook("Apple", "MacBook Pro", 1000);
        Laptop SamsungLaptop("Samsung", "Galaxy Book Flex", 900);
        Laptop HuaweiLaptop("Huawei", "MateBook X Pro", 800);
        Laptop XiaomiLaptop("Xiaomi", "Mi Notebook Pro", 700);
        Laptop OnePlusLaptop("OnePlus", "OnePlus Laptop", 600);

        GlassProtection glassProtection("UAG", "Iphone 12", 50);
        GlassProtection glassProtection2("UAG", "Galaxy S20", 50);
        GlassProtection glassProtection3("UAG", "P40 Pro", 50);
        GlassProtection glassProtection4("UAG", "Mi 10", 50);
        GlassProtection glassProtection5("UAG", "8 Pro", 50);

        GlassProtection glassProtection6("UAG", "iPad Pro", 50);
        GlassProtection glassProtection7("UAG", "Galaxy Tab S7", 50);
        GlassProtection glassProtection8("UAG", "MatePad Pro", 50);
        GlassProtection glassProtection9("UAG", "Mi Pad 4", 50);
        GlassProtection glassProtection10("UAG", "OnePlus Tab", 50);

        GlassProtection glassProtection11("UAG", "MacBook Pro", 50);
        GlassProtection glassProtection12("UAG", "Galaxy Book Flex", 50);
        GlassProtection glassProtection13("UAG", "MateBook X Pro", 50);
        GlassProtection glassProtection14("UAG", "Mi Notebook Pro", 50);
        GlassProtection glassProtection15("UAG", "OnePlus Laptop", 50);

        Case case1("UAG", "Iphone 12", 50);
        Case case2("UAG", "Galaxy S20", 50);
        Case case3("UAG", "P40 Pro", 50);
        Case case4("UAG", "Mi 10", 50);
        Case case5("UAG", "8 Pro", 50);

        Case case6("UAG", "iPad Pro", 50);
        Case case7("UAG", "Galaxy Tab S7", 50);
        Case case8("UAG", "MatePad Pro", 50);
        Case case9("UAG", "Mi Pad 4", 50);
        Case case10("UAG", "OnePlus Tab", 50);

        Case case11("UAG", "MacBook Pro", 50);
        Case case12("UAG", "Galaxy Book Flex", 50);
        Case case13("UAG", "MateBook X Pro", 50);
        Case case14("UAG", "Mi Notebook Pro", 50);
        Case case15("UAG", "OnePlus Laptop", 50);

        // Creare obiecte shared_ptr pentru produse
        std::shared_ptr<Product> smartphone = std::make_shared<Smartphone>(Iphone);
        std::shared_ptr<Product> smartphone2 = std::make_shared<Smartphone>(Samsung);
        std::shared_ptr<Product> smartphone3 = std::make_shared<Smartphone>(Huawei);
        std::shared_ptr<Product> smartphone4 = std::make_shared<Smartphone>(Xiaomi);
        std::shared_ptr<Product> smartphone5 = std::make_shared<Smartphone>(OnePlus);

        std::shared_ptr<Product> tablet = std::make_shared<Tablet>(iPad);
        std::shared_ptr<Product> tablet2 = std::make_shared<Tablet>(SamsungTab);
        std::shared_ptr<Product> tablet3 = std::make_shared<Tablet>(HuaweiTab);
        std::shared_ptr<Product> tablet4 = std::make_shared<Tablet>(XiaomiTab);
        std::shared_ptr<Product> tablet5 = std::make_shared<Tablet>(OnePlusTab);

        std::shared_ptr<Product> laptop = std::make_shared<Laptop>(MacBook);
        std::shared_ptr<Product> laptop2 = std::make_shared<Laptop>(SamsungLaptop);
        std::shared_ptr<Product> laptop3 = std::make_shared<Laptop>(HuaweiLaptop);
        std::shared_ptr<Product> laptop4 = std::make_shared<Laptop>(XiaomiLaptop);
        std::shared_ptr<Product> laptop5 = std::make_shared<Laptop>(OnePlusLaptop);

        // Creare coș de cumpărături
        Cart cart;

        // Verificare autentificare
        std::string username;
        std::string name;
        std::string password;
        std::string cnp;

        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        std::cout << "Enter CNP: ";
        std::cin >> cnp;

        if (username != "admin" || password != "admin") {
            throw loginError();
        }

        if (cnp.size() != 13 || !std::all_of(cnp.begin(), cnp.end(), ::isdigit)) {
            throw cnpError();
        }

        std::cout << "Enter Brand: ";
        std::cin >> name;

        if (name.size() < 3 || !std::all_of(name.begin(), name.end(), ::isalpha)) {
            throw nameError();
        }

        std::cout << "Welcome " << name << "!\n";

        // Afișare meniu produse
        std::cout << "Choose a product:\n";
        std::cout << "1. Smartphone\n";
        std::cout << "2. Laptop\n";
        std::cout << "3. Tablet\n";

        std::cin >> choice;

        switch (choice) {
            case 1:
                cart.addProduct(smartphone);
                std::cout << "Choose an accessory:\n";
                std::cout << "1. Glass protection\n";
                std::cout << "2. Case\n";

                std::cin >> choice2;

                switch (choice2) {
                    case 1:
                        cart.addProduct(std::make_shared<GlassProtection>(glassProtection));
                        break;
                    case 2:
                        cart.addProduct(std::make_shared<Case>(case1));
                        break;
                    default:
                        std::cout << "Invalid choice\n";
                        break;
                }
                break;
            case 2:
                cart.addProduct(laptop);
                std::cout << "Choose an accessory:\n";
                std::cout << "1. Case\n";

                std::cin >> choice3;

                switch (choice3) {
                    case 1:
                        cart.addProduct(std::make_shared<Case>(case6));
                        break;
                    default:
                        std::cout << "Invalid choice\n";
                        break;
                }
                break;
            case 3:
                cart.addProduct(tablet);
                std::cout << "Choose an accessory:\n";
                std::cout << "1. Glass protection\n";
                std::cout << "2. Case\n";

                std::cin >> choice4;

                switch (choice4) {
                    case 1:
                        cart.addProduct(std::make_shared<GlassProtection>(glassProtection11));
                        break;
                    case 2:
                        cart.addProduct(std::make_shared<Case>(case11));
                        break;
                    default:
                        std::cout << "Invalid choice\n";
                        break;
                }
                break;
            default:
                std::cout << "Invalid choice\n";
                break;
        }

        // Afișare produse din coș
        std::cout << "\nProducts in the cart:\n";
        std::cout << cart;

        // Creare obiect shared_ptr pentru produs electronic
        std::shared_ptr<ElectronicProduct> electronicProduct = std::make_shared<Smartphone>();
        ElectronicStore electronicStore(electronicProduct);
        electronicStore.displayProductInfo();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
