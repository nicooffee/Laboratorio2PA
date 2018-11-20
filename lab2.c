#include <stdio.h>
#include <stdlib.h>
struct Arbol{
	double valor;
	struct Arbol *izq;
	struct Arbol *der; 
}

long abrirArchivoArreglo(double **arreglo);
void abrirArchivoArbol(struct Arbol **arbol);

int main(){
	double *arreglo=NULL;
	long largo;
	long i=0;
	largo=abrirArchivoArreglo(&arreglo);
	for(;i<largo;i++)
		printf("%.3le ",arreglo[i]);
	printf("%li\n",largo);
	free(arreglo);
	return 0;
}

long abrirArchivoArreglo(double **arreglo){
	FILE *archivo=fopen("archivo3.tex","r");
	long largo=0;
	long largo2=2;
	free(*arreglo);
	*(arreglo)=(double*) calloc(largo2,sizeof(double));
	while(fscanf(archivo,"%le",&((*arreglo)[largo++]))!=EOF)
		if(largo==largo2)
			*(arreglo)=(double*) realloc(*(arreglo),(largo2*=2)*sizeof(double));
	*(arreglo)=(double *) realloc(*(arreglo),(largo-1)*sizeof(double));
	fclose(archivo);
	return --largo;
}

void abrirArchivoArbol(struct Arbol **arbol){

}