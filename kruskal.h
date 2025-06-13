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

/**
 * Encuentra el representante del conjunto de un nodo.
 * @param u Nodo.
 * @param parent Vector de padres.
 * @return Representante del conjunto.
 */
int find_set(int u, std::vector<int>& parent);

/**
 * Une dos conjuntos disjuntos.
 * @param u Nodo del primer conjunto.
 * @param v Nodo del segundo conjunto.
 * @param parent Vector de padres.
 */
void union_set(int u, int v, std::vector<int>& parent);

/**
 * Calcula el Árbol de Expansión Mínima (MST) con el algoritmo de Kruskal.
 * @param g Grafo de entrada.
 * @return Vector de aristas del MST.
 */
std::vector<std::pair<int, int>> kruskal_mst(const Graph& g);


#endif
