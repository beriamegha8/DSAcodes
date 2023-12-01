#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<stack>

using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void creation(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void print() {
        for (auto i : adj) {
            cout << i.first << "->";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void deletenode(int node) {
        if (adj.find(node) != adj.end()) {
            adj.erase(node);
            for (auto &kv : adj) {
                kv.second.remove(node);
            }
        }
    }

    void dfs(int start) {
        unordered_map<int, bool> visited;
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";

                for (const auto &neighbor : adj[current]) {
                    s.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void bfs(int start) {
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";

                for (int neighbor : adj[current]) {
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int m, n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    graph g;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.creation(u, v, 0);
    }

    cout << "Adjacency List:" << endl;
    g.print();

    cout << "BFS starting from node 5:" << endl;
    g.bfs(5);

    cout << "DFS starting from node 5:" << endl;
    g.dfs(5);

    return 0;
}
