#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "vivienda.h"
#include "input.utn.h"
#include <ctype.h>
#include "censista.h"

void altavivienda(vivienda* strvivienda,int id,int n)
{
	setbuf(stdout, NULL);
	strvivienda[n].idVivienda=id;
	do
	{
	printf("\nIngrese la calle de la vivienda: \n");
	fflush(stdin);
	gets(strvivienda[n].calle);
	}while(validarChar(strvivienda[n].calle));
	do{
	printf("\nIngrese la cantidad de personas de la vivienda : \n");
	fflush(stdin);
	scanf(" %d",&strvivienda[n].cantidadPersonas);
	if(strvivienda[n].cantidadPersonas<1)
	{
		printf("\nERROR en la carga del dato.");
	}
	}while(strvivienda[n].cantidadPersonas<1 || strvivienda[n].cantidadPersonas > 20);
	printf("\n Ingrese la cantidad de habitaciones de la vivienda: \n");
	scanf(" %d",&strvivienda[n].cantidadHabitaciones);
	printf("\n Ingrese el tipo de vivienda: (1-CASA , 2-DEPARTAMENTO,3-CASILLA , 4-RANCHO) \n");
	scanf(" %d",&strvivienda[n].tipoVivienda);
	printf("\nIngrese el legajo del censista : \n");
	scanf(" %d",&strvivienda[n].legCensista.legajoCensista);


}

void listarviviendas(vivienda* strvivienda,int n)

{
		vivienda estraux;

	printf("\nLa lista de las viviendas ingresadas es : %d\n",n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1; j<=n;j++)
		{
			if(strcmp(strvivienda[i].calle,strvivienda[j].calle)>0)
			{
				estraux = strvivienda[i];
				strvivienda[i] = strvivienda[j];
				strvivienda[j] = estraux;
			}
			else
			{
				if(strcmp(strvivienda[i].calle,strvivienda[j].calle)==0&&strvivienda[i].cantidadPersonas<strvivienda[j].cantidadPersonas)
				{
					estraux = strvivienda[i];
					strvivienda[i] = strvivienda[j];
					strvivienda[j] = estraux;
				}
			}
		}
	}
		for(int i=1;i<=n;i++)
		{
			if(strvivienda[i].idVivienda>20000)
			  {
			  	printf(" \n CALLE: %s | PERSONAS: %d | TIPO: %d | HABITACIONES: %d  |  ID: %d",strvivienda[i].calle,strvivienda[i].cantidadPersonas,strvivienda[i].tipoVivienda,strvivienda[i].cantidadHabitaciones,strvivienda[i].idVivienda);
		      }
		}


}

int mostrar_sub_menu()

{
	int retorno;

	printf("\n Ingrese 1 para modificar la calle ");
	printf("\n Ingrese 2 para modificar la cantidad de personas ");
	printf("\n Ingrese 3 para modificar la cantidad de habitaciones ");
	printf("\n Ingrese 4 para modificar el tipo de vivienda ");

	printf("\n opcion : ");
	scanf("%d",&retorno);

	return retorno;

}

int validar_id_vivienda(vivienda* strvivienda,int n,int id)
{
	int i;
	int retorno=-1;

	for(i=1; i<=n; i++)
	{

		if(strvivienda[i].idVivienda == id)
		{
			retorno = 0;
		}

	}

	return retorno;
}

int pedirid()
{
	int id_ingresar;
	printf("\n Ingrese el id de la vivienda : \n ");
	scanf(" %d",&id_ingresar);

	return id_ingresar;
}

void modificarcalle(vivienda* strvivienda ,int id)
{
	int pos= id - 20000;
	char ncalle[20];
	printf("\n Ingrese la calle nueva: ");
	fflush(stdin);
	gets(ncalle);
	strcpy(strvivienda[pos].calle,ncalle);
}
void modificarpersonas(vivienda* strvivienda ,int id)
{
	int pos= id-20000;
	int npersona;
	printf("\n Ingrese la cantidad de personas: ");
	fflush(stdin);
	scanf("%d",&npersona);
	strvivienda[pos].cantidadPersonas=npersona;

}
void modificarhabitaciones(vivienda* strvivienda ,int id)

{
	int pos= id-20000;
	int nhabitaciones;
	printf("\n Ingrese la cantidad de personas: ");
	fflush(stdin);
	scanf("%d",&nhabitaciones);
	strvivienda[pos].cantidadHabitaciones=nhabitaciones;
}
 void modificarvivienda(vivienda* strvivienda ,int id)

 {
	int pos= id-20000;
	int nvivienda;
	printf("\n Ingrese la cantidad de personas: ");
	fflush(stdin);
	scanf("%d",&nvivienda);
	strvivienda[pos].tipoVivienda=nvivienda;
}

void bajavivienda(vivienda* strvivienda,int id,int n)
{

	int i;
	for(i=1; i<=n; i++)
	{

		if(strvivienda[i].idVivienda == id)
		{
			strvivienda[i].idVivienda = strvivienda[0].idVivienda;
			strcpy(strvivienda[i].calle,strvivienda[0].calle);

			strvivienda[i].cantidadHabitaciones = strvivienda[0].cantidadHabitaciones;

			strvivienda[i].cantidadPersonas = strvivienda[0].cantidadPersonas;

			strvivienda[i].tipoVivienda = strvivienda[0].tipoVivienda;

		}

	}
}
