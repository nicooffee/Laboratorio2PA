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
