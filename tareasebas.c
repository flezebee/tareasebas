#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char ID[10];
    char nombre[20];
    int stock=0;
    float precio=0, ganacias=0;
    int pan=0;
    int len=0;
    int aux;
    int des;
    do{
        printf("Accion que quiere realizar: \n");
        printf("1.Registrar producto\n");
        printf("2.Vender producto\n");
        printf("3.Reabastecer producto\n");
        printf("4.Informacion producto\n");
        printf("5.Ganancias totales\n");
        printf("6.Salir\n");
        printf(">>> ");
        scanf("%d",&pan);
        switch(pan){
            case 1:
                printf("Ingresar el ID del producto: ");
                scanf("%s",&ID);
                printf("Ingresar el nombre del producto: ");
                scanf("%s",&nombre);
                printf("Ingresar el stock del producto: ");
                scanf("%d",&stock);
                printf("Ingresar el precio del producto: ");
                scanf("%f",&precio);
                break;
            case 2:
                printf("Ingresar la cantidad de productos a vender: ");
                scanf("%d",&aux);
                
                if (aux > stock){
                    printf("No hay suficiente stock para realizar esta venta\n");
                }else{
                    do
                {
                    printf("¿Desea aplicar un descuento? (1 para si, 0 para no): ");
                    scanf("%d",&len);
                }while(len != 1 && len != 0);
                if (len ==1)
                {
                    printf("Ingrese el descuento a aplicar: ");
                    scanf("%d",&des);
                    if (des > 100 || des < 0){
                        printf("Descuento no valido\n");
                    }else{
                        printf("Descuento aplicado con exito\n");
                        precio = precio - (precio * des / 100);
                    }
                }
                    stock = stock - aux;
                    printf("Venta realizada con exito\n");
                }
                ganacias = ganacias + (precio * aux);
                aux = 0;
                break;
            case 3:
                printf("Ingresar la cantidad de productos a reabastecer: ");
                scanf("%d",&aux);
                stock = stock + aux;
                printf("Reabastecimiento realizado con exito\n");
                aux = 0;
                break;
            case 4:
                printf("Informacion del producto:\n");
                printf("ID: %s\n",ID);
                printf("Nombre: %s\n",nombre);
                printf("Stock: %d\n",stock);
                printf("Precio: %f\n",precio);
                break;
            case 5:
                printf("Ganancias totales: %f\n",ganacias);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida ingrese otro numero\n");
        }
    }while(pan != 6);
    return 0;
}