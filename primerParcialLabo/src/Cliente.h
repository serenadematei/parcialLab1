/*
 * Cliente.h
 *
 *  Created on: 11 oct 2021
 *      Author: Sere
 */
#include "Localidad.h"
#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct{

	int id;
	char nombreEmpresa[50];
	char cuit[50];
	char direccion[50];
	int idLocalidad;
	int isEmpty;

}eCliente;





#endif /* CLIENTE_H_ */

//****************************************ABM***********************************************************************************************************

/** \brief Indica que todas las posiciones en el array de clientes estan vacias
 * poniendo 1 en la bandera isEmpty
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return int Retorna (0) si error [Tamaño invalido o puntero NULL] - (1) si Ok
 *
 */
int inicializarClientes(eCliente listaClientes[],int size_clientes);


/** \brief Agrega en una lista existente de clientes un nuevo cliente
 *en el lugar libre mas proximo
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \param int* id puntero al proximo valor de ID que tomara el cliente agregado
 * \return  int Retorna (0) si error [Tamaño invalido o puntero NULL] o falta de lugar para otro cliente - (1) si Ok
*/
int altaClientes(eCliente listaClientes[],int size_clientes, int* id, eLocalidad localidades[], int size_localidades);




//****************************************BUSQUEDAS***********************************************************************************************************

/** \brief busca una posicion libre en el array de clientes
 *
 * \param listaClientes* Puntero al array de clientes
 * \param  size_clientes tamaño del array
 * \return int Retorna (-1) si error [Tamaño invalido o puntero NULL] o si no encontro espacio libre -
 *        o (indice) posicion libre que encontro si Ok.
 *
 */
int buscarLibreClientes(eCliente listaClientes[],int size_clientes);




/** \brief encuentra un cliente por su id y retorna el indice de su posicion en el array.
 * \param listaClientes* Puntero al array de clientes
 * \param  size_clientes tamaño del array
 * \param int id del cliente para encontrarlo dentro del array
 * \return Retorna el indice de la posicion del cliente o [-1] si error [Tamaño invalido o puntero NULL]
 *          o cliente no encontrado.
 *
 */
int buscarClientePorId(eCliente listaClientes[],int size_clientes,int id);







//****************************************GETS***********************************************************************************************************
/** \brief encuentra un cliente por su id y escribe su direccion y cuit en los punteros pasados por parametro
 * \param listaClientes* Puntero al array de clientes
 * \param  size_clientes tamaño del array
 * \param int id del cliente para encontrarlo dentro del array
 * \return Retorna [0] si error [Tamaño invalido o puntero NULL]
 *          o [1] si ok.
 *
 */
int cargarDatosDelClientePorId(int id,eCliente listaClientes[],int size_clientes,char aux1[],char aux2[]);

