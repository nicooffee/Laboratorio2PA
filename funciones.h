/**--------------------------------------------CONSTANTES GLOBALES----------------------------------------------------**/
#define LARGONODOHEAP 65536 //Largo de cada arreglo en un nodo heap. SOLO POTENCIAS DE 2.
/**------------------------------------------------ESTRUCTURAS--------------------------------------------------------**/
struct Heap{
	double *datos;
	int t;
	struct Heap *sig;
	struct Heap *ant;
};
struct Arbol{
	double valor;
	struct Arbol *izq;
	struct Arbol *der; 
};
/**----------------------------------------------FIN ESTRUCTURAS-------------------------------------------------------**/

long abrirArchivoArreglo(double **arreglo,FILE *archivo);
void abrirArchivoArbol(struct Arbol **arbol);
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

void imprimirArreglo(double *arreglo,long largo);
int estaOrdenado(double *arreglo,long largo);