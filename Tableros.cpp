

#include "Tableros.hpp"

/*****************************************************************************/

int **Crear(int filas, int columnas)
{
    int **arreglo = new int*[filas];
    arreglo[0] = new int[filas*columnas];

    for(int i = 1; i < filas ; ++i)
        arreglo[i] = arreglo[0] + i*columnas;

    return arreglo;
}

/*****************************************************************************/

void Destruir(int **&arreglo)
{
    delete [] arreglo[0];
    delete [] arreglo;
    arreglo = nullptr;
}

/*****************************************************************************/

void ImprimirTablero(int **tablero, int filas, int columnas)
{
    cout << left;

    short x = 6;
    short y = 6;

    MoverCursor(x, y);
    cout << char(ESI);
    for(int j = 0; j < columnas ; ++j) cout << char(BH) << char(BH);
    cout << char(ESD) << endl;

    for(int i = 0 ; i < filas ; ++i){
        MoverCursor(x, ++y);
        cout << char(BV);
        for(int j = 0; j < columnas ; ++j)
            EstadoBicho(tablero, i, j);
        cout << char(BV);
        cout << endl;
    }

    MoverCursor(x, ++y);
    cout << char(EII);
    for(int j = 0; j < columnas ; ++j) cout << char(BH) << char(BH);
    cout << char(EID);

    cout << endl << endl;
}

/*****************************************************************************/

void EstadoBicho(int **tablero, int fila, int columna)
{
    if(tablero[fila][columna] == 1) cout << setw(2) << char(190);
    else cout << setw(2) << ' ';
}

/*****************************************************************************/

void ReglasDeVida(int **tablero_1, int **tablero_2, int filas, int columnas)
{
    int vecinos;

    for(int i = 0; i < filas; ++i){
        for(int j = 0; j < columnas; ++j){
            vecinos = ChecarVecinos(tablero_1, i, j, filas, columnas);
            if(tablero_1[i][j] == 1){
                if(vecinos < 2 || vecinos > 3) tablero_2[i][j] = 0;
                else tablero_2[i][j] = 1;
            }else{
                if(vecinos == 3) tablero_2[i][j] = 1;
                else tablero_2[i][j] = 0;
            }
        }
    }
}

/*****************************************************************************/

int ChecarVecinos(int **tablero, int fila, int columna, int filas, int columnas)
{
    int vecinos = 0;

    // Borde superior horizontal (no esquinas)
    if(fila == 0 && (columna != 0 || columna != columnas - 1)){
       if(tablero[fila + 1][columna] == 1) ++vecinos;
       if(tablero[fila][columna + 1] == 1) ++vecinos;
       if(tablero[fila][columna - 1] == 1) ++vecinos;
       if(tablero[fila + 1][columna + 1] == 1) ++vecinos;
       if(tablero[fila + 1][columna - 1] == 1) ++vecinos;
    }

    // Borde inferior horizontal (no esquinas)
    else if(fila == filas - 1 && (columna != 0 || columna != columnas - 1)){
        if(tablero[fila - 1][columna] == 1) ++vecinos;
        if(tablero[fila][columna + 1] == 1) ++vecinos;
        if(tablero[fila][columna - 1] == 1) ++vecinos;
        if(tablero[fila - 1][columna + 1] == 1) ++vecinos;
        if(tablero[fila - 1][columna - 1] == 1) ++vecinos;
    }

    // Borde izquierdo vertical (no esquinas)
    else if(columna == 0 && (filas != 0 || filas != filas - 1)){
        if(tablero[fila - 1][columna] == 1) ++vecinos;
        if(tablero[fila + 1][columna] == 1) ++vecinos;
        if(tablero[fila][columna + 1] == 1) ++vecinos;
        if(tablero[fila + 1][columna + 1] == 1) ++vecinos;
        if(tablero[fila - 1][columna + 1] == 1) ++vecinos;
    }

    // Borde derecho vertical (no esquinas)
    else if(columna == columnas - 1 && (filas != 0 || filas != filas - 1)){
        if(tablero[fila - 1][columna] == 1) ++vecinos;
        if(tablero[fila + 1][columna] == 1) ++vecinos;
        if(tablero[fila][columna - 1] == 1) ++vecinos;
        if(tablero[fila + 1][columna + 1] == 1) ++vecinos;
        if(tablero[fila + 1][columna - 1] == 1) ++vecinos;
    }

    // Interior de tablero
    else{
        if(tablero[fila - 1][columna] == 1) ++vecinos;
        if(tablero[fila+1][columna] == 1) ++vecinos;
        if(tablero[fila][columna-1] == 1) ++vecinos;
        if(tablero[fila][columna+1] == 1) ++vecinos;
        if(tablero[fila+1][columna+1] == 1) ++vecinos;
        if(tablero[fila-1][columna+1] == 1) ++vecinos;
        if(tablero[fila+1][columna-1] == 1) ++vecinos;
        if(tablero[fila-1][columna-1] == 1) ++vecinos;
    }

    return vecinos;
}
