#ifndef CART_H
#define CART_H
#include <vector>
#include <string>
using namespace std;

struct CartItem {
    int id;
    string name;
    double price;
    int quantity;
};

class Cart {
private:
    vector<CartItem> items;
public:
    void addItem(int id, string name, double price, int quantity);
    void viewCart();
    void clearCart();
    double getTotalPrice(); 
};
#endif