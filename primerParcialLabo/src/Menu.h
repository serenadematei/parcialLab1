/*
 * Menu.h
 *
 *  Created on: 11 oct 2021
 *      Author: Sere
 */

#ifndef MENU_H_
#define MENU_H_

int menu();
int menuInformes();
int menuModificaciones();
int menuModificacionesPedidos();
char verificarSalida(char *pSalida);


//ENCABEZADOS
void encabezadoPendientes();
void encabezadoProcesados();
void encabezadoPedidos();
void imprimirEncabezadoClientes();

#endif /* MENU_H_ */
