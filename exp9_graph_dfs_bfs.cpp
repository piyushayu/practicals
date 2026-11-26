#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << "\n";
}

void dfsHelper(int curr, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[curr] = true;
    cout << curr << " ";

    for (int neighbor : adj[curr]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited);
        }
    }
}

void dfs(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    cout << "DFS Traversal: ";
    dfsHelper(start, adj, visited);
    cout << "\n";
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    if (vertices <= 0 || edges < 0) {
        cout << "Invalid number of vertices or edges.\n";
        return 1;
    }

    vector<vector<int>> adj(vertices);
    cout << "Enter " << edges << " edges (u v) with 0-based vertex indices (0 to "
         << vertices - 1 << "):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cout << "Invalid edge (" << u << ", " << v << "). Skipping.\n";
            continue;
        }
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    int start;
    cout << "Enter starting vertex for BFS and DFS: ";
    cin >> start;

    if (start < 0 || start >= vertices) {
        cout << "Invalid starting vertex.\n";
        return 1;
    }

    bfs(start, adj);
    dfs(start, adj);

    return 0;
}
