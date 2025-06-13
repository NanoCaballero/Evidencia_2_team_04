
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
 * File: kruskal.cpp
 * Description: Implementation of Kruskal's algorithm (MST)
 * Authors:
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Date: June 2025
 */

#include "kruskal.h"
#include <algorithm>


int find_set(int u, std::vector<int>& parent) {
    if (parent[u] != u)
        parent[u] = find_set(parent[u], parent);
    return parent[u];
}

void union_set(int u, int v, std::vector<int>& parent) {
    parent[find_set(u, parent)] = find_set(v, parent);
}

std::vector<std::pair<int, int>> kruskal_mst(const Graph& g) {
    int n = g.GetSize();
    auto edges = g.GetEdges();
    std::sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
        return std::get<2>(a) < std::get<2>(b);
    });

    std::vector<int> parent(n);
    for (int i = 0; i < n; ++i) parent[i] = i;

    std::vector<std::pair<int, int>> mst;
    for (auto [u, v, w] : edges) {
        if (find_set(u, parent) != find_set(v, parent)) {
            mst.emplace_back(u, v);
            union_set(u, v, parent);
        }
    }

    return mst;
}
