#include <stdio.h>
#include <stdlib.h>
#define LARGONODOHEAP 65536

struct Heap{
	double *datos;
	int t;
	struct Heap *sig;
	struct Heap *ant;
};

struct Heap *crearHeap();
void abrirArchivoHeap(struct Heap **h, FILE *archivo);
void mostrarArregloHeap(struct Heap *h);
long largoHeap(struct Heap *h);
void liberarHeap(struct Heap **h);
void monticular(struct Heap *h);
double *getValor(struct Heap *h,long p);
int heapOrdenado(struct Heap *h);
void heapSort(struct Heap *h);

int main(){
	FILE *archivo=fopen("../archivos/archivo3b.tex","r");
	struct Heap *h;
	long largo;
	abrirArchivoHeap(&h,archivo);
	largo=largoHeap(h);
	printf("\n%li\n",largo);
	heapSort(h);
	printf("\nordenado: %d",heapOrdenado(h));
	fclose(archivo);
	liberarHeap(&h);
	return 0;
}
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