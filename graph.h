
/*
 * Archivo: graph.h
 * Descripción: Implementación de la clase Graph con almacenamiento de aristas y matriz de adyacencia.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera
 * Fecha: Junio 2025
 */


#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <tuple>
#include <utility>
#include <limits>
#include <string>

using namespace std;

class Graph {
public:
    Graph(int n);
    void addEdge(int u, int v, int w);
    const vector<tuple<int, int, int>>& getEdges() const;
    const vector<vector<int>>& getAdjMatrix() const;
    int size() const;

private:
    int n;
    vector<vector<int>> adjMatrix;
    vector<tuple<int, int, int>> edges;
};

#endif
