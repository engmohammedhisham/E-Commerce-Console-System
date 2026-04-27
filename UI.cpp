#include<iostream>
#include <string>
#include<vector>
#include<limits>
#include "UI.h"
#include "Product.h"
using namespace std;
void UI::displayProduct(const Product& p){
    cout<<"=============================================="<<endl;
    cout <<       "     Product Details     " << endl;
    cout<<"=============================================="<<endl;
    cout<<"Name:"<<p.getName()<<endl;
    cout<<"Id:"<<p.getId()<<endl;
    cout<<"price:"<<p.getPrice()<<endl;
    cout<<"quantity:"<<p.getQuantity()<<endl;
    cout<<"discount:"<<p.getDiscount()<<endl;
    cout<<"=============================================="<<endl;
}
void UI::printMessage( string& message){
    cout<<message<<endl;
}
int UI::showMenu(){
    int choice;
	cout << "==============================================" << endl;
	cout << "     Product Management System     " << endl;
	cout << "==============================================" << endl;
    cout<<"1. add product"<<endl;
    cout<<"2. display product details"<<endl;
    cout << "3. update existing product" << endl;
    cout << "4. delete a product" << endl;
    cout << "5. search for a product" << endl;
    cout << "6. display all product" << endl;
    cout << "7. veiw shopping cart" << endl; 
    cout<<"8.Exit"<<endl;
    cout<<"Enter your choice: ";
    while (!(cin >> choice)) {
        cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please enter a number: ";
    }
    return choice;
}
void UI::printError(const string& errorMessage){
    cout << "Error:" << errorMessage << endl;
}
void UI::printSuccess(const string& successMessage){
    cout << "success:" << successMessage << endl;
}
void UI::displayHeader(const string& title) {
    cout << "===============================================" << endl;
    cout << "=====" << title << "======" << endl;
}
void UI::displayCart(const vector<Product>& cart){
    cout << "===============================================" << endl;
    cout <<"            shopping cart         "<< endl;
    cout << "=================================================" << endl;
    if (cart.empty()){
		cout << "Your shopping cart is empty." << endl;
        return;
    }
    double totalPrice = 0.0;
    for (size_t i = 0;i < cart.size();++i){
		cout << i + 1 << ". " << cart[i].getName() << "| price: " << cart[i].getPrice() << "| quantity: " << cart[i].getQuantity() << "| discount:" << cart[i].getDiscount() << endl;
		totalPrice += (cart[i].getPrice() * cart[i].getQuantity() - cart[i].getDiscount());
		cout << "   Total price: " << totalPrice << endl;
    }

}