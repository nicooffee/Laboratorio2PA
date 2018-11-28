#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
/**-------------------------------------------------FUNCIONES---------------------------------------------------------**/

/**
 * abrirArchivoArreglo:
 * 
 * Función que recibe una referencia a un arreglo de tipo float, al cual se le asigna memoria para guardar los datos
 * del archivo.
 * 
 * Retorna el largo final del arreglo.
 */
long abrirArchivoArreglo(float **arreglo,FILE *archivo){
	long largo=0;
	long largo2=2;
	free(*arreglo);
    rewind(archivo);
	*(arreglo)=(float*) calloc(largo2,sizeof(float));
	while(fscanf(archivo,"%e",&((*arreglo)[largo++]))!=EOF)
		if(largo==largo2)
			*(arreglo)=(float*) realloc(*(arreglo),(largo2*=2)*sizeof(float));
	*(arreglo)=(float *) realloc(*(arreglo),(largo-1)*sizeof(float));
	return --largo;
}





void abrirArchivoArbol(struct Arbol **arbol){

}




/**----------------------------------------------BLOQUE MERGESORT-----------------------------------------------------**/
void merge(float *arreglo,long inicio,long mitad,long final){
    long i=0,j=0,k=inicio,lA=(mitad-inicio+1),lB=(final-mitad);
    float *A=NULL,*B=NULL;
    A=(float*) calloc(lA,sizeof(float));
    B=(float*) calloc(lB,sizeof(float));
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





void mergeSort(float *arreglo,long inicio,long final){
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
/**--------------------------------------------FIN BLOQUE QUICKSORT---------------------------------------------------**/




void imprimirArreglo(float *arreglo,long largo){
	long i=0;
	for(;i<largo;i++)
		printf("%.3e ",arreglo[i]);
}





int estaOrdenado(float *arreglo,long largo){
	long i=0;
	while(i<largo-1)
		if(arreglo[i++]>arreglo[i])
			return 0;
	return 1;
}
/**-----------------------------------------------FIN FUNCIONES-------------------------------------------------------**/