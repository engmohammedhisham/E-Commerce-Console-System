#include "FileManager.h"
#include "product.h" 
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
void FileManager::loadFromFile(InventoryManager& inventory, const string& filename) {
    inventory.clearInventory();
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not find or open file: " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue; 
        stringstream ss(line);
        string idStr, name, priceStr;
        if (getline(ss, idStr, ',') &&
            getline(ss, name, ',') &&
            getline(ss, priceStr, ',')) {

            try {
                int id = stoi(idStr);
                double price = stod(priceStr);

   
                Product p(id, name, price);
                inventory.addProduct(p);
            }
            catch (...) {
                continue;
            }
        }
    }
    file.close();
}
void FileManager::saveToFile(const InventoryManager& inventory, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << " Error: Could not open file for writing: " << filename << endl;
        return;
    }
    const vector<Product>& products = inventory.getProducts();
    for (int i = 0; i < (int)products.size(); i++) {
        file << products[i].getId() << ","
            << products[i].getName() << ","
            << products[i].getPrice() << endl;
    }
    file.close();
}