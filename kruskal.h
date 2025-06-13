/*
 * Copyright (c) 2025 Team 4
 * SPDX-License-Identifier: MIT
 *
 * File: kruskal.h
 * Description: Header file for Kruskal's algorithm (MST).
 * Authors:
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Date: June 2025
 */

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "graph.h"
#include <vector>
#include <tuple>

int find_set(int u, std::vector<int>& parent);
void union_set(int u, int v, std::vector<int>& parent);
std::vector<std::pair<int, int>> kruskal_mst(const Graph& g);

#endif
