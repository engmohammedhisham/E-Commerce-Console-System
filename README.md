#  E-Commerce Console System (C++)

A comprehensive Command Line Interface (CLI) application built with **C++** using **Object-Oriented Programming (OOP)**. This system simulates a real-world store environment with two main roles: **Admin** and **Customer**, each with a dedicated set of functionalities.

##  Key Modules & File Structure

The project is structured into modular components to ensure scalability and clean code:

###  Authentication & User Roles
* **`AccountCreator` (.h/.cpp):** Handles the logic for registering new customer accounts.
* **`Admin` (.h/.cpp):** Inherits from the `User` class; allows administrative actions like adding products to the inventory.
* **`Customer` (.h/.cpp):** Inherits from the `User` class; manages customer-specific data and purchase history.
* **`User.h`**: The base class for both Admins and Customers, demonstrating **Inheritance**.

###  Shopping Experience
* **`Cart` (.h/.cpp):** Manages the user's shopping session, including adding items, calculating totals, and generating a formatted receipt.
* **`DiscountApplier` (.h/.cpp):** A utility class that processes promo codes (e.g., `DIS10`, `DIS20`) to apply discounts on the total price.
* **`main.cpp`**: The central controller that manages the application flow, including the login system and the search tool.

###  Inventory & Logic
* **`InventoryManager`**: Orchestrates product data across various categories (Computers, Clothes, etc.).
* **`SearchTool`**: Provides a global search functionality to find products by name across the entire store.
* **`Product.h`**: Defines the properties and attributes of items available in the store.

##  OOP Concepts Applied
* **Inheritance:** Derived `Admin` and `Customer` from a common `User` base class.
* **Encapsulation:** Protecting internal data and providing access through public methods.
* **Static Methods:** Used in `AccountCreator` and `DiscountApplier` for utility functions that don't require object instantiation.
* **Data Persistence:** Uses File I/O to save/load products and customer accounts to `.csv` and `.txt` files.

##  How to Run
1. Clone the repository.
2. Open the project in **Visual Studio**.
3. **Critical:** Update the `base` string in `main.cpp` to your local project directory path where the data files are located.
4. Build and Run (`Ctrl + F5`).

## 🛠️ Requirements
* C++11 or higher.
* Windows OS (for `system("cls")` support).
* 
