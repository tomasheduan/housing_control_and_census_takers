#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "input.utn.h"
#include "censista.h"
#include <ctype.h>
#include "vivienda.h"


void censistaseteo(censista* struccensista, int c)
{
	int i;
	for(i=1;i<c;i++)
	{
		struccensista[i].empty=0;
	}
}

void harcode(censista* struccen)
{
	struccen[100].legajoCensista=100;
	strcpy(struccen[100].nombre,"Ana");
	struccen[100].edad=34;
	strcpy(struccen[100].telefono,"1203-2345");
	struccen[100].empty=1;

	struccen[101].legajoCensista=101;
	strcpy(struccen[101].nombre,"Juan");
	struccen[101].edad=24;
	strcpy(struccen[101].telefono,"4301-54678");
	struccen[101].empty=1;

	struccen[102].legajoCensista=102;
	strcpy(struccen[102].nombre,"Sol");
	struccen[102].edad=47;
	strcpy(struccen[102].telefono,"5902-37487");
	struccen[102].empty=1;
}                         /***/

void listarcensistas(censista* strcensista, int c,vivienda* strvivienda,int n)
{
	for(int i=1;i<c;i++)
	{
		if(strcensista[i].empty==1)
			{
			printf( "\n %d-%s-%d-%s\n" , strcensista[i].legajoCensista,strcensista[i].nombre,strcensista[i].edad,strcensista[i].telefono);

			for( int j=1;j<n; j++)
			{
				if(strvivienda[j].legCensista.legajoCensista == strcensista[i].legajoCensista)
				{
					printf( "\n %d-%s-%d-%d-%d\n" , strvivienda[j].idVivienda,strvivienda[j].calle,strvivienda[j].cantidadPersonas,strvivienda[j].cantidadHabitaciones,strvivienda[j].tipoVivienda);
				}
			}

		}


	}

}

void altacensistas(censista* strcensista,int c)
{
	int legajo;
	do{
	printf("\nIngrese el legajo del nuevo censista: ");
	fflush(stdin);
	scanf(" %d", &legajo);
	strcensista[legajo].legajoCensista = legajo;
	if(legajo<1 || legajo>9000)
	{
		printf("\nError en la carga del dato");
	}
	}while(legajo<1 || legajo>9000);

	do{
	printf("\nIngrese el  nombre del nuevo censista:");
	fflush(stdin);
	scanf(" %s", &strcensista[legajo].nombre);
	}
	while(validarChar(strcensista[legajo].nombre));

	do{
		printf("\nIngrese la edad del nuevo censista: ");
		fflush(stdin);
		scanf(" %d", &strcensista[legajo].edad);
		if(strcensista[legajo].edad<18 || strcensista[legajo].edad>100)
		{
			printf("\nError en la carga del dato");
		}
	}
	while(strcensista[legajo].edad<18 || strcensista[legajo].edad>100);

	printf("\nIngrese el  Telefono del nuevo censista:");
	fflush(stdin);
	scanf(" %s", &strcensista[legajo].telefono);

	strcensista[legajo].empty = 1;
}



