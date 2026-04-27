#pragma once
// SearchTool.h
#ifndef SEARCH_TOOL_H
#define SEARCH_TOOL_H
#include "InventoryManager.h"
#include <string>

class SearchTool {
public:
    static Product* findByName(InventoryManager& inv, std::string name);
    static Product* findById(InventoryManager& inv, int id);
};
#endif

// StockUpdater.h
#ifndef STOCK_UPDATER_H
#define STOCK_UPDATER_H
#include "InventoryManager.h"

//class StockUpdater {
//public:
//    static bool updateQuantity(InventoryManager& inv, int id, int addedQuantity);
//};
#endif