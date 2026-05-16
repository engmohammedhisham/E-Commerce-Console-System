#include "LoginValidator.h"
#include "FileManager.h"
#include <iostream>
#include <fstream>  
#include <string>   

using namespace std;

bool LoginValidator::validateCustomerLogin(string uname, string pass) {
    ifstream file("D:\\my projects\\New folder\\final project\\x64\\users.txt");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {

            size_t firstComma = line.find(',');
            size_t lastComma = line.find_last_of(',');

            if (firstComma != string::npos && lastComma != string::npos) {
                string savedUname = line.substr(0, firstComma);
                string savedPass = line.substr(firstComma + 1, lastComma - firstComma - 1);


                if (uname == savedUname && pass == savedPass) {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
    }

    return false;
}
