
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
 * File: test_main.cpp
 * Description: Unit tests for the algorithms implemented in the project.
 * Authors:
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Date: June 2025
 */


#include <gtest/gtest.h>
#include "../graph.h"
#include "../kruskal.h"
#include "../tsp.h"
#include "../ford_fulkerson.h"
#include "../search.h"

// Kruskal
TEST(kruskal_test, basic_mst) {
    Graph g(4);
    g.AddEdge(0, 1, 1);
    g.AddEdge(1, 2, 2);
    g.AddEdge(2, 3, 3);
    g.AddEdge(0, 3, 4);
    auto mst = kruskal_mst(g);
    EXPECT_EQ(mst.size(), 3);
}

// TSP
TEST(tsp_test, basic_tour) {
    std::vector<std::vector<int>> dist = {{0, 1, 2}, {1, 0, 3}, {2, 3, 0}};
    auto [path, cost] = solve_tsp(dist);
    EXPECT_EQ(cost, 6);
    EXPECT_EQ(path.front(), 'A');
    EXPECT_EQ(path.back(), 'A');
}

// Ford-Fulkerson
TEST(flow_test, basic_flow) {
    std::vector<std::vector<int>> cap = {
        {0, 3, 2, 0},
        {0, 0, 5, 2},
        {0, 0, 0, 3},
        {0, 0, 0, 0}
    };
    EXPECT_EQ(ford_fulkerson(cap, 0, 3), 5);
}

// Búsqueda de central
TEST(search_test, closest_point) {
    std::vector<std::pair<int, int>> centrals = {{0,0}, {4,3}, {7,1}};
    std::pair<int, int> house = {1,1};
    auto [idx, dist] = find_closest_central(house, centrals);
    EXPECT_EQ(idx, 0);
}

// Graph
TEST(graph_test, edges_and_size) {
    Graph g(3);
    g.AddEdge(0, 1, 10);
    auto edges = g.GetEdges();
    EXPECT_EQ(edges.size(), 1);
    EXPECT_EQ(g.GetSize(), 3);
}

