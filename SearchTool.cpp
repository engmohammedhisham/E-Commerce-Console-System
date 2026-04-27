#include "SearchTool.h"
Product* SearchTool::findByName(InventoryManager& inv, string name) {
    for (int i = 0; i < inv.getProducts().size(); i++) {
        
        if (inv.getProducts()[i].getName().find(name) != string::npos) {
            return inv.getProductById(inv.getProducts()[i].getId());
        }
    }

    return nullptr;
}
Product* SearchTool::findById(InventoryManager& inv, int id) {
    return inv.getProductById(id);
}