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
/**
 * DestruirArbol: 
 * 
 * Función que recibe una raiz de un arbol AVL y realiza free de cada nodo de este,
 * recorriendo el arbol en post-orden, para asi liberar toda la memoria.
 */ 
void DestruirArbol(struct NodoAvl *raiz){
	if (raiz == NULL){
		return;
	}
	DestruirArbol(raiz->izq);
	DestruirArbol(raiz->der);
	free(raiz);
}
/**
 * Altura: 
 * 
 * Función que recibe un nodo de tipo AVL y devuelve la altura de este, si este nodo no existe, la función retorna 0
 * 
 */
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

/**
 * InicializarNodo: 
 * 
 * Función que recibe un valor double, e iniciliza un nodo de tipo AVL con ese valor.
 * 
 */
struct NodoAvl *InicializarNodo(double valor){
	struct NodoAvl* nodo = (struct NodoAvl*)malloc(sizeof(struct NodoAvl)); 
	nodo->valor = valor; 
	nodo->izq = NULL; 
	nodo->der = NULL; 
	nodo->altura = 1; 
	return(nodo); 
} 

/**
 * rotarDerecha: 
 * 
 * Función que recibe un nodo de tipo AVL, y se encarga de realizar la rotación hacia la derecha 
 * cuando el nodo en cuestión esta desbalanceado. Posteriormente actualiza la altura de los nodos
 * que se usaron en la rotación.
 * 
 */

struct NodoAvl *rotarDerecha(struct NodoAvl *b){

	struct NodoAvl *a = b->izq; 
	struct NodoAvl *hoja = a->der; 
	a->der = b; 
	b->izq = hoja; 
	b->altura = max(Altura(b->izq), Altura(b->der)) + 1; 
	a->altura = max(Altura(a->izq), Altura(a->der)) + 1; 

	return a; 
} 

/**
 * rotarIzquierda: 
 * 
 * Función que recibe un nodo de tipo AVL, y se encarga de realizar la rotación hacia la izquierda 
 * cuando el nodo en cuestión esta desbalanceado. Posteriormente actualiza la altura de los nodos
 * que se usaron en la rotación. 
 */

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

/**
 * insertarNodo: 
 * 
 * Función que recibe un nodo de tipo AVL y lo inserta en el arbol, busca el lugar correspondiente recorriendo el arreglo de 
 * manera recursiva. Despues de insertar el nodo, al volver atras en las instancias de la función, verifica que los nodos esten
 * balanceados, en caso contrario realiza las rotaciones correspondientes. 
 */

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

/**
 * CrearArbol: 
 * 
 * Función que recibe un arreglo de tipo double y el tamaño de este, se leen todos los elementos del arreglo 
 * y se crea el arbol AVL a partir de estos.
 */

void CrearArbol(double arreglo, long largo){
	struct NodoAvl *raiz = NULL;
	for (int i = 0; i < largo; ++i){
		raiz = insertarNodo(raiz,arreglo[i]);
	}


//oli
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
