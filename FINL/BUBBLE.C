/*PROYECTO FINAL APLICADA 1
OBJETIVO: IMPLEMENTAR GRAFICOS EN C
INTEGRANTES:
ALEMAN AXEL  8-878-1461
GOOD LUIS  8-869-2090
GRACIA JOSE  8-893-1290
KISHINANI KARAN  3-735-1345
LOVATO GILLIANNE  8-896-2057
RODRIGUEZ VICTOR  8-878-1015
GRUPO: 1IL121
GRUPO 2*/

/*Declaracion de Librerias*/
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include "\\FINL\\MENU.C"
#include "\\FINL\\PANTALLA.C"
#include "\\FINL\\GAME.C"


/*Inicio del Programa (MAIN) */
void main (void){

   /* Requiere auto deteccion */
   int gdriver = DETECT, gmode, errorcode;
   int opc;

   /* Inicializa las variables locales y los graficas */
   initgraph(&gdriver, &gmode,"c:\\bgi");     /*Ruta del BGI depende de la configuracion de su maquina*/
   clrscr();
   /* Lee el resultado de la inicialización */
   errorcode = graphresult();
   if (errorcode != grOk)  /* Si ocurre algún error */{
      printf("Error grafico: %s\n", grapherrormsg(errorcode));
      printf("Presionar una tecla para salir:");
      getch();
      exit(1); /* Codigo de error */
   }
    cleardevice();
	inicio();         /*Llamado de Funcion Inicio*/
	presentacion();   /*Llamado de Funcion Presentacion*/

	do{
		opc = menu();     /*Llamado de Funcion Menu y Retorna valor de la Opcion seleccionada*/
		switch(opc){

		case 0:
		juego();	  /*Llamado de Juego*/
                                  /* se sale del programa */
		break;

		case 1:
		instrucciones();  /*Llamado de Funcion Intruciones*/
		break;

		case 27:
		closegraph();
		salir();  	  /*Llamado de Salir*/
		break;
		}

	}while(opc!=27);

closegraph ();
getch();
}


