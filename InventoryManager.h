#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H
#include "Product.h"
#include <vector>
#include <string>
using namespace std;
class InventoryManager {
private:
    vector<Product> products;
public:
    void addProduct(Product p);
    Product* searchByName(string name);
    Product* searchById(int id);
    bool updateProduct(int id, int newQuantity);
    bool updatePrice(int id ,double newPrice);
    bool updateDiscount(int id , double newDiscount);
    const vector<Product>& getProducts() const;
    Product* getProductById(int id);
    void displayAllProducts();
    bool deleteProduct(int id);
    bool updateName(int id, const string& newName);
	double calculateTotalInventoryValue() const;
    void clearInventory() { products.clear(); }
};
#endif
