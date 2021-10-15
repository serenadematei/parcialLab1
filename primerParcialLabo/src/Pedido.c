/*
 * Pedido.c
 *
 *  Created on: 11 oct 2021
 *      Author: Sere
 */
#include "Pedido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Get.h"
#include "Cliente.h"
#include "Menu.h"
#include "Nexo.h"
#include "Localidad.h"



#define PENDIENTE 0
#define COMPLETADO 1


//****************************************ABM***********************************************************************************************************
int inicializarPedidos(ePedido listaPedidos[],int size_pedidos){

	int todoOk=0;
	if(listaPedidos!=NULL && size_pedidos>0){
		for(int i=0; i<size_pedidos; i++){
			listaPedidos[i].isEmpty=1;
			listaPedidos[i].estado=0;
			listaPedidos[i].kgPolietilenoAltaDen=0;
			listaPedidos[i].kgPolietilenoBajaDen=0;
			listaPedidos[i].kgPolipropileno=0;

			todoOk=1;
		}
	}

	return todoOk;
}


int crearPedidoDeRecoleccion(ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes,int* id,eLocalidad localidades[], int size_localidades){

	int todoOk=0;
	int idCliente;
	int indicePedidos;
	int indiceCliente;
	ePedido nuevoPedido; //variable auxiliar para guardar datos

	if(listaPedidos!=NULL && size_pedidos>0 &&
			listaClientes!=NULL && size_clientes>0){


		indicePedidos= buscarLibrePedidos(listaPedidos, size_pedidos);
		if(indicePedidos==-1){
			printf("No hay lugar en el sistema para otro pedido.\n");

		}
		else {
			mostrarClientes(listaClientes, size_clientes,listaPedidos,size_pedidos,localidades,size_localidades);
			idCliente = getOnlyInt("Ingrese ID del cliente: ","Opcion invalida.\n");
			indiceCliente = buscarClientePorId(listaClientes, size_clientes, idCliente);  //pido el ingreso de un cliente y evaluo si existe

			if (indiceCliente == -1) {
				printf("No se encontro cliente con ese ID.\n");
			} else {

				nuevoPedido.id = *id;
				nuevoPedido.estado = PENDIENTE;
				nuevoPedido.idCliente = idCliente;
				utn_getNumeroFlotante(&nuevoPedido.kilos,"Ingrese kilos a recolectar: ", "Opcion invalida.\n", 1,999999, 10);
				nuevoPedido.isEmpty = 0;


				listaPedidos[indicePedidos] = nuevoPedido;
				(*id)++;
				todoOk=1;
			}

		}





	}

	return todoOk;
}


int bajaPedidos(ePedido listaPedidos[], int size_pedidos,eCliente listaClientes[], int size_clientes)
{
    int todoOk=0;
    int indice;
    int id;
    char opcion;


    mostrarPedidos(listaPedidos, size_pedidos,listaClientes,size_clientes);
    id = getOnlyInt("Ingrese ID del pedido a dar de baja: ","Opcion invalida.\n");
    indice = buscarPedidoPorId(listaPedidos, size_pedidos, id);


    if (indice == -1) {
		printf("No existe un pedido con el ID %d\n", id);
	} else {
		printf("\nPedido encontrado:\n");
		encabezadoPedidos();
		mostrarUnPedido(listaPedidos[indice],listaClientes,size_clientes);
		utn_getCaracter(&opcion, "Confirma la baja de este pedido? (s/n):","Opcion invalida.\n", 's', 'n', 10);

		if (opcion == 's') {
			listaPedidos[indice].isEmpty = 1;
			printf("El pedido ha sido de dado de baja con exito\n");
			todoOk = 1;
		} else {
			printf("\nBaja cancelada. Volviendo al menu principal...\n ");

		}

	}


   return todoOk;
}

int modificarPedidos(ePedido listaPedidos[], int size_pedidos,eCliente listaClientes[], int size_clientes) {

	int todoOk = 0;

	int opcion;
	int id;
	int indice;
	int flagKilos= 1; //las funciones utn_get retornan CERO cuando están OK, por lo que las banderas se inicializan en 1

	ePedido unPedido;


	if (listaPedidos!= NULL && size_pedidos> 0) {

		mostrarPedidos(listaPedidos,size_pedidos,listaClientes,size_clientes);
		id=getOnlyInt("Ingrese ID del pedido a modificar: ","Opcion invalida.\n");
		indice = buscarPedidoPorId(listaPedidos,size_pedidos,id);


		if (indice == -1) {
			printf("No se encontro pedido con ese ID.\n");
		} else {

			encabezadoPedidos();
			mostrarUnPedido(listaPedidos[indice],listaClientes,size_clientes);

		do {

			opcion=menuModificacionesPedidos();

			switch (opcion) {
			case 1:
				flagKilos=utn_getNumeroFlotante(&unPedido.kilos,"Ingrese modificacion de cantidad de kilos: ", "Opcion invalida.\n", 1,999999, 10);
			break;
			case 2:
				if(!flagKilos){
					listaPedidos[indice].kilos=unPedido.kilos;
				}
				todoOk=1;
				printf("\n\nCambios guardados con exito. Volviendo al menu principal...\n");
				system("pause");
			break;
			case 3:
				printf("\n\nCambios cancelados. Volviendo al menu principal...\n");
				system("pause");
			break;
			}
		}while(opcion!=3 && opcion!=4);

		}
	}

	return todoOk;
}






int procesarResiduos(ePedido listaPedidos[], int size_pedidos,eCliente listaClientes[], int size_clientes){

	int todoOk=0;
	int id;
	int indice;
	float kilosDelPedido;
	float kilosAProcesar;
	float kgLDPE;
	float kgHDPE;
	float kgPP;


	if(listaPedidos!=NULL && size_pedidos>0){


		mostrarPedidos(listaPedidos,size_pedidos,listaClientes,size_clientes);
		printf("\n\n****PROCESAR RESIDUOS****\n");
		id=getOnlyInt("Ingrese ID del pedido: ","Opcion invalida.\n");
		indice = buscarPedidoPorId(listaPedidos,size_pedidos,id);

		if(indice==-1){
			printf("No se encontro pedido con ese ID.\n");
		}else{



			kilosDelPedido=listaPedidos[indice].kilos;
			printf("-------------------------------------------\n");
			printf("Los kilos totales del pedido son %.2f kg\n",kilosDelPedido);
			printf("-------------------------------------------\n");
			kilosAProcesar=pedirKilosDeResiduosAProcesar(&kgHDPE,&kgLDPE,&kgPP);
			printf("\nLos kilos totales a procesar son %.2f kg\n",kilosAProcesar);

			while(kilosDelPedido<kilosAProcesar){
				printf("ERROR: La cantidad de kilos a procesar excede los kilos del pedido. Reintente. \n\n\n");
				printf("-------------------------------------------\n");
				printf("\nLos kilos totales del pedido son %.2f kg\n",kilosDelPedido);
				printf("-------------------------------------------\n");
				kilosAProcesar=pedirKilosDeResiduosAProcesar(&kgHDPE,&kgLDPE,&kgPP);
			}

			listaPedidos[indice].estado=COMPLETADO;
			listaPedidos[indice].kgPolietilenoAltaDen=kgHDPE;
			listaPedidos[indice].kgPolietilenoBajaDen=kgLDPE;
			listaPedidos[indice].kgPolipropileno=kgPP;

			todoOk=1;

		}

	}
	return todoOk;

}

//****************************************BUSQUEDAS**********************************************************************************************************

int buscarLibrePedidos(ePedido listaPedidos[],int size_pedidos){

	int indice=-1;

	if(listaPedidos!=NULL && size_pedidos>0){
		for(int i=0; i<size_pedidos; i++){
			if(listaPedidos[i].isEmpty==1){
				indice=i;
			}
		}
	}

	return indice;
}


int buscarPedidoPorId(ePedido listaPedidos[], int size_pedidos,int id){

	int indice=-1;

		if(listaPedidos!=NULL && size_pedidos>0){
			for(int i=0; i<size_pedidos; i++){
				if(!listaPedidos[i].isEmpty && listaPedidos[i].id==id){
				    indice=i;
				    break;
				}
			}
		}

	return indice;
}


//****************************************LISTADOS**********************************************************************************************************

int mostrarPedidos(ePedido listaPedidos[],int size_pedidos, eCliente listaClientes[], int size_clientes){

	int todoOk=0;
    int flag=0;

	if (listaPedidos != NULL && size_pedidos > 0) {
		printf("\n\n               *****************LISTA DE PEDIDOS********************\n");
		encabezadoPedidos();
		for (int i = 0; i < size_pedidos; i++) {
			if (!listaPedidos[i].isEmpty) {
				mostrarUnPedido(listaPedidos[i],listaClientes,size_clientes);
				flag = 1;
				todoOk = 1;
			}

		}
		if (!flag) {
			printf("No hay pedidos que mostrar\n\n");
		}

	}

	return todoOk;
}




int mostrarUnPedido(ePedido unPedido,eCliente listaClientes[], int size_clientes){


	int todoOk=0;
	char auxNombre[50];
	char auxEstado[50];



	if(listaClientes!=NULL && size_clientes>0){

	cargarDescripcionNombre(unPedido.idCliente,listaClientes,size_clientes,auxNombre);
	if(unPedido.estado){
	   strcpy(auxEstado,"Completado");
	}else if(!unPedido.estado){
		strcpy(auxEstado,"Pendiente");
	}



	 printf("%5d        |    %10s        |        %7.2f      |       %10s \n",unPedido.id,auxNombre,unPedido.kilos,auxEstado);
	 todoOk=1;
	}



	return todoOk;
}




int mostrarUnPedidoPendiente(ePedido unPedido,eCliente listaClientes[], int size_clientes){

	int todoOk=0;
	char cuit[50];
	char direccion[50];

    if(listaClientes!=NULL && size_clientes>0){
    	cargarDatosDelClientePorId(unPedido.idCliente,listaClientes,size_clientes,direccion,cuit);
        printf("%10s   |    %10s        |  %5.2f \n",cuit,direccion,unPedido.kilos);

        todoOk=1;
    }

    return todoOk;
}


int mostrarUnPedidoProcesado(ePedido unPedido,eCliente listaClientes[], int size_clientes){

	int todoOk=0;
	char cuit[50];
	char direccion[50];



	if(listaClientes!=NULL && size_clientes>0){
		cargarDatosDelClientePorId(unPedido.idCliente,listaClientes,size_clientes,direccion,cuit);
		printf("%10s   |    %10s        |     %0.2f    |     %0.2f    |  %0.2f \n",cuit,direccion,unPedido.kgPolietilenoAltaDen,
					unPedido.kgPolietilenoBajaDen,unPedido.kgPolipropileno);
		todoOk=1;
	}

	return todoOk;
}







int listarPedidosPendientes(ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes){

	int todoOk=0;

	printf("\n\n                     LISTADO DE PEDIDOS PENDIENTES      \n");
	encabezadoPendientes();
	for(int i=0; i<size_clientes;i++){
		if(!listaClientes[i].isEmpty){
			getPedidosPendientes(listaClientes[i].id,listaPedidos,size_pedidos,listaClientes,size_clientes);
			todoOk=1;
		}
	}
	return todoOk;
}


int listarPedidosProcesados(ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes){

	int todoOk=0;


	printf("\n\n                     LISTADO DE PEDIDOS PROCESADOS      \n");

	encabezadoProcesados();
	for (int i = 0; i < size_clientes; i++) {
		if (!listaClientes[i].isEmpty) {
			getPedidosProcesados(listaClientes[i].id, listaPedidos,size_pedidos, listaClientes, size_clientes);
			todoOk = 1;
		}

	}


	return todoOk;
}

//****************************************CONTADORES**********************************************************************************************************

int contadorPedidosProcesados(ePedido listaPedidos[],int size_pedidos){

	int contadorPedidos=0;


	for(int i=0; i<size_pedidos; i++){
		if(!listaPedidos[i].isEmpty && listaPedidos[i].estado){
			contadorPedidos++;
		}
	}



	return contadorPedidos;
}


int contadorPedidosPendientes(ePedido listaPedidos[],int size_pedidos){

	int contadorPedidos=0;


	for(int i=0; i<size_pedidos; i++){
		if(!listaPedidos[i].isEmpty && !listaPedidos[i].estado){
			contadorPedidos++;
		}
	}



	return contadorPedidos;
}

//****************************************INPUTS**********************************************************************************************************

float pedirKilosDeResiduosAProcesar(float* kgHDPE, float* kgLDPE, float* kgPP) {

	float total=0;
	float auxHDPE;
	float auxLDPE;
	float auxPP;

	printf("\nCANTIDADES A PROCESAR:\n");
	utn_getNumeroFlotante(&auxHDPE,
			"Ingrese KG de Polietileno de alta densidad: ",
			"Opcion invalida.\n", 0, 999999, 10);

	utn_getNumeroFlotante(&auxLDPE,
			"Ingrese KG de Polietileno de baja densidad: ",
			"Opcion invalida.\n", 0, 999999, 10);

	utn_getNumeroFlotante(&auxPP,
			"Ingrese KG de Polipropileno: ", "Opcion invalida.\n", 0, 999999,
			10);


	total=auxHDPE+auxLDPE+auxPP;

	*kgHDPE=auxHDPE;
	*kgLDPE=auxLDPE;
	*kgPP=auxPP;

	return total;

}
