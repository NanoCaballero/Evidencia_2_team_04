
/*
 * Archivo: kruskal.h
 * Descripción: Algoritmo de Kruskal para encontrar el árbol de expansión mínima.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera
 * Fecha: Junio 2025
 */

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "graph.h"
#include <vector>
#include <tuple>
#include <algorithm>

int findSet(int u, std::vector<int>& parent) {
    if (parent[u] != u)
        parent[u] = findSet(parent[u], parent);
    return parent[u];
}

void unionSet(int u, int v, std::vector<int>& parent) {
    parent[findSet(u, parent)] = findSet(v, parent);
}

std::vector<std::pair<int, int>> kruskalMST(const Graph& g) {
    int n = g.size_of_graph();
    auto edges = g.get_edges();
    std::sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
        return std::get<2>(a) < std::get<2>(b);
    });

    std::vector<int> parent(n);
    for (int i = 0; i < n; ++i) parent[i] = i;

    std::vector<std::pair<int, int>> mst;
    for (auto [u, v, w] : edges) {
        if (findSet(u, parent) != findSet(v, parent)) {
            mst.emplace_back(u, v);
            unionSet(u, v, parent);
        }
    }

    return mst;
}

#endif

