
/*
 * Archivo: tsp.h
 * Descripción: Solución al problema del viajero (TSP) utilizando fuerza bruta para obtener la ruta mínima.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera
 * Fecha: Junio 2025
 */


#ifndef TSP_H
#define TSP_H

#include <vector>
#include <string>
#include <utility>

using namespace std;

pair<vector<char>, int> solveTSP(const vector<vector<int>>& dist);

#endif
