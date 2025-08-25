#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // Definimos el tamaño máximo del arreglo

/* 
   Este programa muestra cómo trabajar con:
   1. ARREGLOS en C (guardar varios datos en una misma variable)
   2. ARCHIVOS DE TEXTO (leer y escribir datos)
   
   El archivo de entrada "datos.txt" debe tener el siguiente formato:
   
   5
   10 20 30 40 50
   
   Donde:
   - La primera línea indica la cantidad de números (5).
   - La segunda línea son los valores que se guardarán en el arreglo.
*/

/* -------- FUNCION PARA LEER EL ARCHIVO -------- */
int leerArchivo(const char *nombre, int arreglo[MAX]) {
    FILE *archivo;
    int n, i;

    archivo = fopen(nombre, "r");   // Abrimos el archivo en modo lectura
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);  // Terminamos el programa si no se encuentra el archivo
    }

    fscanf(archivo, "%d", &n);  // Leemos cuántos números hay
    for (i = 0; i < n; i++) {
        fscanf(archivo, "%d", &arreglo[i]);  // Guardamos cada número en el arreglo
    }

    fclose(archivo);  // Cerramos el archivo
    return n;         // Devolvemos la cantidad de números leídos
}

/* -------- FUNCION PARA IMPRIMIR EL ARREGLO -------- */
void imprimirArreglo(int arreglo[MAX], int n) {
    int i;
    printf("Contenido del arreglo:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);  // Mostramos cada número
    }
    printf("\n");
}

/* -------- FUNCION PARA GUARDAR EL ARREGLO EN ARCHIVO -------- */
void guardarArchivo(const char *nombre, int arreglo[MAX], int n) {
    FILE *archivo;
    int i;

    archivo = fopen(nombre, "w");  // Abrimos el archivo en modo escritura (sobrescribe)
    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        exit(1);
    }

    fprintf(archivo, "%d\n", n);   // Escribimos la cantidad de números
    for (i = 0; i < n; i++) {
        fprintf(archivo, "%d ", arreglo[i]);  // Escribimos cada número
    }
    fprintf(archivo, "\n");

    fclose(archivo);
}

/* -------- PROGRAMA PRINCIPAL -------- */
int main() {
    int numeros[MAX];  // Declaramos el arreglo
    int n;             // Variable para saber cuántos números hay

    // 1. Leemos los números desde "datos.txt"
    n = leerArchivo("datos.txt", numeros);

    // 2. Mostramos los números en pantalla
    imprimirArreglo(numeros, n);

    // 3. Guardamos los mismos números en "salida.txt"
    guardarArchivo("salida.txt", numeros, n);

    printf("Los datos fueron guardados en 'salida.txt'.\n");
    return 0;
}

/*
   RESUMEN:
   - Un ARREGLO permite guardar varios datos del mismo tipo.
     Ejemplo: int numeros[MAX]; crea una "fila de cajas" para guardar enteros.
   
   - Un ARCHIVO DE TEXTO se maneja con un puntero FILE * y funciones:
       fopen(nombre, modo)   -> abrir archivo ("r" lectura, "w" escritura)
       fscanf()              -> leer datos desde archivo
       fprintf()             -> escribir datos en archivo
       fclose()              -> cerrar archivo

   - Este ejemplo:
       1) Lee datos desde "datos.txt" y los guarda en un arreglo.
       2) Los muestra en pantalla.
       3) Los escribe en "salida.txt".
*/
