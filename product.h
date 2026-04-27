#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;
class Product {
private:
    int id;
    string name;
    double price;
    int quantity;
    double discount;
public:
    Product();
    void setData(int i, const string& n, double p, int q, double d);
    string getName() const;
    int getId() const;
    int getQuantity()const;
    double getPrice() const;
    double getDiscount()const;
    void setPrice(double p);
    void setQuantity(int q);
    void setDiscount(double d);
    Product(int i, const string& n, double p, int q, double d);
    Product(int i, const string& n, double p);
    void setId(int i);
    void setName(const string& n);
    double getTotalPrice() const;
};
#endif