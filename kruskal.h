
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

int FindSet(int u, std::vector<int>& parent) {
    if (parent[u] != u)
        parent[u] = FindSet(parent[u], parent);
    return parent[u];
}

void UnionSet(int u, int v, std::vector<int>& parent) {
    parent[FindSet(u, parent)] = FindSet(v, parent);
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
        if (FindSet(u, parent) != FindSet(v, parent)) {
            mst.emplace_back(u, v);
            UnionSet(u, v, parent);
        }
    }

    return mst;
}

#endif

