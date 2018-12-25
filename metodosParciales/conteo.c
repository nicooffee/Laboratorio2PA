#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenarPorConteo(double **A,long l);
int main(){
    double *arreglo;
    long largo=20;
    long i=0;
    srand(time(0));
    arreglo=(double*) calloc(largo,sizeof(double));
    for(;i<largo;i++)
        arreglo[i]=rand()%10000;
    for(i=0;i<largo;i++)
        printf("%.0lf ",arreglo[i]);
    printf("\n");
    ordenarPorConteo(&arreglo,largo);
    printf("\n");
    for(i=0;i<largo;i++)
        printf("%.0lf ",arreglo[i]);
    printf("\n");
    return 0;
}

void ordenarPorConteo(double **A,long l){
    unsigned int *conteo=(int *) calloc(l,sizeof(unsigned int));
    double *B=(double *) calloc(l,sizeof(double));
    int i=0,j;
    for(;i<l;i++)
        for(j=i+1;j<l;j++)
            if((*A)[i]>=(*A)[j]){
                conteo[i]++;
            }
            else{
                conteo[j]++;    
            }
    for(i=0;i<l;i++)
        B[conteo[i]]=(*A)[i];
    free(conteo);
    free(*A);
    *A=B;
    return;
}   