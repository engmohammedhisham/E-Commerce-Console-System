#include<iostream>
#include "InventoryManager.h"
#include "UI.h"
using namespace std;
void InventoryManager::addProduct(Product p) {
    for (int i = 0;i < products.size();i++) {
        if (products[i].getId() == p.getId()) {
            cout << "Product with the same ID already exists." << endl;
            return;
        }
    }
    products.push_back(p);
}
Product* InventoryManager::searchByName(string name) {
    for (int i = 0;i < products.size();i++) {
        if (products[i].getName() == name) {
            return &products[i];
        }
    }
    return nullptr;
}
Product* InventoryManager::searchById(int id) {
    for (int i = 0;i < products.size();i++) {
        if (products[i].getId() == id) {
            return &products[i];
        }
    }
    return nullptr;
}
bool InventoryManager::updateProduct(int id, int newQuantity) {
    Product* p = searchById(id);
    if (p != nullptr) {
        p->setQuantity(newQuantity);
        return true;
    }
    return false;
}
bool InventoryManager::updatePrice(int id, double newPrice) {
    Product* p = searchById(id);
    if (p != nullptr) {
        p->setPrice(newPrice);
        return true;
    }
    return false;
}
bool InventoryManager::updateDiscount(int id, double newDiscount) {
    Product* p = searchById(id);
    if (p != nullptr) {
        p->setDiscount(newDiscount);
        return true;
    }
    return false;
}
void InventoryManager::displayAllProducts() {
    if (products.empty()) {
        string message = "No products in inventory.";
        UI::printMessage(message);
        return;
    }
    for (int i = 0;i < products.size();i++) {
        UI::displayProduct(products[i]);
    }
}
const vector<Product>& InventoryManager::getProducts() const {
    return products;
}
bool InventoryManager::deleteProduct(int id) {
    for (auto it = products.begin();it != products.end();++it) {
        if (it->getId() == id) {
            products.erase(it);
            return true;
        }
    }
    return false;
}
bool InventoryManager::updateName(int id, const string& newName) {
    Product* p = searchById(id);
    if (p != nullptr) {
        p->setName(newName);
        return true;
    }
    return false;
}
double InventoryManager::calculateTotalInventoryValue() const {
    double totalValue = 0.0;
    for (int i = 0;i < products.size();i++) {
        totalValue += products[i].getPrice() * products[i].getQuantity();

    }
    return totalValue;
}
Product* InventoryManager::getProductById(int id) {
    for (int i = 0;i < products.size();i++) {
        if (products[i].getId() == id) {
            return &products[i];
        }
    }
    return nullptr;
}