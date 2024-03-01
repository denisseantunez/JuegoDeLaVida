
#include "Utileria.hpp"


/*****************************************************************************/

float CapturarEntero(const char solicitud[])
{
    float x;
    cout << solicitud;
    cin >> x;

    while (cin.fail() || x != (int)x) {
        cout << "Error: valor no v\240lido, se espera un entero";
        if (cin.fail()) {
            cout << ", se espera un n\243mero" << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
        else {
            cout << endl;
        }
        cout << solicitud;
        cin >> x;
    }
    return x;
}

/*****************************************************************************/
