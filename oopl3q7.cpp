#include <iostream>
#include <iomanip>
using namespace std;
class STATIONARY_SHOP {
private:
    string *allStock;
    float *allPrices;
    int itemCount;
    int capacity;

public:
    STATIONARY_SHOP(int cap) {
        capacity = cap;
        itemCount = 0;
        if (capacity > 0) {
            allStock = new string[capacity];
            allPrices = new float[capacity];
        } else {
            allStock = nullptr;
            allPrices = nullptr;
        }
    }

    void addItem(string item, float price) {
        if (capacity == 0) {
            cout << "Error: Shop has no capacity. Cannot add items.\n";
            return;
        }

        if (itemCount < capacity) {
            allStock[itemCount] = item;
            allPrices[itemCount] = price;
            itemCount++;
            cout << "Item added successfully!\n";
        } else {
            cout << "Error: Cannot add more items. Shop is full!\n";
        }
    }

    void fetchItems() {
        if (itemCount == 0) {
            cout << "Error: No items available in the shop.\n";
            return;
        }
        cout << "List of items:\n";
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << allStock[i] << "\n";
        }
    }

    void editPrice(string item, float newPrice) {
        if (capacity == 0) {
            cout << "Error: Shop has no capacity. Cannot edit prices.\n";
            return;
        }

        if (itemCount == 0) {
            cout << "Error: No items available to edit.\n";
            return;
        }

        for (int i = 0; i < itemCount; i++) {
            if (allStock[i] == item) {
                allPrices[i] = newPrice;
                cout << "Price updated successfully!\n";
                return;
            }
        }
        cout << "Error: Item not found!\n";
    }

    void viewAllItems() {
        if (itemCount == 0) {
            cout << "Error: No items available in the shop.\n";
            return;
        }
        cout << "Items and Prices:\n";
        cout << "-------------------------------\n";
        for (int i = 0; i < itemCount; i++) {
            cout << left << setw(15) << allStock[i] << " - Rs. " << fixed << setprecision(2) << allPrices[i] << "\n";
        }
        cout << "-------------------------------\n";
    }

    bool isStockEmpty() {
        return itemCount == 0;
    }

    ~STATIONARY_SHOP() {
        delete[] allStock;
        delete[] allPrices;
    }
};

int main() {
    int capacity;
    cout << "Enter the maximum number of items the shop can hold: ";
    cin >> capacity;

    STATIONARY_SHOP shop(capacity);
    int choice;

    do {
        cout << "\n---- Stationary Shop Menu ----\n";
        cout << "1. Add Item\n";
        cout << "2. Fetch Items\n";
        cout << "3. Edit Item Price\n";
        cout << "4. View All Items\n";
        cout << "5. Purchase Items (Generate Receipt)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (capacity == 0) {
                    cout << "Error: Cannot add items. Shop has no capacity.\n";
                    break;
                }
                string item;
                float price;
                cout << "Enter item name: ";
                cin >> item;
                cout << "Enter item price: ";
                cin >> price;
                shop.addItem(item, price);
                break;
            }
            case 2:
                shop.fetchItems();
                break;

            case 3: {
                if (capacity == 0) {
                    cout << "Error: Cannot edit prices. Shop has no capacity.\n";
                    break;
                }
                string item;
                float newPrice;
                cout << "Enter item name to edit: ";
                cin >> item;
                cout << "Enter new price: ";
                cin >> newPrice;
                shop.editPrice(item, newPrice);
                break;
            }
            case 4:
                shop.viewAllItems();
                break;
            case 5: {
                if (shop.isStockEmpty()) {
                    cout << "Error: No items in stock. Cannot generate a receipt.\n";
                    break;
                }
                int numItems;
                cout << "Enter number of items purchased: ";
                cin >> numItems;

                if (numItems <= 0) {
                    cout << "Error: Invalid number of items.\n";
                    break;
                }
                string *items = new string[numItems];
                int *quantities = new int[numItems];

                for (int i = 0; i < numItems; i++) {
                    cout << "Enter item " << i + 1 << " name: ";
                    cin >> items[i];
                    cout << "Enter quantity: ";
                    cin >> quantities[i];
                }
                delete[] items;
                delete[] quantities;
                break;
            }

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
