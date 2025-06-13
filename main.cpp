
/*
 * Archivo: main.cpp
 * Descripción: Función principal que integra la lógica de entrada/salida y utiliza los algoritmos de Kruskal, TSP, Ford-Fulkerson y búsqueda de central más cercana.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Fecha: Junio 2025
 */

#include <iostream>
#include <vector>
#include "graph.h"
#include "kruskal.h"
#include "tsp.h"
#include "ford_fulkerson.h"
#include "search.h"

using namespace std;

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
            if (i < j && dist[i][j] > 0)
                g.add_edge(i, j, dist[i][j]);
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

    // Leer ubicación nueva casa
    int xNew, yNew;
    cin >> xNew >> yNew;
    pair<int, int> newHouse = {xNew, yNew};

    // 1. Fibra óptica (Kruskal)
    auto mst = kruskalMST(g);
    cout << "1.\n";
    for (auto [u, v] : mst)
        cout << "(" << char('A' + u) << ", " << char('A' + v) << ")\n";

    // 2. Reparto (TSP)
    auto [path, cost] = solveTSP(dist);
    cout << "2.\n";
    for (char c : path)
        cout << c << " ";
    cout << "\n";

    // 3. Flujo máximo (Ford-Fulkerson)
    cout << "3.\n" << ford_fulkerson(capacity, 0, n - 1) << "\n";

    // 4. Central más cercana
    auto [idx, d] = findClosestCentral(newHouse, centrals);
    cout << "4.\n(" << centrals[idx].first << ", " << centrals[idx].second << ")\n";

    return 0;
}

