#include <gtest/gtest.h>
#include "graph.h"
#include "kruskal.h"
#include "tsp.h"
#include "ford_fulkerson.h"
#include "search.h"

TEST(KruskalTest, MST) {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    auto mst = kruskalMST(g);
    EXPECT_EQ(mst.size(), 3);
}

TEST(TSPTest, Simple4Nodes) {
    std::vector<std::vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    auto [path, cost] = solveTSP(dist);
    EXPECT_EQ(path.front(), 'A');
    EXPECT_EQ(path.back(), 'A');
    EXPECT_GT(cost, 0);
}

TEST(FordFulkersonTest, MaxFlow) {
    std::vector<std::vector<int>> capacity = {
        {0, 8, 0, 0, 3, 0},
        {0, 0, 9, 0, 0, 0},
        {0, 0, 0, 0, 7, 2},
        {0, 0, 0, 0, 0, 5},
        {0, 0, 7, 4, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    int maxFlow = fordFulkerson(capacity, 0, 5);
    EXPECT_EQ(maxFlow, 5);
}

TEST(SearchTest, ClosestCentral) {
    std::vector<std::pair<int, int>> centrals = {
        {0, 0}, {100, 100}, {200, 200}
    };
    auto [idx, dist] = findClosestCentral({90, 90}, centrals);
    EXPECT_EQ(idx, 1);
    EXPECT_GT(dist, 0);
}
