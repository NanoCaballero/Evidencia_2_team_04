/*
 * Copyright (c) 2025 Team 4
 * SPDX-License-Identifier: MIT
 *
 * File: search.cpp
 * Description: Search function to find the closest central office to a new house location.
 * Authors:
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Date: June 2025
 */

#include "search.h"
#include <cmath>
#include <limits>

std::pair<int, double> find_closest_central(const std::pair<int, int>& newHouse, const std::vector<std::pair<int, int>>& centrals) {
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
