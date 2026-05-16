#include <iostream>
#include "OrderFinalizer.h"
using namespace std;

void OrderFinalizer::processCheckout(Cart& currentCart, Customer& currentCustomer) {

    cout << "\nProcessing order for: "
        << currentCustomer.getUsername() << endl;

    double total = 0;

    currentCart.viewCart();    

    cout << "\nCheckout completed successfully!\n";
}

void OrderFinalizer::printReceipt(const Cart& currentCart, double finalTotal) {
    cout << "\n===== FINAL RECEIPT =====\n";
    cout << "Total Paid: $" << finalTotal << endl;
    cout << "=========================\n";
}
