#include <iostream>
#include "HistoryLogger.h"
using namespace std;

void HistoryLogger::saveOrderToHistory(const Customer& customer, Cart& finalizedCart, double totalPaid) {

    cout << "\n====================================\n";
    cout << "         ORDER HISTORY LOG          \n";
    cout << "====================================\n";

   
    cout << "Customer: " << customer.getUsername() << endl;

    cout << "\n--- CART DETAILS ---\n";
    finalizedCart.viewCart();

    cout << "\nTOTAL PAID: $" << totalPaid << endl;

    cout << "====================================\n";
    cout << "saved successfully\n";
}