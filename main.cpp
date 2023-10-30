#include <iostream>
#include <vector>
#include <string>

class Produs {
public:
    Produs(const std::string& nume, double pret) : nume_(nume), pret_(pret) {}

    Produs(const Produs& other) : nume_(other.nume_), pret_(other.pret_) {}
    Produs& operator=(const Produs& other) {
        if (this != &other) {
            nume_ = other.nume_;
            pret_ = other.pret_;
        }
        return *this;
    }
    ~Produs() = default;

    friend std::ostream& operator<<(std::ostream& os, const Produs& produs) {
        os << "Produs: " << produs.nume_ << ", Pret: " << produs.pret_;
        return os;
    }

private:
    std::string nume_;
    double pret_;
};

class Client {
public:
    Client(std::string  nume) : nume_(std::move(nume)) {}

    Client(const Client& other) : nume_(other.nume_) {}
    Client& operator=(const Client& other) {
        if (this != &other) {
            nume_ = other.nume_;
        }
        return *this;
    }
    ~Client() = default;

    friend std::ostream& operator<<(std::ostream& os, const Client& client) {
        os << "Client: " << client.nume_;
        return os;
    }

private:
    std::string nume_;
};

class Magazin {
public:
    explicit Magazin(std::string  nume) : nume_(std::move(nume)) {}

    Magazin(const Magazin& other) : nume_(other.nume_) {}
    Magazin& operator=(const Magazin& other) {
        if (this != &other) {
            nume_ = other.nume_;
        }
        return *this;
    }
    ~Magazin() = default;

    void adaugaProdus(const Produs& produs) {
        produse_.push_back(produs);
    }

    void adaugaClient(const Client& client) {
        clienti_.push_back(client);
    }

    void vindeProdus(const Client& client, const Produs& produs) {
        // Logica pentru vanzare
        std::cout << "Clientul " << client << " a cumparat " << produs << " din magazinul " << nume_ << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Magazin& magazin) {
        os << "Magazin: " << magazin.nume_;
        return os;
    }

private:
    std::string nume_;
    std::vector<Produs> produse_;
    std::vector<Client> clienti_;
};

int main() {
    Produs laptop("Laptop", 2500.0);
    Produs telefon("Telefon", 1200.0);

    Client client("John Doe");

    Magazin magazin("Magazinul Meu");
    magazin.adaugaProdus(laptop);
    magazin.adaugaProdus(telefon);
    magazin.adaugaClient(client);

    std::cout << magazin << std::endl;

    magazin.vindeProdus(client, laptop);

    return 0;
}
