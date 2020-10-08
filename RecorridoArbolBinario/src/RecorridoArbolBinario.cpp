//============================================================================
// Name        : RecorridoArbolBinario.cpp
// Author      : Jonathan Javier Areas
// Version     :
// Copyright   : N.A.
// Description : Recorre el arbol binario
//============================================================================
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    struct Nodo *der;
    struct Nodo *izq;
};

Nodo *arbol = nullptr;

Nodo *crearNodo(int n) {
    Nodo * nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->der = nullptr;
    nuevoNodo->izq = nullptr;

    return nuevoNodo;
}

void insertar (Nodo *&arbol, int n) {
    if (arbol == nullptr) {
        Nodo *nuevoNodo = crearNodo(n);
        arbol = nuevoNodo;
    } else {
        int valorRaiz = arbol->dato;
        (n < valorRaiz) ? insertar(arbol->izq, n) : insertar(arbol->der, n);
    }
}

void mostrar(Nodo *arbol, int cont) {
    if (arbol == nullptr) {
        return;
    } else {
        mostrar(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++) {
            cout << "           ";
        }
        cout << arbol->dato << endl;
        mostrar(arbol->izq, cont + 1);
    }
}

void menu() {
    int dato{}, opcion{}, cont{};
    do {
        cout << "/t MENU:" << endl;
        cout << "1. Insertar un nuevo elemento." << endl;
        cout << "2. Mostrar Arbol." << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Inserte un numero: " << endl;
                cin >> dato;
                insertar(arbol, dato);
                break;
            case 2:
                cout << "Mostrando el arbol completo: \n\n" << endl;
                mostrar(arbol, cont);
                cout << endl;
                system("pause");
                break;
            default:
                cout << "Opcion Invalida. Intentelo de Nuevo." << endl;
        }
        system("cls");
    } while (opcion != 3);
}

int main () {
    menu();
    return 0;
}
