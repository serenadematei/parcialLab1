/*
 * Datos.c
 *
 *  Created on: 12 oct 2021
 *      Author: Sere
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Datos.h"

 char nombresEmpresas[10][50]={
    "Coca Cola",
    "OCA Postal",
    "Sancor",
    "Arcor",
    "BC",
    "Amazon",
    "Colombraro",
    "YPF",
    "Nestle",
    "Pedigree"

};



char direcciones[10][50]={
    "37 n815",
    "26 n512",
    "12 n124",
    "60 n103",
    "12 n718",
    "24 n513",
    "10 n666",
    "34 n789",
    "36 n915",
    "47 n803"

};

 char cuits[10][50]={
    "30-50000661-3",
    "30-66320562-1",
    "30-60495864-0",
    "34-50004533-9",
    "30-71549115-6",
    "30-50001008-4",
    "30-99922856-5",
    "30-69229637-7",
    "30-68695518-0",
    "30-54733941-6"

};

int idClientes[20]={2009,2001,2008,2002,2005,2003,2000,2007,2005,2006,2004,2009,2007,2008,2008,2001,2002,2005,2001,2001};
int idLocalidades[10]={10,17,11,13,14,14,16,15,12,12};
float kilos[20]={200,350,603,1015,4000,2010,3500,800,500,1000,3500,6000,750,400,820,2000,3200,1900};

int hardcodearClientes(eCliente listaClientes[],int size_clientes,int cant, int* id){

	int total=0;
	if(listaClientes!=NULL && size_clientes>0 && cant>=0 && cant<=size_clientes && id!=NULL){
		for(int i=0; i<cant; i++){
			listaClientes[i].id= *id;
			(*id)++;

			strcpy(listaClientes[i].nombreEmpresa,nombresEmpresas[i]);
			strcpy(listaClientes[i].cuit,cuits[i]);
			strcpy(listaClientes[i].direccion,direcciones[i]);
            listaClientes[i].idLocalidad=idLocalidades[i];
			listaClientes[i].isEmpty=0;

			total++;
		}


	}

	return total;
}


int hardcodearPedidos(ePedido pedidos[], int size_pedidos, int cant, int* id)
{
    int retorno=0;
    if(pedidos!=NULL && size_pedidos>0 && cant>=0 && cant<=size_pedidos && id!=NULL)
    {
        for(int i=0; i<cant; i++)
        {
            pedidos[i].id=*id;
            (*id)++;

            pedidos[i].isEmpty=0;
            pedidos[i].idCliente=idClientes[i];
            pedidos[i].kilos=kilos[i];
            pedidos[i].estado=0;



        }
    }
    return retorno;
}
