#ifndef UI_H
#define UI_H
#include "Product.h"
#include <string>
#include<vector>
using namespace std;
class UI {
    public:
    static void displayProduct(  const Product& p) ;
    static void printMessage(string& message) ;
    static int showMenu() ;
    static void printError(const string& errorMessage);
	static void printSuccess(const string& successMessage);
	static void displayHeader(const string& title);
	static void displayCart(const vector<Product>& cart);
};
#endif
