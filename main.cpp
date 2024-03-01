/*
Nombre: Juego de la vida de Conway
Descripción: Simulación de generaciones de bichos bajo ciertas reglas
Autor: Denisse Gabriela Antunez López
Fecha: Mayo 27, 2023
*/

#include <iostream>
#include <ctime>

#include "Tableros.hpp"
#include "Windows.hpp"
#include "Utileria.hpp"

#define MAX 50
#define MIN 2

using namespace std;

int main()
{
    WORD original = ObtenerColorOriginal();
    EstablecerColor(NEGRO, AMARILLOCLARO);

    cout << "Juego de la vida de Conway" << endl;
    cout << "Presione <ENTER> para visualizar la nueva generaci\242n, presione <ESC> para terminar el juego" << endl << endl;

    int ** tablero_1 = nullptr;
    int ** tablero_2 = nullptr;

    int filas, columnas;
    do{
        filas = CapturarEntero("Ingrese el n\243mero de filas del tablero (min 2, max 50): ");
        columnas = CapturarEntero("Ingrese el n\243mero de columnas del tablero (min 2, max 50): ");
        if(filas < MIN || filas > MAX) cout << "Error, n\243mero de filas no v\240lido" << endl;
        if(columnas < MIN || columnas > MAX) cout << "Error, n\243mero de columnas no v\240lido" << endl;
    }while(filas < MIN || filas > MAX || columnas < MIN || columnas > MAX);

    try{
        tablero_1 = Crear(filas, columnas);
        tablero_2 = Crear(filas, columnas);

        // Generación inicial al azar
        srand(time(NULL));
        for(int i = 0; i < filas; ++i){
            for(int j = 0; j < columnas; ++j)
                tablero_1[i][j] = rand() % 2;
        }

        MoverCursor(6, 6);
        CambiarCursor(APAGADO);
        char tecla;

        while(true){
            if(_kbhit){
                tecla = _getch();
                if(tecla == ESCAPE) break;
                else if(tecla == ENTER){
                    ImprimirTablero(tablero_1, filas, columnas);
                    if(_kbhit){
                        tecla = _getch();
                        if(tecla == ESCAPE) break;
                        else if(tecla == ENTER){
                            ReglasDeVida(tablero_1, tablero_2, filas, columnas);
                            ImprimirTablero(tablero_2, filas, columnas);
                            ReglasDeVida(tablero_2, tablero_1, filas, columnas);
                        }
                    }
                }
            }
        }

        Destruir(tablero_1);
        Destruir(tablero_2);

    }catch(const bad_alloc &){
        cerr << "Error en la asignaci\242n de memoria" << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado" << endl;
    }

    system("pause");
    EstablecerColor(original);
    CambiarCursor(ENCENDIDO);
    return 0;
}
