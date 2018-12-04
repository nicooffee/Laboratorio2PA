#include <stdio.h>
#include <stdlib.h>


struct Heap{
	double *datos;
	int t;
	struct Heap *sig;
};
struct Heap *crearHeap();
void abrirArchivoHeap(struct Heap **h, FILE *archivo);
void mostrarArregloHeap(struct Heap *h);
long largoHeap(struct Heap *h);
int main(){
	FILE *archivo=fopen("../archivos/archivo0.tex","r");
	struct Heap *h;
	long largo;
	abrirArchivoHeap(&h,archivo);
	largo=largoHeap(h);
	mostrarArregloHeap(h);
	printf("\n%li ",largo);
	fclose(archivo);
	return 0;
}

struct Heap *crearHeap(){
	struct Heap *h=(struct Heap*) calloc(1,sizeof(struct Heap));
	h->datos=(double*) calloc(1,sizeof(double));
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
		if(it->t==1024 && i==it->t){
			it->sig=crearHeap();
			it=it->sig;
			i=0;
		}
		if(i==it->t)
			it->datos=(double*) realloc(it->datos,((it->t)*=2)*sizeof(double));
	}
	if(i<it->t-1){
		it->datos=(double *) realloc((it->datos),(i-1)*sizeof(double));
		it->t=i-1;
	}
	return;
}
void mostrarArregloHeap(struct Heap *h){
	struct Heap *it=h;
	int i=0;
	while(it!=NULL){
		printf("%le ",it->datos[i++]);
		if(i==it->t){
			i=0;
			it=it->sig;
		}
	}
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