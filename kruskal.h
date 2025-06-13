
/*
 * Archivo: kruskal.h
 * Descripción: Implementación del algoritmo de Kruskal para construir el árbol de expansión mínima.
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

using namespace std;

vector<pair<int, int>> kruskalMST(const Graph& g);

#endif
