/*
 * Copyright (c) 2025 Team 4
 * SPDX-License-Identifier: MIT
 *
 * File: graph.h
 * Description: Header file for the Graph class.
 * Authors:
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Date: June 2025
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <tuple>

// Clase para representar un grafo
class Graph {
public:
    // Constructor que inicializa el grafo con n nodos
    Graph(int n);
    
    // Agrega una arista al grafo
    void AddEdge(int u, int v, int w);

    // Obtiene las aristas del grafo
    const std::vector<std::tuple<int, int, int>>& GetEdges() const;

    // Obtiene el tamaño del grafo (número de nodos)
    int GetSize() const;

private:
    int n;
    std::vector<std::vector<int>> adjMatrix;
    std::vector<std::tuple<int, int, int>> edges;
};

#endif
