#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
/**-------------------------------------------------FUNCIONES---------------------------------------------------------**/

/**
 * abrirArchivoArreglo:
 * 
 * Función que recibe una referencia a un arreglo de tipo double, al cual se le asigna memoria para guardar los datos
 * del archivo.
 * 
 * Retorna el largo final del arreglo.
 */
long abrirArchivoArreglo(double **arreglo,FILE *archivo){
	long largo=0;
	long largo2=2;
    if(*arreglo!=NULL)
        free(*arreglo);
    rewind(archivo);
	*(arreglo)=(double*) calloc(largo2,sizeof(double));
	while(fscanf(archivo,"%le",&((*arreglo)[largo++]))!=EOF)
		if(largo==largo2)
			*(arreglo)=(double*) realloc(*(arreglo),(largo2*=2)*sizeof(double));
	*(arreglo)=(double *) realloc(*(arreglo),(largo-1)*sizeof(double));
	return --largo;
}





/**----------------------------------------------BLOQUE MERGESORT-----------------------------------------------------**/
/**
 * merge: 
 * 
 * Función que recibe un arreglo, dos indices limite y la mitad entre ellos. Genera dos arreglos A y B, los cuales se
 * llenan con los valores correspondientes a [inicio,mitad] y [mitad+1,final] del arreglo, respectivamente.
 * 
 * Se mezclan ambos arreglos con el criterio menor o igual y se reemplazan en las posiciones [inicio,final] del arreglo.
 */
void merge(double *arreglo,long inicio,long mitad,long final){
    long i=0,j=0,k=inicio,lA=(mitad-inicio+1),lB=(final-mitad);
    double *A=NULL,*B=NULL;
    A=(double*) calloc(lA,sizeof(double));
    B=(double*) calloc(lB,sizeof(double));
    while(i++<lA)
        A[i-1]=arreglo[inicio+(i-1)];
    while(j++<lB)
        B[j-1]=arreglo[mitad+1+(j-1)];
    i=j=0;
    while(i<lA && j<lB)
        if(A[i]<=B[j])
            arreglo[k++]=A[i++];
        else   
            arreglo[k++]=B[j++];
    while(i<lA)
        arreglo[k++]=A[i++];
    while(j<lB)
        arreglo[k++]=B[j++];
    free(A);
    free(B);
    return;
}




/**
 * mergeSort:
 * 
 * Funcion recursiva que recibe un arreglo y calcula la mitad correspondiente con los valores
 * inicio y final enviados por parametro. Se llama a si misma dos veces, dividiendo el intervalo
 * [inicio,final] en [inicio,mitad] y [mitad+1,final]. Luego, llama a la funcion merge para
 * mezclar ambas partes.
 */
void mergeSort(double *arreglo,long inicio,long final){
    long mitad=(inicio+final)/2;
    long i=0;
    if(inicio==final)
        return;
    else if(inicio==final-1){
        if(arreglo[inicio]>arreglo[final])
            arreglo[inicio]=(arreglo[inicio]+arreglo[final])-(arreglo[final]=arreglo[inicio]);
        return;
    }
    else if(inicio<mitad && mitad<final){
        mergeSort(arreglo,inicio,mitad);
        mergeSort(arreglo,mitad+1,final);
        merge(arreglo,inicio,mitad,final);
    }
    return;
}





/**--------------------------------------------FIN BLOQUE MERGESORT---------------------------------------------------**/




/**----------------------------------------------BLOQUE QUICKSORT-----------------------------------------------------**/
void swapf(double* a, double* b) { 
    double t = *a; 
    *a = *b; 
    *b = t; 
}





/**
 * particion: 
 * 
 * Función que recibe el arreglo junto con 2 índices que serían los límites
 * para realizar la partición de este, escogiendo el mayor como pivote. La función tambien se encarga de realizar los swap
 * correspondientes dentro de la partición al recorrerla.
 */ 
int particion(double *arreglo,int menor, int mayor ){

	double pivote = arreglo[mayor];
	int auxMenor = (menor -1);

	for (int i = menor; i <= mayor-1; i++){

		if (arreglo[i] <= pivote){

			auxMenor++;
			swapf(&(arreglo[auxMenor]),&(arreglo[i]));
		}
	}
	swapf(&(arreglo[auxMenor+1]),&(arreglo[mayor]));
	return (auxMenor + 1);
}





/**
 * quicksort: 
 * 
 * Función que recibe el arreglo a ordenar, y de manera recursiva se encarga de llamar a la 
 * función particion para así ordenar todo el arreglo (recursion de cola).
 *
 */ 
void quicksort(double *arreglo,int menor,int mayor){
    while (menor < mayor){
        int part = particion(arreglo, menor, mayor);

        if ((part - menor)<(part - mayor)){
            quicksort(arreglo, menor, part-1);
            menor = part + 1;
        }
        else{
            quicksort(arreglo, part + 1, mayor);
            mayor = part - 1;
        }
        
    }
}
/**--------------------------------------------FIN BLOQUE QUICKSORT---------------------------------------------------**/

/**-----------------------------------------------BLOQUE HEAPSORT-----------------------------------------------------**/
/**
 * heapSort:
 * 
 * Función que recibe un stuct Heap con datos. Lo monticula y luego intercambia en un ciclo el valor que está al final
 * de la estructura con el primero. Remonticula el después del intercambio si es necesario.
 */
void heapSort(struct Heap *h){
	long largo=largoHeap(h);
	long mitad=largo/2;
	long i=largo-1,j,k;
	int heap;
	double vi,vj;
	monticular(h);
	while(i>0){
		i=largo-1;
		j=0;
		vi=*(getValor(h,i));
		vj=*(getValor(h,j));
		*(getValor(h,i))=vj;
		*(getValor(h,j))=vi;
		heap=0;
		largo--;
		k=2*j;
		while(heap==0 && (k)<largo){
			if(k<largo-1)
				if(*(getValor(h,k))<*(getValor(h,k+1)))
					k++;
			if(vi>=*(getValor(h,k)))
				heap=1;
			else{
				(*(getValor(h,j)))=*(getValor(h,k));
				j=k;
			}
			k=2*j;
		}
		*(getValor(h,j))=vi;
	}
}




/**
 * monticular:
 * 
 * Función que monticula un struct Heap. Utiliza las restricciones de la estructura explicados
 * en el archivo funciones.h
 */
void monticular(struct Heap *h){
	long largo=largoHeap(h);
	long i,j,k;
	long aux;
	double v;
	int heap;
	struct Heap *aux1,*it=h;
	if(h!=NULL){
		for(i=largo/2;i>=0;i--){
			k=i;
			aux1=h;
			heap=0;
			v=*(getValor(h,k));
			j=2*k;
			while(heap==0 && (j)<largo){
				if(j<largo-1)
					if(*(getValor(h,j))<*(getValor(h,j+1)))
						j++;
				if(v>=*(getValor(h,j)))
					heap=1;
				else{
					*(getValor(h,k))=*(getValor(h,j));
					k=j;
				}
				j=2*k;
			}
			*(getValor(h,k))=v;
		}
	}	
}





/**
 * crearHeap:
 * 
 * Función que asigna memoria a un puntero struct Heap. Retorna el puntero nuevo.
 */
struct Heap *crearHeap(){
	struct Heap *h=(struct Heap*) calloc(1,sizeof(struct Heap));
	h->datos=(double*) calloc(1,sizeof(double));
	h->sig=h->ant=NULL;
	h->t=1;
	return h;
}





/**
 * abrirArchivoHeap:
 * 
 * Función que recibe un struct Heap y un archivo. reasigna la memoria del heap e itera
 * los valores del archivo, los cuales se guardan en la nueva estructura.
 */
void abrirArchivoHeap(struct Heap **h, FILE *archivo){
	int i=0;
	struct Heap *it;
	(*h)=crearHeap();
	it=(*h);
	rewind(archivo);
	while(fscanf(archivo,"%le",&((it->datos)[i++]))!=EOF){
		if(it->t==LARGONODOHEAP && i==it->t){
			it->sig=crearHeap();
			it->sig->ant=it;
			it=it->sig;
			i=0;
		}
		if(i==it->t)
			it->datos=(double*) realloc(it->datos,((it->t)*=2)*sizeof(double));
	}
	if(i<it->t-1)
		it->datos=(double *) realloc((it->datos),(it->t=i-1)*sizeof(double));
	return;
}





void mostrarArregloHeap(struct Heap *h){
	struct Heap *it=h;
	int i=0;
	while(it!=NULL){
		printf("%.3le ",it->datos[i++]);
		if(i==it->t){
			i=0;
			it=it->sig;
		}
	}
}





/**
 * getValor:
 * 
 * Función que itera h, hasta encontrar el valor de la posición p.
 * Si p es mayor a LARGONODOHEAP, se avanza al nodo siguiente, hasta que la diferencia de la
 * posición absoluta y p sea menor a LARGONODOHEAP.
 */
double *getValor(struct Heap *h,long p){
	long numNodo=0;
	while((p-(numNodo*LARGONODOHEAP))>=LARGONODOHEAP){
		h=h->sig;
		numNodo++;
	}
	return &(h->datos[(p-((numNodo)*LARGONODOHEAP))]);
}




/**
 * largoHeap:
 *  
 * Función que retorna el largo absoluto de un struct Heap.
 */
long largoHeap(struct Heap *h){
	long largo=0;
	struct Heap *it=h;
	while(it!=NULL){
		largo+=it->t;
		it=it->sig;
	}
	return largo;
}




/**
 * liberarHeap:
 * 
 * Función que recorre todo los nodos de un struct Heap mientras elimina todo el contenido
 * de cada nodo.
 */
void liberarHeap(struct Heap **h){
	struct Heap *aux=*h;
	while(*h!=NULL){
		aux=(*h)->sig;
		free((*h)->datos);
		free((*h));
		(*h)=aux;
	}
	(*h)=NULL;
    return;
}
	
/**
 * heapOrdenado:
 * 
 * Función que comprueba si todos los valores del struct Heap h están ordenados de menor a mayor.
 */
int heapOrdenado(struct Heap *h){
	long largo=largoHeap(h);
	int i=0;
	for(i=0;i<largo-1;i++)
		if(*(getValor(h,i))>*(getValor(h,i+1)))
			return 0;
	return 1;
}
/**---------------------------------------------FIN BLOQUE HEAPSORT---------------------------------------------------**/

/**-------------------------------------------------BLOQUE AVL--------------------------------------------------------**/






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
	return a>b?a:b;
}






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
 * crearAvlArchivo:
 * 
 * Función que recibe un nodo avl y guarda los valores del archivo recibido en este. Se hacen
 * los balances y ajustes para que el arbol sea un arbol AVL.
 * 
 * Se retorna la cantidad de elementos que posee el arbol.
 */
long crearAvlArchivo(struct NodoAvl **avl, FILE *archivo){
	long l=0;
	double aux;
	*avl=NULL;
	rewind(archivo);
	while(fscanf(archivo,"%le",&aux)!=EOF){
		*avl = insertarNodo(*avl,aux);
		l++;
	}
	return l-1;
}





/**
 * liberarAVL: 
 * 
 * Función que recibe una raiz de un arbol AVL y realiza free de cada nodo de este,
 * recorriendo el arbol en post-orden, para asi liberar toda la memoria.
 */ 
void liberarAVL(struct NodoAvl **avl){
	if(*avl!=NULL){
		liberarAVL(&((*avl)->izq));
		liberarAVL(&((*avl)->der));
		free(*avl);
		*avl=NULL;
	}
}





void MostrarInOrden(struct NodoAvl *raiz){ 
	if(raiz != NULL){  
		MostrarInOrden(raiz->izq);
		printf("%.3le \n", raiz->valor); 
		MostrarInOrden(raiz->der); 
	} 
}
/**-----------------------------------------------FIN BLOQUE AVL------------------------------------------------------**/

/**----------------------------------------BLOQUE INTERCAMBIO TIEMPO-MEMORIA------------------------------------------**/
void ordenarPorConteo(double **A,long l){
    unsigned int *conteo=(int *) calloc(l,sizeof(unsigned int));
    double *B=(double *) calloc(l,sizeof(double));
    int i=0,j;
    for(;i<l;i++)
        for(j=i+1;j<l;j++)
			(*A)[i]>=(*A)[j]?conteo[i]++:conteo[j]++; 
    for(i=0;i<l;i++)
        B[conteo[i]]=(*A)[i];
    free(conteo);
    free(*A);
    *A=B;
    return;
}   
/**--------------------------------------FIN BLOQUE INTERCAMBIO TIEMPO-MEMORIA----------------------------------------**/

/**--------------------------------------------BLOQUE ESTADÍSTICA BÁSICA----------------------------------------------**/
double mediana(double *A,long L){
	return L%2!=0?A[(L-1)/2]:(A[((L-1)/2)]+A[(L-1)/2+1])/2;
}
double *cuartiles(double *A,long L){
	double *cuar=(double *) calloc(3,sizeof(double));
	if((L-1)%2!=0){
		cuar[0]=(A[((int)(0.25*(L-1)))]+A[(int)(0.25*(L-1)+1)])/2;
		cuar[2]=(A[(int)(0.75*(L-1))]+A[(int)(0.75*(L-1)+1)])/2;
	}
	else{
		cuar[0]=A[(int)(0.25*(L-1))];
		cuar[2]=A[(int)(0.75*(L-1))];
	}
	cuar[1]=mediana(A,L);
	return cuar;
}
double valorMasRepetido (double *A, long L){
	long i=1;
	long max=1;
	long count=1;
	double valMR=A[0];
	for(;i<L;i++){
		if(A[i-1]==A[i])
			count++;
		else{
			if(count>max){
				max=count;
				valMR=A[i-1];
			}
			count=1;
		}
	}
	return valMR;
}
long cantidadValDistintos(double *A,long L){
	long count=1;
	long i=1;
	for(;i<L;i++)
		if(A[i-1]!=A[i])
			count++;
	return count;
}
/**------------------------------------------FIN BLOQUE ESTADÍSTICA BÁSICA--------------------------------------------**/
void imprimirArreglo(double *arreglo,long largo){
	long i=0;
	for(;i<largo;i++)
        printf("%.3le ",arreglo[i]);
}





int estaOrdenado(double *arreglo,long largo){
	long i=0;
	while(i<largo-1)
		if(arreglo[i++]>arreglo[i])
			return 0;
	return 1;
}
/**-----------------------------------------------FIN FUNCIONES-------------------------------------------------------**/