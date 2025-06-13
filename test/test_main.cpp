
/*
 * Archivo: test_main.cpp
 * Descripción: Pruebas de algoritmos Kruskal, TSP, Ford-Fulkerson y búsqueda de central más cercana.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Fecha: Junio 2025
 */

#include <gtest/gtest.h>
#include "../kruskal.h"
#include "../tsp.h"
#include "../ford_fulkerson.h"
#include "../search.h"

// === Parte 1: Kruskal ===

TEST(kruskal_test, basic_mst) {
    Graph g(4);
    g.add_edge(0, 1, 1);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 3, 3);
    g.add_edge(0, 3, 4);

    auto mst = kruskal_mst(g);
    EXPECT_EQ(mst.size(), 3);
}

// === Parte 2: TSP ===

TEST(tsp_test, simple_tour) {
    std::vector<std::vector<int>> dist = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    auto [path, cost] = solve_tsp(dist);
    EXPECT_EQ(cost, 6);
    EXPECT_EQ(path.front(), 'A');
    EXPECT_EQ(path.back(), 'A');
}

// === Parte 3: Ford-Fulkerson ===

TEST(ford_fulkerson_test, small_graph_flow) {
    std::vector<std::vector<int>> cap = {
        {0, 3, 2, 0},
        {0, 0, 5, 2},
        {0, 0, 0, 3},
        {0, 0, 0, 0}
    };
    EXPECT_EQ(ford_fulkerson(cap, 0, 3), 4);
}

TEST(ford_fulkerson_test, no_path_available) {
    std::vector<std::vector<int>> cap = {
        {0, 0},
        {0, 0}
    };
    EXPECT_EQ(ford_fulkerson(cap, 0, 1), 0);
}

// === Parte 4: Closest Central ===

TEST(search_test, finds_closest_central) {
    std::vector<std::pair<int, int>> centrals = {{0, 0}, {4, 3}, {7, 1}};
    std::pair<int, int> house = {1, 1};
    auto [idx, dist] = find_closest_central(house, centrals);
    EXPECT_EQ(idx, 0);
}

// === Parte 5: Graph Methods ===

TEST(graph_test, add_edge_and_get_edges) {
    Graph g(3);
    g.add_edge(0, 1, 10);
    auto edges = g.get_edges();
    EXPECT_EQ(edges.size(), 1);
    EXPECT_EQ(edges[0], std::make_tuple(0, 1, 10));
}

TEST(graph_test, graph_size) {
    Graph g(4);
    EXPECT_EQ(g.get_size(), 4);
}
