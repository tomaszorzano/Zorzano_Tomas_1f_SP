#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "eComputer.h"
#include "Parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

int menuPpal();




int main()
{
    int option = 0;
    LinkedList* eComputer = ll_newLinkedList();
    LinkedList* eComputerFilter = ll_newLinkedList();

    char pathArch[12]= "datos_SP_1F";
    char pathArch2[13]= "filtrado.csv";
int sort;



    do{
        option = menuPpal();
        switch(option)
        {
            case 1:
                system("cls");
                printf("\nIngrese Nombre de Archivo a cargar: ");
                scanf("%s", pathArch);
                if (strcmp(pathArch,"datos_SP_1F")== 0)
                {
                  controller_loadFromText("datos_SP_1F.csv" ,eComputer);
                }else
                {
                    printf("\nArchivo Inexistente M ");
                    system("pause");
                }

                break;
            case 2:
                system("cls");
                sort = ll_sort(eComputer,eComputer_comparaTipos,1);
                break;
            case 3:
                system("cls");
                controller_ListEComputer(eComputer);
                break;

            case 4:
                system("cls");
                ll_map(eComputer, eComputer_tipoComputer);
                controller_ListEComputer(eComputer);
                break;
        case 5:
            eComputerFilter= ll_filter(eComputer,eComputer_computersType);
            controller_ListEComputer(eComputerFilter);
            break;
        case 6:
            controller_saveAsText(pathArch2,eComputerFilter);
            break;
        case 7:
            break;
        }
    }while(option != 7);
    return 0;
}

int menuPpal()
{
    int r;
    do
    {
        system("cls");
        printf(" \n");
        printf("  Menu:                                                                          \n");
        printf("  1. Cargar datos                                                                \n");
        printf("  2. Ordenar                                                             \n");
        printf("  3. Imprimir                                                              \n");
        printf("  4. Incrementar Precio                                                  \n");
        printf("  5. Genera lista Laptop                                                    \n");
        printf("  6. Genera archivo Laptop.csv                                                   \n");
        printf("  7. Salir                                                                       \n");
        printf(" \n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 10);

    return r;
}

