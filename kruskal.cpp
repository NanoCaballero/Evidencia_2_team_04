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

int find_set(int u, std::vector<int>& parent);
void union_set(int u, int v, std::vector<int>& parent);
std::vector<std::pair<int, int>> kruskal_mst(const Graph& g);

#endif
