#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    int op, cont = 0;
    registrar Books[10];
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            registro_libros(Books, &cont);
            break;
        case 2:
            mostrar(Books, &cont);
            break;
        case 3:
        buscarLibro(Books, &cont);
            break;
        case 4:
            actualizar(Books, &cont);
            break;
        case 5:
            eliminar(Books, &cont);
            break;
        }
    } while (op != 6);
    
    return 0;
}