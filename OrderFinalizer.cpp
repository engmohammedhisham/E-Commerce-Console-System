#include <iostream>
#include "OrderFinalizer.h"
using namespace std;

void OrderFinalizer::processCheckout(Cart& currentCart, Customer& currentCustomer) {

    cout << "\nProcessing order for: "
        << currentCustomer.getUsername() << endl;

    double total = 0;

    // حساب التوتال
    currentCart.viewCart();   // ده بيطبع الفاتورة 

    cout << "\nCheckout completed successfully!\n";
}

// ptin cart
void OrderFinalizer::printReceipt(const Cart& currentCart, double finalTotal) {
    cout << "\n===== FINAL RECEIPT =====\n";
    cout << "Total Paid: $" << finalTotal << endl;
    cout << "=========================\n";
}