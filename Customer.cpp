#include "Customer.h"

Customer::Customer(string u, string p, string e) : User(u, p) {
    email = e;
}

void Customer::viewHistory() const {
    cout << "Displaying history for customer: " << username << " (Email: " << email << ")" << endl;
}