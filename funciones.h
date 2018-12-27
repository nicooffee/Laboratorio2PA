/**--------------------------------------------CONSTANTES GLOBALES----------------------------------------------------**/
#define LARGONODOHEAP 16 //Largo de cada arreglo en un nodo heap. SOLO POTENCIAS DE 2.
/**------------------------------------------------ESTRUCTURAS--------------------------------------------------------**/
/**
 * struct Heap:
 * 
 * Estructura que representa un montículo. Cada nodo de la lista enlazada es un arreglo de largo LARGONODOHEAP.
 * Cada posicion menor o igual a n/2 es un pariente y las siguientes a n/2 son hojas. Cada pariente en k tiene a sus
 * hijos en las posiciones 2k y 2k+1.
 */
struct Heap{
	double *datos;
	int t;
	struct Heap *sig;
	struct Heap *ant;
};
struct NodoAvl{ 
	double valor; 
	struct NodoAvl *izq; 
	struct NodoAvl *der; 
	int altura; 
};
/**----------------------------------------------FIN ESTRUCTURAS-------------------------------------------------------**/


long abrirArchivoArreglo(double **arreglo,FILE *archivo);
/**----------------------------------------------BLOQUE MERGESORT-----------------------------------------------------**/
void merge(double *arreglo,long inicio,long mitad,long final);
void mergeSort(double *arreglo,long inicio,long final);
/**--------------------------------------------FIN BLOQUE MERGESORT---------------------------------------------------**/


/**----------------------------------------------BLOQUE QUICKSORT-----------------------------------------------------**/
int particion(double *arreglo,int menor,int mayor);
void quicksort(double *arreglo,int menor,int mayor);
void swapf(double* a, double* b);
/**--------------------------------------------FIN BLOQUE QUICKSORT---------------------------------------------------**/


/**-----------------------------------------------BLOQUE HEAPSORT-----------------------------------------------------**/
struct Heap *crearHeap();
void abrirArchivoHeap(struct Heap **h, FILE *archivo);
void mostrarArregloHeap(struct Heap *h);
long largoHeap(struct Heap *h);
void liberarHeap(struct Heap **h);
void monticular(struct Heap *h);
double *getValor(struct Heap *h,long p);
int heapOrdenado(struct Heap *h);
void heapSort(struct Heap *h);
/**---------------------------------------------FIN BLOQUE HEAPSORT---------------------------------------------------**/


/**--------------------------------------------------BLOQUE AVL-------------------------------------------------------**/
int Altura(struct NodoAvl *nodo);
int max(int a, int b);
struct NodoAvl *InicializarNodo(double valor);
struct NodoAvl *rotarDerecha(struct NodoAvl *b);
struct NodoAvl *rotarIzquierda(struct NodoAvl *a);
int Nivel(struct NodoAvl *nodo);
struct NodoAvl *insertarNodo(struct NodoAvl* nodo, double valor);
void MostrarInOrden(struct NodoAvl *raiz);
long crearAvlArchivo(struct NodoAvl **avl, FILE *archivo);
void liberarAVL(struct NodoAvl **avl);
/**------------------------------------------------FIN BLOQUE AVL-----------------------------------------------------**/


/**----------------------------------------BLOQUE INTERCAMBIO TIEMPO-MEMORIA------------------------------------------**/
void ordenarPorConteo(double **A,long l);
/**--------------------------------------FIN BLOQUE INTERCAMBIO TIEMPO-MEMORIA----------------------------------------**/


/**--------------------------------------------BLOQUE ESTADÍSTICA BÁSICA----------------------------------------------**/
double mediana(double *A,long L);
double *cuartiles(double *A,long L);
double valorMasRepetido (double *A, long L);
long cantidadValDistintos(double *A,long L);
/**------------------------------------------FIN BLOQUE ESTADÍSTICA BÁSICA--------------------------------------------**/


void imprimirArreglo(double *arreglo,long largo);
int estaOrdenado(double *arreglo,long largo);