#include "Product.h"
#include <iostream>
#include <string>
using namespace std;
Product::Product() : id(0), name(""), price(0.0), quantity(0), discount(0.0) {}
Product::Product(int i, const string& n, double p, int q, double d) : id(i), name(n), price(p), quantity(q), discount(d) {}
Product::Product(int i, const string& n, double p) : id(i), name(n), price(p), quantity(0), discount(0.0) {}
void Product::setData(int i, const string& n, double p, int q, double d) {
    id = i;
    name = n;
    setPrice(p);
    setQuantity(q);
    setDiscount(d);;
}
string Product::getName()const {
    return name;
}
int Product::getId() const {
    return id;
}
int Product::getQuantity() const {
    return quantity;
}
double Product::getPrice() const {
    return price;
}
double Product::getDiscount() const {
    return discount;
}
void Product::setPrice(double p) {
    if (p >= 0) {
        price = p;
    }
}
void Product::setQuantity(int q) {
    if (q >= 0) {
        quantity = q;
    }
}
void Product::setDiscount(double d) {
    if (d >= 0) {
        discount = d;
    }
}
void Product::setId(int i) {
    id = i;
}
void Product::setName(const string& n) {
    name = n;
}
double Product::getTotalPrice() const {
    double total = price * quantity;
    if (discount > 0) {
        total -= total * (discount / 100);
    }
    if (total < 0) {
        return 0.0;
    }
    return total;
}