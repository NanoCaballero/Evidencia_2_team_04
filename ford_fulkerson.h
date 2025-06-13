
/*
 * Archivo: ford_fulkerson.h
 * Descripción: Algoritmo Ford-Fulkerson para hallar el flujo máximo entre nodos.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera
 * Fecha: Junio 2025
 */

#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

#include <vector>
#include <queue>
#include <limits>

bool bfs(const std::vector<std::vector<int>>& rGraph, int s, int t, std::vector<int>& parent) {
    int n = rGraph.size();
    std::vector<bool> visited(n, false);
    std::queue<int> q;
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

int fordFulkerson(const std::vector<std::vector<int>>& capacity, int s, int t) {
    int n = capacity.size();
    std::vector<std::vector<int>> rGraph = capacity;
    std::vector<int> parent(n);
    int maxFlow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int pathFlow = std::numeric_limits<int>::max();
        for (int v = t; v != s; v = parent[v])
            pathFlow = std::min(pathFlow, rGraph[parent[v]][v]);

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

#endif

