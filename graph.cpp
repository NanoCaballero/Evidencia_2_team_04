/*
 * Copyright (c) 2025 Team 4
 * SPDX-License-Identifier: MIT
 *
 * File: graph.cpp
 * Description: Implementation of the Graph class.
 * Authors:
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Date: June 2025
 */

#include "graph.h"

Graph::Graph(int n) : n(n), adjMatrix(n, std::vector<int>(n, 0)) {}

void Graph::AddEdge(int u, int v, int w) {
    edges.emplace_back(u, v, w);
    adjMatrix[u][v] = w;
    adjMatrix[v][u] = w;
}

const std::vector<std::tuple<int, int, int>>& Graph::GetEdges() const {
    return edges;
}

int Graph::GetSize() const {
    return n;
}
