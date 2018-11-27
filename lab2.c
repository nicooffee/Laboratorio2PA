/*---------------------------------Tarea Programación Avanzada-Ordenamiento y busqueda--------------------------------**/
/************************************************************************************************************************
    Autores   : NICOLAS IGNACIO HONORATO DROGUETT; EDUARDO ANDRÉS BALTRA ROJAS.
    Programa  : Ordenamiento e inferencia de datos.
	Proposito : Aplicar algoritmos de ordenamiento de datos para hacer un an alisis estadístico de una series de datos.
    Fecha     : Santiago de Chile, 30 de noviembre de 2018.
	Compilador: gcc (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0
	Standard  : C99
************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
/**--------------------------------------------CONSTANTES GLOBALES----------------------------------------------------**/
#define FILEPATH "archivo1.tex" // nombre del archivo que se abrirá en las funciones.

/**------------------------------------------------ESTRUCTURAS--------------------------------------------------------**/
struct Arbol{
	double valor;
	struct Arbol *izq;
	struct Arbol *der; 
};
/**-------------------------------------------------PROTOTIPOS--------------------------------------------------------**/
long abrirArchivoArreglo(double **arreglo);
void abrirArchivoArbol(struct Arbol **arbol);



void imprimirArreglo(double *arreglo,long largo);
/**-----------------------------------------------FIN PROTOTIPOS------------------------------------------------------**/
int main(){
	double *arreglo=NULL;
	long largo;
	largo=abrirArchivoArreglo(&arreglo);
	imprimirArreglo(arreglo,largo);
	free(arreglo);
	return 0;
}

/**-------------------------------------------------FUNCIONES---------------------------------------------------------**/

/**
 * abrirArchivoArreglo:
 * 
 * Función que recibe una referencia a un arreglo de tipo double, al cual se le asigna memoria para guardar los datos
 * del archivo FILEPATH.
 * 
 * Retorna el largo final del arreglo.
 */
long abrirArchivoArreglo(double **arreglo){
	FILE *archivo=fopen(FILEPATH,"r");
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

void imprimirArreglo(double *arreglo,long largo){
	long i=0;
	for(;i<largo;i++)
		printf("%.3le ",arreglo[i]);
}



void abrirArchivoArbol(struct Arbol **arbol){

}

/**-----------------------------------------------FIN FUNCIONES-------------------------------------------------------**/