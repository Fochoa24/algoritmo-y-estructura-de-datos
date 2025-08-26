#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // Definimos el tamaño máximo del arreglo (100 enteros).
// Es un límite de seguridad: nunca vamos a permitir más de 100 elementos.

/* LEE:
- lÍNEA 1: N
- LINEA 2: N Enteros -> arreglo
- Linea 3: a b
devuelve 0 si OK; sale con error si algo falla.
*/

int leerArchivo(const char *nombre, int arreglo[MAX], int *N, int *a, int *b){

/*
Se crea una función que recibe:
nombre: nombre del archivo (ej: "datos_ej1.txt").
arreglo: el arreglo donde guardaremos los números.
*N: un puntero a entero donde guardaemos la cantidad de elementos.
*a, *b: pnuteros a enteros donde guardaemos los índices del segmento.

Usamos los punteros (*N, *a, *b) porque queremos modificar esas variables en el main.
*/

    FILE *archivo = fopen(nombre, "r");
    if (!archivo) {
        printf("Error al abrir el archivo. \n");
        exit(1);
    }

/*
    Abre el archivo en modo de lectura ("r")
    si archivo == NULL, significa que no se pudo abrir (ej: no existe)
    En ese caso imprimimos error y terminamos el programa.
*/


    /*Lee N*/
    if (fscanf(archivo, "%d", N) != 1){
        printf("Error: no se pudo leer N.\n");
        fclose(archivo);
        exit(1);
    }

/*
    Lee el primer número del archivo -> N.
    "fscanf" devuelve la cantidad de datos leídos correctamente.
    Si no se leyó nada -> error
*/

    if (*N < 0 || *N > MAX) {
        printf("Error: N fuera de rango (0..%d).\n", MAX);
        fclose(archivo);
        exit(1);
    }
/*
    Validamos que N esté en el rango permitido.
    Si N es mayor a MAX o negativo, salimos con error.
*/

    /* Lee N enteros */
    for (int i = 0; i < *N; i++) {
        if (fscanf(archivo, "%d", arreglo[i]) !=1){
            printf("Error: Faltan datos en la línea de los enteros.\n");
            fclose(archivo);
            exit(1);
        }
    }
/*
    Recorremos de 0 hasta N-1.
    Cada vez leemos un entero y lo guardamos en el arreglo (arreglo[i]).
    Si no hay suficiente datos en el archivo, sale error.
*/

    /* Lee a y b */
    if (fscanf(archivo, "%d %d", a, b) != 2){
        printf("Error: no se pudieron leer los índices a y b.\n");
        fclose(archivo);
        exit(1);
    }
/*
    Lee los dos últimos valores (a y b).
    Como son punteros, fscanf guarda directamente en las variables originales que están en main.
*/

    /* Valida rango de a y b */
    if (!(*a >= 0 && *b >= 0 && *a <= *b && *b < *N)){
        printf("Error: índices fuera de rango (se requiere 0 <= a <= b < N).\n");
        fclose(archivo);
        exit(1);
    }

/*
    Validamosque:
        a y b sean mayores o iguales a 0.
        a <= b (para que el segmento tenga sentido).
        b < N (no puede pasarse del arreglo).
*/

    fclose(archivo);
    return 0;
/*
    Cerramos el archivo.
    Devolvemos 0 indicando que todo salió bien
*/

}



int main() {
    int arr[MAX], N, a, b;
    leerArchivo("datos_ej1.txt", arr, &N, &a, &b);
}

int suma(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) total += arr[i];
    return total;
}

double promedio(int arr[], int n){
    return (double) suma(arr, n) / n;
}

int maximo(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr [i] > max) max = arr[i];
    return max;
}

int minimo(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min) min = arr[i];
    return min;
}

int contarPares(int arr[], int n) {
    int pares = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0) pares++;
    return pares;
}

int sumaSegmento(int arr[], int a, int b) {
    int total = 0;
    for  (int i = a; i <= b; i++) total += arr[i];
    return total;
}