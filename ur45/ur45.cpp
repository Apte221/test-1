
#include <iostream>
#include "storage.h"
using namespace std;

int main() {
    Storage storage;
    storage.itemCount = 0;
    int choice = 0;
    while (choice != 13)
    {


        cout << "\nMenu:\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Replace Item\n";
        cout << "4. Search By Name\n";
        cout << "5. Search By Manufacturer\n";
        cout << "6. Search By Price\n";
        cout << "7. Search By Group\n";
        cout << "8. Search By Arrival Date\n";
        cout << "9. Search By Expiry Date\n";
        cout << "10. Sort By Price\n";
        cout << "11. Sort By Group\n";
        cout << "12. Display Storage\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";



        cin >> choice;
        switch (choice) {
        case 1: {
            storage.addItem();
            break;
        }
        case 2: {
            int itemNamer;
            cout << "Enter the name of the item to remove: ";
            cin >> itemNamer;
            storage.removeItem(itemNamer);
            break;
        }
        case 3: {
            char itemName[50];
            cout << "Enter the name of the item to replace: ";
            cin.getline(itemName, sizeof(itemName));
            Item newItem;
            cout << "Enter the new details for the item:\n";
            cout << "New Name: ";
            cin.getline(newItem.name, sizeof(newItem.name));
            storage.replaceItem(itemName, newItem);
            break;
        }
        case 4: {
            char itemName[50];
            cout << "Enter the name of the item to search: ";
            cin.getline(itemName, sizeof(itemName));
            storage.searchByName(itemName);
            break;
        }
        case 5: {
            char manufacturerName[50];
            cout << "Enter the manufacturer to search: ";
            cin.getline(manufacturerName, sizeof(manufacturerName));
            storage.searchByManufacturer(manufacturerName);
            break;
        }
        case 6: {
            float maxPrice;
            cout << "Enter the maximum price to search: ";
            cin >> maxPrice;
            storage.searchByPrice(maxPrice);
            break;
        }
        case 7: {
            char group[20];
            cout << "Enter the group to search: ";
            cin.getline(group, sizeof(group));
            storage.searchByGroup(group);
            break;
        }
        case 8: {
            char date[11];
            cout << "Enter the arrival date to search (yyyy-mm-dd): ";
            cin.getline(date, sizeof(date));
            storage.searchByArrivalDate(date);
            break;
        }
        case 9: {
            char date[11];
            cout << "Enter the expiry date to search (yyyy-mm-dd): ";
            cin.getline(date, sizeof(date));
            storage.searchByExpiryDate(date);
            break;
        }
        case 10: {
            storage.sortByPrice();
            break;
        }
        case 11: {
            storage.sortByGroup();
            break;
        }
        case 12: {
            storage.displayStorage();
            break;
        }
        case 13: {
            cout << "Exit";
        }
        default: {
            cout << "Invalid choice. Please enter a valid option.\n";
        }
        }

    }
    delete[] storage.items;
}