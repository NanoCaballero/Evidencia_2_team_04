/*
 * Archivo: tsp.h
 * Descripción: Solución al problema del vendedor viajero (TSP) usando fuerza bruta.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Fecha: Junio 2025
 */

#ifndef TSP_H
#define TSP_H

#include <vector>
#include <utility>

std::pair<std::vector<char>, int> solve_tsp(const std::vector<std::vector<int>>& dist);

#endif
