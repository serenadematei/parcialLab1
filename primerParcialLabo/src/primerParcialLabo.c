/*
 ============================================================================
 Name        : primerParcialLabo.c
 Author      : Serena Dematei
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Get.h"
#include "Menu.h"
#include "Cliente.h"
#include "Pedido.h"
#include "Datos.h"
#include "Nexo.h"
#include "Localidad.h"

#define TAMCLI 100 // tamaño de la lista de clientes 100
#define TAMPED 1000 // tamano de lista de pedidos: 1000
#define TAMLOC 8 //tamañao lista de localidades

int main(void) {

	setbuf(stdout,NULL);
	int opcion;
	char salida='n';
	int idClientes=2000;
	int idPedidos=500;


	ePedido listaPedidos[TAMPED];
	eCliente listaClientes[TAMCLI];


	inicializarClientes(listaClientes,TAMCLI);
	inicializarPedidos(listaPedidos,TAMPED);
	eLocalidad localidades[TAMLOC]={
			{10,"Avellaneda"},
			{11,"Mercedes"},
			{12,"Pilar"},
			{13,"Lujan"},
			{14,"Quilmes"},
			{15,"Alberti"},
			{16,"Belgrano"},
			{17,"Avellaneda"},

	};

	hardcodearClientes(listaClientes,TAMCLI,10,&idClientes);
		hardcodearPedidos(listaPedidos,TAMPED,15,&idPedidos);






	do{

			   opcion=menu();

		    	switch(opcion){
		    	    case 1:
		    	    	if(altaClientes(listaClientes,TAMCLI, &idClientes,localidades,TAMLOC)){
		    	    		printf("Cliente dado de alta con exito\n");
		    	    	}
		    	    	system("pause");
		    	        break;
		    	    case 2:
		    	    	if(modificarClientes(listaClientes,TAMCLI,listaPedidos,TAMPED,localidades,TAMLOC)){
		    	    		printf("Cliente modificado con exito\n");
		    	    	}
		    	    	system("pause");
		    	        break;
		    	    case 3:
		    	    	bajaClientes(listaClientes,TAMCLI,listaPedidos,TAMPED,localidades,TAMLOC);
		    	    	system("pause");
		    	    	break;
		    	    case 4://ALTA PEDIDO
		    	    	if(crearPedidoDeRecoleccion(listaPedidos,TAMPED,listaClientes,TAMCLI,&idPedidos,localidades,TAMLOC)){
		    	    		printf("Pedido creado exitosamente\n");
		    	    	}
		    	    	else
		    	    	{
		    	    		printf("Problema al crear pedido\n");
		    	    	}
		    	    	system("pause");

		    	    	break;
		    	    case 5://PROCESAR RESIDUOS
		    	    	if(procesarResiduos(listaPedidos,TAMPED,listaClientes,TAMCLI)){
		    	    		printf("Residuos procesados con exito.\n");
		    	    	}
		    	    	system("pause");
		    	    	break;
		    	    case 6: //IMPRIMIR LISTA DE CLIENTES
		    	    	mostrarClientes(listaClientes,TAMCLI,listaPedidos,TAMPED,localidades,TAMLOC);
		    	    	system("pause");
		    	    	break;
		    	    case 7: //IMPRIMIR PEDIDOS PENDIENTES
		    	    	if (contadorPedidosPendientes(listaPedidos, TAMPED)>0){

		    	    	  listarPedidosPendientes(listaPedidos, TAMPED, listaClientes,TAMCLI);
		    	    	}
		    	    	else
		    	    	{
		    	    			printf("\nNo hay pedidos pendientes.\n");
		    	    	}
		    	    	system("pause");
		    	    	break;
		    	    case 8://IMPRIMIR PEDIDOS PROCESADOS
		    	    	if(contadorPedidosProcesados(listaPedidos,TAMPED)>0){
		    	    		listarPedidosProcesados(listaPedidos,TAMPED,listaClientes,TAMCLI);
		    	    	}
		    	    	else
		    	    	{
		    	    		printf("\nNo hay pedidos procesados.\n");
		    	    	}
		    	    	 system("pause");
		    	    	 break;
		    	    case 9:
		    	    	informes(listaPedidos,TAMPED,listaClientes,TAMCLI,localidades,TAMLOC);
		    	    	system("pause");
		    	    	break;

		    	    case 10: //baja pedido
		    	    	bajaPedidos(listaPedidos,TAMPED,listaClientes,TAMCLI);
		    	    	system("pause");
		    	    	break;
		    	    case 11://modificar pedido
		    	    	modificarPedidos(listaPedidos,TAMPED,listaClientes,TAMCLI);
		    	    	break;
		    	    case 0:
		    	    	verificarSalida(&salida);
		    	    	break;
		    	    default:
		    	    	printf("Opcion invalida.\n\n");
		    	    	system("pause");
		    	    	break;
		    	}

		    }while(salida=='n');

	return EXIT_SUCCESS;
}

