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

/**
 * Realiza una búsqueda en anchura (BFS) sobre un grafo residual.
 * 
 * @param rGraph El grafo residual.
 * @param s Nodo origen.
 * @param t Nodo destino.
 * @param parent Vector para reconstruir el camino.
 * @return true si hay camino de s a t, false si no.
 */
bool bfs(const std::vector<std::vector<int>>&, int, int, std::vector<int>&);

/**
 * Calcula el flujo máximo entre dos nodos usando el algoritmo de Ford-Fulkerson.
 * 
 * @param capacity Matriz de capacidades.
 * @param s Nodo origen.
 * @param t Nodo destino.
 * @return Flujo máximo.
 */
int ford_fulkerson(const std::vector<std::vector<int>>&, int, int);


#endif
