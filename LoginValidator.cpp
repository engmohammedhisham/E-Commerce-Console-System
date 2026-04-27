#include "LoginValidator.h"
#include <iostream>
using namespace std;
bool LoginValidator::validateCustomerLogin(string username, string password) {
    cout << "Validating Customer Login for: " << username << endl;
    return true; 
}
bool LoginValidator::validateAdminLogin(string username, string password) {
    cout << "Validating Admin Login for: " << username << endl;
    return true;
}