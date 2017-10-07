/*ALGP.C Este archivo contiene las funciones auxiliares necesarias para la interfaz de juego */
/*Devuelve el puntaje de las burbujas*/
long int puntaje(int color, int be) /*recibe(color de burbuja que se tira, cantidad e burbujas que se explotan)*/
{ long int punt=0;
  if(color==2)
	punt+=1000*be;
  if(color==4)
	punt+=500*be;
  if(color==1)
	punt+=200*be;
  if(color==3)
	punt+=100*be;
  return punt;
}
/*Genera matriz inicial*/
void genMatriz(int m[10][10]){
 int i,j,k=9,n=0;
 srand(time(NULL));
 for(i=0; i<=9; i++){
   for(j=0; j<=9; j++){
     if(j>=n && j<=k)
       m[i][j]=rand()%4+1;
     else
       m[i][j]=0;
   }
   if(i%2==1)
     k--;
   if(i%2==0)
    n++;
 }
}
/*Verifica si esta vacia*/
int estaVacia(int m[10][10]){
 int i,j,conta=0;
 for(i=0; i<=9; i++)
  for(j=0; j<=9; j++)
    if(m[i][j]!=0)
       conta++;
 if(conta>=1)
   return 0;
 else
   return 1;
}
/*Verifica si esta LLena*/
int estaLLena(int m[10][10]){
 int i,j,conta=0;
 for(i=0; i<=9; i++)
  for(j=0; j<=9; j++)
    if(m[i][j]==0)
       conta++;
 if(conta>=1)
   return 0;
 else
   return 1;
}

/*Regresa 1 si la bola especial esta aun viva */
int estaBolaEspecial(int m[10][10],int bolaespecial, long int *p){
    int i,j;
    if(m[0][bolaespecial]==0){
       for(i=0; i<=9; i++)
         for(j=0; j<=9; j++){
           *p+=puntaje(m[i][j],1);
           m[i][j]=0;
       }
       return 0;
   }
   else{
      return 1;
    }

}

/*Verifica si se puede eliminar verticalmente*/
long int VVertical(int i, int j,int color, int m[10][10]){
 long int aux=0;
 int k,conta1=0,conta2=0;
 for(k=0; k<=i; k++){ /*Busqueda ascendente*/
   if(m[i-k][j]==color)
     conta1++;
   else
     break;
 }
 for(k=1; k<=9-i; k++){/*Busqueda descendente*/
   if(m[i+k][j]==color)
     conta2++;
   else
     break;
 }
 if(conta1+conta2>=3){/*Eliminacion horizontal*/
   for(k=0; k<conta1; k++)
     m[i-k][j]=0;
   for(k=1; k<=conta2; k++)
    m[i+k][j]=0;
   aux=puntaje(color,conta1+conta2);
 }
 return aux;
}
/*Verifica si se puede eliminar diagonalmente a la derecha*/
long int VDiagI(int i,int j,int color,int m[10][10]){
 int conta1,conta2,k;
 long int aux=0;
   conta1=0;
   conta2=0;
   if((9-i)>(9-j)){/*Recorrido Descendente*/
     for(k=0; k<=(9-j);k++){
      if(color==m[i+k][j+k] )
	conta1++;
      else
       break;
     }
   }
   else{
     for(k=0; k<=(9-i);k++){
      if(color==m[i+k][j+k] )
	conta1++;
      else
	break;
     }
   }
   if(i>j){ /*Recorrido Ascendente*/
    for(k=1; k<=j;k++){
      if(color==m[i-k][j-k] )
	conta2++;
      else
	break;
     }
   }
   else{
    for(k=1; k<=i;k++){
      if(color==m[i-k][j-k] )
	conta2++;
      else
	break;
     }
   }
   if((conta1+conta2)>=3){
     for(k=0; k<conta1; k++)
       m[i+k][j+k]=0;
     for(k=1; k<=conta2; k++)
       m[i-k][j-k]=0;
     aux=puntaje(color,conta1+conta2);
   }
   return aux;
}
/*Verifica si se puede eliminar diagonalmente a la izquierda*/
long int VDiagD(int i, int j,int color, int m[10][10]){
 int conta1,conta2,k;
 long int aux=0;
   conta1=0;
   conta2=0;
   if((9-i)>j){/*Recorrido Descendente*/
     for(k=0; k<=j;k++){
      if(color==m[i+k][j-k])
	conta1++;
      else
       break;
     }
   }
   else{
     for(k=0; k<=(9-i);k++){
      if(color==m[i+k][j-k])
	conta1++;
      else
	break;
     }
   }
   if(i>(9-j)){ /*Recorrido Ascendente*/
    for(k=1; k<=(9-j);k++){
      if(color==m[i-k][j+k])
	conta2++;
      else
	break;
     }
   }
   else{
    for(k=1; k<=i;k++){
      if(color==m[i-k][j+k] )
	conta2++;
      else
	break;
     }
   }
   if((conta1+conta2)>=3){
     for(k=0; k<conta1; k++)
       m[i+k][j-k]=0;
     for(k=1; k<=conta2; k++)
       m[i-k][j+k]=0;
      aux=puntaje(color,conta1+conta2);
   }
   return aux;
}
/*Funcion de verificacion horizontal*/
long int VHorizontal(int i, int j, int color, int m[10][10]){
 long int aux=0;
 int k,conta1=0,conta2=0;
 for(k=0; k<=j; k++){ /*Busqueda a la izquierda*/
   if(m[i][j-k]==color)
     conta1++;
   else
     break;
 }
 for(k=1; k<=9-j; k++){/*Busqueda a la derecha*/
   if(m[i][j+k]==color)
     conta2++;
   else
     break;
 }
 if(conta1+conta2>=3){/*Eliminacion horizontal*/
   for(k=0; k<conta1; k++)
     m[i][j-k]=0;
   for(k=1; k<=conta2; k++)
    m[i][j+k]=0;
   aux=puntaje(color,conta1+conta2);
 }
 return aux;
}
/*Funcion a llamar si el usuario escoge jugada vertical*/
long int JVertical(int j,int color, int m[10][10]){
 int i=9;
 long int aux=0;
 /*Busqueda de abajo a arriba*/
 do{
   if(m[i][j]==0 && m[i-1][j]!=0){
     m[i][j]=color;
     aux=VVertical(i,j,color,m);
     if(aux==0)
       aux=VDiagD(i,j,color,m);
     if(aux==0)
       aux==VDiagI(i,j,color,m);
     if(aux==0)
       aux==VHorizontal(i,j,color,m);
     break;
   }
   i--;
   if(i==0 && m[i][j]==0)
      m[i][j]=color;
 }while(i>0);
 return aux;
}
/*Funcion a llamar si el usuario escoge jugada diagonal izquierda*/
long int JDiagI(int i,int color, int m[10][10]){
 int j=0;
 int a=i;
 long int aux=0;
 /*Busqueda de Izquierda a Derecha*/
 do{
   /*Caso 1*/
   if(m[a][j]==0 && m[a-1][j+1]!=0  &&(a>=1 && j<=8)){
     m[a][j]=color;
     aux=VDiagI(a,j,color,m);
     if(aux==0)
       aux=VVertical(a,j,color,m);
     if(aux==0)
       aux==VDiagD(a,j,color,m);
     if(aux==0)
       aux==VHorizontal(a,j,color,m);
     break;
   }
   if(a==0 && m[a][j]==0)
    m[a][j]=color;
   a--;
   j++;
 }while(j<=9 && a>=0);
 return aux;
}
/*Funcion a llamar si el usuario escoge jugada diagonal derecha*/
long int JDiagD(int i,int color,int m[10][10]){
 int j=9;
 int a=i;
 long int aux=0;
 /*Busqueda de Derecha a Izquierda*/
 do{
   /*Caso 1*/
   if(m[a][j]==0 && m[a-1][j-1]!=0 && (a>=1 && j>=1)){
     m[a][j]=color;
     aux=VDiagD(a,j,color,m);
     if(aux==0)
       aux=VVertical(a,j,color,m);
     if(aux==0)
       aux==VDiagI(a,j,color,m);
     if(aux==0)
       aux==VHorizontal(a,j,color,m);
     break;
   }
   if(a==0 &&  m[a][j]==0)
     m[a][j]=color;
   a--;
   j--;
 }while(j>=0);
 return aux;
}
/*Lee cadena en modo grafico*/
void leercadena(char cad[]){
	int k = 0;
	char tecla;
	char pantalla[2];
	int x,y;
        setcolor(BLACK);
	do{
		tecla = getch();
		if(tecla != 13 && tecla!=8){
			cad[k] = tecla;
			pantalla[0]=tecla;
			pantalla[1]='\0';
			x=getx(); y=gety();
			outtext(pantalla);
                        moverel(10,0);
			k++;
		}
		else if(tecla==8 && k>=1){
		   pantalla[0]=cad[k-1];
		   pantalla[1]='\0';
		   setcolor(2);
		   moveto(x,y);
		   outtext(pantalla);
		   moveto(x,y);
		   setcolor(BLACK);
		   k--;
		   continue;
		}
	} while (tecla != 13 && k < 10);
	cad[k] = '\0';
}
/*Convierte una cadena en un numero*/
int cadanum(char cad[]){
	int l, num = 0, aux;
	int i, j;
	l = strlen(cad);
	for (i = 0; i <= l-1; i++){
		aux = (cad[i] - 48);
		for (j = i; j < l - 1; j++)
			aux *= 10;
		num += aux;
	}
	return num;
}
/*Genera bolas al azar*/
int genBola(){
  srand(time(NULL));
  return rand()%4+1;
}

