#include "DiscountApplier.h"
#include <algorithm>

double DiscountApplier::applyPromoCode(const std::string& promoCode, double totalAmount) {
    string code = promoCode;

    code.erase(0, code.find_first_not_of(" \t\n\r"));
    code.erase(code.find_last_not_of(" \t\n\r") + 1);

    for (auto& c : code) c = toupper(c);

    if (code == "DIS10") {
        return totalAmount * 0.9;
    }

    if (code == "DIS20") {
        return totalAmount * 0.8;
    }

    return totalAmount;
}
