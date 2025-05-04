// #include "getUserData.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <queue>
using namespace std;

vector<pair<int, int>> createGnp(int quantityOfNodes, float probability){
    vector<pair<int, int>> ans;
    srand(time(0));
    for(int i = 0; i < quantityOfNodes; i++){
        for(int p = i + 1; p < quantityOfNodes; p++){
            float prob = static_cast<float>(rand()) / RAND_MAX;
            if (prob > probability){
                ans.push_back(make_pair(i, p));
            } else continue;
        }
    }
    return ans;
}

vector<pair<int, int>> createGnm(int quantityOfNodes, int quantityOfEdges){
    vector<pair<int, int>> ans;
    for(int i = 0; i < quantityOfNodes; i++){
        for(int p = i + 1; p < quantityOfNodes; p++){
            ans.push_back(make_pair(i, p));
        }
    }
    random_device rd;
    mt19937 gen(rd());

    shuffle(ans.begin(), ans.end(), gen);

    vector<pair<int, int>> selectedEdges(ans.begin(), ans.begin() + quantityOfEdges);
    return selectedEdges;
}

void dfs(int v, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, visited);
        }
    }
}

pair<int, int> bfs2(int start, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    vector<int> dist(adj.size(), -1);
    q.push(start);
    dist[start] = 0;
    visited[start] = true;

    int farthestNode = start;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : adj[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                visited[u] = true;
                q.push(u);
                if (dist[u] > dist[farthestNode]) {
                    farthestNode = u;
                }
            }
        }
    }
    return {dist[farthestNode], farthestNode};
}


int getGraphDiameter(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    int maxDiameter = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            auto [_, farthest] = bfs2(i, adj, visited);
            vector<bool> tempVisited(n, false);
            int diameter = bfs2(farthest, adj, tempVisited).first;
            maxDiameter = max(maxDiameter, diameter);
        }
    }
    return maxDiameter;
}

bool isConnected(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    dfs(0, adj, visited);

    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
}

bool hasCycleDFS(int v, int parent, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            if (hasCycleDFS(u, v, adj, visited)) return true;
        } else if (u != parent) {
            return true; // цикл найден
        }
    }
    return false;
}

bool hasCycle(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u); // неориентированный
    }

    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (hasCycleDFS(i, -1, adj, visited)) return true;
        }
    }
    return false;
}

double averageDegree(int n, const vector<pair<int, int>>& edges) {
    return (2.0 * edges.size()) / n;
}


struct graphInfo
{
    bool connected;
    int diameter;
    double degreeAverage;
    bool cycled;
};




void printVector(const std::vector<pair<int, int>>& vec) {
    for (const pair<int, int>& val : vec) {
        std::cout << "(" << val.first << ", " << val.second << ") ";
    }
    std::cout << std::endl;
}

graphInfo getGraphInfo(vector<pair<int, int>>& graph, int nodes){
    graphInfo infoGraph;
    infoGraph.connected = isConnected(nodes, graph);
    infoGraph.diameter = getGraphDiameter(nodes, graph);
    infoGraph.degreeAverage = averageDegree(nodes, graph);
    infoGraph.cycled = hasCycle(nodes, graph);
    return infoGraph;
}


