#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swapf(float* a, float* b);
int particion(float *arreglo,int menor,int mayor);
void quicksort(float *arreglo,int menor,int mayor);

void swapf(float* a, float* b) { 
    float t = *a; 
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
int particion(float *arreglo,int menor, int mayor ){

	float pivote = arreglo[mayor];
	int auxMenor = (menor -1);

	for (int i = menor; i <= mayor-1; i++){

		if (arreglo[i] <= pivote){

			auxMenor++;
			swapf(&arreglo[auxMenor],&arreglo[i]);
		}
	}
	swapf(&arreglo[auxMenor + 1],&arreglo[mayor]);
	return (auxMenor + 1);
}
/**
 * quicksort: 
 * 
 * Función que recibe el arreglo a ordenar, y de manera recursiva se encarga de llamar a la 
 * función particion para así ordenar todo el arreglo (recursion de cola).
 *
 */ 
void quicksort(float *arreglo,int menor,int mayor){
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
