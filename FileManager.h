#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include "InventoryManager.h"
#include <string>
class FileManager {
public:
    static void saveToFile(const InventoryManager& inventory, const std::string& filename);
    static void loadFromFile(InventoryManager& inventory, const std::string& filename);
};
#endif