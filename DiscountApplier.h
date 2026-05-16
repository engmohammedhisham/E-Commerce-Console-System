#pragma once
#pragma once
#ifndef DISCOUNT_APPLIER_H
#define DISCOUNT_APPLIER_H
#include <string>

using namespace std;

class DiscountApplier {
public:
    static double applyPromoCode(const string& promoCode, double totalAmount);
};
#endif
