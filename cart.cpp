#include "cart.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Cart::addItem(int id, string name, double price, int qty) {
    CartItem newItem = { id, name, price, qty };
    items.push_back(newItem);
    cout << "\n[OK] " << qty << "x (" << name << ") added to your cart." << endl;
}

void Cart::viewCart() {
    if (items.empty()) {
        cout << "\n[!] Your cart is empty. Go shopping first!" << endl;
        return;
    }

    double grandTotal = 0;
    cout << "\n==============================================" << endl;
    cout << "              SHOPPING CART RECEIPT           " << endl;
    cout << "==============================================" << endl;
    cout << left << setw(10) << "ID"
        << setw(20) << "Product Name"
        << setw(10) << "Price"
        << "Qty" << endl;
    cout << "----------------------------------------------" << endl;

    for (int i = 0; i < items.size(); i++) {
        double subTotal = items[i].price * items[i].quantity;
        cout << left << setw(10) << items[i].id
            << setw(20) << items[i].name.substr(0, 18)
            << "$" << setw(9) << items[i].price
            << "x" << items[i].quantity << endl;

        grandTotal += subTotal;
    }

    cout << "----------------------------------------------" << endl;
    cout << " TOTAL AMOUNT TO PAY: $" << fixed << setprecision(2) << grandTotal << endl;
    cout << "==============================================" << endl;
}

void Cart::clearCart() {
    items.clear();
    cout << "\n[!] Cart has been cleared." << endl;
}

// الكود الجديد اللي بيحسب التوتال ويرجعه لملف الـ main
double Cart::getTotalPrice() {
    double total = 0;
    for (int i = 0; i < items.size(); i++) {
        total += items[i].price * items[i].quantity;
    }
    return total;
}