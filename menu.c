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
#include "funciones.h"
/**-------------------------------------------------PROTOTIPOS--------------------------------------------------------**/
void menuPrincipal();
void menuArchivo();
void menuMetodos(FILE *archivo);
void menuArreglos(FILE *archivo);
void menuArboles(FILE *archivo);
void menuTiempoMemoria(FILE *archivo);

double ejecutarMergeSort(float *arreglo,long largo);
double ejecutarQuickSort(float *arreglo,long largo);

void subirLineas(int n);
/**-----------------------------------------------FIN PROTOTIPOS------------------------------------------------------**/
int main(){
    system("clear");
    menuPrincipal();
    return 0;
}
/**-------------------------------------------------FUNCIONES---------------------------------------------------------**/

void menuPrincipal(){
    char op;
    int lineas=7;
    do{
        printf("\rMenu principal: \n\n");
        printf("Ingrese el numero de la opcion a ejecutar: \n");
        printf("\t1: Abrir archivo.\n");
        printf("\t0: Salir.\n\n");
        printf("\t\33[2KOpcion: ");
        scanf("%c",&op);
        switch(op){
            case '0':
                subirLineas(lineas);
                exit(0);
            case '1':
                subirLineas(lineas);
                menuArchivo();
                break;
            default:
                printf("\r\t\33[2KOpcion invalida.\33[A");
                subirLineas(lineas);
        }
    }while(op!='0');
    
}





void menuArchivo(){
    FILE *archivo;
    char *nombre=(char *) calloc(100,sizeof(char));
    char *buffer=(char *) calloc(100,sizeof(char));
    printf("Ingrese el nombre del archivo: ");
    do{
        scanf("%s",nombre);
        snprintf(buffer,100,"archivos/%s",nombre);
        archivo=fopen(buffer,"r");
        if(archivo==NULL || nombre=="\n"){
            printf("Error al abrir el archivo. \33[A\33[2K");
            printf("\rIngrese el nombre del archivo: ");
        }
    }while(archivo==NULL);
    free(nombre);
    free(buffer);
    subirLineas(2);
    menuMetodos(archivo);
    fclose(archivo);
    return;
}





void menuMetodos(FILE *archivo){
    char op;
    int lineas=9;
    do{
        printf("\rMenu metodos de ordenamiento: \n\n");
        printf("Ingrese el numero de la opcion a ejecutar: \n");
        printf("\t1: Metodos arreglo:\n");
        printf("\t2: Metodos arbol:\n");
        printf("\t3: Estrategias intercambio tiempo-memoria: \n");
        printf("\t0: Volver al menu principal.\n");
        printf("\t\33[2KOpcion: ");
        scanf("%c",&op);
        switch(op){
            case '0':
                subirLineas(lineas);
                break;
            case '1':
                subirLineas(lineas);
                menuArreglos(archivo);
                break;
            case '2':
                subirLineas(lineas);
                menuArboles(archivo);
                break;
            case '3':
                subirLineas(lineas);
                menuTiempoMemoria(archivo);
                break;
            default:
                printf("\r\t\33[2KOpcion invalida.\33[A");
                subirLineas(lineas);
                op='-';
        }
    }while(op!='0');
}





void menuArreglos(FILE *archivo){
    int lineas=8;
    char op;
    float *arreglo=NULL;
    double tiempo;
    long largo=abrirArchivoArreglo(&arreglo,archivo);
    do{
        printf("\rMenu metodos de ordenamiento para arreglos: \n\n");
        printf("Ingrese el numero de la opcion a ejecutar: \n");
        printf("\t1: Ejecutar MergeSort.\n");
        printf("\t2: Ejecutar QuickSort.\n");
        printf("\t0: Volver.\n");
        printf("\t\33[2KOpcion: ");
        scanf("%c",&op);
        switch(op){
            case '0':
               subirLineas(lineas);
                break;
            case '1':
                tiempo=ejecutarMergeSort(arreglo,largo);
                printf("\r\tAlgoritmo ejecutado correctamente. Tiempo: %.3lf\33[A",tiempo);
                largo=abrirArchivoArreglo(&arreglo,archivo);
                subirLineas(lineas);
                break;
            case '2':
                tiempo=ejecutarQuickSort(arreglo,largo);
                printf("\r\tAlgoritmo ejecutado correctamente. Tiempo: %.3lf\33[A",tiempo);
                largo=abrirArchivoArreglo(&arreglo,archivo);
                subirLineas(lineas);
            default:
                printf("\r\t\33[2KOpcion invalida.\33[A");
                subirLineas(lineas);
                op='-';
        }
    }while(op!='0');
    free(arreglo);
    return;
}






void menuArboles(FILE *archivo){
    int lineas=9;
    char op;
    do{
        printf("\rMenu metodos de ordenamiento para arboles: \n\n");
        printf("Ingrese el numero de la opcion a ejecutar: \n");
        printf("\t1: Ejecutar HeapSort.\n");
        printf("\t2: Ejecutar AVL.\n");
        printf("\t3: Ejecutar arboles 2-3.\n");
        printf("\t0: Volver.\n");
        printf("\t\33[2KOpcion: ");
        scanf("%c",&op);
        switch(op){
            case '0':
               subirLineas(lineas);
                break;
            case '1':
            case '2':
            case '3':
            default:
                printf("\r\t\33[2KOpcion invalida.\33[A");
                subirLineas(lineas);
                op='-';
        }
    }while(op!='0');
}





void menuTiempoMemoria(FILE *archivo){
    int lineas=8;
    char op;
    do{
        printf("\rMenu estrategias intercambio tiempo-memoria: \n\n");
        printf("Ingrese el numero de la opcion a ejecutar: \n");
        printf("\t1: Ejecutar Ordenar por conteo.\n");
        printf("\t2: Ejecutar Listado de repeticiones de valores.\n");
        printf("\t0: Volver.\n");
        printf("\t\33[2KOpcion: ");
        scanf("%c",&op);
        switch(op){
            case '0':
               subirLineas(lineas);
                break;
            case '1':
            case '2':
            default:
                printf("\r\t\33[2KOpcion invalida.\33[A");
                subirLineas(lineas);
                op='-';
        }
    }while(op!='0');
}





void subirLineas(int n){
    while(--n>=0)
        printf("\33[2K\33[A");
}



double ejecutarMergeSort(float *arreglo,long largo){
    double tiempo;
    clock_t begin;
    begin=clock();
    mergeSort(arreglo,0,largo-1);
    tiempo=(double)((clock()-begin)*1000)/CLOCKS_PER_SEC;
    if(!estaOrdenado(arreglo,largo))
        tiempo=-1;
    return tiempo;
}





double ejecutarQuickSort(float *arreglo,long largo){
    double tiempo;
    clock_t begin;
    begin=clock();
    quicksort(arreglo,0,largo-1);
    tiempo=(double)((clock()-begin)*1000)/CLOCKS_PER_SEC;
    if(!estaOrdenado(arreglo,largo))
        tiempo=-1;
    return tiempo;
}
/**-----------------------------------------------FIN FUNCIONES-------------------------------------------------------**/
