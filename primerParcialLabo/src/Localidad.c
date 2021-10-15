/*
 * Localidad.c
 *
 *  Created on: 15 oct 2021
 *      Author: Sere
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Get.h"
#include "Localidad.h"


int mostrarLocalidades(eLocalidad localidades[],int size_localidades){

	int todoOk=0;
    int flag=0;

	if (localidades!= NULL && size_localidades> 0) {
		printf("\n\n               *****************LISTA DE LOCALIDADES********************\n");
		printf("\nID     DESCRIPCION\n");
		for (int i = 0; i < size_localidades; i++) {
			{
				mostrarUnaLocalidad(localidades[i]);
				flag = 1;
				todoOk = 1;
			}

		}
		if (!flag) {
			printf("No hay localidades que mostrar\n\n");
		}

	}

	return todoOk;
}


void mostrarUnaLocalidad(eLocalidad unaLocalidad){
	printf("%5d           %10s\n",unaLocalidad.id,unaLocalidad.descripcion);
}



int buscarLocalidadPorId(eLocalidad localidades[],int size_localidades,int id){

	int indice=-1;

		if(localidades!=NULL && size_localidades>0){
			for(int i=0; i<size_localidades; i++){
				if(localidades[i].id==id){
				    indice=i;
				    break;
				}
			}
		}

		return indice;
}

