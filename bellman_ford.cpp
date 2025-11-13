/*
Problem (Bellman-Ford)
Write a program to implement Bellman-Ford Algorithm using Dynamic Programming and verify the time complexity.

This file: bellman_ford.cpp
- Reads number of vertices V and number of edges E, then E lines of (u v w)
- Computes single-source shortest paths (handles negative weights), and detects negative cycles
- Compile: g++ bellman_ford.cpp -o bellman_ford
- Run: ./bellman_ford
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E;
    cout << "Enter number of vertices: ";
    if(!(cin >> V)) return 0;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<tuple<int,int,int>> edges;
    cout << "Enter edges as: u v w (0-based indices)" << "\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w; cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    int src;
    cout << "Enter source vertex: "; cin >> src;

    const long long INF = (1LL<<60);
    vector<long long> dist(V, INF);
    dist[src] = 0;
    // Relax edges V-1 times
    for (int i = 0; i < V-1; ++i) {
        for (auto &e : edges) {
            int u, v, w; tie(u,v,w) = e;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    // Check negative cycles
    bool neg = false;
    for (auto &e : edges) {
        int u, v, w; tie(u,v,w) = e;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            neg = true; break;
        }
    }

    if (neg) cout << "Graph contains a negative-weight cycle\n";
    else {
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INF) cout << i << ": INF\n";
            else cout << i << ": " << dist[i] << "\n";
        }
    }
    return 0;
}
