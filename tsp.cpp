
/*
 * SonarQube, open source software quality management tool.
 * Copyright (C) 2008-2013 SonarSource
 * http://github.com/SonarOpenCommunity/sonar-cxx
 *
 * SonarQube is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * SonarQube is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

/*
 * Copyright (c) 2025 Team 4
 * SPDX-License-Identifier: MIT
 *
 * File: tsp.cpp
 * Description: Implementation of a solution to the TSP using brute force.
 * Authors:
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Date: June 2025
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
