

#define DIAMBUBBLE 35

void dibujar_fondo()
{
    char pattern[8]={0xe0, 0x90, 0xe0, 0x97, 0xe8, 0x6, 0x1, 0xe}; /* FONDO BS con 1 y 0 en binario */

	setfillpattern(pattern, 2);

	setbkcolor(0);

	setfillstyle(12,2);
	bar(1,1,639,479);

	setfillstyle(1,10);
	bar(10,10,629,469);

	setlinestyle(0, 1, 3);
}

void draw_bubbles(int matcolor[][10], int bolaespecial)
{
	int i,j, radx, rady, cad[10];

    /* Dibuja los numeros en los bordes */
	radx=(getmaxx()-200-(DIAMBUBBLE*10))/2 -DIAMBUBBLE/2;
	rady=(getmaxy()-80-(DIAMBUBBLE*10))/2 + DIAMBUBBLE*10 + 5;
	setcolor(0);
	for(i=1;i<=10;i++)
	{
	    sprintf(cad,"%d",i);
		outtextxy(radx,rady,cad);
		radx+=(DIAMBUBBLE+DIAMBUBBLE/10);
	}

	radx=(getmaxx()-200-(DIAMBUBBLE*10))/2 -DIAMBUBBLE/2;
	rady=(getmaxy()-80-(DIAMBUBBLE*10))/2 ;
	for(i=10;i>1;i--)
	{
		sprintf(cad,"%d",i);
		outtextxy(radx,rady,cad);
		rady+=DIAMBUBBLE+5;
    }


    /*la posicion x,y de la primera burbuja*/
    radx=(getmaxx()-180-(DIAMBUBBLE*10))/2 + DIAMBUBBLE/2;
    rady=(getmaxy()-80-(DIAMBUBBLE*10))/2 + DIAMBUBBLE/2;

    /* Dibuja y rellena las burbujas */
    for(i=0;i<10;i++)
    {
	/* el centreo de las bolas */
	if(i%2==0)
	    radx=(getmaxx()-180-(DIAMBUBBLE*10))/2 + DIAMBUBBLE/2;
	else
			radx=(getmaxx()-180-(DIAMBUBBLE*10))/2;

	for(j=0;j<10;j++)
	{
			if (matcolor[i][j]==0)
	    {
				setfillstyle(1,10); /*se dibujan circulos del color de fondo para que parezca que no hay nada*/
				setcolor(10);
	    }
	    else
	    {
               
		setfillstyle(1,matcolor[i][j]);
		setcolor(0);
	           
	    }

	    fillellipse (radx, rady, DIAMBUBBLE/2, DIAMBUBBLE/2);
	    radx+=DIAMBUBBLE;
	}
	rady+=DIAMBUBBLE;
    }
}
/*Dibuja la bola a tirar*/
void dibBola(int bola){
 int radx=520;
 int rady=180;
 setfillstyle(1,bola);
 setcolor(0);
 fillellipse (radx, rady, DIAMBUBBLE/2, DIAMBUBBLE/2);
}
/*Dibuja las estrella*/
void dibEstrella(long int punt){
 /*Determina los puntos o coordenadas del poligono que se dibujara*/
  int triangle1[8]={456,360,486,360,471,330,456,360};
  int triangle2[8]={498,360,528,360,513,330,498,360};
  int triangle3[8]={540,360,570,360,555,330,540,360};
  int Itriangle1[8]={456,337,486,337,471,367,456,337};
  int Itriangle2[8]={498,337,528,337,513,367,498,337};
  int Itriangle3[8]={540,337,570,337,555,367,540,337};
  /*dependiendo del puntaje, se dibujan las estrellas (triangulo y triangulo inverso)*/
  setcolor(MAGENTA); /*color del borde, o color con que se dibuja el cada triangulo*/
  setfillstyle(SOLID_FILL,MAGENTA); /*color de relleno*/
  if(punt>=10000 && punt<=19999)
	{ fillpoly(4,triangle1);
      fillpoly(4,Itriangle1);
	}
  if(punt>=20000 && punt<=50000)
	{ fillpoly(4,triangle1);
	  fillpoly(4,Itriangle1);
	  fillpoly(4,triangle2);
	  fillpoly(4,Itriangle2);
	}
  if(punt>50000)
	{ fillpoly(4,triangle1);
      fillpoly(4,Itriangle1);
	  fillpoly(4,triangle2);
	  fillpoly(4,Itriangle2);
	  fillpoly(4,triangle3);
	  fillpoly(4,Itriangle3);
	}
}
/*Imprime el puntaje en la pantalla*/
void dibPuntaje(long int punt){
  char print[20]={0}; /*por lo tanto puntaje maximo 9999999*/
  sprintf(print,"Puntaje: %ld",punt);
  settextstyle(SMALL_FONT,HORIZ_DIR,5);
  setcolor(BLUE);
  outtextxy(520,72,print);
}
