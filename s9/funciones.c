#include <stdio.h>
#include <string.h>
#include "funciones.h"

int validarEntero(int a, int b){
    int n, aux;
    do
    {
        aux = scanf("%d", &n);
        while((getchar()) != '\n');
        if (aux!= 1 || n < a || n > b){
            printf("\nError, ingrese nuevamente");
            printf("\n>>> ");
        }
    } while (aux != 1 || n < a || n > b);
}

void leerCadena (char *cadena, int n){
    int len;
    fgets(cadena, n, stdin);
    len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

int menu(){
    int op;
    printf("\n==========GESTION BIBLIOTECARIA==========");
    printf("\nSeleccione una opcion.");
    printf("\n1. Registrar libro.");
    printf("\n2. Mostrar registro de libros.");
    printf("\n3. Buscar libro.");
    printf("\n4. Actualizar estado del libro.");
    printf("\n5. Eliminar libro.");
    printf("\n6. Salir.");
    printf("\n>>> ");
    op=validarEntero(1,6);
    return op;
}

void registro_libros(registrar *libros, int *numLibros){
    if (*numLibros >= 10)
    {
        printf("\nError, solo se pueden ingresar 10 libros.");
        return;
    }else {
        printf("\n=====LIBRO===== %d", *numLibros +1);
        printf("\nIngrese el ID del libro: ");
        printf("\n>>> ");
        libros[*numLibros].id = validarEntero(1, 1000000000);
        printf("\nIngrese el titulo del libro: ");
        printf("\n>>> ");
        leerCadena(libros[*numLibros].titulo, 100);
        printf("\nIngrese el autor del libro: ");
        printf("\n>>> ");
        leerCadena(libros[*numLibros].autor, 50);
        printf("\nIngrese el anio del libro: ");
        printf("\n>>> ");
        libros[*numLibros].anio = validarEntero(1000, 9999);
        printf("\nIngrese si el libro es 'Prestado' o 'Disponible': ");
        printf("\n>>> ");
        leerCadena(libros[*numLibros].estado, 15);
    }
    (*numLibros)++;
}

void mostrar(registrar *libros, int *numLibros){
    if (*numLibros == 0)
    {
        printf("\nNo se han registrado ningun libro.");
        return;
    } else {
        printf("\n#\t\tID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado");
        for (int i = 0; i < *numLibros; i++)
        {
            printf("\n%d\t\t%d\t\t%s\t\t%s\t\t%d\t\t%s", i+1, libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio,libros[i].estado);
        }
    }
}

int buscarLibro (registrar *libros, int *numLibros){
    char buscar[100];
    int busca;
    int op;
    printf("\nDesea buscar el libro por titulo o ID?");
    printf("\n1. Titulo.");
    printf("\n2. ID.");
    printf("\n>>> ");
    op = validarEntero(1, 2);
    switch (op)
    {
    case 1:
        printf("\nIngrese el titulo del libro: ");
        printf("\n>>> ");
        leerCadena(buscar, 100);
        for (int i = 0; i < *numLibros; i++){
            if ((strcmp(buscar, libros[i].titulo)) == 0) // si da 0 si lo encontro
            {

                printf("\nLibro encontrado.");
                printf("\n#\t\tID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado");
                printf("\n%d\t\t%d\t\t%s\t\t%s\t\t%d\t\t%s", i+1, libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio,libros[i].estado);
                return i;
            } 
        }
        printf("\nLibro no encontrado.");
        return -1;
        
        break;
    case 2:
        printf("\nIngrese el ID del libro: ");
        printf("\n>>> ");
        busca = validarEntero(1, 1000000000);
        for (int i = 0; i < *numLibros; i++)
        {
            if (busca == libros[i].id ) // como es un int no puedo usar strcmp ya q eso compara cadenas
            {
                printf("\nLibro encontrado.");
                printf("\n#\t\tID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado");
                printf("\n%d\t\t%d\t\t%s\t\t%s\t\t%d\t\t%s", i+1, libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio,libros[i].estado);
                return i;
            }
        } 
        printf("\nLibro no encontrado.");
        return -1;
        break;
    default:
        break;
    }
    return -1;
}

void actualizar (registrar *libros, int *numLibros){
    int posicion;
    posicion = buscarLibro(libros, numLibros);
    if (posicion == -1)
    {
        return;
    }

    if (strcmp(libros[posicion].estado, "Disponible") == 0)
    {
        strcpy(libros[posicion].estado, "Prestado");
    }else{
        strcpy(libros[posicion].estado, "Disponible");
    }
    printf("\nEstado actualizado correctamente.\n");
}

void eliminar (registrar *libros, int *numLibros){
    int posicion;
    posicion = buscarLibro(libros, numLibros);
    if (posicion == -1)
    {
        return;
    }
    for (int i = posicion; i < *numLibros -1; i++)
    {
        libros[i] = libros[i+1];
    }
    (*numLibros)--;
    printf("\nLibro eliminado correctamente.");
}