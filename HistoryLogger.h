#pragma once
#ifndef HISTORY_LOGGER_H
#define HISTORY_LOGGER_H
#include "Cart.h"
#include "Customer.h"

class HistoryLogger {
public:
    static void saveOrderToHistory(const Customer& customer, Cart& finalizedCart, double totalPaid);
};

#endif
