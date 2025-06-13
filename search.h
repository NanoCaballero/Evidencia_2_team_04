
/*
 * Archivo: search.h
 * Descripción: Función para encontrar la central más cercana usando distancia euclidiana.
 * Autores: 
 * Bernardo Caballero Zambrano A01722757
 * Juan Daniel Vázquez Alonso A01285354
 * Harold Andres Lancheros Álvarez A00836416
 * Francisco Vaquera
 * Fecha: Junio 2025
 */


#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <utility>

using namespace std;

pair<int, double> findClosestCentral(const pair<int, int>& newHouse, const vector<pair<int, int>>& centrals);

#endif
