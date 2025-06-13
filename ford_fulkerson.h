
/*
 * Archivo: ford_fulkerson.h
 * Descripción: Implementación del algoritmo de Ford-Fulkerson para encontrar el flujo máximo entre dos nodos.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera
 * Fecha: Junio 2025
 */


#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

#include <vector>
using namespace std;

int fordFulkerson(const vector<vector<int>>& capacity, int s, int t);

#endif