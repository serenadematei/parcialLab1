/* Primer parcial laboratorio 1
 * Menu.c
 *
 *  Created on: 11 oct 2021
 *      Author: Sere
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Get.h"

int menu() {

	int opcion;

	printf("\n\n **** ADMINISTRACION DE CLIENTES Y PEDIDOS DE RECOLECCION ****\n\n");
	printf("1. Alta de cliente\n");
	printf("2. Modificar cliente\n");
	printf("3. Baja cliente\n");
	printf("4. Crear un pedido de recoleccion\n");
	printf("5. Procesar residuos\n");
	printf("6. Imprimir clientes\n");
	printf("7. Imprimir pedidos pendientes\n");
	printf("8. Imprimir pedidos procesados\n");
	printf("9. Informes\n");
	printf("10. Baja pedido\n");
	printf("11. Modificar pedidos\n");
	printf("0. Salir\n");
	printf("Ingrese opcion:");
	scanf("%d",&opcion);

	return opcion;
}


int menuInformes(){

	int opcion;

	printf("\n\n *****Menu Informes*****\n");
    printf("1- Pedidos pendientes por localidad\n");
	printf("2- Cantidad Promedio de Kg de PP Reciclados\n");
   // printf("3- \n");
   // printf("4- \n");
   // printf("5- \n");
    //printf("6- \n");
    //printf("7- \n");
    printf("0- Volver al menu principal\n");


	utn_getNumero(&opcion,"Ingrese una opcion: ","Error.\n",0,4,10);

	return opcion;
}


int menuModificaciones(){

	int opcion;

	printf("\n\n *****Menu modificaciones *****\n");
	printf("1- Modificar direccion\n");
	printf("2- Modificar localidad\n");
	printf("3- Guardar cambios y salir\n");
	printf("4- Cancelar cambios y salir\n");


	utn_getNumero(&opcion,"Ingrese una opcion: ","Error.:",1,4,10);

	return opcion;
}

int menuModificacionesPedidos(){

	int opcion;

		printf("\n\n *****Menu modificaciones *****\n");
		printf("1- Modificar cantidad de kilos ingresados\n");
		printf("2- Guardar cambios y salir\n");
		printf("3- Cancelar cambios y salir\n");


		utn_getNumero(&opcion,"Ingrese una opcion: ","Error.:",1,4,10);

		return opcion;
}

char verificarSalida(char *pSalida) {
	int todoOk = 0;
	char opcion;

	if (pSalida != NULL) {

		fflush(stdin);
		utn_getCaracter(&opcion,"Confirma salida? (s/n):","Opcion invalida.\n",'s','n',10);

		*pSalida = opcion;
		todoOk = 1;
	}

	return todoOk;

}

void encabezadoPendientes(){
	printf("CUIT                     DIRECCION              KILOS A RECOLECTAR\n  " );
}


void encabezadoProcesados(){
	printf("CUIT                     DIRECCION          KG HDPE       KG LDPE        KG PP\n  " );
}


void encabezadoPedidos(){

	printf(
			"_______________________________________________________________________________________\n");
	printf(
			"ID                  CLIENTE             KILOS TOTALES              ESTADO\n");
	printf(
			"_______________________________________________________________________________________\n");
}

void imprimirEncabezadoClientes(){


	printf("\n________________________________________________________________________________________________________________________\n");
	printf("ID        NOMBRE DE EMPRESA          CUIT               DIRECCION              Id LOCALIDAD           PEDIDOS PENDIENTES \n");
	printf("__________________________________________________________________________________________________________________________\n\n");
}
