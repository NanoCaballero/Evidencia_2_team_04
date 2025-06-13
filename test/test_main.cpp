
/*
 * Archivo: test_main.cpp
 * Descripción: Pruebas test
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

// === Kruskal ===
TEST(KruskalTest, BasicMST) {
    Graph g(4);
    g.AddEdge(0, 1, 1);
    g.AddEdge(1, 2, 2);
    g.AddEdge(2, 3, 3);
    g.AddEdge(0, 3, 4);

    auto mst = kruskalMST(g);
    EXPECT_EQ(mst.GetSize(), 3);
}

// === TSP ===
TEST(TSPTest, SimpleTour) {
    std::vector<std::vector<int>> dist = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    auto [path, cost] = solveTSP(dist);
    EXPECT_EQ(cost, 6);
    EXPECT_EQ(path.front(), 'A');
    EXPECT_EQ(path.back(), 'A');
}

// === Ford-Fulkerson ===
TEST(ford_fulkersonTest, SmallGraphFlow) {
    std::vector<std::vector<int>> cap = {
        {0, 3, 2, 0},
        {0, 0, 5, 2},
        {0, 0, 0, 3},
        {0, 0, 0, 0}
    };
    EXPECT_EQ(ford_fulkerson(cap, 0, 3), 4);
}

// === Closest Central ===
TEST(SearchTest, FindsClosestCentral) {
    std::vector<std::pair<int, int>> centrals = {{0, 0}, {4, 3}, {7, 1}};
    std::pair<int, int> house = {1, 1};
    auto [idx, dist] = findClosestCentral(house, centrals);
    EXPECT_EQ(idx, 0);
}

TEST(FordFulkersonTest, NoPathAvailable) {
    std::vector<std::vector<int>> cap = {
        {0, 0},
        {0, 0}
    };
    EXPECT_EQ(run_max_flow(cap, 0, 1), 0);
}

TEST(GraphTest, AddEdgeAndGetEdges) {
    Graph g(3);
    g.AddEdge(0, 1, 10);
    auto edges = g.GetEdges();
    EXPECT_EQ(edges.size(), 1);
    EXPECT_EQ(edges[0], std::make_tuple(0, 1, 10));
}

TEST(GraphTest, Size) {
    Graph g(4);
    EXPECT_EQ(g.GetSize(), 4);
}
