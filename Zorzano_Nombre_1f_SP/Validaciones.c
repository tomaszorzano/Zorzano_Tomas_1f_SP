#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

int isValidInt(int numero, int minimo, int maximo)
{
    int ret = RETURN_ERROR;
    if(numero >= minimo && numero <= maximo)
    {
        ret = RETURN_OK;
    }
    return ret;
}

int isValidFloat(float numero, float minimo, float maximo)
{
    int ret = RETURN_ERROR;
    if(numero >= minimo && numero <= maximo)
    {
        ret = RETURN_OK;
    }
    return ret;
}

int isValidChar(char letra, char minimo, char maximo)
{
    int ret = RETURN_ERROR;
    if(letra >= minimo && letra <= maximo)
    {
        ret = RETURN_OK;
    }
    return ret;
}

int isValidName (char* cadena)
{
    int ret = RETURN_OK;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a'))
        {
            ret = RETURN_ERROR;
            break;
        }
    }
    return ret;
}

int isValidApellido (char* cadena)
{
    int ret = RETURN_OK;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a'))
        {
            ret = RETURN_ERROR;
            break;
        }
    }
    return ret;
}

int isValidDni(char* cadena)
{
    int ret = RETURN_OK;
    int i;
    int contadorPunto=0;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]!='.'))
        {
            ret = RETURN_ERROR;
        }
        if (cadena[i]=='.')
        {
            contadorPunto++;
        }
        if(contadorPunto>2)
        {
            ret = RETURN_ERROR;
        }
        if ((cadena[1]=='.' && cadena[5]=='.') || (cadena[2]=='.' && cadena[6]=='.'))
        {
            ret = RETURN_OK;
        }
    }
    return ret;
}

int isNumber (char* pString)
{
    int ret = RETURN_OK;
    int i=0;
    while(pString[i]!='\0')
    {
        if(pString[i]<'0' || pString[i]>'9')
        {
            ret = RETURN_ERROR;
        }
        i++;
    }
    return ret;
}

int isValidFloatNumber(char* stringRecibido)
{
    int ret = RETURN_OK;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            ret = RETURN_ERROR;
            break;
        }
    }
    return ret;
}

int isValidNumber(char* stringRecibido)
{
    int ret = RETURN_OK;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')//
        {
            ret = RETURN_ERROR;
            break;
        }
    }
    return ret;
}

int isCuit (char* pString)
{
    int ret = RETURN_ERROR;
    int i=0;
    while(pString[i]!='\0')
    {
        if((pString[i]!='-')&&(pString[i]<'0' || pString[i]>'9'))
        {
            ret = RETURN_ERROR;
        }
        else if((pString[2]=='-')&&(pString[10]=='-' || pString[11]=='-'))
        {
            ret = RETURN_OK;
        }
        i++;
    }
    return ret;
}

int isTelefono (char* pString)
{
    int i=0;
    int contadorGuion=0;
    while(pString[i]!='\0')
    {
        if((pString[i]!=' ')&&(pString[i]!='-')&&(pString[i]<'0' || pString[i]>'9'))
        {
            return RETURN_ERROR;
        }
        if(pString[i]=='-')
        {
            contadorGuion++;
        }
        i++;
    }
    if(contadorGuion==1)
        {
            return RETURN_OK;
        }
    return RETURN_ERROR;
}
/*
int isEmail(char* cadena)
{
    int retorno=TRUE;
    int contadorArroba=0;
    int i;
    for (i=0;i<50;i++)
    {
       while (cadena[i]!='\0')
        {
            if ((cadena[i]=='-')&&(cadena[i]=='_')&& (cadena[i]=='.')
                && (cadena[i]>='0' || cadena[i]<='9') && (cadena[i]>='A'||cadena[i]<='Z') &&
                (cadena[i]>='a' || cadena[i]<='z') && (cadena[i]=='@'))
            {
                retorno=TRUE;
                break;
            }
            if(cadena[i]=='@')
            {
                contadorArroba++;
            }
        }
    }
    if(contadorArroba==0 || contadorArroba>1)
    {
        retorno=FALSE;
    }
    return retorno;
}*/

int isValidEmail(char* cadena)
{
    int contador=0;
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'-' && cadena[i]!='+') || (cadena[i]>'9' && cadena[i]<'@') ||
           (cadena[i]>'Z' && cadena[i]!='_' && cadena[i]<'a')|| cadena[i]>'z')
        {
            retorno=0;
            break;
        }

        if (cadena[i]=='@')
        {
            contador++;
        }
    }

    if (contador==0 || contador>1)
    {
        retorno=0;
    }
    return retorno;
}

int isValidSex(char letra, char maximo, char minimo)
{
    int retorno = RETURN_OK;

    if((letra != 'f') && (letra != 'F') && (letra != 'm') && (letra != 'M'))
    {
        retorno = RETURN_ERROR;
    }
    return retorno;
}

/*
int isValidEmail(char* cadena)
{
    int retorno=TRUE;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int contadorArroba=0;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'-' && cadena[i]!='+') || (cadena[i]>'9' && cadena[i]<'@') ||
           (cadena[i]>'Z' && cadena[i]!='_' && cadena[i]<'a')|| cadena[i]>'z')
        {
            retorno=FALSE;
        }
        if(cadena[i]=='@')
        {
            contadorArroba++;
        }
    }
        if(contadorArroba==1)
        {
            retorno=TRUE;
        }
    return retorno;
}
int isValidEmail(char* cadena)
{
    int retorno=TRUE;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int contadorArroba=0;
    for(i=0;cadena[i]!='\0';i++)
    {
        if (cadena[i]=='@')
        {
            contadorArroba++;
            if (contadorArroba==1 && cadena[i]=='_' && cadena[i]=='-' && cadena[i]=='.' &&
                (cadena[i]>=0 || cadena[i]<=9) && (cadena[i]>'Z' || cadena[i]<'A') &&
                (cadena[i]>'z' || cadena[i]<'a'))
            {
                retorno=TRUE;
                break;
            }else
                {
                    retorno=FALSE;
                }
        }
    }
    return retorno;
}*/

int isValidAlphanumeric(char* cadena)
{
    int retorno = RETURN_OK;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if(cadena[i]<'0' || (cadena[i]>'9' && cadena[i]<'A') || (cadena[i]>'Z' && cadena[i]<'a') || cadena[i]>'z' )
        {
            retorno = RETURN_ERROR;
            break;
        }
    }
    return retorno;
}

int isValidFecha(char *cadena)
{
    int ret = RETURN_OK;
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]!= '/' ))
        {
            ret = RETURN_ERROR;
        }
    }
    return ret;
}

/*int isValidCUIT(char* stringRecibido)
{
  //  int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int j;
    char buffer[14];
    strncpy(buffer,stringRecibido,14);

    for(i=0;buffer[i]!='\0';i++)
    {
        if((buffer[i]<'0' || buffer[i]>'9') && (buffer[i]!='-')) // chequeo que solo sean numeros o -
        {
            retorno=0;
            break;
        }

        if(buffer[i]=='-')  //elimino los -
        {
            for(j=i;buffer[j]!='\0';j++)
            {
                strncpy(&buffer[j],&buffer[j+1],1);
            }
        }
    }

    int digitos[10]={2,3,4,5,6,7,2,3,4,5};
    int acumulado = 0;
    int verificador;

    for(i=0;i < strlen(buffer-1); i++)
    {
        acumulado+=buffer[i]*digitos[i];
    }

    verificador=11-(acumulado%11);
	if(verificador == 11)
	{
		verificador = 0;
	}

	if(buffer[11]!=verificador)
    {
        retorno=0;
    }
}
    //if(stringRecibido[2]!='-' || stringRecibido[11]!='-' || stringRecibido[0]!='2' || stringRecibido[1]!='0' || stringRecibido[1]!='3' || stringRecibido[1]!='4' || stringRecibido[1]!='7')
*/
