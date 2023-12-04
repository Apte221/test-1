#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "product.h"
#include <iostream>

struct Warehouse {
    Product products[100];
    int productCount;

    // Додавання товару на склад
    void addProduct(const Product& product) {
        if (productCount < 100) {
            products[productCount++] = product;
        }
        else {
            std::cout << "Warehouse is full. Cannot add more products." << std::endl;
        }
    }

    // Видалення товару зі складу
    void removeProduct(const char* name) {
        for (int i = 0; i < productCount; ++i) {
            if (strcmp(products[i].name, name) == 0) {
                for (int j = i; j < productCount - 1; ++j) {
                    products[j] = products[j + 1];
                }
                productCount--;
                return;
            }
        }
    }

    // Заміна інформації про товар
    void replaceProduct(const char* name, const Product& newProduct) {
        for (int i = 0; i < productCount; ++i) {
            if (strcmp(products[i].name, name) == 0) {
                products[i] = newProduct;
                return;
            }
        }
    }

    // Виведення інформації про товари
    void printProducts(const Product* productList, int count) const {
        for (int i = 0; i < count; ++i) {
            std::cout << "Name: " << productList[i].name << std::endl;
            std::cout << "Manufacturer: " << productList[i].manufacturer << std::endl;
            std::cout << "Price: " << productList[i].price << std::endl;
            std::cout << "Category: " << productList[i].category << std::endl;
            std::cout << "Arrival Date: " << productList[i].arrivalDate << std::endl;
            std::cout << "Expiration Date: " << productList[i].expirationDate << std::endl;
            std::cout << "--------------------------\n";
        }
    }

    // Пошук товарів за ключовим словом
    Product* searchProducts(const char* keyword, bool sortByPrice, int& resultCount) const {
        Product result[100];
        resultCount = 0;

        for (int i = 0; i < productCount; ++i) {
            if (strstr(products[i].name, keyword) != nullptr ||
                strstr(products[i].manufacturer, keyword) != nullptr ||
                strstr(products[i].category, keyword) != nullptr) {
                result[resultCount++] = products[i];
            }
        }

        // Сортування за ціною, якщо вказано
        if (sortByPrice) {
            // Замінено на швидке сортування (QuickSort)
            // Швидке сортування по ціні
            int low = 0;
            int high = resultCount - 1;
            quickSort(result, low, high);
        }

        return result;
    }

    // Сортування товарів за категорією
    Product* sortProductsByCategory(const char* category, int& resultCount) const {
        Product result[100];
        resultCount = 0;

        for (int i = 0; i < productCount; ++i) {
            if (strcmp(products[i].category, category) == 0) {
                result[resultCount++] = products[i];
            }
        }

        // Замінено на сортування вставками
        // Сортування за категорією
        insertionSort(result, resultCount);

        return result;
    }

private:
    // Швидке сортування (QuickSort) для сортування за ціною
    void quickSort(Product arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    // Допоміжна функція для швидкого сортування (QuickSort)
    int partition(Product arr[], int low, int high) {
        double pivot = arr[high].price;
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j].price <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    // Сортування вставками для сортування за категорією
    void insertionSort(Product arr[], int n) {
        int i, j;
        Product key;

        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && strcmp(arr[j].name, key.name) > 0) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
};

#endif // WAREHOUSE_H
