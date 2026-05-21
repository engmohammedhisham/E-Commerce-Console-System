#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
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
using namespace ftxui;

string base = #"put your base here";

int showMenu(string title, vector<string> entries) {
    auto screen = ScreenInteractive::TerminalOutput();
    int selected = 0;
    MenuOption option;
    option.on_enter = screen.ExitLoopClosure();
    auto menu = Menu(&entries, &selected, option);
    auto renderer = Renderer(menu, [&] {
        return window(text(title) | bold | center, menu->Render() | frame) | center;
        });
    screen.Loop(renderer);
    return selected;
}

string inputGUI(string prompt_text, string title) {
    auto screen = ScreenInteractive::FitComponent();
    string input_str;
    InputOption option;
    option.on_enter = screen.ExitLoopClosure();
    auto input_comp = Input(&input_str, "...", option);
    auto renderer = Renderer(input_comp, [&] {
        return window(text(title) | bold | color(Color::Green),
            vbox({ text(prompt_text), separator(), input_comp->Render() }));
        });
    screen.Loop(renderer);
    return input_str;
}

void msgGUI(string msg, string title) {
    auto screen = ScreenInteractive::FitComponent();
    auto btn = Button("OK", screen.ExitLoopClosure());
    auto renderer = Renderer(btn, [&] {
        return window(text(title) | bold | color(Color::Yellow),
            vbox({ text(msg), separator(), btn->Render() | center }));
        });
    screen.Loop(renderer);
}

int getIntGUI(string prompt, string title) {
    while (true) {
        string res = inputGUI(prompt, title);
        if (res.empty()) return 0;
        try { return stoi(res); }
        catch (...) { msgGUI("Invalid Number", "Error"); }
    }
}

double getDoubleGUI(string prompt, string title) {
    while (true) {
        string res = inputGUI(prompt, title);
        if (res.empty()) return 0.0;
        try { return stod(res); }
        catch (...) { msgGUI("Invalid Price", "Error"); }
    }
}

bool loginFormGUI(string& out_username, string& out_password) {
    auto screen = ScreenInteractive::TerminalOutput();
    string username = "";
    string password = "";
    bool submit = false;
    InputOption pass_option;
    pass_option.password = true;
    Component input_user = Input(&username, "Username");
    Component input_pass = Input(&password, "Password", pass_option);
    auto btn_submit = Button("Login", [&] { submit = true; screen.ExitLoopClosure()(); });
    auto btn_cancel = Button("Cancel", screen.ExitLoopClosure());
    auto container = Container::Vertical({ input_user, input_pass, Container::Horizontal({btn_submit, btn_cancel}) });
    auto renderer = Renderer(container, [&] {
        return window(text(" LOGIN ") | bold | color(Color::Cyan) | center,
            vbox({
                hbox({text(" Username : "), input_user->Render()}),
                separator(),
                hbox({text(" Password : "), input_pass->Render()}),
                separator(),
                hbox({btn_submit->Render(), text("  "), btn_cancel->Render()}) | center
                })
        ) | center;
        });
    screen.Loop(renderer);
    out_username = username;
    out_password = password;
    return submit;
}

bool registerFormGUI(string& out_username, string& out_password, string& out_email) {
    auto screen = ScreenInteractive::TerminalOutput();
    string username = "";
    string password = "";
    string email = "";
    bool submit = false;
    InputOption pass_option;
    pass_option.password = true;
    Component input_user = Input(&username, "Username");
    Component input_pass = Input(&password, "Password", pass_option);
    Component input_email = Input(&email, "Email");
    auto btn_submit = Button("Register", [&] { submit = true; screen.ExitLoopClosure()(); });
    auto btn_cancel = Button("Cancel", screen.ExitLoopClosure());
    auto container = Container::Vertical({ input_user, input_pass, input_email, Container::Horizontal({btn_submit, btn_cancel}) });
    auto renderer = Renderer(container, [&] {
        return window(text(" REGISTER ") | bold | color(Color::Magenta) | center,
            vbox({
                hbox({text(" Username : "), input_user->Render()}),
                separator(),
                hbox({text(" Password : "), input_pass->Render()}),
                separator(),
                hbox({text(" Email    : "), input_email->Render()}),
                separator(),
                hbox({btn_submit->Render(), text("  "), btn_cancel->Render()}) | center
                })
        ) | center;
        });
    screen.Loop(renderer);
    out_username = username;
    out_password = password;
    out_email = email;
    return submit;
}

vector<string> getCategoriesList() {
    return { "1. PCs", "2. Clothes", "3. Shoes", "4. Sports", "5. Beauty", "6. PS", "7. Toys", "8. Books", "9. Home", "10. Acc", "11. iPhone", "12. Laptops", "0. Back" };
}

void handleAdminMenu(InventoryManager& inv, string path) {
    vector<string> adminOptions = { "1. Display All", "2. Add", "3. Delete", "4. Save & Back" };
    while (true) {
        int choiceIdx = showMenu("ADMIN", adminOptions);
        if (choiceIdx == 3) { FileManager::saveToFile(inv, path); break; }
        if (choiceIdx == 0) { system("cls"); inv.displayAllProducts(); msgGUI("Done", "Info"); }
        if (choiceIdx == 1) {
            int id = getIntGUI("ID:", "Add");
            if (id == 0) continue;
            string name = inputGUI("Name:", "Add");
            double price = getDoubleGUI("Price:", "Add");
            inv.addProduct(Product(id, name, price));
        }
        if (choiceIdx == 2) {
            int id = getIntGUI("ID to Delete:", "Delete");
            if (id != 0) inv.deleteProduct(id);
        }
    }
}

int main() {
    vector<string> startOptions = { "1. Login", "2. Register", "0. Exit" };
    vector<string> mainOptions = { "1. Browse", "2. Cart", "3. Checkout", "0. Logout" };
    AccountCreator accountCreator;
    LoginValidator loginValidator;

    while (true) {
        InventoryManager myInventory;
        Cart myCart;
        OrderFinalizer finalizer;
        string activeUser = "";
        Customer* loggedInCustomer = nullptr;

        int sIdx = showMenu("STORE", startOptions);
        if (sIdx == 2) return 0;

        if (sIdx == 1) {
            string uname, pass, mail;
            if (registerFormGUI(uname, pass, mail)) {
                if (!uname.empty() && !pass.empty()) {
                    accountCreator.registerNewCustomer(uname, pass, mail);
                    msgGUI("Registered!", "Success");
                }
            }
            continue;
        }

        if (sIdx == 0) {
            string uname, pass;
            if (loginFormGUI(uname, pass)) {
                if ((uname == "mohammed" || uname == "Mohammed") && pass == "2512007") {
                    while (true) {
                        int cIdx = showMenu("ADMIN CATEGORIES", getCategoriesList());
                        if (cIdx == 12) break;
                        string files[] = { "pcs_data.csv","clothes_data.csv","shoes_data.csv","sports&fitness_data.csv","beauty&health_data.csv","playstations_data.csv","toys&games_data.csv","books_data.csv","appliances_data.csv","accessories_data.csv","iphones_data.csv","laptops_data.csv" };
                        string fullPath = base + files[cIdx];
                        InventoryManager adminInv;
                        FileManager::loadFromFile(adminInv, fullPath);
                        handleAdminMenu(adminInv, fullPath);
                    }
                    continue;
                }
                else {
                    if (loginValidator.validateCustomerLogin(uname, pass)) {
                        activeUser = uname;
                        loggedInCustomer = new Customer(uname, pass, uname + "@store.com");
                    }
                    else {
                        msgGUI("Login Failed!", "Error");
                        continue;
                    }
                }
            }
            else continue;
        }

        bool session = true;
        while (session && loggedInCustomer != nullptr) {
            int mIdx = showMenu("USER: " + activeUser, mainOptions);
            if (mIdx == 3) { session = false; break; }
            if (mIdx == 0) {
                while (true) {
                    int cIdx = showMenu("CATEGORIES", getCategoriesList());
                    if (cIdx == 12) break;
                    string files[] = { "pcs_data.csv","clothes_data.csv","shoes_data.csv","sports&fitness_data.csv","beauty&health_data.csv","playstations_data.csv","toys&games_data.csv","books_data.csv","appliances_data.csv","accessories_data.csv","iphones_data.csv","laptops_data.csv" };
                    FileManager::loadFromFile(myInventory, base + files[cIdx]);
                    system("cls");
                    myInventory.displayAllProducts();
                    int act = showMenu("ACTION", { "1. Add to Cart", "0. Back" });
                    if (act == 0) {
                        int id = getIntGUI("ID:", "Cart");
                        Product* p = SearchTool::findById(myInventory, id);
                        if (p) {
                            int q = getIntGUI("Qty:", "Cart");
                            myCart.addItem(p->getId(), p->getName(), p->getPrice(), q);
                        }
                    }
                }
            }
            if (mIdx == 1) { system("cls"); myCart.viewCart(); msgGUI("Back", "Cart"); }
            if (mIdx == 2) {
                if (myCart.getTotalPrice() > 0) {
                    string promo = inputGUI("Promo:", "Checkout");
                    double fPrice = DiscountApplier::applyPromoCode(promo, myCart.getTotalPrice());
                    finalizer.processCheckout(myCart, *loggedInCustomer);
                    system("cls");
                    finalizer.printReceipt(myCart, fPrice);
                    HistoryLogger::saveOrderToHistory(*loggedInCustomer, myCart, fPrice);
                    myCart = Cart();
                    msgGUI("Done", "Success");
                }
            }
        }
        if (loggedInCustomer) delete loggedInCustomer;
    }
    return 0;
}
