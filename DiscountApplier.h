#pragma once
#ifndef DISCOUNT_APPLIER_H
#define DISCOUNT_APPLIER_H
#include <string>

using namespace std;

class DiscountApplier {
public:
    // بتاخد كود الخصم وإجمالي السعر وترجع السعر بعد الخصم
    static double applyPromoCode(string promoCode, double totalAmount);
};

#endif