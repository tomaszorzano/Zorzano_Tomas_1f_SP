#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "eComputer.h"
#include "Parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** \brief Parsea los datos los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int parser_eComputerFromText(FILE* pFile , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idStr[6];
    char descripcionStr[256];
    char precioStr[20];
    char idTipoStr[2];


    if(pFile != NULL)
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n", idStr, descripcionStr, precioStr,idTipoStr);
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n", idStr, descripcionStr, precioStr,idTipoStr);
            if(cant != 4)
            {
                printf("Error al cargar ArchivoP\n\n");
                system("pause");
            }
            else
            {
                eComputer* pComp;
                pComp = eComputer_newParametros(idStr, descripcionStr, precioStr,idTipoStr);
                ll_add(pArrayList, pComp);
            }
        }
    fclose(pFile);
    ret = RETURN_OK;
    }
    else
    {
        printf("Archivo no hay datosP\n\n");
        system("pause");
    }

    return ret;
}
