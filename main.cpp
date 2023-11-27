#include <iostream>
#include "headers/produs.h"
#include "headers/client.h"
#include "headers/magazin.h"

int main() {
    Produs laptop("Laptop", 2500.0, 250.0);
    Produs telefon("Telefon", 1200.0, 120.0);

    client client("John Doe");

    magazin magazin("Magazinul Meu");
    magazin.adaugaProdus(laptop);
    magazin.adaugaProdus(telefon);
    magazin.adaugaClient(client);

    std::cout << magazin << std::endl;

    magazin.vindeProdus(client, laptop);
    magazin.vindeProdus(client, telefon);

    return 0;
}

