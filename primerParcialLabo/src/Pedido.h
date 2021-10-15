/*
 * Pedido.h
 *
 *  Created on: 11 oct 2021
 *      Author: Sere
 */


#ifndef PEDIDO_H_
#define PEDIDO_H_
#include "Cliente.h"


typedef struct{

	int id;
	float kilos;
	int estado;
	int idCliente;
	int isEmpty;

	//tipos de residuos
	float kgPolietilenoAltaDen;
	float kgPolietilenoBajaDen;
	float kgPolipropileno;
}ePedido;


int inicializarPedidos(ePedido listaPedidos[],int size_pedidos);
/***********************************ABM**********************************************************************************************************





/** \brief Agrega en una lista existente de pedidos un nuevo pedido
 *en el lugar libre mas proximo
 * \param listaPedidos* Puntero al array de pedidos
 * \param size_pedidos tamaño del array
  \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \param int* id puntero al proximo valor de ID que tomara el pedido agregado
 * \return  int Retorna (0) si error [Tamaño invalido o puntero NULL] o falta de lugar para otro pedido - (1) si Ok
*/
int crearPedidoDeRecoleccion(ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes,int* id,eLocalidad localidades[], int size_localidades);



/** \brief Elimina un pedido ingresando su ID (pone su bandera isEmpty en 1)
 *
 * \param listaPedidos* Puntero al array de pedidos
 * \param size_pedidos tamaño del array
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return  int Retorna (0) si error [Tamaño invalido o puntero NULL] o no se encontro pedido con el ID ingresado - (1) si Ok
 *
 */
int bajaPedidos(ePedido listaPedidos[], int size_pedidos,eCliente listaClientes[], int size_clientes);



/** \brief Permite modificar los kilos de un pedido ya realizado ingresando su ID
  * \param listaPedidos* Puntero al array de pedidos
 * \param size_pedidos tamaño del array
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return  int Retorna (0) si error [Tamaño invalido o puntero NULL] o si se cancelaron los cambios- (1) si Ok
 *
 */
int modificarPedidos(ePedido listaPedidos[], int size_pedidos,eCliente listaClientes[], int size_clientes);



/** \brief Permite definir cuantos kilos del total de kilos ingresados seran procesados dentro de los diferentes tipos de plastico
 * ingresando el ID del pedido
  * \param listaPedidos* Puntero al array de pedidos
 * \param size_pedidos tamaño del array
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return  int Retorna (0) si error [Tamaño invalido o puntero NULL] o si no se encontro pedido con ese ID- (1) si Ok
 *
 */
int procesarResiduos(ePedido listaPedidos[], int size_pedidos,eCliente listaClientes[], int size_clientes);











//**********************************BUSQUEDAS**********************************************************************************************************

/** \brief busca una posicion libre en el array de pedidos
 *
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \return int Retorna (-1) si error [Tamaño invalido o puntero NULL] o si no encontro espacio libre -
 *        o (indice) posicion libre que encontro si Ok.
 *
 */
int buscarLibrePedidos(ePedido listaPedidos[],int size_pedidos);


/** \brief encuentra un pedido por su id y retorna el indice de su posicion en el array.
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \param int id del pedido para encontrarlo dentro del array
 * \return Retorna el indice de la posicion del pedido o [-1] si error [Tamaño invalido o puntero NULL]
 *          o pedido no encontrado.
 *
 */
int buscarPedidoPorId(ePedido listaPedidos[], int size_pedidos,int id);



//***********************************LISTADOS**********************************************************************************************************

/** \brief Imprime en pantalla el contenido de la lista de pedidos con su id, y el nombre, kilos totales y
 * estado (pendiente/completado) del pedido
 * \param listaPedidos* Puntero al array de pedidos
 * \param size_pedidos tamaño del array
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return Retorna  [0] si error [Tamaño invalido o puntero NULL] o si no hay pedidos que mostrar
 *          y [1] si ok.
 */
int mostrarPedidos(ePedido listaPedidos[],int size_pedidos, eCliente listaClientes[], int size_clientes);


/** \brief Imprime en pantalla un pedido con su ID, nombre de empresa, kilos totales y estado
 * \param  un pedido de la lista de pedidos
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return Retorna  [0] si error [Tamaño invalido o puntero NULL]
 *          y [1] si ok.
 */
int mostrarUnPedido(ePedido unPedido,eCliente listaClientes[], int size_clientes);


/** \brief Imprime la lista de pedidos procesados con cuit y direccion del cliente, y cantidad de kilos reciclados
 * de cada tipo de plastico
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return Retorna  [0] si error [Tamaño invalido o puntero NULL]
 *          y [1] si ok.
 */
int listarPedidosProcesados(ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes);


/** \brief Imprime en pantalla un pedido con estado completado, con el cuit y direccion del cliente y
 *  la cantidad de kilos reciclados de cada tipo de plastico
 * \param  un pedido de la lista de pedidos
 *  * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return Retorna  [0] si error [Tamaño invalido o puntero NULL]
 *          y [1] si ok.
 */
int mostrarUnPedidoProcesado(ePedido unPedido,eCliente listaClientes[], int size_clientes);


/** \brief Imprime la lista de pedidos pendientes con cuit y direccion del cliente, y cantidad de kilos a recolectar
 * listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return Retorna  [0] si error [Tamaño invalido o puntero NULL]
 *          y [1] si ok.
 */
int listarPedidosPendientes(ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes);


/** \brief Imprime en pantalla un pedido con estado pendiente, con su id y la direccion y cuit del cliente.
 *   un pedido de la lista de pedidos
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \param listaClientes* Puntero al array de clientes
 * \param size_clientes tamaño del array
 * \return Retorna  [0] si error [Tamaño invalido o puntero NULL]
 *          y [1] si ok.
 */
int mostrarUnPedidoPendiente(ePedido unPedido,eCliente listaClientes[], int size_clientes);



//***********************************INPUTS**********************************************************************************************************


/** \brief Pide el ingreso de la cantidad de kilos a procesar de cada tipo de plastico y los suma
 * \param  puntero a tipo de plastico HDPE
 * \param  puntero a tipo de plastico LDPE
 * \param  puntero a tipo de plastico PP
 * \return Retorna la cantidad total de kilos
 */
float pedirKilosDeResiduosAProcesar(float* kgHDPE, float* kgLDPE, float* kgPP);




//***********************************CONTADORES**********************************************************************************************************


/** \brief recorre la lista de pedidos en busca de pedidos cuyo estado sea 0 (pendiente).
 * cada vez que encuentra uno, lo suma.
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \return Retorna la cantidad de pedidos pendientes encontrados
 *
 */
int contadorPedidosPendientes(ePedido listaPedidos[],int size_pedidos);



/** \brief recorre la lista de pedidos en busca de pedidos cuyo estado sea 1 (completado).
 * cada vez que encuentra uno, lo suma.
 * \param listaPedidos* Puntero al array de pedidos
 * \param  size_pedidos tamaño del array
 * \return Retorna la cantidad de pedidos procesados encontrados
 *
 */
int contadorPedidosProcesados(ePedido listaPedidos[],int size_pedidos);

#endif /* PEDIDO_H_ */

