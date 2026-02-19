#include "Database.h"
#include <fstream>
#include <iostream>

Database::Database(const string& filename) : filename(filename){}

void Database::load() {
    ifstream file(filename);
    if (!file) return;

    string line;
    while (getline(file, line)){
        products.push_back(product::fromFileString(line));
    }
    file.close();
}

void Database::save() {
    ofstream file(filename);
    for (const auto& p : products) {
        file << p.toFileString() << endl;
    }
    file.close();
}

void Database::addProduct(const product& product){
    products.push_back(product);
}

bool Database::deleteProduct(int id){
        for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getID() == id) {
            products.erase(it);
            return true;
        }
    }
    return false;

}

product* Database::findProduct(int id) {
     for (auto& p : products) {
        if (p.getID() == id)
            return &p;
    }
    return nullptr;
}

void Database:: displayAll() const {
    cout << "Product list:\n";
    for (const auto&p : products) {
        cout << "ID: " << p.getID();
        cout << " | Name: " << p.getName();
        cout << " | Price: " << p.getPrice();
        cout << " | Quantity: " << p.getQuantity() << endl;
    }
}