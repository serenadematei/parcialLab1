/*
 * Informes.h
 *
 *  Created on: 12 oct 2021
 *      Author: Sere
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "Cliente.h"
#include "Pedido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Get.h"
#include "Localidad.h"

//****************************************INFORMES***********************************************************************************************************

/** \brief funcion que organiza las llamadas a funciones relacionadas con informes a traves de un menu
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return int Retorna (0) si error [Tamaño invalido o puntero NULL] - (1) si Ok
 *
 */

int informes(ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes,eLocalidad localidades[],int size_localidades);

int pedidosPendientesPorLocalidad(ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes,eLocalidad localidades[],int size_localidades);


/** \brief muestra la cantidad promedio de kg de polipropileno reciclado por cada cliente
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return int Retorna (0) si error [Tamaño invalido o puntero NULL] - (1) si Ok
 *
 */
int cantidadPromedioKgPPReciclados(ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes);




/** \brief pide el ingreso de una localidad y cuenta los pedidos pendientes de la misma
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return int Retorna (0) si error [Tamaño invalido o puntero NULL] - (1) si Ok
 *
 */










//****************************************CALCULOS***********************************************************************************************************
/** \brief Calcula el promedio de kilos de basura reciclada por cliente
 * \param int cantidad de pedidos de un cliente
 * \param float total de kilos acumulados de los pedidos de un cliente
 * \return float Retorna cantidad promedio reciclada
 *
 */
float calcularPromedio(int cantidad, float total);






//****************************************CONTADORES***********************************************************************************************************

/** \brief Cuenta la cantidad de kilos de polipropileno que reciclo un cliente
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 *  \param int ID del cliente
 * \return Retorna la cantidad total de kilos de polipropileno que reciclo un cliente
 *
 */
int contadorKgPolipropilenoPorCliente(int id,ePedido listaPedidos[],int size_pedidos);




/** \brief recorre la lista de pedidos en busca de pedidos cuyo estado sea 0 (pendiente) y coincida en idCliente con el id pasado
 * por parametro. Cada vez que encuentra uno, lo suma.
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \return Retorna la cantidad de pedidos pendientes del cliente encontrados
 *
 */
int contadorPedidosPendientesPorCliente(ePedido listaPedidos[],int size_pedidos,int id);


/** \brief recorre la lista de pedidos en busca de pedidos cuyo estado sea 0 (procesado) y coincida en idCliente con el id pasado
 * por parametro. Cada vez que encuentra uno, lo suma.
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \return Retorna la cantidad de pedidos procesados del cliente encontrados
 *
 */
int contadorPedidosProcesadosPorCliente(ePedido listaPedidos[],int size_pedidos,int id);






//**************************************GETS y CARGAS***********************************************************************************************************


/** \brief recorre la lista de pedidos en busca de pedidos procesados de los clientes para mostrarlos
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return int Retorna (0) si error [Tamaño invalido o puntero NULL] - (1) si Ok
 *
 */
int getPedidosProcesados(int id,ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes);



/** \brief recorre la lista de pedidos en busca de pedidos pendientes de los clientes para mostrarlos
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return int Retorna (0) si error [Tamaño invalido o puntero NULL] - (1) si Ok
 *
 */
int getPedidosPendientes(int id,ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes);






/** \brief escribe en el puntero cantidadPendientes la cantidad de pedidos pendientes de un cliente
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \param int* puntero cantidadPendientres
 * \param int id del cliente
 * \return int Retorna (0) si error [Tamaño invalido o puntero NULL] - (1) si Ok
 *
 */
int cargarCantidadPendientes(int id,ePedido listaPedidos[],int size_pedidos, int* cantidadPendientes);




/** \brief Escribe en su parametro auxNombre el nombre de la empresa que posee dicho id
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \param id del cliente(empresa)
 * \return Retorna  [0] si error [Tamaño invalido o puntero NULL] o no encontro cliente con ese ID
 *          y [1] si ok.
 */
int cargarDescripcionNombre(int id,eCliente listaClientes[],int size_clientes,char auxNombre[]);




















//****************************************CLIENTE***********************************************************************************************************


/** \brief Imprime en pantalla el contenido de la lista de clientes con su id, nombre, cuit, direccion, localidad y
 * cantidad de pedidos pendientes.
 * * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \param listaPedidos* Puntero al array de pedidos
 * \param size_pedidos tamaño del array
 * \return Retorna  [0] si error [Tamaño invalido o puntero NULL] o si no hay pedidos que mostrar
 *          y [1] si ok.
 */
int mostrarClientes(eCliente listaClientes[],int size_clientes, ePedido listaPedidos[],int size_pedidos,eLocalidad localidades[], int size_localidades);



/** \brief Imprime en pantalla un cliente con su ID, nombre, cuit, direccion, localidad y
 * cantidad de pedidos pendientes.
 * \param  un cliente de la lista de clientes
 * \param listaPedidos* Puntero al array de pedidos
 * \param size_pedidos tamaño del array
 * \return Retorna  [0] si error [Tamaño invalido o puntero NULL]
 *          y [1] si ok.
 */
int mostrarUnCliente(eCliente unCliente,ePedido listaPedidos[],int size_pedidos,eLocalidad localidades[], int size_localidades);


/** \brief Elimina un cliente ingresando su ID (pone su bandera isEmpty en 1)
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \param listaPedidos* Puntero al array de pedidos
 * \param size_pedidos tamaño del array
 * \return  int Retorna (0) si error [Tamaño invalido o puntero NULL] o no se encontro cliente con el ID ingresado - (1) si Ok
 *
 */

int bajaClientes(eCliente listaClientes[], int size_clientes,ePedido listaPedidos[],int size_pedidos,eLocalidad localidades[], int size_localidades);


/** \brief Permite modificar la direccion y localidad de un cliente ingresando su ID
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \param listaPedidos* Puntero al array de pedidos
 * \param size_pedidos tamaño del array
 * \return  int Retorna (0) si error [Tamaño invalido o puntero NULL] o si se cancelaron los cambios- (1) si Ok
 *
*/
int modificarClientes(eCliente listaClientes[], int size_clientes,ePedido listaPedidos[],int size_pedidos,eLocalidad localidades[], int size_localidades);











#endif /* INFORMES_H_ */



