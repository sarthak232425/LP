/*
Problem (0/1 Knapsack)
Write a program to implement 0/1 knapsack using dynamic programming and also find the maximum profit.

This file: zero_one_knapsack.cpp
- Reads n, capacity, then n items (value weight) and uses DP table to compute max profit
- Compile: g++ zero_one_knapsack.cpp -o zero_one_knapsack
- Run: ./zero_one_knapsack
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cout << "Enter number of items: ";
    if(!(cin >> n)) return 0;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<int> val(n+1), wt(n+1);
    for (int i = 1; i <= n; ++i) {
        cout << "Enter value and weight for item " << i << ": ";
        cin >> val[i] >> wt[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            dp[i][w] = dp[i-1][w];
            if (wt[i] <= w) {
                dp[i][w] = max(dp[i][w], dp[i-1][w-wt[i]] + val[i]);
            }
        }
    }

    cout << "Maximum profit = " << dp[n][W] << "\n";

    // Recover picked items
    int w = W;
    cout << "Items selected (index:value,weight):\n";
    for (int i = n; i >= 1; --i) {
        if (dp[i][w] != dp[i-1][w]) {
            cout << i << ":" << val[i] << "," << wt[i] << "\n";
            w -= wt[i];
        }
    }

    return 0;
}
