#pragma once

#include "item.h"
#include <cstring> 
#include <iostream>

struct Storage {
    Item items[100];  
    int itemCount;

    void addItem() {
        if (itemCount < 100) {
            Item newItem;
            std::cout << "Enter item details:\n";
            std::cout << "Name: ";
            std::cin >>newItem.name;

            std::cout << "Manufacturer: ";
            std::cin >> newItem.manufacturer;

            std::cout << "Price: ";
            std::cin >> newItem.price;
            

            std::cout << "Group: ";
            std::cin >> newItem.group;

            std::cout << "Arrival Date (yyyy-mm-dd): ";
            std::cin >> newItem.arrivalDate;

            std::cout << "Expiry Date (yyyy-mm-dd): ";
            std::cin >> newItem.expiryDate;

            items[itemCount++] = newItem;
            std::cout << "Item added to the storage.\n";
        }
        else {
            std::cout << "Storage is full. Cannot add more items.\n";
        }
    }

     void removeItem(int itemNumber) {
        if (itemNumber >= 1 && itemNumber <= itemCount) {
            for (int i = itemNumber - 1; i < itemCount - 1; ++i) {
                items[i] = items[i + 1];
            }
            --itemCount;
            std::cout << "Item removed from the storage.\n";
        } else {
            std::cout << "Invalid item number. No item removed.\n";
        }
    }

    void replaceItem(const char* itemName, const Item& newItem) {
        for (int i = 0; i < itemCount; ++i) {
            if (std::strcmp(items[i].name, itemName) == 0) {
                items[i] = newItem;
                std::cout << "Item replaced in the storage.\n";
                return;
            }
        }
        std::cout << "Item not found in the storage. Cannot replace.\n";
    }

    void searchByName(const char* itemName) const {
        bool found = false;
        for (int i = 0; i < itemCount; ++i) {
            if (std::strcmp(items[i].name, itemName) == 0) {
                std::cout << "Item found: " << items[i].name << ", " << items[i].manufacturer << ", " << items[i].price << ", " << items[i].group << ", " << items[i].arrivalDate << ", " << items[i].expiryDate << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Item with name \"" << itemName << "\" not found.\n";
        }
    }


    void searchByManufacturer(const char* manufacturerName) const {
        bool found = false;
        for (int i = 0; i < itemCount; ++i) {
            if (std::strcmp(items[i].manufacturer, manufacturerName) == 0) {
                std::cout << "Item found: " << items[i].name << ", " << items[i].manufacturer << ", " << items[i].price << ", " << items[i].group << ", " << items[i].arrivalDate << ", " << items[i].expiryDate << "\n";
                found = true;
            }
        }
        if (!found) {
            std::cout << "No items found from manufacturer \"" << manufacturerName << "\".\n";
        }
    }


    void searchByPrice(float maxPrice) const {
        bool found = false;
        for (int i = 0; i < itemCount; ++i) {
            if (items[i].price <= maxPrice) {
                std::cout << "Item found: " << items[i].name << ", " << items[i].manufacturer
 << ", " << items[i].price << ", " << items[i].group << ", " << items[i].arrivalDate << ", " << items[i].expiryDate << "\n";
                found = true;
            }
        }
        if (!found) {
            std::cout << "No items found within the specified price range.\n";
        }
    }


    void searchByGroup(const char* group) const {
        bool found = false;
        for (int i = 0; i < itemCount; ++i) {
            if (std::strcmp(items[i].group, group) == 0) {
                std::cout << "Item found: " << items[i].name << ", " << items[i].manufacturer << ", " << items[i].price << ", " << items[i].group << ", "<< items[i].arrivalDate << ", " << items[i].expiryDate << "\n";
                found = true;
            }
        }
        if (!found) {
            std::cout << "No items found in the group \"" << group << "\".\n";
        }
    }


    void searchByArrivalDate(const char* date) const {
        bool found = false;
        for (int i = 0; i < itemCount; ++i) {
            if (std::strcmp(items[i].arrivalDate, date) == 0) {
                std::cout << "Item found: " << items[i].name << ", " << items[i].manufacturer<< ", " << items[i].price << ", " << items[i].group << ", "<< items[i].arrivalDate << ", " << items[i].expiryDate << "\n";
                found = true;
            }
        }
        if (!found) {
            std::cout << "No items found with the specified arrival date.\n";
        }
    }


    void searchByExpiryDate(const char* date) const {
        bool found = false;
        for (int i = 0; i < itemCount; ++i) {
            if (std::strcmp(items[i].expiryDate, date) == 0) {
                std::cout << "Item found: " << items[i].name << ", " << items[i].manufacturer<< ", " << items[i].price << ", " << items[i].group << ", " << items[i].arrivalDate << ", " << items[i].expiryDate << "\n";
                found = true;
            }
        }
        if (!found) {
            std::cout << "No items found with the specified expiry date.\n";
        }
    }


    void sortByPrice() {
        for (int i = 0; i < itemCount - 1; ++i) {
            for (int j = 0; j < itemCount - i - 1; ++j) {
                if (items[j].price > items[j + 1].price) {
                    Item temp = items[j];
                    items[j] = items[j + 1];
                    items[j + 1] = temp;
                }
            }
        }
        std::cout << "Items sorted by price.\n";
    }

    void sortByGroup() {
        for (int i = 0; i < itemCount - 1; ++i) {
            for (int j = 0; j < itemCount - i - 1; ++j) {
                if (std::strcmp(items[j].group, items[j + 1].group) > 0) {
                    Item temp = items[j];
                    items[j] = items[j + 1];
                    items[j + 1] = temp;
                }
            }
        }
        std::cout << "Items sorted by group.\n";
    }
    void displayStorage() const {
        if (itemCount == 0) {
            std::cout << "Storage is empty.\n";
        }
        else {
            std::cout << "Items in the storage:\n";
            for (int i = 0; i < itemCount; ++i) {
                std::cout<< i << "Item: " << items[i].name << ", " << items[i].manufacturer << ", " << items[i].price << ", " << items[i].group << ", " << items[i].arrivalDate << ", " << items[i].expiryDate << "\n";
            }
        }
    }

};

