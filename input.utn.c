#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "input.utn.h"
#include <ctype.h>

int validarChar(char string[])
{
	int retorno = 0;
	for (int i = 0; i < strlen(string); i++)
    {
        if(isdigit(string[i]))
		{
            printf("\nIngrese caracteres validos.\n");
            retorno = 1;
            return retorno;
        }
    }
    return retorno;
}

