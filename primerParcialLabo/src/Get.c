//primer parcial labo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get.h"

static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);
static int esNumerico(char* cadena, int limite);
static int validatePositiveInteger(char number[]);

static int getCharacter(char* pResultado);
static int myGetsChar(char* cadena, int longitud);
static int esCaracter(char* cadena, int limite);
char getChar(char message[],char errorMessage[]);

static int getCadenaChar(char* pResultado);
static int esNombre(char* cadena, int limite);
int isAlpha(char string[]);
void getString(char string[],int len,char message[],char errorMessage[]);

static int getFloat(float* pResultado);
static int esNumeroFlotante(char* cadena, int limite);


static int isNumberAndLetters(char string[]);




static int getTextoEspecial(char* pResultado);
static int esTextoEspecial(char* cadena, int limite);


void getStringWithNumbers(char string[],int len,char message[],char errorMessage[]);


void pasarInicialAMayuscula(char array[]){

	array[0] = toupper(array[0]);
}



int utn_getTextoEspecial(char* pResultado, char* mensaje, char* mensajeError, int sizeNombre, int reintentos)
{
    int retorno=-1;
    char bufferNombre[sizeNombre];

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && sizeNombre>0 && reintentos>=0)
    {
        do{
            printf("%s",mensaje);
            if(getTextoEspecial(bufferNombre)==0)
            {
                strcpy(pResultado,bufferNombre);
				retorno = 0;
				break;
            }
            reintentos--;
            printf("%s",mensajeError);
        }while(reintentos>=0);
    }

    return retorno;
}

/*******************************************************************************************************************************/

/** \brief verifica si la cadena ingresada es un texto especcial. Acepta ciertos caracteres especiales ('-', '_', '@' y espacio) y numeros
 *
 * \param cadena char* cadena de caracteres a ser analizada
 * \param limite int tamaño de la cadena a analizar
 * \return int Retorna 1 (verdadero) si la cadena es un nombre, 0 (falso) si no lo es o -1 en caso de error
 *
 */
static int esTextoEspecial(char* cadena, int limite)
{
    int retorno=-1;
    if (cadena!= NULL && limite>0)
    {
        retorno = 1;
        for(int i=0; i<limite && cadena[i]!='\0'; i++)
        {
            if(i==0 && cadena[i]==' ')
            {
                retorno=0;
                break;
            }
            else if(cadena[i]!=' ' && (cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z') && cadena[i]!='@' && cadena[i]!='-' && cadena[i]!='_' && (cadena[i]<'0' || cadena[i]>'9'))
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/********************************************************************************************************************************/

/** \brief pide al usuario ingresar un array de de caracteres (texto especial), limita los caracteres validos (con mas posibilidades que la funcion getCadenaChar() y almacena el array por referencia
 *
 * \param pResultado char* puntero al espacio en memoria donde se guardara el array obtenido
 * \return int retorna 0 si se guardo el array o -1 si no
 *
 */
static int getTextoEspecial(char* pResultado)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL && !myGets(bufferString,sizeof(bufferString)) && esTextoEspecial(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        strcpy(pResultado,bufferString);
    }
    return retorno;
}



static int isNumberAndLetters(char string[])
{
    int returnValue=1;

    for(int i=0;string[i]!='\0';i++)
    {
        if((string[i]<'a'||string[i]>'z')&&(string[i]<'A'||string[i]>'Z')&&(string[i]<'0'||string[i]>'9'))
        {
            returnValue=0;
        }
    }

    return returnValue;
}


void getStringWithNumbers(char string[],int len,char message[],char errorMessage[])
{
    puts(message);
    fflush(stdin);
    fgets(string,len,stdin);
    string[strlen(string)-1]='\0';

    while(!isNumberAndLetters(string))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(string,len,stdin);
        string[strlen(string)-1]='\0';
    }
}





int getOnlyInt(char message[],char errorMessage[])
{
    char strNumber[32];
    int number;

    printf("%s",message);
    fflush(stdin);
    fgets(strNumber,sizeof(strNumber),stdin);
    strNumber[strlen(strNumber)-1]='\0';

    while(!validatePositiveInteger(strNumber))
    {
        printf("%s",errorMessage);
        fflush(stdin);
        fgets(strNumber,sizeof(strNumber),stdin);
        strNumber[strlen(strNumber)-1]='\0';
    }

    number=atoi(strNumber);

    return number;
}

static int validatePositiveInteger(char number[])
{
    int returnValue=1;

    for(int i=0;number[i]!='\0';i++)
    {
        if(number[i]<'0'||number[i]>'9')
        {
            returnValue=0;
            break;
        }
    }

    return returnValue;
}


int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError, int sizeNombre, int reintentos)
{
    int retorno=-1;
    char bufferNombre[sizeNombre];

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && sizeNombre>0 && reintentos>=0)
    {
        do{
            printf("%s",mensaje);
            if(getCadenaChar(bufferNombre)==0)
            {
                strcpy(pResultado,bufferNombre);
				retorno = 0;
				break;
            }
            reintentos--;
            printf("%s",mensajeError);
        }while(reintentos>=0);
    }

    return retorno;
}


static int getCadenaChar(char* pResultado)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL && !myGets(bufferString,sizeof(bufferString)) && esNombre(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        strcpy(pResultado,bufferString);
    }
    return retorno;
}


static int esNombre(char* cadena, int limite)
{
    int retorno=-1;
    if (cadena!= NULL && limite>0)
    {
        retorno = 1;
        for(int i=0; i<limite && cadena[i]!='\0'; i++)
        {
            if(i==0 && cadena[i]==' ')
            {
                retorno=0;
                break;
            }
            else if(cadena[i]!=' ' && (cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z'))
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}



/*****************************************************************************************/


int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getFloat(&bufferFloat)==0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			reintentos--;
            printf("%s",mensajeError);
		}while(reintentos >= 0);
	}
	return retorno;
}


static int getFloat(float* pResultado)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL && !myGets(bufferString,sizeof(bufferString)) && esNumeroFlotante(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        *pResultado = atof(bufferString);
    }
    return retorno;
}

static int esNumeroFlotante(char* cadena, int limite)
{
    int retorno=-1;
    int flagComa=0;
    if(cadena!=NULL && limite>0)
    {
        retorno=1;
        for(int i=0;i<limite && cadena[i]!='\0';i++)
        {
            if(i==0 && (cadena[i]=='-' || cadena[i]=='+'))
            {
                continue;
            }
            if(cadena[i]==',')
            {
                if(flagComa==1 || i==0)
                {
                    retorno=0;
                    break;
                }
                flagComa=1;
            }
            if(cadena[i]>'9' || cadena[i]<'0')
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}



/**********************************************************************************************************/


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno=-1;
    int bufferInt;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
    {
        do{
            printf("%s",mensaje);
            if(getInt(&bufferInt)==0 && bufferInt>=minimo && bufferInt<=maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",mensajeError);
        }while(reintentos>=0);
    }

    return retorno;
}

static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL && !myGets(bufferString,sizeof(bufferString)) && esNumerico(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        *pResultado = atoi(bufferString);
    }
    return retorno;
}


static int myGets(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[4096];
    if(cadena!=NULL && longitud>0)
    {
        fflush(stdin);
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL && bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
        {
            bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
        }
        if(strnlen(bufferString,sizeof(bufferString))<= longitud)
        {
            strncpy(cadena,bufferString,longitud);
            retorno=0;
        }
    }

    return retorno;
}


static int esNumerico(char* cadena, int limite)
{
    int retorno=-1;
    int i;
    if(cadena!=NULL && limite>0)
    {
        retorno=1;
        for(i=0;i<limite && cadena[i]!='\0';i++)
        {
            if(i==0 && (cadena[i]=='-' || cadena[i]=='+'))
            {
                continue;
            }
            if(cadena[i]>'9' || cadena[i]<'0')
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}






/*****************************************************************************************/

int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char opcion1, char opcion2, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getCharacter(&bufferChar)==0 && (bufferChar==opcion1 || bufferChar==opcion2))
			{
				*pResultado=bufferChar;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	}
	return retorno;
}


static int getCharacter(char* pResultado)
{
    int retorno = -1;
    char bufferString;

    if(pResultado != NULL && !myGetsChar(&bufferString,sizeof(bufferString)) && esCaracter(&bufferString,sizeof(bufferString)))
    {
        retorno=0;
        *pResultado=tolower(bufferString);
    }
    return retorno;
}

static int myGetsChar(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[4096];
    if(cadena!=NULL && longitud>0)
    {
        fflush(stdin);
        gets(bufferString);
        if(strnlen(bufferString,sizeof(bufferString))<= longitud)
        {
            strncpy(cadena,bufferString,longitud);
            retorno=0;
        }
    }

    return retorno;
}



static int esCaracter(char* cadena, int limite)
{
    int retorno=-1;
    if(cadena!=NULL && limite>0)
    {
        retorno=1;
        if((cadena[0]<'A' || cadena[0]>'Z') && (cadena[0]<'a' || cadena[0]>'z') && limite>1)
        {
            retorno=0;
        }
    }
    return retorno;
}

char getChar(char message[],char errorMessage[])
{
    char aux;

    printf("%s",message);
    fflush(stdin);
    scanf("%c",&aux);

    while((aux<'a'||aux>'c')&&(aux<'A'||aux>'C')) //RANGO DE OPCIONES DISPONIBLES
    {
        printf("%s",errorMessage);
        fflush(stdin);
        scanf("%c",&aux);
    }
    aux=tolower(aux);
    return aux;
}

void getString(char string[],int len,char message[],char errorMessage[])
{
    puts(message);
    fflush(stdin);
    fgets(string,len,stdin);
    string[strlen(string)-1]='\0';

    while(!isAlpha(string))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(string,len,stdin);
        string[strlen(string)-1]='\0';
    }
}

int isAlpha(char string[])
{
    int returnValue=1;

    for(int i=0;string[i]!='\0';i++)
    {
        if((string[i]<'a'||string[i]>'z')&&(string[i]<'A'||string[i]>'Z'))
        {
            returnValue=0;
        }
    }

    return returnValue;
}
