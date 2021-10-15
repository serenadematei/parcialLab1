/*
 * Informes.c
 *
 *  Created on: 12 oct 2021
 *      Author: Sere
 */

#include "Nexo.h"

#include "Pedido.h"
#include "Cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Get.h"
#include "Menu.h"
#include "Localidad.h"


//***********************************INFORMES**********************************************************************************************************
int informes(ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes,eLocalidad localidades[],int size_localidades){

	int todoOk=0;
	int opcion;

	if(listaClientes!=NULL && size_clientes>0 && listaPedidos!=NULL && size_pedidos>0){


		do{
			 opcion=menuInformes();

			 switch(opcion){
			 case 0:
				 break;
			 case 1://Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.
				 pedidosPendientesPorLocalidad(listaPedidos,size_pedidos,listaClientes,size_clientes,localidades,size_localidades);
				 break;
			 case 2://cantidad promedio Kg PP reciclados por cliente
				 cantidadPromedioKgPPReciclados(listaPedidos,size_pedidos,listaClientes,size_clientes);
				 break;

			 }

			 todoOk=1;
			}while(opcion!=0);



	}



	return todoOk;
}


int pedidosPendientesPorLocalidad(ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes,eLocalidad localidades[],int size_localidades){

	int todoOk=0;
	int contador=0;
	int idLocalidad;
    char auxDescripcion[50];


	if(listaClientes!=NULL && size_clientes>0 && listaPedidos!=NULL && size_pedidos>0){


		mostrarLocalidades(localidades,size_localidades);



		utn_getNumero(&idLocalidad,"Ingrese ID localidad: ","Opcion invalida.\n",10,17,10);
			for(int i=0; i<size_clientes; i++){
				if(!listaClientes[i].isEmpty && listaClientes[i].idLocalidad==idLocalidad){
					for(int j=0; j<size_pedidos; j++){
						if(!listaPedidos[j].isEmpty && listaPedidos[j].idCliente==listaClientes[i].id && !listaPedidos[j].estado){
							contador++;
                            todoOk=1;
						}
					}
				}



			//cargar nombre localidad
			printf("Los pedidos pendientes de la localidad %s son: %d\n",auxDescripcion,contador);
			system("pause");
		}

	}


	return todoOk;
}




int cantidadPromedioKgPPReciclados(ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes){

	int todoOk=0;
	float total=0;
	int contadorPedidos=0;
	float promedio=0;

	for(int i=0; i<size_clientes; i++){

		if(!listaClientes[i].isEmpty){
         	printf("Cliente:  %s\n",listaClientes[i].nombreEmpresa);


         	contadorPedidos=contadorPedidosProcesadosPorCliente(listaPedidos,size_pedidos,listaClientes[i].id);
         	total=contadorKgPolipropilenoPorCliente(listaClientes[i].id,listaPedidos,size_pedidos);

         	promedio=calcularPromedio(contadorPedidos,total);


         	if(promedio>0){
			printf("Total de kg de Polipropileno reciclado promedio : %.2f\n\n",promedio);
         	}else
         	{
         		printf("El cliente aun no presenta pedidos procesados\n\n");
         	}



			todoOk=1;
		}
	}




	return todoOk;
}





//***********************************GETS Y CARGAS**********************************************************************************************************
int cargarCantidadPendientes(int id,ePedido listaPedidos[],int size_pedidos, int* cantidadPendientes)
{
    int todoOk=0;
    int contador=0;

    if(id>=2000 && listaPedidos !=NULL && size_pedidos>0 && cantidadPendientes!=NULL)
       {

    	  contador = contadorPedidosPendientesPorCliente(listaPedidos,size_pedidos,id);
          *cantidadPendientes=contador;
          todoOk=1;
       }

 return todoOk;
}




int getPedidosPendientes(int id,ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes){

	int todoOk=0;


	if(listaClientes!=NULL && size_clientes>0 && listaPedidos!=NULL && size_pedidos>0){

		for(int i=0; i<size_pedidos;i++){
				if(!listaPedidos[i].isEmpty && listaPedidos[i].idCliente==id && !listaPedidos[i].estado){
					mostrarUnPedidoPendiente(listaPedidos[i],listaClientes,size_clientes);
				    todoOk=1;
				}
			}
	}


	return todoOk;
}


int getPedidosProcesados(int id,ePedido listaPedidos[],int size_pedidos,eCliente listaClientes[],int size_clientes){

	int todoOk=0;


	if(listaClientes!=NULL && size_clientes>0 && listaPedidos!=NULL && size_pedidos>0){
		for (int i = 0; i < size_pedidos; i++) {
				if (!listaPedidos[i].isEmpty && listaPedidos[i].idCliente == id
							&& listaPedidos[i].estado) {
				 mostrarUnPedidoProcesado(listaPedidos[i],listaClientes,size_clientes);
                 todoOk=1;
			}
		}
	}



	return todoOk;
}


int cargarDescripcionNombre(int id,eCliente listaClientes[],int size_clientes,char auxNombre[]){

	int todoOk=0;


	if(id>=2000 && listaClientes!=NULL && size_clientes>0 && auxNombre!=NULL){

		for(int i=0; i<size_clientes;i++){
			if(listaClientes[i].id==id && !listaClientes[i].isEmpty){
				strcpy(auxNombre,listaClientes[i].nombreEmpresa);
				break;
				todoOk=1;
			}
		}
	}

	return todoOk;
}


//***********************************CONTADORES**********************************************************************************************************
int contadorKgPolipropilenoPorCliente(int id,ePedido listaPedidos[],int size_pedidos){

	float acumulador=0;
    float total=0;

	for(int i=0; i<size_pedidos; i++){
		if(!listaPedidos[i].isEmpty && listaPedidos[i].idCliente==id && listaPedidos[i].estado){
			acumulador+=listaPedidos[i].kgPolipropileno;
		}
	}


    total=acumulador;
	return total;
}

int contadorPedidosProcesadosPorCliente(ePedido listaPedidos[],int size_pedidos,int id){

	int contador=0;


	for(int i=0; i<size_pedidos; i++){
		if(!listaPedidos[i].isEmpty && listaPedidos[i].idCliente==id && listaPedidos[i].estado){
			contador++;
		}
	}


	return contador;
}



int contadorPedidosPendientesPorCliente(ePedido listaPedidos[],int size_pedidos,int id){

	int contador=0;


	for(int i=0; i<size_pedidos; i++){
		if(!listaPedidos[i].isEmpty && listaPedidos[i].idCliente==id && !listaPedidos[i].estado){
			contador++;
		}
	}


	return contador;
}

//***********************************CALCULOS**********************************************************************************************************



float calcularPromedio(int cantidad, float total){

	float promedio;


	promedio=(float)total/cantidad; //cantidad total de kg dividido pedidos del cliente


	return promedio;
}


//***********************************CLIENTES**********************************************************************************************************



int bajaClientes(eCliente listaClientes[], int size_clientes,ePedido listaPedidos[],int size_pedidos,eLocalidad localidades[], int size_localidades) {

	int todoOk=0;
	int indice;
	char opcion;
	int id;

	if (listaClientes != NULL && size_clientes > 0) {

		mostrarClientes(listaClientes, size_clientes,listaPedidos,size_pedidos,localidades,size_localidades);
		id = getOnlyInt("Ingrese ID del cliente a dar de baja ","Opcion invalida.\n");
        indice = buscarClientePorId(listaClientes, size_clientes, id);

		if (indice == -1) {
			printf("No se encontro cliente con ese ID.\n");
		} else {

			printf("\nCliente encontrado:\n");
			imprimirEncabezadoClientes();
			mostrarUnCliente(listaClientes[indice],listaPedidos,size_pedidos,localidades,size_localidades);

			utn_getCaracter(&opcion, "Confirma la baja de este cliente? (s/n):","Opcion invalida.\n", 's', 'n', 10);
			if (opcion == 's') {
				listaClientes[indice].isEmpty = 1;
				printf("El cliente ha sido de dado de baja con exito\n");
				todoOk=1;
			} else {
				printf("\nBaja cancelada. Volviendo al menu principal...\n ");

			}
		}

	}
	return todoOk;
}




int mostrarClientes(eCliente listaClientes[],int size_clientes, ePedido listaPedidos[],int size_pedidos,eLocalidad localidades[], int size_localidades){

	int todoOk=0;
	int flag=1;

	if(listaClientes!=NULL && size_clientes>0){

		printf("\n\n               *****************LISTA DE CLIENTES********************\n");
		imprimirEncabezadoClientes();

		for (int i = 0; i < size_clientes; i++) {
			if (!listaClientes[i].isEmpty) {
				mostrarUnCliente(listaClientes[i],listaPedidos,size_pedidos,localidades,size_localidades);
				todoOk=1;
				flag = 0;

			}

		}


			if(flag){
				printf("\nNo hay clientes que mostrar\n");
			}


	}

	return todoOk;

}

int mostrarUnCliente(eCliente unCliente,ePedido listaPedidos[],int size_pedidos,eLocalidad localidades[], int size_localidades){


	   int todoOk=0;
	   int cantidadPendientes=0;

	   if(listaPedidos !=NULL && size_pedidos>0){
		   cargarCantidadPendientes(unCliente.id,listaPedidos,size_pedidos,&cantidadPendientes);
		  	    	printf("%5d   |      %10s    |     %10s    |       %10s    |      %d     | %5d     \n",
		  	    						unCliente.id,
		  	    						unCliente.nombreEmpresa,
		  								unCliente.cuit,
		  								unCliente.direccion,
		  								unCliente.idLocalidad,
		  								cantidadPendientes
		  	      );
		  	    todoOk=1;
	   }



    return todoOk;
}

