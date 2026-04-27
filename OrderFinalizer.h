#ifndef ORDER_FINALIZER_H
#define ORDER_FINALIZER_H
#include "Cart.h"
#include "Customer.h"

class OrderFinalizer {
public:
    //  بتستلم السلة وتحسب النهائي وتطبع الفاتورة
    void processCheckout(Cart& currentCart, Customer& currentCustomer);
    void printReceipt(const Cart& currentCart, double finalTotal);
};

#endif