/*
 * Copyright (c) 2025 Team 4
 * SPDX-License-Identifier: MIT
 *
 * File: ford_fulkerson.h
 * Description: Ford-Fulkerson algorithm for finding the maximum flow between nodes.
 * Authors:
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Date: June 2025
 */

#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

#include <vector>

bool bfs(const std::vector<std::vector<int>>&, int, int, std::vector<int>&);
int ford_fulkerson(const std::vector<std::vector<int>>&, int, int);

#endif
