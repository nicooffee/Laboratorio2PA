Modo de compilacion: 

gcc menu.c funciones.c -lm -Wextra -std=c99

IMPORTANTE:

- Para abrir archivos, almacenar previamente en la carpeta "archivos".
- Si el m�todo ejecutado entrega tiempo igual a -1, significa que el ordenamiento no se pudo completar.
- Cantidad de valores cercano a los 20M podr�an producir que funciones como mergesort aborten sin aviso.

- Se env�a el programa para generar archivos y el .c donde se promedian los tiempos obtenidos al calcular el tiempo de ejecuci�n al ordenar los archivos generados con cada una de las t�cnicas en la carpeta 'generadorArchivos'.
	*Modo de compilacion:
	gcc medicion.c funciones.c -lm -Wextra -std=c99