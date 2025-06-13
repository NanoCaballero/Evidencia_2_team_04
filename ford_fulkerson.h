/*
 * Archivo: ford_fulkerson.h
 * Descripción: Algoritmo Ford-Fulkerson para hallar el flujo máximo entre nodos.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera A01234377
 * Pablo Velazquez A01734635
 * Fecha: Junio 2025
 */

#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

#include <vector>

bool bfs(const std::vector<std::vector<int>>&, int, int, std::vector<int>&);
int ford_fulkerson(const std::vector<std::vector<int>>&, int, int);

#endif
