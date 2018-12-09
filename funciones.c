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





void abrirArchivoArbol(struct Arbol **arbol){

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
    while(i<lA)
        A[i]=arreglo[inicio+(i++)];
    while(j<lB)
        B[j]=arreglo[mitad+1+(j++)];
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

int particion(double *arreglo,int menor, int mayor ){

	double pivote = arreglo[mayor];
	int auxMenor = (menor -1);

	for (int i = menor; i <= mayor-1; i++){

		if (arreglo[i] <= pivote){

			auxMenor++;
            arreglo[auxMenor]=arreglo[auxMenor]+arreglo[i]-(arreglo[i]=arreglo[auxMenor]);
		}
	}
    arreglo[auxMenor+1]=arreglo[auxMenor+1]+arreglo[mayor]-(arreglo[mayor]=arreglo[auxMenor+1]);
	return (auxMenor + 1);
}






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
		while(heap==0 && (k=2*j)<largo){
			if(k<largo-1)
				if(*(getValor(h,k))<*(getValor(h,k+1)))
					k++;
			if(vi>=*(getValor(h,k)))
				heap=1;
			else
				*(getValor(h,j))=*(getValor(h,j=k));
		}
		*(getValor(h,j))=vi;
	}
}
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
			while(heap==0 && (j=2*k)<largo){
				if(j<largo-1)
					if(*(getValor(h,j))<*(getValor(h,j+1)))
						j++;
				if(v>=*(getValor(h,j)))
					heap=1;
				else
					*(getValor(h,k))=*(getValor(h,k=j));
			}
			*(getValor(h,k))=v;
		}
	}	
}
struct Heap *crearHeap(){
	struct Heap *h=(struct Heap*) calloc(1,sizeof(struct Heap));
	h->datos=(double*) calloc(1,sizeof(double));
	h->sig=h->ant=NULL;
	h->t=1;
	return h;
}

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
		printf("%.3lf ",it->datos[i++]);
		if(i==it->t){
			i=0;
			it=it->sig;
		}
	}
}
double *getValor(struct Heap *h,long p){
	long numNodo=-1;
	while((p-(++numNodo*LARGONODOHEAP))>=LARGONODOHEAP) h=h->sig;
	return &(h->datos[(p-(numNodo*LARGONODOHEAP))]);
}
long largoHeap(struct Heap *h){
	long largo=0;
	struct Heap *it=h;
	while(it!=NULL){
		largo+=it->t;
		it=it->sig;
	}
	return largo;
}
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
	

int heapOrdenado(struct Heap *h){
	long largo=largoHeap(h);
	int i=0;
	for(i=0;i<largo-1;i++)
		if(*(getValor(h,i))>*(getValor(h,i+1)))
			return 0;
	return 1;
}
/**---------------------------------------------FIN BLOQUE HEAPSORT---------------------------------------------------**/


void imprimirArreglo(double *arreglo,long largo){
	long i=0;
	for(;i<largo;i++)
        printf("%.3lf ",arreglo[i]);
}





int estaOrdenado(double *arreglo,long largo){
	long i=0;
	while(i<largo-1)
		if(arreglo[i++]>arreglo[i])
			return 0;
	return 1;
}
/**-----------------------------------------------FIN FUNCIONES-------------------------------------------------------**/