#include <stdio.h>

int main () {
    int pan, stock, vendidos, n=0;
    char ID[10], nombre[30];
    float precio, ganancias=0, total, descuento;

    do {
        printf("\n*** GESTION DE VENTAS ***");
        printf("\nSeleccione una opcion");
        printf("\n1. Registrar datos del producto");
        printf("\n2. Vender producto");
        printf("\n3. Reabastecer el producto");
        printf("\n4. Consultar informacion");
        printf("\n5. Mostrar ganancias obtenidas");
        printf("\n6. Salir");
        printf("\n>>> ");
        scanf("%d",&pan );

        switch (pan){
        case 1:
            printf("\nIngrese el ID del producto: ");
            scanf("%s", &ID);
            printf("\nIngrese el nombre del producto: ");
            scanf("%s", &nombre);
            printf("\nIngrese el Stock del producto: ");
            scanf("%d", &stock);
            printf("\nIngrese el precio del producto: ");
            scanf("%f", &precio);
            break;

        case 2:
            printf("\nIngrese la cantidad de productos que desea vender: ");
            scanf("%d", &vendidos);
            if (stock >= vendidos){
                total = precio * vendidos;

                if (vendidos >= 10) {
                    printf("El usuario aplica para un descuento del 5 porciento.\n");
                    descuento = total * 0.95;
                    printf("Su total a pagar es de: %.2f\n", descuento);
                    ganancias += descuento;
                }else {
                    printf("Su total a pagar es de: %.2f\n", total);
                    ganancias += total;
                }
                printf("Venta realizada con exito.\n");
                printf("Gracias por su compra.\n");
                stock= stock - vendidos;
            }else {
                printf("Venta No Realizada. Stocks insuficientes.\n");
                printf("Necesita reabastecer los stocks para realizar la venta.\n");
            }
            break;

        case 3:
            printf("\nIngrese la cantidad de Stocks para la venta: ");
            scanf("%d", &n);
            stock=stock+n;
            printf("La cantidad de stocks disponibles es de: %d\n", stock);
            break;
        
        case 4:
            printf("\nPRODUCTO\n");
            printf("ID: %s\n", ID);
            printf("Nombre: %s\n", nombre);
            printf("Stocks: %d\n", stock);
            printf("Precio: %.2f\n", precio);
            break;

        case 5:
            printf("Ganancias obtenidas: %.2f\n", ganancias);
            break;

        case 6:
            printf("GRACIAS POR USAR EL SISTEMA.");
            break;

        default:
            printf("No existe la opcion, ingrese otro numero.\n");
        }

    } while (pan != 6);
    
    return 0;
}