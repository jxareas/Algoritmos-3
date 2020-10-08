//============================================================================
// Name        : grafoEvaluativo.cpp
// Author      : EMIT
// Version     :
// Copyright   : Your copyright notice
// Description : Construccion de un grafo que describe el tiempo de vuelo entre ciudades
//============================================================================

#include <iostream>
using namespace std;


char opc;
char volver;
char valor;

struct nodo {
	string pais;
	struct nodo *next;
	struct arista *ady;
};

typedef struct nodo *Tnodo;
Tnodo puntero;

struct arista {
	int horas;
	struct nodo *destino;
	struct arista *next;
};

typedef struct arista *Tarista;

void insertar_nodo(string dato){
	Tnodo t,nuevo = new struct nodo;
	nuevo->pais = dato;
	nuevo->next = NULL;
	nuevo->ady = NULL;

	if(puntero == NULL){
		puntero = nuevo;
	}else{
		t=puntero;
		while(t->next!=NULL){
			t = t->next;
		}
		t->next=nuevo;
	};
}

void agregar_arista(Tnodo &aux1, Tnodo &aux2, Tarista &nuevo){
	Tarista q;
	if(aux1->ady==NULL){
		aux1->ady=nuevo;
		nuevo->destino=aux2;
	}
	else{
		q=aux1->ady;
		while(q->next!=NULL){
			q=q->next;
		};
		nuevo->destino=aux2;
		q->next=nuevo;
	};
}

void ingresarAristas(string origen, string destino, int time){
	Tarista nuevo = new struct arista;
	Tnodo aux1, aux2;
	if(puntero == NULL){
		cout<<"No hay grafo."<<endl;
		return;
	};
	nuevo->horas = time;
	nuevo->next=NULL;
	aux1 = puntero;
	aux2 = puntero;
	while(aux2!=NULL){
		if(aux2->pais==destino){
			break;
		}
		aux2=aux2->next;
	};
	while(aux1 != NULL){
		if(aux1->pais==origen){
			agregar_arista(aux1, aux2, nuevo);
			return;
		}
		aux1 = aux1->next;
	 };

}

void mostrar_grafo(){
	Tnodo ptr;
	Tarista ar;
	ptr=puntero;

	cout<<"Nodo : Adyacencia"<<endl;

	while(ptr!=NULL){

		cout<<"   "<<ptr->pais<<"|";

		if(ptr->ady!=NULL){
			ar=ptr->ady;

			while(ar!=NULL){
				cout<<" "<<ar->destino->pais<<" // Duración de viaje: "<<ar->horas<<" horas."<<endl;
				ar=ar->next;
			};

		};

		ptr=ptr->next;
		cout<<endl;
	};
}


int main() {
	int longitud;
	string paises[] = {"Coruña", "Bilbao", "Barcelona", "Madrid", "Murcia", "Sevilla"};
	int cantAristas[6] = {2, 3, 3, 5, 1, 3};
	string destino, origen;
	int duracion;
	string conexiones[6][5] = {
			{"Bilbao", "Madrid"},
			{"Coruña", "Madrid", "Barcelona"},
			{"Bilbao", "Madrid", "Sevilla"},
			{"Coruña", "Bilbao", "Barcelona", "Murcia", "Sevilla"},
			{"Madrid"},
			{"Bilbao", "Madrid", "Barcelona"}
	};

	int horarios[6][5] = {
			{2, 2},
			{2, 1, 3},
			{3, 1, 3},
			{2, 1, 1, 6, 2},
			{6},
			{4, 2, 3}
	};

	longitud= sizeof(paises) / sizeof(*paises);

	for(int x = 0; x < longitud; x++){
		insertar_nodo(paises[x]);
	};


	for(int y = 0; y < longitud; y++){
		for(int z = 0; z < cantAristas[y]; z++){
			origen = paises[y];
			destino = conexiones[y][z];
			duracion = horarios[y][z];
			ingresarAristas(origen, destino, duracion);
		};
	};

	mostrar_grafo();

	return 0;
}
