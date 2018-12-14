/**--------------------------------------------CONSTANTES GLOBALES----------------------------------------------------**/
#define LARGONODOHEAP 65536 //Largo de cada arreglo en un nodo heap. SOLO POTENCIAS DE 2.
/**------------------------------------------------ESTRUCTURAS--------------------------------------------------------**/
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
void DestruirArbol(struct NodoAvl *raiz);
struct NodoAvl *InicializarNodo(double valor);
struct NodoAvl *rotarDerecha(struct NodoAvl *b);
struct NodoAvl *rotarIzquierda(struct NodoAvl *a);
int Nivel(struct NodoAvl *nodo);
struct NodoAvl *insertarNodo(struct NodoAvl* nodo, double valor);
void MostrarInOrden(struct NodoAvl *raiz);
long crearAvlArchivo(struct NodoAvl **avl, FILE *archivo);
void liberarAVL(struct NodoAvl **avl);
/**------------------------------------------------FIN BLOQUE AVL-----------------------------------------------------**/

void imprimirArreglo(double *arreglo,long largo);
int estaOrdenado(double *arreglo,long largo);