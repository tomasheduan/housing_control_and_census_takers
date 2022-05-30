#ifndef VIVIENDA_H_
#define VIVIENDA_H_
#include "censista.h"

typedef struct
{
	int idVivienda; //ojo, comienza en 20.000
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda; //1-CASA 2-DEPTO 3-CASILLA 4-RANCHO
	censista legCensista; //anidacion para usar legajo

}vivienda;

void altavivienda(vivienda*,int,int);

void listarviviendas(vivienda*,int);

int mostrar_sub_menu();

int validar_id_vivienda(vivienda*,int,int);

int pedirid();

void modificarcalle(vivienda*,int);

void modificarpersonas(vivienda*,int);

void modificarhabitaciones(vivienda*,int);

void modificarvivienda(vivienda*,int);

void bajavivienda(vivienda*,int,int);



#endif /* VIVIENDA_H_ */
