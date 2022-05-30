#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "vivienda.h"
#include "input.utn.h"
#define cantcencistas 9000
#define cantviviendas 9000

int main() {

	setbuf(stdout, NULL);

	censista lista_censistas[cantcencistas];
	vivienda lista_vivienda[cantviviendas];
	censistaseteo(lista_censistas, cantcencistas);
	harcode(lista_censistas);

	int loop=1; //1=TRUE, 0 = FALSE;
	int idvivienda=20000;
	int nvivienda=0;
	int retorno;
	int retornoUno;
	int id;
	int menu_habilitado=0;
	while(loop)  //while(var) var==1 RESP: SI -> retorno RESP: NO -> SALE
	{
		printf("\n\n");
		system("pause");
		system("cls");
		//MENU
		printf("\nMENU");
			printf("\nA-> ALTA VIVIENDA");
			printf("\nB->MODIFICAR VIVIENDA");
	 		printf("\nC->BAJA VIVIENDA");
			printf("\nD->LISTAR VIVIENDAS");
			printf("\nE->LISTAR CENSISTAS");
			printf("\nF->ALTA CENSISTAS");
		char opciones;
		printf("\n\nINGRESE LA OPCION: ");
		scanf(" %c", &opciones);
		switch(opciones)
			{
				case 'A':
					menu_habilitado=1;
					printf("\nALTA VIVIENDA");
					idvivienda++;
					nvivienda++;
					altavivienda(lista_vivienda,idvivienda,nvivienda);
				break;
				case 'B':
					if(menu_habilitado==1)
					{

						printf("\nMODIFICAR VIVIENDA");
						id=pedirid();
						retorno=validar_id_vivienda(lista_vivienda,cantviviendas,id);
						if(retorno==0)
						{
							printf("\n la vivienda existe");
							retornoUno=mostrar_sub_menu();
							switch(retornoUno)
							{
								case 1:
								modificarcalle(lista_vivienda,id);
								break;

								case 2:
								modificarpersonas(lista_vivienda,id);
								break;

								case 3:
								modificarhabitaciones(lista_vivienda,id);
								break;

								case 4:
								modificarvivienda(lista_vivienda,id);
								break;

								default:
								break;
							}
						}
						else
						{
							printf("\n La vivienda no existe");
						}


					}
					else
					{
						printf("\n Para comenzar ingrese una vivienda");
					}
				break;
				case 'C':
					if(menu_habilitado==1)
					{
						printf("\nBAJA VIVIENDA");
						id=pedirid();
						bajavivienda(lista_vivienda,id,cantviviendas);
					}
					else
					{
						printf("\n Para comenzar ingrese una vivienda");
					}
				break;
				case 'D':
					if(menu_habilitado==1)
					{
					printf("\nLISTAR VIVIENDAS");
					listarviviendas(lista_vivienda,nvivienda);
					}
					else
					{
						printf("\n Para comenzar ingrese una vivienda");
					}
				break;
				case 'E':
					if(menu_habilitado==1)
					{
					printf("\nLISTAR CENSISTAS");
					listarcensistas(lista_censistas,cantcencistas,lista_vivienda,cantviviendas);
					}
					else
					{
						printf("\n Para comenzar ingrese una vivienda");
					}
				break;
				case 'F':
					if(menu_habilitado==1)
					{
					printf("\nALTA CENSISTAS");
					altacensistas(lista_censistas,cantcencistas);
					}
					else
					{
						printf("\n Para comenzar ingrese una vivienda");
					}
					break;
				default:
					printf("\nERROR");
					break;
			}
		}
}
