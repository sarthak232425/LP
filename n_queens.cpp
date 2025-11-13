/*
Problem (N-Queens)
Write a recursive program to find the solution of placing N queens on the chessboard so that no two queens attack each other using Backtracking.

This file: n_queens.cpp
- Finds one solution (or all solutions if you set find_all=true)
- Input: N
- Compile: g++ n_queens.cpp -o n_queens
- Run: ./n_queens
*/

#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> col; // col[row] = column index of queen in row

bool ok(int r, int c) {
    for (int i = 0; i < r; ++i) {
        if (col[i] == c) return false;
        if (abs(col[i] - c) == abs(i - r)) return false;
    }
    return true;
}

bool solve(int r) {
    if (r == N) return true;
    for (int c = 0; c < N; ++c) {
        if (ok(r, c)) {
            col[r] = c;
            if (solve(r+1)) return true;
        }
    }
    return false;
}

int main() {
    cout << "Enter N for N-Queens: ";
    if(!(cin >> N)) return 0;
    col.assign(N, -1);
    if (solve(0)) {
        cout << "One solution (row:col)\n";
        for (int i = 0; i < N; ++i) cout << i << ":" << col[i] << "\n";
        // print board
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << (col[i] == j ? 'Q' : '.') << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "No solution for N = " << N << "\n";
    }
    return 0;
}
