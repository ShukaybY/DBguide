/**
 * @file product.h
 * @brief Declaration of the product class representing a single inventory item.
 *
 * Encapsulates the data and behaviour of a product record, including
 * accessors, mutators, and CSV serialisation for file persistence.
 */
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class product {
    private:
        int id;
        string name;
        double price;
        int quantity;
    
    public:
        product();
        product(int id, string name, double price, int quantity);

        int getID() const;
        string getName() const;
        double getPrice() const;
        int getQuantity() const;

        void setName(const string& name);
        void setPrice(double price);
        void setQuantity(int quantity);

        string toFileString() const;
        static product fromFileString(const string &line);
};

#endif