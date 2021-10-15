/*
 * Localidad.h
 *
 *  Created on: 15 oct 2021
 *      Author: Sere
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

typedef struct{

	int id;
	char descripcion[50];

}eLocalidad;


int mostrarLocalidades(eLocalidad localidades[],int size_localidades);
void mostrarUnaLocalidad(eLocalidad unaLocalidad);
int buscarLocalidadPorId(eLocalidad localidades[],int size_localidades,int id);


#endif /* LOCALIDAD_H_ */

