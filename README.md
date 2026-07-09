# Console E-Commerce & Store Management System

A fully functional, terminal-based e-commerce and store management system built entirely in C++. This project focuses on applying advanced software engineering practices, clean code architecture, and delivering a highly interactive and engaging user experience right inside the console.

## 🚀 Tech Stack

* **Programming Language:** C++ (Requires C++17 or higher).
* **UI Library:** **FTXUI Library** to build interactive, animated graphical user interfaces (GUI), menus, and pop-ups directly within the terminal.
* **Data Management:** **File Handling (CSV)** for persistent and reliable storage of products, user accounts, and purchase histories.
* **Architecture:** **Object-Oriented Programming (OOP)** to ensure a modular codebase, clear separation of concerns, and easy future scalability.

## ✨ Key Features

### 1. Customer Portal
* **Browse Products:** Users can navigate through various categorized products (e.g., PCs, Clothes, Shoes, Books, etc.).
* **Cart System:** Add items to the shopping cart, specify quantities, and automatically calculate total prices.
* **Checkout Process:** Finalize orders, print detailed purchase receipts, and log the transaction into the customer's history.

### 2. Admin Panel
* **Inventory Viewing:** Admins have full access to view all available products across different categories.
* **Product Management:** Add new products with unique IDs and prices, or delete existing products from the inventory.
* **Auto-Save:** Any modifications made by the admin are instantly synced and saved to the respective CSV database files.

## 📁 Project Structure

* `main.cpp`: The entry point of the application, handling the main flow and FTXUI menu rendering.
* `InventoryManager`: Manages the store's products (adding, deleting, and displaying).
* `Cart`: Represents the user's shopping cart, handling item tracking and price calculations.
* `FileManager`: Handles reading from and writing to CSV files to ensure data persistence.
* `OrderFinalizer`: Processes the final checkout, applies logic, and generates receipts.
* `HistoryLogger`: Records and archives user transactions and purchase history.
* 'to watch video':https://www.linkedin.com/posts/mohammed-hisham-09b85637a_cpp-programming-data-ugcPost-7461428564106784768-4lN0/?utm_source=share&utm_medium=member_desktop&rcm=ACoAAF29_fcB97-p5jOvuqn8WqcPDaVNHQLtL_k

## ⚙️ How to Run

1. Ensure the `FTXUI` library is installed and properly linked in your development environment (e.g., Visual Studio).
2. Clone this repository to your local machine.
3. Open `main.cpp` and update the `base` path variable to match the absolute path of your project's data folder:
   ```cpp
   string base = "D:\\path_to_your_project\\data\\";
