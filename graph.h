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
 * File: graph.h
 * Description: Header file for the Graph class.
 * Authors:
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Date: June 2025
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <tuple>

/**
 * Clase para representar un grafo con matriz de adyacencia y lista de aristas.
 */
class Graph {
public:
    /**
     * Constructor del grafo.
     * @param n Número de nodos.
     */
    Graph(int n);

    /**
     * Agrega una arista entre dos nodos con peso.
     * @param u Nodo origen.
     * @param v Nodo destino.
     * @param w Peso de la arista.
     */
    void AddEdge(int u, int v, int w);

    /**
     * Obtiene todas las aristas del grafo.
     * @return Vector de tuplas (u, v, peso).
     */
    const std::vector<std::tuple<int, int, int>>& GetEdges() const;

    /**
     * Obtiene el número de nodos del grafo.
     * @return Número de nodos.
     */
    int GetSize() const;

private:
    int n;
    std::vector<std::vector<int>> adjMatrix;
    std::vector<std::tuple<int, int, int>> edges;
};

#endif
