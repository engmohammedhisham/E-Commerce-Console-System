#ifndef LOGIN_VALIDATOR_H
#define LOGIN_VALIDATOR_H
#include <string>
using namespace std;
class LoginValidator {
public:
    static bool validateCustomerLogin(string username, string password);
    static bool validateAdminLogin(string username, string password);
};

#endif
