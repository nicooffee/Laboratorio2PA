Modo de compilacion: 

gcc menu.c funciones.c -lm -Wextra -std=c99

IMPORTANTE:

- Para abrir archivos, almacenar previamente en la carpeta "archivos".
- Si el método ejecutado entrega tiempo igual a -1, significa que el ordenamiento no se pudo completar.
- Cantidad de valores cercano a los 20M podrían producir que funciones como mergesort aborten sin aviso.

- Se envía el programa para generar archivos y el .c donde se promedian los tiempos obtenidos al calcular el tiempo de ejecución al ordenar los archivos generados con cada una de las técnicas en la carpeta 'generadorArchivos'.
	*Modo de compilacion:
	gcc medicion.c funciones.c -lm -Wextra -std=c99