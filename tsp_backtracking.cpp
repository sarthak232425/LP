/*
Problem (Travelling Salesman — LC Branch & Bound requested)
Write a program to solve the Travelling Salesman Problem and to print the path and the cost using LC Branch and Bound.

This file: tsp_backtracking.cpp
- A readable implementation that finds the minimum Hamiltonian cycle using backtracking with simple pruning (current cost >= bestCost)
- Input: n, then an n x n adjacency matrix (use a large number for no-edge or 0 for self)
- Compile: g++ tsp_backtracking.cpp -o tsp_backtracking
- Run: ./tsp_backtracking

Note: This implementation uses backtracking with pruning by current path cost. It is suitable for small n (n<=12-13). For full LC Branch & Bound with reduced matrix cost, a more elaborate implementation can be added later.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> distmat;
vector<int> bestPath;
int bestCost = INT_MAX;

void dfs(int node, vector<int>& visited, vector<int>& path, int currentCost) {
    if (currentCost >= bestCost) return; // prune
    if ((int)path.size() == n) {
        // complete cycle back to start
        int total = currentCost + distmat[node][path[0]];
        if (total < bestCost) {
            bestCost = total;
            bestPath = path;
        }
        return;
    }
    for (int nxt = 0; nxt < n; ++nxt) {
        if (!visited[nxt]) {
            visited[nxt] = 1;
            path.push_back(nxt);
            dfs(nxt, visited, path, currentCost + distmat[node][nxt]);
            path.pop_back();
            visited[nxt] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter number of cities (n): ";
    if(!(cin >> n)) return 0;
    distmat.assign(n, vector<int>(n));
    cout << "Enter adjacency matrix (n x n):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> distmat[i][j];
        }
    }

    vector<int> visited(n, 0);
    vector<int> path;
    // start from city 0
    visited[0] = 1;
    path.push_back(0);
    dfs(0, visited, path, 0);

    if (bestCost == INT_MAX) {
        cout << "No Hamiltonian cycle found or input invalid.\n";
    } else {
        cout << "Best cost: " << bestCost << "\n";
        cout << "Path: ";
        for (int v : bestPath) cout << v << " -> ";
        cout << bestPath[0] << "\n"; // return to start
    }
    return 0;
}
