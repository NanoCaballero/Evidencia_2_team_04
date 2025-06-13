/*
 * Copyright (c) 2025 Team 4
 * SPDX-License-Identifier: MIT
 *
 * File: tsp.h
 * Description: Header file for the TSP solution using brute force.
 * Authors:
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Date: June 2025
 */

#ifndef TSP_H
#define TSP_H

#include <vector>
#include <utility>

// Function to solve the Traveling Salesman Problem (TSP) using brute force
std::pair<std::vector<char>, int> solve_tsp(const std::vector<std::vector<int>>& dist);

#endif
