/*
 * Archivo: tsp.cpp
 * Descripción: Implementación de solución al TSP con fuerza bruta.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Fecha: Junio 2025
 */

#include "tsp.h"
#include <limits>
#include <algorithm>

std::pair<std::vector<char>, int> solve_tsp(const std::vector<std::vector<int>>& dist) {
    int n = dist.size();
    std::vector<int> cities(n);
    for (int i = 0; i < n; ++i) cities[i] = i;

    int minCost = std::numeric_limits<int>::max();
    std::vector<int> bestPath;

    do {
        int cost = 0;
        for (int i = 0; i < n - 1; ++i)
            cost += dist[cities[i]][cities[i + 1]];
        cost += dist[cities[n - 1]][cities[0]];

        if (cost < minCost) {
            minCost = cost;
            bestPath = cities;
        }
    } while (std::next_permutation(cities.begin(), cities.end()));

    std::vector<char> path;
    for (int i : bestPath) path.push_back('A' + i);
    path.push_back('A');

    return {path, minCost};
}
