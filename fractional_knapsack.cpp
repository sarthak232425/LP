/*
Problem (Fractional Knapsack)
Write a program to implement Fractional knapsack using Greedy algorithm and also find the maximum profit.

This file: fractional_knapsack.cpp
- Simple console program that reads n, capacity, then n items (value weight), computes maximum profit
- Uses greedy approach by value/weight ratio
- Compile: g++ fractional_knapsack.cpp -o fractional_knapsack
- Run: ./fractional_knapsack  (or fractional_knapsack.exe on Windows)
*/

#include <bits/stdc++.h>
using namespace std;

struct Item {
    double value, weight;
};

bool cmp(const Item &a, const Item &b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

int main() {
    cout << "=============================\n";
    cout << " Fractional Knapsack Program \n";
    cout << "=============================\n";
    cout << "1. Compute Maximum Profit\n";
    cout << "2. Exit\n";
    cout << "=============================\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    if (choice == 2) {
        cout << "Exiting program.\n";
        return 0;
    } else if (choice != 1) {
        cout << "Invalid choice.\n";
        return 0;
    }

    int n;
    double capacity;
    cout << "\nEnter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;
    for (int i = 0; i < n && capacity > 0; ++i) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].value * (capacity / items[i].weight);
            capacity = 0;
        }
    }

    cout << "\n=============================\n";
    cout << " Maximum Profit: " << fixed << setprecision(4) << totalValue << "\n";
    cout << "=============================\n";
    cout << "Thank you for using the program!\n";
    return 0;
}
