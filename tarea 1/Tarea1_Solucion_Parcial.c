#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 200 

int leeArchivo(char nombre[50], float datos[max]) // Declara una función que recibe el nombre del archivo (arreglo de 50 chars) y un arreglo de floats para escribir hasta max floats. Devuelve un int con la cantidad de datos leídos.
{
    FILE *archivo; // Puntero a archivo
    int i, n; // i será indicade de la lectura; n será la cantidad de datos que el archivo dice tener.
    float dato; // Variable no usada

    archivo = fopen(nombre, "r"); // Abre el archivo en modo lectura.
    if (archivo == NULL) // Verifica si el archivo se abrió correctamente.
    {
        printf("No se puede abrir el archivo. \nRevisa su ubicaci%cn.", 162); // intenta imprimir la ó con %c.Ojo: usar el numero 162 para representar ó no es portable (depende de la página de codigos de la consola). Mejor escribir directamente "ubicación" guardadno el archivo en UTF-8, o usa setlocale
        printf("\n\n");
        system("pause"); // solo funciona en windows y no es portable. Mejor usar getchar() para esperar a que el usuario presione Enter.
        exit(0);
    }
    fscanf(archivo, "%i", &n);
    i = 0;
    while (i < n)
    {
        fscanf(archivo, "%f", &datos[i]);
        i++;
    }
    return n;
}

void imprime(float datos[max], int n)
{
    int i;

    i=0;
    while (i<n)
    {
        printf("%15.3f\n", datos[i]);
        i++;
    }
}

int main()
{
    char nombreArchivo[50];
    float datos[max];
    int n;

    printf("Ingresa el nombre del archivo: ");
    scanf("%s", &nombreArchivo);
    n = leeArchivo(nombreArchivo, datos);
    printf("\nContenido del archivo %s:\n", nombreArchivo);
    imprime(datos, n);

    printf("\n");
    system("pause");
    printf("\n\n");
    return 0;
}
