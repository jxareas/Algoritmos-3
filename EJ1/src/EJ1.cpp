//============================================================================
// Name        : EJ1.cpp
// Author      : FJ
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "string.h"
#include "stdio.h"
#include "memory.h"
#include "iostream"

using namespace std;

struct nodo {
	char descrip[50];
	struct nodo *lptr;
	struct nodo *rptr;
};

struct nodo *Root;

void CreaNodo(struct nodo *n, int bDirecc)
{
	struct nodo *n1;	 // Nuevo nodo
	char descPadre[50];
	char flecha[20];

	n1 = (struct nodo *)malloc(sizeof(struct nodo));
	n1->lptr = NULL;
	n1->rptr = NULL;

	strcpy(flecha, "");
	if (bDirecc==1) strcpy(flecha, "izquierda de");
	else if (bDirecc==2) strcpy(flecha, "derecha de");
	strcpy(descPadre, "");
	if (n == NULL) strcpy(descPadre, "Raiz");
	else strcpy(descPadre, n->descrip);
	cout << "Por favor ingrese el valor del nodo " << flecha << " " << descPadre << " (palabra nulo para no agregar):\n";
	cin >> n1->descrip;
	if (strcmp(n1->descrip, "nulo")==0) {
		delete(n1);
		return;
	}

	if (n == NULL) Root =  n1;
	else {
		if (bDirecc==1) n->lptr = n1;
		if (bDirecc==2) n->rptr = n1;
	}
	CreaNodo(n1, 1); // izquierda
	CreaNodo(n1, 2); // derecha
}

void MuestraArbol(struct nodo *n, int nivel)
{
	char Snivel[20];
	int i;

	if (n==NULL)
		return;

	if (nivel > 0 ) {
		for (i=0; i < nivel; i++)
			cout << "\t";
	}
	cout << n->descrip << "\n";
	MuestraArbol(n->lptr, nivel+1);
	MuestraArbol(n->rptr, nivel+1);
}

int main(int argc, char* argv[])
{
	char ch[10];

	CreaNodo(NULL, 0);

	cout << "\n\n *** Arbol en preorden ***\n\n";
	MuestraArbol(Root, 0);

	cout << "\nPresione una letra y ENTER para continuar...";
	cin >> ch;
	cout << "\n\n";
	return 0;
}

