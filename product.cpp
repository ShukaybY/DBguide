#include "product.h"
#include <sstream>

product::product() : id(0), price(0.0), quantity(0) {}

product::product(int id, string name, double price, int quantity)
    : id(id), name(name), price(price), quantity(quantity) {}

int product::getID() const {return id; }
string product::getName() const {return name; }
double product::getPrice() const {return price;}
int product::getQuantity() const {return quantity; }

void product::setName(const string& name) {this->name = name;}
void product::setPrice(double price) {this->price = price;}
void product::setQuantity(int quantity) {this->quantity = quantity;}

string product::toFileString() const {
    return to_string(id) + "," + name + ","+ to_string(price)+ "," + to_string(quantity);
}

product product::fromFileString(const string& line) {
    stringstream ss(line);
    string item;

    int id, quantity;
    double price;
    string name;

    getline(ss, item, ',');
    id = stoi(item);

    getline(ss, name, ',');

    getline(ss, item, ',');
    price = stod(item);

    getline(ss, item, ',');
    quantity = stoi(item);

    return product(id, name, price, quantity);
}