#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(float *arreglo,long inicio,long mitad,long final);
void mergeSort(float *arreglo,long inicio,long final);
int main(){
    float *arreglo;
    long largo=20;
    long i=0;
    srand(time(0));
    arreglo=(float*) calloc(largo,sizeof(float));
    for(;i<largo;i++)
        arreglo[i]=rand()%10;
    for(i=0;i<largo;i++)
        printf("%.0lf ",arreglo[i]);
    printf("\n");
    mergeSort(arreglo,0,largo-1);
    for(i=0;i<largo;i++)
        printf("%.0lf ",arreglo[i]);
    printf("\n");
    return 0;
}

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
    printf("%ld %ld %ld\n",inicio,mitad,final);
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
