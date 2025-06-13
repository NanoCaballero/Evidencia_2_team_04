

/*
 * Archivo: main.cpp
 * Descripción: Función principal que integra la lógica de entrada/salida y utiliza los algoritmos de Kruskal, TSP, Ford-Fulkerson y búsqueda de central más cercana.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera
 * Fecha: Junio 2025
 */


#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

// --------------------- Graph ---------------------
class Graph {
public:
    Graph(int n) : n(n), adjMatrix(n, vector<int>(n, 0)) {}

    void addEdge(int u, int v, int w) {
        edges.emplace_back(u, v, w);
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }

    const vector<tuple<int, int, int>>& getEdges() const {
        return edges;
    }

    int size() const {
        return n;
    }

private:
    int n;
    vector<vector<int>> adjMatrix;
    vector<tuple<int, int, int>> edges;
};

// --------------------- Kruskal ---------------------
int findSet(int u, vector<int>& parent) {
    if (parent[u] != u)
        parent[u] = findSet(parent[u], parent);
    return parent[u];
}

void unionSet(int u, int v, vector<int>& parent) {
    parent[findSet(u, parent)] = findSet(v, parent);
}

vector<pair<int, int>> kruskalMST(const Graph& g) {
    int n = g.size();
    vector<tuple<int, int, int>> edges = g.getEdges();
    sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
        return get<2>(a) < get<2>(b);
    });

    vector<int> parent(n);
    for (int i = 0; i < n; ++i) parent[i] = i;

    vector<pair<int, int>> mst;
    for (auto [u, v, w] : edges) {
        if (findSet(u, parent) != findSet(v, parent)) {
            mst.emplace_back(u, v);
            unionSet(u, v, parent);
        }
    }

    return mst;
}

// --------------------- TSP (Brute-force) ---------------------
pair<vector<char>, int> solveTSP(const vector<vector<int>>& dist) {
    int n = dist.size();
    vector<int> cities(n);
    for (int i = 0; i < n; ++i) cities[i] = i;

    int minCost = numeric_limits<int>::max();
    vector<int> bestPath;

    do {
        int cost = 0;
        for (int i = 0; i < n - 1; ++i)
            cost += dist[cities[i]][cities[i+1]];
        cost += dist[cities[n-1]][cities[0]]; // ciclo

        if (cost < minCost) {
            minCost = cost;
            bestPath = cities;
        }
    } while (next_permutation(cities.begin(), cities.end()));

    vector<char> path;
    for (int i : bestPath) path.push_back('A' + i);

    return {path, minCost};
}

// --------------------- Ford-Fulkerson ---------------------
bool bfs(const vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    int n = rGraph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

int fordFulkerson(const vector<vector<int>>& capacity, int s, int t) {
    int n = capacity.size();
    vector<vector<int>> rGraph = capacity;
    vector<int> parent(n);
    int maxFlow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int pathFlow = numeric_limits<int>::max();
        for (int v = t; v != s; v = parent[v])
            pathFlow = min(pathFlow, rGraph[parent[v]][v]);

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

// --------------------- Closest Central ---------------------
pair<int, double> findClosestCentral(const pair<int, int>& newHouse, const vector<pair<int, int>>& centrals) {
    double minDist = numeric_limits<double>::max();
    int idx = -1;

    for (int i = 0; i < centrals.size(); ++i) {
        double d = hypot(newHouse.first - centrals[i].first, newHouse.second - centrals[i].second);
        if (d < minDist) {
            minDist = d;
            idx = i;
        }
    }

    return {idx, minDist};
}

// --------------------- MAIN ---------------------
int main() {
    int n;
    cin >> n;

    Graph g(n);
    vector<vector<int>> dist(n, vector<int>(n));
    vector<vector<int>> capacity(n, vector<int>(n));
    vector<pair<int, int>> centrals;

    // Leer distancias
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
            if (i < j && dist[i][j] > 0) g.addEdge(i, j, dist[i][j]);
        }

    // Leer capacidades
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> capacity[i][j];

    // Leer coordenadas
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        centrals.emplace_back(x, y);
    }

    int xNew, yNew;
    cin >> xNew >> yNew;
    pair<int, int> newHouse = {xNew, yNew};

    // 1. Fibra óptica (Kruskal)
    auto mst = kruskalMST(g);
    cout << "1.\n";
    for (auto [u, v] : mst)
        cout << "(" << char('A'+u) << ", " << char('A'+v) << ")\n";

    // 2. Reparto (TSP)
    auto [path, cost] = solveTSP(dist);
    cout << "2.\n";
    for (char c : path) cout << c << " ";
    cout << "\n";

    // 3. Flujo máximo (Ford-Fulkerson)
    cout << "3.\n" << fordFulkerson(capacity, 0, n-1) << "\n";

    // 4. Central más cercana
    auto [idx, d] = findClosestCentral(newHouse, centrals);
    cout << "4.\n(" << centrals[idx].first << ", " << centrals[idx].second << ")\n";

    return 0;
}
