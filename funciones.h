/**------------------------------------------------ESTRUCTURAS--------------------------------------------------------**/
struct Arbol{
	float valor;
	struct Arbol *izq;
	struct Arbol *der; 
};
/**----------------------------------------------FIN ESTRUCTURAS-------------------------------------------------------**/

long abrirArchivoArreglo(float **arreglo,FILE *archivo);
void abrirArchivoArbol(struct Arbol **arbol);

void merge(float *arreglo,long inicio,long mitad,long final);
void mergeSort(float *arreglo,long inicio,long final);

int particion(float *arreglo,int menor,int mayor);
void quicksort(float *arreglo,int menor,int mayor);

void imprimirArreglo(float *arreglo,long largo);
int estaOrdenado(float *arreglo,long largo);