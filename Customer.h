#pragma once
#include "User.h"
#include <iostream>

class Customer : public User {
private:
    string email;

public:
    Customer(string u, string p, string e);
    void viewHistory() const;
};