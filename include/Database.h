/**
 * @file Database.h
 * @brief Declaration of the Database class for persistent product storage.
 *
 * Manages an in memory collection of product objects backed by a plain text
 * CSV file. Provides load/save functionality and CRUD operations.
 */
#ifndef DATABASE_H
#define DATABASE_H


#include <vector>
#include <string>
#include "product.h"


class Database{
    private:
        vector<product> products;
        string filename;

    public:
        Database(const string& filename);

        void load();
        void save();

        void addProduct(const product& product);
        bool deleteProduct(int id);
        product* findProduct(int id);
        void displayAll() const;
};
#endif