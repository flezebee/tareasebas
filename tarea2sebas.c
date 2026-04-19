#include <stdio.h>

int main (int argc, char *argv[]) {

    float maxAsig=0, minAsig=0;
    float cal[5][3][3]={0};
    char nombres[5][20];
    char asignaturas[3][20]={"Fisica",
                          "Quimica",
                          "Calculo"};

    float prom[5][3]={0};
    int opc = 0, opc2 = 0;
    int contE = 0;
    int selE=0;
    int aprobados=0, reprobados=0;

    do{
        printf("Seleccione una opcion:\n");
        printf("1.Registrar estudiante\n");
        printf("2.Registrar calificaciones\n");
        printf("3.Promedios por estudiante\n");
        printf("4.Promedios por asignatura\n");
        printf("5.Calificacione mas alta y baja por estudiante\n");
        printf("6.Calificacione mas alta y baja por asignatura\n");
        printf("7.Estudiantes aprobados y reprobados por asignatura\n");
        printf(">> ");
        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            printf("Registre el nombre del estudiante %d:\n",contE+1);
            getchar();
            fgets(nombres[contE],20,stdin);
            contE++;
            break;
        case 2:
            printf("Seleccione el estudiante al cual desea registras las calificaciones:\n");
            for (int i = 0; i < contE; i++)
            {
                printf("%d.%s",i,nombres[i]);
            }
            printf(">> ");
            scanf("%d",&selE);

            printf("Ingrese las calificaciones del estudiante %d:\n",selE+1);

            for (int i = 0; i < 3; i++)
            {
                printf("%s\n",asignaturas[i]);
                for (int j = 0; j < 3; j++)
                {
                    printf("Nota %d: ",j+1);
                    scanf("%f",&cal[selE][i][j]);
                    prom[selE][i]+=cal[selE][i][j];
                }
                prom[selE][i]/=3;
            }
            break;
        case 3:
            float promAux = 0;
            printf("%s\t\t%s\t\t%s\t\tPromedio\t\tNombre\n",asignaturas[0],
                                                            asignaturas[1],
                                                            asignaturas[2]);
            for (int i = 0; i < contE; i++)
            {
                promAux = (prom[i][0] + prom[i][1] + prom[i][2])/3;
                printf("%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%s",prom[i][0],
                                                            prom[i][1],
                                                            prom[i][2],
                                                            promAux,
                                                            nombres[i]);
            }
            break;
            case 4:
                float promAsig[3]={0};
                printf("%s\t\t%s\t\t%s\n",asignaturas[0],
                                            asignaturas[1],
                                            asignaturas[2]);
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < contE; j++)
                    {
                        promAsig[i]+=prom[j][i];
                    }
                    promAsig[i]/=contE;
                    printf("%.2f\t\t",promAsig[i]);
                }
                break;
            case 5:
                float max=0, min=0;
                printf("Seleccione el estudiante al cual desea ver las calificaciones mas alta y baja:\n");
                for (int i = 0; i < contE; i++)
                {
                    printf("%d.%s",i,nombres[i]);
                }
                printf(">> ");
                scanf("%d",&selE);
                max = cal[selE][0][0];
                min = cal[selE][0][0];
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (cal[selE][i][j] > max)
                        {
                            max = cal[selE][i][j];
                        }
                        if (cal[selE][i][j] < min)
                        {
                            min = cal[selE][i][j];
                        }
                    }
                }
                printf("Calificacion mas alta: %.2f\n",max);
                printf("Calificacion mas baja: %.2f\n",min);
                break;
            case 6:
                printf("Seleccione la asignatura a la cual desea ver las calificaciones mas alta y baja:\n");
                for (int i = 0; i < 3; i++)
                {
                    printf("%d.%s\n",i,asignaturas[i]);
                }
                printf(">> ");
                scanf("%d",&selE);
                maxAsig = cal[0][selE][0];
                minAsig = cal[0][selE][0];
                for (int i = 0; i < contE; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (cal[i][selE][j] > maxAsig)
                        {
                            maxAsig = cal[i][selE][j];
                        }
                        if (cal[i][selE][j] < minAsig)
                        {
                            minAsig = cal[i][selE][j];
                        }
                    }
                }
                printf("Calificacion mas alta: %.2f\n",maxAsig);
                printf("Calificacion mas baja: %.2f\n",minAsig);
                break;
            case 7:
                printf("Seleccione la asignatura a la cual desea ver el numero de estudiantes aprobados y reprobados:\n");
                for (int i = 0; i < 3; i++)
                {
                    printf("%d.%s\n",i,asignaturas[i]);
                }
                printf(">> ");
                scanf("%d",&selE);
                for (int i = 0; i < contE; i++)
                {
                    if (prom[i][selE] >= 6){
                        aprobados++;
                    }else{
                        reprobados++;
                    }
                }
                printf("Estudiantes aprobados: %d\n",aprobados);
                printf("Estudiantes reprobados: %d\n",reprobados);
                break;
        default:
             printf("Opcion no valida ingrese otro numero\n");
            break;
        }




        printf("Desea seleccionar otra opcion? 1.Si/2.No: ");
        scanf("%d",&opc2);
    }while(opc2==1);







    return 0;
}