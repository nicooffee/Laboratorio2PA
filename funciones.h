/**------------------------------------------------ESTRUCTURAS--------------------------------------------------------**/
struct Arbol{
	double valor;
	struct Arbol *izq;
	struct Arbol *der; 
};
/**----------------------------------------------FIN ESTRUCTURAS-------------------------------------------------------**/

long abrirArchivoArreglo(double **arreglo,FILE *archivo);
void abrirArchivoArbol(struct Arbol **arbol);

void merge(double *arreglo,long inicio,long mitad,long final);
void mergeSort(double *arreglo,long inicio,long final);

int particion(double *arreglo,int menor,int mayor);
void quicksort(double *arreglo,int menor,int mayor);

void imprimirArreglo(double *arreglo,long largo);
int estaOrdenado(double *arreglo,long largo);