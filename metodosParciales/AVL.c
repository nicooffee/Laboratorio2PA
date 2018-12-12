#include<stdio.h> 
#include<stdlib.h> 
/*
int Altura(struct NodoAvl *nodo);
int max(int a, int b);
void DestruirArbol(struct NodoAvl *raiz);
struct NodoAvl *InicializarNodo(double valor);
struct NodoAvl *rotarDerecha(struct NodoAvl *b);
struct NodoAvl *rotarIzquierda(struct NodoAvl *a);
int Nivel(struct NodoAvl *nodo);
struct NodoAvl *insertarNodo(struct NodoAvl* nodo, double valor);
void MostrarInOrden(struct NodoAvl *raiz);
*/


struct NodoAvl{ 
	double valor; 
	struct NodoAvl *izq; 
	struct NodoAvl *der; 
	int altura; 
}; 
void DestruirArbol(struct NodoAvl *raiz){
	if (raiz == NULL){
		return;
	}
	DestruirArbol(raiz->izq);
	DestruirArbol(raiz->der);
	free(raiz);
}

int Altura(struct NodoAvl *nodo){ 
	if (nodo == NULL) 
		return 0; 
	else{
		return nodo->altura;
		} 
} 

int max(int a, int b){
	if (a>b) return a;
	else return b;
};


struct NodoAvl *InicializarNodo(double valor){
	struct NodoAvl* nodo = (struct NodoAvl*)malloc(sizeof(struct NodoAvl)); 
	nodo->valor = valor; 
	nodo->izq = NULL; 
	nodo->der = NULL; 
	nodo->altura = 1; 
	return(nodo); 
} 


struct NodoAvl *rotarDerecha(struct NodoAvl *b){

	struct NodoAvl *a = b->izq; 
	struct NodoAvl *hoja = a->der; 
	a->der = b; 
	b->izq = hoja; 
	b->altura = max(Altura(b->izq), Altura(b->der)) + 1; 
	a->altura = max(Altura(a->izq), Altura(a->der)) + 1; 

	return a; 
} 


struct NodoAvl *rotarIzquierda(struct NodoAvl *a){ 
	struct NodoAvl *b = a->der; 
	struct NodoAvl *hoja = b->izq; 

	b->izq = a; 
	a->der = hoja; 
 
	a->altura = max(Altura(a->izq), Altura(a->der)) + 1; 
	b->altura = max(Altura(b->izq), Altura(b->der)) + 1; 

	return b; 
} 


int Nivel(struct NodoAvl *nodo){
	if (nodo == NULL) return 0;
	else{
		return (Altura(nodo->izq) - Altura(nodo->der));
	} 
	 
} 


struct NodoAvl *insertarNodo(struct NodoAvl* nodo, double valor){ 

	if (nodo == NULL){
		return(InicializarNodo(valor));
	}	 
	if (valor < nodo->valor){
		nodo->izq = insertarNodo(nodo->izq, valor);
	}	 
	else if (valor > nodo->valor){
		nodo->der = insertarNodo(nodo->der, valor);
	} 	 
	else return nodo; 

	nodo->altura = 1 + max(Altura(nodo->izq), Altura(nodo->der));
	int balance = Nivel(nodo); 
 
	if ((balance > 1) && (valor < nodo->izq->valor)){
		return rotarDerecha(nodo);
	} 
	if ((balance < -1) && (valor > nodo->der->valor)){
		return rotarIzquierda(nodo);
	}
	if ((balance > 1) && (valor > nodo->izq->valor)){ 
		nodo->izq = rotarIzquierda(nodo->izq); 
		return rotarDerecha(nodo); 
	} 
	if ((balance < -1) && (valor < nodo->der->valor)){ 
		nodo->der = rotarDerecha(nodo->der); 
		return rotarIzquierda(nodo); 
	} 

	return nodo; 
} 

 
void MostrarInOrden(struct NodoAvl *raiz){ 
	if(raiz != NULL){  
		MostrarInOrden(raiz->izq);
		printf("%lf \n", raiz->valor); 
		MostrarInOrden(raiz->der); 
	} 
} 


int main(){ 
	double Arreglo[] = {10,14,20,43,12,30,25,32};
	struct NodoAvl *raiz = NULL; 
	for (int i = 0; i < 8; ++i){
		raiz = insertarNodo(raiz,Arreglo[i]);
	}
	MostrarInOrden(raiz); 
	return 0; 
} 
