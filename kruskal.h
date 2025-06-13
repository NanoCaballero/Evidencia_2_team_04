
/*
 * Archivo: kruskal.h
 * Descripción: Algoritmo de Kruskal para encontrar el árbol de expansión mínima.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Fecha: Junio 2025
 */

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "graph.h"
#include <vector>
#include <tuple>
#include <algorithm>

int find_set(int u, std::vector<int>& parent) {
    if (parent[u] != u)
        parent[u] = find_set(parent[u], parent);
    return parent[u];
}

void union_set(int u, int v, std::vector<int>& parent) {
    parent[find_set(u, parent)] = find_set(v, parent);
}

std::vector<std::pair<int, int>> kruskal_mst(const Graph& g) {
    int n = g.GetSize();
    auto edges = g.GetEdges();
    std::sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
        return std::get<2>(a) < std::get<2>(b);
    });

    std::vector<int> parent(n);
    for (int i = 0; i < n; ++i) parent[i] = i;

    std::vector<std::pair<int, int>> mst;
    for (auto [u, v, w] : edges) {
        if (find_set(u, parent) != find_set(v, parent)) {
            mst.emplace_back(u, v);
            union_set(u, v, parent);
        }
    }

    return mst;
}

#endif

