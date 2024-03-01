
#include "Windows.hpp"


/*************************************************************************************************************************/

void MoverCursor(SHORT x, SHORT y)
{
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*************************************************************************************************************************/

void EstablecerColor(WORD colorEst)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorEst);
}

/*************************************************************************************************************************/

void EstablecerColor(Color colorFondo, Color colorTexto)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorFondo * 16 + colorTexto);
}

/*************************************************************************************************************************/

WORD ObtenerColorOriginal()
{
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO* ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
    GetConsoleScreenBufferInfo(hConsoleHandle, ConsoleInfo);
    WORD original = ConsoleInfo->wAttributes;
    delete ConsoleInfo;
    return original;
}

/*************************************************************************************************************************/

void CambiarCursor(EstadoCursor estado, ModoCursor modo /* = NORMAL*/)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info = {modo,estado};
	SetConsoleCursorInfo(consoleHandle, &info);
}

/*************************************************************************************************************************/
