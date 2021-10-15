/*
 * Cliente.c
 *
 *  Created on: 11 oct 2021
 *      Author: Sere
 */
#include "Cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Get.h"
#include "Menu.h"
#include "Datos.h"
#include "Nexo.h"
#include "Localidad.h"


//****************************************ABM***********************************************************************************************************
int inicializarClientes(eCliente listaClientes[],int size_clientes){

	int todoOk=0;

	if(listaClientes!=NULL && size_clientes>0){
		for(int i=0; i<size_clientes; i++){
			listaClientes[i].isEmpty=1;
			todoOk=1;
		}
	}


	return todoOk;
}

int altaClientes(eCliente listaClientes[],int size_clientes, int* id, eLocalidad localidades[], int size_localidades){

	int todoOk=0;
	int indice;

	eCliente nuevoCliente;

	if(listaClientes!=NULL && size_clientes>0 && id!=NULL){

		indice=buscarLibreClientes(listaClientes,size_clientes);
		if(indice==-1){
			printf("No hay lugar en el sistema para otro cliente\n");
		}
		else
		{
			printf("     Alta cliente\n");
			printf("ID Cliente: %d\n", *id);
			nuevoCliente.id=*id;
			utn_getNombre(nuevoCliente.nombreEmpresa,"Ingrese nombre de la empresa: ","Opcion invalida.\n",50,10);
			utn_getTextoEspecial(nuevoCliente.cuit,"Ingrese cuit ej(00-12345678-0): ", "Opcion invalida\n",50,10);
			utn_getTextoEspecial(nuevoCliente.direccion,"Ingrese direccion ej(10 n100):", "Opcion invalida\n",50,10);

			mostrarLocalidades(localidades,size_localidades);
			utn_getNumero(&nuevoCliente.idLocalidad,"Ingrese ID localidad: ","Opcion invalida.\n",10,17,10);



	        nuevoCliente.isEmpty=0;
	     	listaClientes[indice]=nuevoCliente;
	     	(*id)++;

	        todoOk=1;

		}


	}

	return todoOk;
}


int modificarClientes(eCliente listaClientes[], int size_clientes,ePedido listaPedidos[],int size_pedidos,eLocalidad localidades[], int size_localidades) {

	int todoOk = 0;

	int opcion;
	int id;
	int indice;
	int flagDireccion = 1; //las funciones utn_get retornan CERO cuando están OK, por lo que las banderas se inicializan en 1
	int flagLocalidad = 1;
	eCliente unCliente;


	if (listaClientes != NULL && size_clientes> 0) {

		mostrarClientes(listaClientes,size_clientes,listaPedidos,size_pedidos,localidades,size_localidades);
		id=getOnlyInt("Ingrese ID del cliente a modificar: ","Opcion invalida.\n");
		indice = buscarClientePorId(listaClientes,size_clientes,id);


		if (indice == -1) {
			printf("No se encontro cliente con ese ID.\n");
		} else {

			imprimirEncabezadoClientes();
			mostrarUnCliente(listaClientes[indice],listaPedidos,size_pedidos,localidades,size_localidades);




		do {

			opcion=menuModificaciones();

			switch (opcion) {
			case 1:
				flagDireccion=utn_getTextoEspecial(unCliente.direccion,"Ingrese nueva direccion: ", "Opcion invalida\n",50,10);
			break;
			case 2:
				mostrarLocalidades(localidades,size_localidades);
				flagLocalidad=utn_getNumero(&unCliente.idLocalidad,"Ingrese ID de nueva localidad: ","Opcion invalida.\n",10,17,10);
			break;
			case 3:
				if(!flagDireccion){
				    strcpy(listaClientes[indice].direccion,unCliente.direccion);
				}
				if(!flagLocalidad){
					listaClientes[indice].idLocalidad=unCliente.idLocalidad;
				}
				todoOk=1;
				printf("\n\nCambios guardados con exito. Volviendo al menu principal...\n");
				system("pause");
			break;
			case 4:
				printf("\n\nCambios cancelados. Volviendo al menu principal...\n");
				system("pause");
			break;
			}
		}while(opcion!=3 && opcion!=4);

		}
	}

	return todoOk;
}





//****************************************BUSQUEDAS***********************************************************************************************************
int buscarLibreClientes(eCliente listaClientes[],int size_clientes){

	int indice=-1;

		if(listaClientes!=NULL && size_clientes>0){
           for(int i=0; i<size_clientes; i++){
        	   if(listaClientes[i].isEmpty){
        		   indice=i;
        		   break;
        	   }
           }
		}

		return indice;
}

int buscarClientePorId(eCliente listaClientes[],int size_clientes,int id){

	int indice=-1;

		if(listaClientes!=NULL && size_clientes>0){
			for(int i=0; i<size_clientes; i++){
				if(!listaClientes[i].isEmpty && listaClientes[i].id==id){
				    indice=i;
				    break;
				}
			}
		}

		return indice;
}





//****************************************CARGAS***********************************************************************************************************

int cargarDatosDelClientePorId(int id,eCliente listaClientes[],int size_clientes,char aux1[],char aux2[]){

	int todoOk=0;


		if(id>=2000 && listaClientes!=NULL && size_clientes>0 && aux1!=NULL){

			for(int i=0; i<size_clientes;i++){
				if(listaClientes[i].id==id && !listaClientes[i].isEmpty){
					strcpy(aux1,listaClientes[i].direccion);
					strcpy(aux2,listaClientes[i].cuit);

					break;
					todoOk=1;
				}
			}
		}

		return todoOk;

}


