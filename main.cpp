
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
 * File: main.cpp
 * Description: Main program to solve the problem of connecting a new house to a network of central offices.
 * Authors:
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Date: June 2025
 */

#include <iostream>
#include <vector>
#include "graph.h"
#include "kruskal.h"
#include "tsp.h"
#include "ford_fulkerson.h"
#include "search.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    Graph g(n);
    vector<vector<int>> dist(n, vector<int>(n));
    vector<vector<int>> capacity(n, vector<int>(n));
    vector<pair<int, int>> centrals;

    // Leer distancias
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
            if (i < j && dist[i][j] > 0)
                g.AddEdge(i, j, dist[i][j]);
        }

    // Leer capacidades
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> capacity[i][j];

    // Leer coordenadas
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        centrals.emplace_back(x, y);
    }

    // Leer ubicación nueva casa
    int xNew, yNew;
    cin >> xNew >> yNew;
    pair<int, int> newHouse = {xNew, yNew};

    // 1. Fibra óptica (Kruskal)
    auto mst = kruskal_mst(g);
    cout << "1.\n";
    for (auto [u, v] : mst)
        cout << "(" << char('A' + u) << ", " << char('A' + v) << ")\n";

    // 2. Reparto (TSP)
    auto [path, cost] = solve_tsp(dist);
    cout << "2.\n";
    for (char c : path)
        cout << c << " ";
    cout << "\n";

    // 3. Flujo máximo (Ford-Fulkerson)
    cout << "3.\n" << ford_fulkerson(capacity, 0, n - 1) << "\n";

    // 4. Central más cercana
    auto [idx, d] = find_closest_central(newHouse, centrals);
    cout << "4.\n(" << centrals[idx].first << ", " << centrals[idx].second << ")\n";

    return 0;
}

