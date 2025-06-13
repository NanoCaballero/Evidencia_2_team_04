/*
 * Archivo: graph.h
 * Descripción: Clase Graph para manejar aristas y matriz de adyacencia.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Fecha: Junio 2025
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <tuple>

class Graph {
public:
    Graph(int n);
    void AddEdge(int u, int v, int w);
    const std::vector<std::tuple<int, int, int>>& GetEdges() const;
    int GetSize() const;

private:
    int n;
    std::vector<std::vector<int>> adjMatrix;
    std::vector<std::tuple<int, int, int>> edges;
};

#endif
