/**
 * @file Database.cpp
 * @brief Implementation of the Database class for persistent product storage.
 *
 * Manages an in memory collection of product objects and provides
 * load/save functionality to a plain text CSV file, along with
 * CRUD operations for individual products.
 */

#include "Database.h"
#include <fstream>
#include <iostream>

/**
 * @brief Constructs a Database bound to the specified file.
 *
 * Does not read from or write to disk at construction time.
 * Call load() explicitly to populate the in memory product list.
 *
 * @param filename Path to the CSV file used for persistence.
 */
Database::Database(const string& filename) : filename(filename){}

/**
 * @brief Loads all products from the bound CSV file into memory.
 *
 * Opens the file at the path provided at construction, reads it line
 * by line, and deserialises each line into a product via
 * product::fromFileString(). Silently returns if the file cannot be
 * opened. Any products previously held in memory are preserved.
 */

void Database::load() {
    ifstream file(filename);
    if (!file) return;

    string line;
    while (getline(file, line)){
        products.push_back(product::fromFileString(line));
    }
    file.close();
}

/**
 * @brief Persists all in-memory products to the bound CSV file.
 *
 * Creates or overwrites the file at the path provided at construction,
 * writing one product per line in the format produced by
 * product::toFileString().
 */
void Database::save() {
    ofstream file(filename);
    for (const auto& p : products) {
        file << p.toFileString() << endl;
    }
    file.close();
}

/**
 * @brief Appends a product to the in memory product list.
 *
 * The change is not written to disk until save() is called.
 *
 * @param product The product object to add.
 */

void Database::addProduct(const product& product){
    products.push_back(product);
}

/**
 * @brief Removes the product with the given ID from the in-memory list.
 *
 * Performs a linear search and erases the first product whose ID matches
 * @p id. The change is not written to disk until save() is called.
 *
 * @param id The unique identifier of the product to remove.
 * @return @c true if a matching product was found and removed;
 *         @c false if no product with that ID exists.
 */
bool Database::deleteProduct(int id){
        for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getID() == id) {
            products.erase(it);
            return true;
        }
    }
    return false;

}

/**
 * @brief Finds a product by its unique ID.
 *
 * Performs a linear search over the in-memory product list.
 *
 * @param id The unique identifier of the product to locate.
 * @return Pointer to the matching product, or @c nullptr if not found.
 * @warning The returned pointer is invalidated if the products vector is
 *          subsequently modified.
 */
product* Database::findProduct(int id) {
     for (auto& p : products) {
        if (p.getID() == id)
            return &p;
    }
    return nullptr;
}

/**
 * @brief Prints all products in the database to standard output.
 *
 * Outputs a formatted list of every product's ID, name, price, and
 * quantity. Produces only the header line if the product list is empty.
 */
void Database:: displayAll() const {
    cout << "Product list:\n";
    for (const auto&p : products) {
        cout << "ID: " << p.getID();
        cout << " | Name: " << p.getName();
        cout << " | Price: " << p.getPrice();
        cout << " | Quantity: " << p.getQuantity() << endl;
    }
}