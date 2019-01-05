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
void menuEstadistica(FILE *archivo);

double ejecutarMergeSort(double *arreglo,long largo);
double ejecutarQuickSort(double *arreglo,long largo);
double ejecutarHeapSort(struct Heap *h);
double ejecutarAVL(FILE *archivo);
double ejecutarOrdenarPorConteo(double **arreglo,long largo);

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
    int lineas=10;
    do{
        printf("\rMenu metodos de ordenamiento: \n\n");
        printf("Ingrese el numero de la opcion a ejecutar: \n");
        printf("\t1: Metodos arreglo:\n");
        printf("\t2: Metodos arbol:\n");
        printf("\t3: Estrategias intercambio tiempo-memoria: \n");
        printf("\t4: Estadisticas basicas.\n");
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
            case '4':
                subirLineas(lineas);
                menuEstadistica(archivo);
                break;
            default:
                printf("\r\t\33[2KOpcion invalida.\33[A");
                subirLineas(lineas);
                op='-';
        }
    }while(op!='0');
}





void menuArreglos(FILE *archivo){
    int pause;
    int lineas=8;
    char op;
    double *arreglo=NULL;
    double tiempo;
    long largo=abrirArchivoArreglo(&arreglo,archivo);
    do{
        printf("\rMenu metodos de ordenamiento para arreglos: \n\n");
        printf("Ingrese el numero de la opcion a ejecutar: \n");
        printf("\t1: Ejecutar MergeSort.\n");
        printf("\t2: Ejecutar QuickSort.\n");
        printf("\t3: Mostrar arreglo.\n");
        printf("\t4: Re-cargar arreglo.\n");
        printf("\t0: Volver.\n");
        printf("\t\33[2KOpcion: ");
        scanf("%c",&op);
        switch(op){
            case '0':
               subirLineas(lineas);
                break;
            case '1':
                tiempo=ejecutarMergeSort(arreglo,largo);
                printf("\r\tAlgoritmo ejecutado correctamente. Tiempo: %.3lf ms\33[A",tiempo);
                subirLineas(lineas);
                break;
            case '2':
                tiempo=ejecutarQuickSort(arreglo,largo);
                printf("\r\tAlgoritmo ejecutado correctamente. Tiempo: %.3lf ms\33[A",tiempo);
                subirLineas(lineas);
                break;
            case '3':
                subirLineas(lineas);
                imprimirArreglo(arreglo,largo);
                printf("\nPresione una tecla para continuar...");
                pause=getchar();
                pause=getchar();
                system("clear");
                break;
            case '4':
                largo=abrirArchivoArreglo(&arreglo,archivo);
                printf("\r\t\33[2KDatos cargados correctamente.\33[A");
                subirLineas(lineas);
                break;
            default:
                printf("\r\t\33[2KOpcion invalida.\33[A");
                subirLineas(lineas);
                op='-';
        }
    }while(op!='0');
    if(arreglo!=NULL)
        free(arreglo);
    return;
}






void menuArboles(FILE *archivo){
    int lineas=9;
    char op;
    int pause;
    double tiempo;
    struct Heap *h=NULL;
    do{
        printf("\rMenu metodos de ordenamiento para arboles: \n\n");
        printf("Ingrese el numero de la opcion a ejecutar: \n");
        printf("\t1: Ejecutar HeapSort.\n");
        printf("\t2: Ejecutar AVL.\n");
        printf("\t3: Mostrar Heap.\n");
        printf("\t4: Resetear datos.\n");
        printf("\t0: Volver.\n");
        printf("\t\33[2KOpcion: ");
        scanf("%c",&op);
        switch(op){
            case '0':
                liberarHeap(&h);
                subirLineas(lineas);
                break;
            case '1':
                if(h==NULL)
                    abrirArchivoHeap(&h,archivo);
                tiempo=ejecutarHeapSort(h);
                printf("\r\tAlgoritmo ejecutado correctamente. Tiempo: %.3lf ms\33[A",tiempo);
                subirLineas(lineas);
                break;
            case '2':
                system("clear");
                tiempo=ejecutarAVL(archivo);
                printf("\rAlgoritmo ejecutado correctamente. Tiempo: %.3lf ms\33[A",tiempo);
                printf("\n\nPresione una tecla para continuar...");
                pause=getchar();
                pause=getchar();
                system("clear");
                subirLineas(lineas);
                break;
            case '3':
                system("clear");
                if(h!=NULL)
                    mostrarArregloHeap(h);
                printf("\n\nPresione una tecla para continuar...");
                pause=getchar();
                pause=getchar();
                system("clear");
                subirLineas(lineas);
                break;
            case '4':
                liberarHeap(&h);
                subirLineas(lineas);
                break;
            default:
                printf("\r\t\33[2KOpcion invalida.\33[A");
                subirLineas(lineas);
                op='-';
        }
    }while(op!='0');
}





void menuTiempoMemoria(FILE *archivo){
    double tiempo=0;
    int lineas=8;
    char op;
    double *A=NULL;
    int pause;
    long L=abrirArchivoArreglo(&A,archivo);
    do{
        printf("\rMenu estrategias intercambio tiempo-memoria: \n\n");
        printf("Ingrese el numero de la opcion a ejecutar: \n");
        printf("\t1: Ejecutar Ordenar por conteo.\n");
        printf("\t2: Mostrar arreglo.\n");
        printf("\t0: Volver.\n");
        printf("\t\33[2KOpcion: ");
        scanf("%c",&op);
        switch(op){
            case '0':
                if(A!=NULL)
                    free(A);
                subirLineas(lineas);
                break;
            case '1':
                tiempo=ejecutarOrdenarPorConteo(&A,L);
                printf("\r\tAlgoritmo ejecutado correctamente. Tiempo: %.3lf ms\33[A",tiempo);
                subirLineas(lineas);
                break;
            case '2':
                system("clear");
                if(A!=NULL)
                    imprimirArreglo(A,L);
                printf("\n\nPresione una tecla para continuar...");
                pause=getchar();
                pause=getchar();
                system("clear");
                subirLineas(lineas);
                break;
            default:
                printf("\r\t\33[2KOpcion invalida.\33[A");
                subirLineas(lineas);
                op='-';
        }
    }while(op!='0');
}

void menuEstadistica(FILE *archivo){
    double *cuar;
    double tiempo=0;
    int lineas=7;
    char op;
    double *A=NULL;
    int pause;
    long L=abrirArchivoArreglo(&A,archivo);
    do{
        printf("\rMenu estadisticas basicas: \n\n");
        printf("Ingrese el numero de la opcion a ejecutar: \n");
        printf("\t1: Mostrar estadisticas basicas.\n");
        printf("\t0: Volver.\n");
        printf("\t\33[2KOpcion: ");
        scanf("%c",&op);
        switch(op){
            case '0':
                free(A);
               subirLineas(lineas);
                break;
            case '1':
                mergeSort(A,0,L-1);
                system("clear");
                if(A!=NULL){
                    cuar=cuartiles(A,L);
                    printf("|Minimo: %lf |Maximo: %lf\n",A[0],A[L-1]);
                    printf("|Mediana: %lf\n",mediana(A,L));
                    printf("|Cuartil 1: %lf |Cuartil 2: %lf |Cuartil 3: %lf\n",cuar[0],cuar[1],cuar[2]);
                    printf("|Valor mas repetido: %lf |Cantidad valores distintos: %ld",valorMasRepetido(A,L),cantidadValDistintos(A,L));
                    free(cuar);
                }
                printf("\n\nPresione una tecla para continuar...");
                pause=getchar();
                pause=getchar();
                system("clear");
                subirLineas(lineas);
                subirLineas(lineas);
                break;
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



double ejecutarMergeSort(double *arreglo,long largo){
    double tiempo;
    clock_t begin;
    begin=clock();
    mergeSort(arreglo,0,largo-1);
    tiempo=(double)((clock()-begin)*1000)/CLOCKS_PER_SEC;
    if(!estaOrdenado(arreglo,largo))
        tiempo=-1;
    return tiempo;
}





double ejecutarQuickSort(double *arreglo,long largo){
    double tiempo;
    clock_t begin;
    begin=clock();
    quicksort(arreglo,0,largo-1);
    tiempo=(double)((clock()-begin)*1000)/CLOCKS_PER_SEC;
    if(!estaOrdenado(arreglo,largo))
        tiempo=-1;
    return tiempo;
}





double ejecutarHeapSort(struct Heap *h){
    double tiempo;
    clock_t begin;
    begin=clock();
    heapSort(h);
    tiempo=(double)((clock()-begin)*1000)/CLOCKS_PER_SEC;
    if(!heapOrdenado(h))
        tiempo=-1;
    return tiempo;
}




double ejecutarAVL(FILE *archivo){
    double tiempo;
    clock_t begin;
    begin=clock();
    struct NodoAvl *avl=NULL;
    crearAvlArchivo(&avl,archivo);
    tiempo=(double)((clock()-begin)*1000)/CLOCKS_PER_SEC;
    if(tiempo<=10000)
        MostrarInOrden(avl);
    liberarAVL(&avl);
    return tiempo;
}





double ejecutarOrdenarPorConteo(double **arreglo,long largo){
    double tiempo;
    clock_t begin;
    begin=clock();
    ordenarPorConteo(arreglo,largo);
    tiempo=(double)((clock()-begin)*1000)/CLOCKS_PER_SEC;
    if(!estaOrdenado(*arreglo,largo))
        tiempo=-1;
    return tiempo;
}
/**-----------------------------------------------FIN FUNCIONES-------------------------------------------------------**/
