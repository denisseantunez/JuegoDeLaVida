#ifndef MATRICES_HPP_INCLUDED
#define MATRICES_HPP_INCLUDED

#include <iostream>
#include <iomanip>

#include "Windows.hpp"

using std::cout;
using std::endl;
using std::setw;
using std::left;

/*****************************************************************************/

enum { BH = 196, ESD = 191, EII, BV = 179, EID = 217, ESI};

/*****************************************************************************/

int **Crear(int filas, int columnas);

/*****************************************************************************/

void Destruir(int **&arreglo);

/*****************************************************************************/

void ImprimirTablero(int **tablero, int filas, int columnas);

/*****************************************************************************/

void EstadoBicho(int **tablero, int fila, int columna);

/*****************************************************************************/

void ReglasDeVida(int **tablero_1, int **tablero_2, int filas, int columnas);

/*****************************************************************************/

int ChecarVecinos(int **tablero, int fila, int columna, int filas, int columnas);

/*****************************************************************************/

#endif // MATRICES_HPP_INCLUDED
