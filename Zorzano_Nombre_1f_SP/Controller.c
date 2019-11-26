#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "eComputer.h"
#include "Parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** \brief Carga los datos de las computadoras desde el archivo datos_SP_1F.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        ret = parser_eComputerFromText(pFile, pArrayList);
    }
    else
    {
        printf("El Archivo No ExisteC\n\n");
        system("pause");
    }

    return ret;
}

/** \brief Listar computadoras
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */

int controller_ListEComputer(LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    len = ll_len(pArrayList);

    if(pArrayList != NULL)
    {
        if(len != 0)
        {
            printf("ID Descripcion Precio Tipo\n\n");
            for(int i = 1; i < len; i++)
            {
                eComputer_showComputers(pArrayList);
                ret = RETURN_OK;
                break;
            }
            system("pause");
        }
        else
        {
            printf("No hay datosC\n\n");
            system("pause");
        }
    }
    return ret;
}
/** \brief Guarda los datos de las computadoras en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile;
    pFile = fopen(path, "w");
    eComputer* pComp;


    if(pArrayList != NULL)
    {
        for(int i = 0; i<ll_len(pArrayList);i++)
        {
            pComp = (eComputer*)ll_get(pArrayList, i);
            fprintf(pFile, "%4d  %s  %f  %d\n",pComp->id ,pComp->descripcion ,pComp->precio, pComp->idTipo);
        }
        fclose(pFile);
        ret = RETURN_OK;
    }

    else
    {
        printf("No hay DatosC\n");
        system("pause");
    }

    return ret;
}

