
/*
 * Archivo: search.h
 * Descripción: Función para encontrar la central más cercana a una nueva ubicación.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera
 * Fecha: Junio 2025
 */

#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <utility>
#include <cmath>
#include <limits>

std::pair<int, double> findClosestCentral(const std::pair<int, int>& newHouse, const std::vector<std::pair<int, int>>& centrals) {
    double minDist = std::numeric_limits<double>::max();
    int idx = -1;

    for (int i = 0; i < centrals.size(); ++i) {
        double d = std::hypot(newHouse.first - centrals[i].first, newHouse.second - centrals[i].second);
        if (d < minDist) {
            minDist = d;
            idx = i;
        }
    }

    return {idx, minDist};
}

#endif

