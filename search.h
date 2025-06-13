
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
 * File: search.h
 * Description: Header file for the search function to find the closest central office.
 * Authors:
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Date: June 2025
 */

#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <utility>

/**
 * Encuentra la central más cercana a una casa nueva.
 * 
 * @param newHouse Coordenadas de la nueva casa.
 * @param centrals Vector de coordenadas de centrales existentes.
 * @return Par (índice de la central más cercana, distancia).
 */
std::pair<int, double> find_closest_central(
    const std::pair<int, int>& newHouse,
    const std::vector<std::pair<int, int>>& centrals
);


#endif
