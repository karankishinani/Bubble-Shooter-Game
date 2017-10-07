/*GAME.C Este archivo tiene la funcion principal de juego*/
#include "\\FINL\\ALGP.C"
#include "\\FINL\\JUEGO.C"
#define DIAMBUBBLE 35


/*Funcion de Juego*/
void juego(){
    int c, bola, matcolor[10][10];
    int bolaespecial;
    char tecla, buffer[10];
    long int puntos=0;
    settextstyle(2,0,5);
    genMatriz(matcolor);
    srand(time(NULL));
    bolaespecial = rand()%9+1; /*genera la bola especial */

    do{ /*Ciclo repetivo de juego*/
	dibujar_fondo();
	draw_bubbles(matcolor,bolaespecial);
        bola=genBola();
        dibBola(bola);
        dibEstrella(puntos);
        dibPuntaje(puntos);
	setcolor(BLACK);
	outtextxy(210,400,"Ingrese V para jugada vertical o D para diagonal ");
	moveto(400,400);
	leercadena(buffer);
	 if(buffer[0]=='V' || buffer[0]=='v'){ 		/*Se escoge jugada vertical*/
        	outtextxy(130,418,"Ingrese el numero de columna ");
        	moveto(400,418);
        	leercadena(buffer);
        	c=cadanum(buffer);
        	/*Ejecutar jugada vertical*/
                  puntos+=JVertical(c-1,bola,matcolor);
     		}
     	else if(buffer[0]=='D' || buffer[0]=='d'){ 	/*Se escoge jugada diagonal*/
        	outtextxy(120,418,"Ingrese el numero de fila ");
        	moveto(400,418);
        	leercadena(buffer);
        	c=cadanum(buffer);
        	c=10-c;
        	outtextxy(155,436,"Ingrese I para izquierda D derecha ");
        	moveto(400,436);
        	leercadena(buffer);
		if(buffer[0]=='I' || buffer[0]=='i'){		/*Ejecuta jugada diagonal izquierda*/
                  puntos+=JDiagI(c,bola,matcolor);
        	}
        	else if(buffer[0]=='D' || buffer[0]=='d'){	/*Ejecuta jugada diagonal derecha*/
			puntos+=JDiagD(c,bola,matcolor);
        	}
    	}
    getch();
    tecla=getch();
    cleardevice();
    if(estaLLena(matcolor)==1 || estaVacia(matcolor)==1)
     tecla=27;
    }while((estaLLena(matcolor)==0 && estaVacia(matcolor)==0 && estaBolaEspecial(matcolor,bolaespecial,&puntos)==1)&&tecla!=27 );
    restorecrtmode(); 
    if(estaLLena(matcolor)==1){
        gameover();
    }
    else if(estaVacia(matcolor)==1 ){
      congrats(puntos);
    }
    setgraphmode(VGAHI);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    return;
}
