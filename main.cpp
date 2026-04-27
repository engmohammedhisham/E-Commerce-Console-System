#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "InventoryManager.h"
#include "FileManager.h"
#include "Cart.h"
#include "UI.h"
#include "Product.h"
#include "Customer.h"
#include "Admin.h"
#include "AccountCreator.h"
#include "LoginValidator.h"
#include "SearchTool.h"
#include "DiscountApplier.h"
#include "OrderFinalizer.h"
#include "HistoryLogger.h"
using namespace std;
string base = "";#حط الملفات جوا فولدر واعملهم copy path  وضيف الباث بتاعك هنا
int getInt(string prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return val;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[!] Invalid input. Please enter a number." << endl;
    }
}
void displayMainMenu() {
    cout << "\n==============================================" << endl;
    cout << "                 MAIN MENU                    " << endl;
    cout << "==============================================" << endl;
    cout << "1. Browse Categories & Products" << endl;
    cout << "2. Search for a Product" << endl;
    cout << "3. View Cart" << endl;
    cout << "4. Checkout & Print Receipt" << endl;
    cout << "0. Logout / Exit" << endl;
    cout << "==============================================" << endl;
}
void displayCategoriesOnly() {
    cout << "\n==============================================" << endl;
    cout << "                 CATEGORIES                   " << endl;
    cout << "==============================================" << endl;
    cout << "1. Computers & PCs     7. Toys & Games" << endl;
    cout << "2. Clothes             8. Books" << endl;
    cout << "3. Shoes               9. Home Appliances" << endl;
    cout << "4. Sports & Fitness    10. Accessories" << endl;
    cout << "5. Beauty & Health     11. iPhones" << endl;
    cout << "6. PlayStations        12. Laptops" << endl;
    cout << "0. Back" << endl;
    cout << "==============================================" << endl;
}
void handleAdminMenu(InventoryManager& inv, string path) {
    while (true) {
        system("cls");
        cout << "\n==============================================" << endl;
        cout << "                 ADMIN PANEL                  " << endl;
        cout << "==============================================" << endl;
        cout << "1. Display All Products" << endl;
        cout << "2. Add Product" << endl;
        cout << "3. Delete Product" << endl;
        cout << "4. Save & Back to Categories" << endl;
        cout << "==============================================" << endl;
        int choice = getInt("Choice: ");
        if (choice == 4) {
            FileManager::saveToFile(inv, path);
            break;
        }
        if (choice == 1) {
            system("cls");
            inv.displayAllProducts();
            system("pause");
        }
        if (choice == 2) {
            int id = getInt("ID: ");
            string name; cout << "Name: "; cin >> name;
            double price; cout << "Price: "; cin >> price;
            inv.addProduct(Product(id, name, price));
            cout << "Product Added!\n";
            system("pause");
        }
        if (choice == 3) {
            int id = getInt("ID to delete: ");
            if (inv.deleteProduct(id)) cout << "Deleted." << endl;
            else cout << "Not found." << endl;
            system("pause");
        }
    }
}
int main() {
    while (true) { 
        InventoryManager myInventory;
        Cart myCart;
        OrderFinalizer finalizer;
        string activeUser = "Guest";
        Customer* loggedInCustomer = nullptr;
        system("cls");
        cout << "==============================================" << endl;
        cout << "          WELCOME TO OUR STORE                " << endl;
        cout << "==============================================" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register New Account" << endl;
        cout << "0. Shutdown System" << endl;
        int startChoice = getInt("Choose: ");
        if (startChoice == 0) return 0;
        if (startChoice == 2) {
            string uname, pass, email;
            cout << "Enter Username: "; cin >> uname;
            cout << "Enter Password: "; cin >> pass;
            cout << "Enter Email: "; cin >> email;
            AccountCreator::registerNewCustomer(uname, pass, email);
            cout << "\nAccount created successfully! Please login.\n";
            system("pause");
            continue;
        }
        if (startChoice == 1) {
            system("cls");
            string uname, pass;
            cout << "==============================================" << endl;
            cout << "                 LOGIN SYSTEM                 " << endl;
            cout << "==============================================" << endl;
            cout << "Username: "; cin >> uname;
            cout << "Password: "; cin >> pass;  
            if ((uname == "mohammed" || uname == "Mohammed") && pass == "2512007") {
                while (true) {
                    system("cls");
                    cout << "\n[ ADMIN MODE ] - Select Category to Manage:\n";
                    displayCategoriesOnly();
                    int catChoice = getInt("Choose Category: ");
                    if (catChoice == 0) { 
                        break; 
                    }
                    string fileName = "";
                    switch (catChoice) {
                    case 1: fileName = "pcs_data.csv"; break;
                    case 2: fileName = "clothes_data.csv"; break;
                    case 3: fileName = "shoes_data.csv"; break;
                    case 4: fileName = "sports&fitness_data.csv"; break;
                    case 5: fileName = "beauty&health_data.csv"; break;
                    case 6: fileName = "playstations_data.csv"; break;
                    case 7: fileName = "toys&games_data.csv"; break;
                    case 8: fileName = "books_data.csv"; break;
                    case 9: fileName = "appliances_data.csv"; break;
                    case 10: fileName = "accessories_data.csv"; break;
                    case 11: fileName = "iphones_data.csv"; break;
                    case 12: fileName = "laptops_data.csv"; break;
                    default: continue;
                    }
                    string fullPath = base + fileName;
                    InventoryManager adminInv;
                    FileManager::loadFromFile(adminInv, fullPath);
                    handleAdminMenu(adminInv, fullPath);
                }
                continue; 
            }
            else {
                if (LoginValidator::validateCustomerLogin(uname, pass)) {
                    cout << "\n[+] Login Successful! Welcome, " << uname << "!\n";
                    system("pause");
                    activeUser = uname;
                    loggedInCustomer = new Customer(uname, pass, uname + "@store.com");
                }
                else {
                    cout << "\n[-] Invalid Login. Try again.\n";
                    system("pause");
                    continue;
                }
            }
        }
        bool userSession = true;
        while (userSession) {
            system("cls");
            displayMainMenu();
            int choice = getInt("Choose: ");
            if (choice == 0) {
                userSession = false;
                break;
            }
            if (choice == 1) {
                while (true) {
                    system("cls");
                    displayCategoriesOnly();
                    int catChoice = getInt("Choose Category: ");
                    if (catChoice == 0) { 
                        break; 
                    }
                    string fileName = "";
                    switch (catChoice) {
                    case 1: fileName = "pcs_data.csv"; break;
                    case 2: fileName = "clothes_data.csv"; break;
                    case 3: fileName = "shoes_data.csv"; break;
                    case 4: fileName = "sports_data.csv"; break;
                    case 5: fileName = "beauty&health_data.csv"; break;
                    case 6: fileName = "playstations_data.csv"; break;
                    case 7: fileName = "toys_data.csv"; break;
                    case 8: fileName = "books_data.csv"; break;
                    case 9: fileName = "appliances_data.csv"; break;
                    case 10: fileName = "accessories_data.csv"; break;
                    case 11: fileName = "iphones_data.csv"; break;
                    case 12: fileName = "laptops_data.csv"; break;
                    default: continue;
                    }
                    string fullPath = base + fileName;
                    myInventory = InventoryManager(); 
                    FileManager::loadFromFile(myInventory, fullPath);
                    system("cls");
                    cout << "\n--- Products in " << fileName << " ---\n";
                    myInventory.displayAllProducts();
                    cout << "\n1. Add to Cart | 0. Back: ";
                    if (getInt("") == 1) {
                        int id = getInt("Enter Product ID: ");
                        Product* p = SearchTool::findById(myInventory, id);
                        if (p != nullptr) {
                            int q = getInt("Qty: ");
                            myCart.addItem(p->getId(), p->getName(), p->getPrice(), q);
                            cout << "\n[+] Added to cart!\n";
                        }
                        else cout << "\n[-] ID not found!\n";
                        system("pause");
                    }
                }
            }
            else if (choice == 2) {
                system("cls");
                string sName;
                cout << "Search (Case-Sensitive): ";
                cin >> sName;
                vector<string> files = { "pcs_data.csv", "clothes_data.csv", "shoes_data.csv", "sports_data.csv", "beauty&health_data.csv", "playstations_data.csv", "toys_data.csv", "books_data.csv", "appliances_data.csv", "accessories_data.csv", "iphones_data.csv", "laptops_data.csv" };
                bool foundAny = false;
                for (const string& f : files) {
                    InventoryManager temp;
                    FileManager::loadFromFile(temp, base + f);
                    Product* p = SearchTool::findByName(temp, sName);
                    if (p) {
                        cout << "[+] Found: " << p->getName() << " ($" << p->getPrice() << ") in " << f << endl;
                        foundAny = true;
                    }
                }
                if (!foundAny) cout << "[-] Not found.\n";
                system("pause");
            }
            else if (choice == 3) {
                system("cls");
                myCart.viewCart();
                system("pause");
            }
            else if (choice == 4) {
                system("cls");
                myCart.viewCart();
                if (loggedInCustomer && myCart.getTotalPrice() > 0) {
                    cout << "\n1. Checkout | 0. Back: ";
                    if (getInt("") == 1) {
                        string promo; cout << "Promo Code (or 'none'): "; cin >> promo;
                        double finalPrice = DiscountApplier::applyPromoCode(promo, myCart.getTotalPrice());
                        finalizer.processCheckout(myCart, *loggedInCustomer);
                        finalizer.printReceipt(myCart, finalPrice);
                        HistoryLogger::saveOrderToHistory(*loggedInCustomer, myCart, finalPrice);
                        myCart = Cart();
                    }
                }
                else cout << "\nCart is empty!\n";
                system("pause");
            }
        }
        if (loggedInCustomer) {
            delete loggedInCustomer; loggedInCustomer = nullptr;
        }
    }
    return 0;
}
