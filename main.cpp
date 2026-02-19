#include <iostream>
#include "Database.h"
using namespace std;

void showMenu() {
    cout << "\n1. Add Product";
    cout << "\n2. View Products";
    cout << "\n3. Update Product";
    cout << "\n4. Delete Product";
    cout << "\n5. Save & Exit\n";
    cout << "Choice: ";
}

int main() {
    Database db("products.txt");
    db.load();

    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {

        case 1: {
            int id,qty;
            string name;
            double price;

            cout << "ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Name: ";
            getline(cin, name);

            cout << "Price: ";
            cin >> price;

            cout << "Quantity: ";
            cin >> qty;

            db.addProduct(product(id, name, price, qty));
            break;
        }

        case 2: {
            db.displayAll();
            break;
        }

        case 3: {
            int id;
            cout << "Enter ID to update: ";
            cin >> id;

            product* p = db.findProduct(id);
            if (p) {
                double price;
                int qty;

                cout << "New price: ";
                cin >> price;

                cout << "New quantity: ";
                cin >> qty;

                p->setPrice(price);
                p->setQuantity(qty);
            } else {
                cout << "Product not found.\n";
            }
            break;
        }

        case 4: {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;

            if (!db.deleteProduct(id))
                cout << "Product not found.\n";

            break;
        }

        case 5:
            db.save();
            cout << "Database saved. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
