#include "DiscountApplier.h"

//  كود الخصم
double DiscountApplier::applyPromoCode(string promoCode, double totalAmount) {

    double finalPrice = totalAmount;

    if (promoCode == "DIS10") {
        finalPrice = totalAmount * 0.9;   // خصم 10
    }
    else if (promoCode == "DIS20") {
        finalPrice = totalAmount * 0.8;   // خصم 20
    }
    else {
        finalPrice = totalAmount;         // مفيش خصم
    }

    return finalPrice;
}