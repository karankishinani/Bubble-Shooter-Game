/*Constantes Simbolicas para manejo del teclado*/
#define ENTER 13
#define ESC 27
#define K_UP 72
#define K_DOWN 80
#define K_LEFT 75
#define K_RIGHT 77
#include <conio.h>
#define AST cprintf("%c", 004)
#define EST cprintf("*")

/*Funcion de Inicio*/
void inicio(){
int tecla=0;

	/*Estrellas y Borde*/
	setlinestyle(0,2,3);
	setcolor(CYAN);
	line(1,0,getmaxx()-1,0);

	setcolor(GREEN);
	line(1,getmaxy()-1,getmaxx()-1,getmaxy()-1);

	setcolor(RED);
	line(1,00,0,getmaxy()-1);

	setcolor(WHITE);
	line(getmaxx()-1,00,getmaxx()-1,getmaxy()-1);

	gotoxy(10,23);
	printf("%c",4);
	gotoxy(71,23);
	printf("%c",4);
	gotoxy(19,14);
	printf("%c",4);
	gotoxy(61,14);
	printf("%c",4);
	gotoxy(59,8);
	printf("%c",4);
	gotoxy(22,8);
	printf("%c",4);

	/*Rectangulo de Colores*/
	setcolor(RED);
	line(50,50,50,getmaxy()-50);

	setcolor(GREEN);
	line(50,getmaxy()-50,getmaxx()-50,getmaxy()-50);

	setcolor(WHITE);
	line(getmaxx()-50,50,getmaxx()-50,getmaxy()-50);

	setcolor(CYAN);
	line(50,50,getmaxx()-50,50);

	setcolor(CYAN);
	setfillstyle(10,BLACK);
	settextstyle(10,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(getmaxx()/2,120,"BUBBLE");

	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(getmaxx()/2,200,"SHOOTER!");

	settextstyle(10,0,3);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(getmaxx()/2,350," Presione ENTER para jugar!");

	setcolor(WHITE);
	pieslice(50,125,0,360,50);

	/*Bola dentro de la bola gigante y la linea para que parezca pokeball*/
	setlinestyle(0,1,3);
	setfillstyle(1,WHITE);
	pieslice(50,125,0,360,20);

	line(0,125,50,125);

	/*Burbujas Cyan */
	setcolor(CYAN);
	setfillstyle(1,CYAN);
	pieslice(14,13,0,360,10);
	pieslice(285,260,0,360,10);
	pieslice(305,260,0,360,10);
	pieslice(325,260,0,360,10);
	pieslice(345,260,0,360,10);

	/*Burbujas Rojas*/
	setcolor(RED);
	setfillstyle(1,RED);
	pieslice(12,getmaxy()-15,0,360,10);
	pieslice(295,283,0,360,10);
	pieslice(315,283,0,360,10);
	pieslice(335,283,0,360,10);

	/*Burbujas Verdes*/
	setcolor(GREEN);
	setfillstyle(1,GREEN);
	pieslice(getmaxx() - 14,getmaxy()-15,0,360,10);
	pieslice(305,303,0,360,10);
	pieslice(325,303,0,360,10);

	/*Burbujas Blancas*/
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	pieslice(getmaxx() - 14,13,0,360,10);
	pieslice(315,323,0,360,10);
	do{
		if(kbhit())
		tecla=getch();
	}while(tecla!=ENTER);
	cleardevice();
}

/*Funcion de Presentacion*/
void presentacion(){
int tecla=0;
do{
	setlinestyle(0, 1, 3);
	rectangle(0, 0, 639, 479);
	setcolor(WHITE);
	settextstyle(2, 0, 5);
	outtextxy(300, 10, "Universidad Tecnologica de Panama");
	outtextxy(300, 35, "Facultad de Ingenieria en Sistemas");
	outtextxy(300, 60, "Ingenieria en Sistemas y Computacion");
	outtextxy(300, 85, "Programacion Aplicada 1");
	outtextxy(300, 110, "Proyecto Final Modo Grafico");
	outtextxy(300, 135, "Grupo 2 Integrantes");
	outtextxy(420, 160, "Aleman,Axel 8-878-1461");
	outtextxy(410, 185, "Good,Luis 8-869-2090");
	outtextxy(420, 210, "Gracia, Jose 3-893-1290");
	outtextxy(435, 235, "Kishiniani,Karan 3-735-1345");
	outtextxy(435, 260, "Lovato, Gillianne 8-896-2057");
	outtextxy(440, 285, "Rodriguez, Victor 8-878-1015");
	outtextxy(300, 370, "Grupo 1IL121");
	outtextxy(300, 400, "I Semestre 2014");
	if(kbhit())
		  tecla=getch();
	}while(tecla!=ENTER);
	cleardevice();
}

/*Funcion de Menu de Opciones*/
int menu(){
int tecla, linea=0;
do{
		cleardevice();
	do{
		/*Menu Principal*/
		settextstyle(10, 0, 1);
		outtextxy(210,40,"Bubble Shooter Menu");
		outtextxy(300,120,"Jugar");
		outtextxy(300,200,"Instrucciones");
		outtextxy(300,280,"Salir");
		if(linea==0){
		   rectangle(160,120,190,150);
		   setcolor(BLACK);
		   rectangle(160,200,190,230);
		   rectangle(160,280,190,310);
		   setcolor(WHITE);
		}
		else if(linea==1){
		   rectangle(160,200,190,230);
		   setcolor(BLACK);
		   rectangle(160,120,190,150);
		   rectangle(160,280,190,310);
		   setcolor(WHITE);
		}
		else{
		   rectangle(160,280,190,310);
		   setcolor(BLACK);
		   rectangle(160,120,190,150);
		   rectangle(160,200,190,230);
		   setcolor(WHITE);
		}
	tecla=getch();
	sound(453); delay(50);
	nosound();
	if(tecla==K_UP && linea>0){
	linea--;
	}
	else if(tecla==K_DOWN && linea<2){
	linea++;
	}
	}while(tecla!=ENTER);

	cleardevice();
	if (linea == 0){
	/*Retorna Opcion de Entrada al juego**/
	return linea;
	}
	else if (linea == 1){
	/*Retorna Opcion de instrucciones*/
	return linea;
	}
	else{
	/*Retorna Opcion de Salir del Programa*/
	tecla = ESC;
	return tecla;

	}
} while (tecla!=ESC);
}


/*Funcion de Instrucciones*/
void instrucciones(){

	  settextstyle(3,0,1);
	  outtextxy(90,10,"INSTRUCCIONES:");
	  outtextxy(310,50,"El juego bubble shooter consiste en eliminar burbujas que formen");
	  outtextxy(310,70,"un grupo de 3 o mas de su mismo color, las jugadas pueden ser");
	  outtextxy(265,90,"Verticales y Diagonales; las jugadas verticales requieren");
	  outtextxy(292,110,"ingresar el numero de columna donde se encuentra la burbuja");
	  outtextxy(285,130,"a eliminar,las jugadas diagonales requieren el numero de fila");
	  outtextxy(290,150,"donde se encuentra la burbuja a eliminar ademas ingresar \'i'\ ");
	  outtextxy(290,170,"o \'I'\ para ejecutar una jugada diagonal izquierda. Tambien se");
	  outtextxy(305,190,"puede ejecutar una jugada diagonal derecha ingresando \'D'\ o \'d'\. ");
	  outtextxy(317,230,"El puntaje se acumula dependiendo del color y cantidad de burbujas ");
          outtextxy(80,245,"que se eliminen: ");
	  outtextxy(320,265,"--> las burbujas verdes valen 1000 puntos cada una");
	  outtextxy(305,285,"--> las burbujas rojas valen 500 puntos cada una");
	  outtextxy(310,305,"--> las burbujas azules valen 200 puntos cada una");
	  outtextxy(302,325,"--> las burbujas cyan valen 100 puntos cada una");
	  outtextxy(322,365,"Ademas el juego cuenta con una burbuja especial en la fila superior.");
          outtextxy(232,385,"Si logras eliminarla, ganas!!");
          outtextxy(522,445,"SUERTE :D");
	  getch();
	  }

/*Funcion de Salir y Despedida*/
void salir(){
	int x, y=1;
	_setcursortype(_NOCURSOR);
	do{
		x++;
		if(x==16)
			x=1;
		textcolor(x);
		clrscr();
		gotoxy(18,11);
		cprintf("Adios, que tengas un buen dia, gracias por jugar");
		if(y==1) {
		gotoxy(8,6);
		AST;
		gotoxy(9,7);
		AST;
		gotoxy(10,8);
		AST;
		}
		if(y==3) {
		gotoxy(28,5);
		AST;
		gotoxy(29,6);
		AST;
		gotoxy(30,7);
		AST;
		}
		if(y==5) {
		gotoxy(52,5);
		AST;
		gotoxy(51,6);
		AST;
		gotoxy(50,7);
		AST;
		}
		if(y==7) {
		gotoxy(72,6);
		AST;
		gotoxy(71,7);
		AST;
		gotoxy(70,8);
		AST;
		}
		if(y==2) {
		gotoxy(60,15);
		AST;
		gotoxy(61,16);
		AST;
		gotoxy(62,17);
		AST;
		}
		if(y==4) {
		gotoxy(40,15);
		AST;
		gotoxy(40,16);
		AST;
		gotoxy(40,17);
		AST;
		}
		if(y==6) {
		gotoxy(20,15);
		AST;
		gotoxy(19,16);
		AST;
		gotoxy(18,17);
		AST;
		}
		if(y==8) {
		gotoxy(70,11);
		AST;
		gotoxy(72,11);
		AST;
		gotoxy(74,11);
		AST;
		}
		/*_____*/
		if(y==2) {
		gotoxy(18,5);
		AST;
		gotoxy(19,6);
		AST;
		gotoxy(20,7);
		AST;
		}
		if(y==4) {
		gotoxy(40,5);
		AST;
		gotoxy(40,6);
		AST;
		gotoxy(40,7);
		AST;
		}
		if(y==6) {
		gotoxy(62,5);
		AST;
		gotoxy(61,6);
		AST;
		gotoxy(60,7);
		AST;
		}
		if(y==1) {
		gotoxy(70,15);
		AST;
		gotoxy(71,16);
		AST;
		gotoxy(72,17);
		AST;
		}
		if(y==3) {
		gotoxy(50,15);
		AST;
		gotoxy(51,16);
		AST;
		gotoxy(52,17);
		AST;
		}
		if(y==5) {
		gotoxy(30,15);
		AST;
		gotoxy(29,16);
		AST;
		gotoxy(28,17);
		AST;
		}
		if(y==7) {
		gotoxy(10,15);
		AST;
		gotoxy(9,16);
		AST;
		gotoxy(8,17);
		AST;
		}
		if(y==8) {
		gotoxy(10,11);
		AST;
		gotoxy(8,11);
		AST;
		gotoxy(6,11);
		AST;
		}
		y++;
		if(y==9)
			y=1;
		delay(100);
		clrscr();
	   }while(!kbhit());
}
