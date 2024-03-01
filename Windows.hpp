#ifndef WINDOWS_HPP_INCLUDED
#define WINDOWS_HPP_INCLUDED

#include <windows.h>
#include <conio.h>

/*****************************************************************************/

/** S�mbolos de colores **/
enum Color {
    NEGRO,          /**< Color negro */
    AZUL,           /**< Color azul fuerte */
    VERDE,          /**< Color verde oscuro */
    AGUAMARINA,     /**< Color azul verde */
    ROJO,           /**< Color rojo oscuro */
    PURPURA,        /**< Color morado */
    AMARILLO,       /**< Color amarillo */
    GRISCLARO,      /**< Color gris claro */
    GRIS,           /**< Color gris oscuro */
    AZULCLARO,      /**< Color azul cielo */
    VERDECLARO,     /**< Color verde claro */
    AGUAMARINACLARO,/**< Color azul verde claro */
    ROJOCLARO,      /**< Color rojo claro */
    MAGENTA,        /**< Color rosa fuerte */
    AMARILLOCLARO,  /**< Color amarillo claro */
    BLANCO          /**< Color blanco */
};

/*****************************************************************************/

/** Posibles estados del cursor */
enum EstadoCursor{
	APAGADO,    /**< Cursor no visible */
	ENCENDIDO   /**< Cursor visible */
};

/*****************************************************************************/

/** Modos o tama�os del cursor */
enum ModoCursor{
	MINI = 1,       /**< Tama�o de cursor peque�o */
	NORMAL = 40,    /**< Tama�o de cursor mediano  */
	SOLIDO = 80     /**< Tama�o de cursor grande */
};

/*****************************************************************************/

/** Tecla **/
#define ESCAPE 27
#define ENTER 13

/*****************************************************************************/

/** Funci�n que mueve el cursor en la consola **/
void MoverCursor(short x, short y);

/*****************************************************************************/

/** Funciones de impresi�n de color en la consola **/
void EstablecerColor(WORD colorEst);
void EstablecerColor(Color colorFondo, Color colorTexto);
WORD ObtenerColorOriginal();

/*****************************************************************************/

/** Funci�n que cambia el estado y modo del cursor **/
void CambiarCursor(EstadoCursor estado, ModoCursor modo = NORMAL);

/*****************************************************************************/

#endif // WINDOWS_HPP_INCLUDED
