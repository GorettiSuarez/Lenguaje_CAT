#include "Q.h" 
BEGIN
STAT(0)
		STR(0x11ffc, "%c"); //formato caracteres
		STR(0x11ff8, "%f" ); //formato decimales
		STR(0x11ff4,"%d"); //formato entero
CODE(0)
L 0:
		R6= R7;
L 1:	R7 = R6 - 8;	 //Comienza la funcion
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 16
		R7 = R7 - 184;
		U(R7 + 0) = 'S';
		U(R7 + 4) = 'e';
		U(R7 + 8) = 'l';
		U(R7 + 12) = 'e';
		U(R7 + 16) = 'c';
		U(R7 + 20) = 'c';
		U(R7 + 24) = 'i';
		U(R7 + 28) = 'o';
		U(R7 + 32) = 'n';
		U(R7 + 36) = 'a';
		U(R7 + 40) = ' ';
		U(R7 + 44) = 'u';
		U(R7 + 48) = 'n';
		U(R7 + 52) = 'a';
		U(R7 + 56) = ' ';
		U(R7 + 60) = 'd';
		U(R7 + 64) = 'e';
		U(R7 + 68) = ' ';
		U(R7 + 72) = 'l';
		U(R7 + 76) = 'a';
		U(R7 + 80) = 's';
		U(R7 + 84) = ' ';
		U(R7 + 88) = 'o';
		U(R7 + 92) = 'p';
		U(R7 + 96) = 'e';
		U(R7 + 100) = 'r';
		U(R7 + 104) = 'a';
		U(R7 + 108) = 'c';
		U(R7 + 112) = 'i';
		U(R7 + 116) = 'o';
		U(R7 + 120) = 'n';
		U(R7 + 124) = 'e';
		U(R7 + 128) = 's';
		U(R7 + 132) = ' ';
		U(R7 + 136) = 'p';
		U(R7 + 140) = 'e';
		U(R7 + 144) = 'r';
		U(R7 + 148) = 'm';
		U(R7 + 152) = 'i';
		U(R7 + 156) = 't';
		U(R7 + 160) = 'i';
		U(R7 + 164) = 'd';
		U(R7 + 168) = 'a';
		U(R7 + 172) = 's';
		U(R7 + 176) = ':';
		U(R7 + 180) = ' ';
		R1=0x11ffc; //COMIENZA IMPRIMIR
		R2=R7; //POSICION PILA A IMPRIMIR
		R3=46; //NUMERO CARRACTERES
		R0=2; //RETORNO
		GT(putf_);
L 2:
		R1=0x11ffc ; //COMIENZA IMPRIMIR
		R2 = 10; //POSICION PILA A IMPRIMIR
		R3 = -3; //IMPRIMIR SALTO LINEA
		R0=3; //RETORNO
		GT(putf_);
L 3:
		R7 = R7 - 52;
		U(R7 + 0) = ' ';
		U(R7 + 4) = '1';
		U(R7 + 8) = '.';
		U(R7 + 12) = ' ';
		U(R7 + 16) = 'F';
		U(R7 + 20) = 'a';
		U(R7 + 24) = 'c';
		U(R7 + 28) = 't';
		U(R7 + 32) = 'o';
		U(R7 + 36) = 'r';
		U(R7 + 40) = 'i';
		U(R7 + 44) = 'a';
		U(R7 + 48) = 'l';
		R1=0x11ffc; //COMIENZA IMPRIMIR
		R2=R7; //POSICION PILA A IMPRIMIR
		R3=13; //NUMERO CARRACTERES
		R0=4; //RETORNO
		GT(putf_);
L 4:
		R1=0x11ffc ; //COMIENZA IMPRIMIR
		R2 = 10; //POSICION PILA A IMPRIMIR
		R3 = -3; //IMPRIMIR SALTO LINEA
		R0=5; //RETORNO
		GT(putf_);
L 5:
		R7 = R7 - 52;
		U(R7 + 0) = ' ';
		U(R7 + 4) = '2';
		U(R7 + 8) = '.';
		U(R7 + 12) = ' ';
		U(R7 + 16) = 'P';
		U(R7 + 20) = 'o';
		U(R7 + 24) = 't';
		U(R7 + 28) = 'e';
		U(R7 + 32) = 'n';
		U(R7 + 36) = 'c';
		U(R7 + 40) = 'i';
		U(R7 + 44) = 'a';
		U(R7 + 48) = ' ';
		R1=0x11ffc; //COMIENZA IMPRIMIR
		R2=R7; //POSICION PILA A IMPRIMIR
		R3=13; //NUMERO CARRACTERES
		R0=6; //RETORNO
		GT(putf_);
L 6:
		R1=0x11ffc ; //COMIENZA IMPRIMIR
		R2 = 10; //POSICION PILA A IMPRIMIR
		R3 = -3; //IMPRIMIR SALTO LINEA
		R0=7; //RETORNO
		GT(putf_);
L 7:
		R7 = R7 - 56;
		U(R7 + 0) = ' ';
		U(R7 + 4) = '3';
		U(R7 + 8) = '.';
		U(R7 + 12) = ' ';
		U(R7 + 16) = 'F';
		U(R7 + 20) = 'i';
		U(R7 + 24) = 'b';
		U(R7 + 28) = 'o';
		U(R7 + 32) = 'n';
		U(R7 + 36) = 'a';
		U(R7 + 40) = 'c';
		U(R7 + 44) = 'c';
		U(R7 + 48) = 'i';
		U(R7 + 52) = ' ';
		R1=0x11ffc; //COMIENZA IMPRIMIR
		R2=R7; //POSICION PILA A IMPRIMIR
		R3=14; //NUMERO CARRACTERES
		R0=8; //RETORNO
		GT(putf_);
L 8:
		R1=0x11ffc ; //COMIENZA IMPRIMIR
		R2 = 10; //POSICION PILA A IMPRIMIR
		R3 = -3; //IMPRIMIR SALTO LINEA
		R0=9; //RETORNO
		GT(putf_);
L 9:
		R1 = R6;
		R1 = R1 - 16;
		R0=10; //RETORNO
		GT(scanf_);
L 10:
		R7 = R7 - 8; //AQUI COMIENZA EL IF
		P(R7) = R6;
		R6 = R7;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 1; //Cojo el valor y lo pongo en la cima de la pila 
		RR2 = D(R7); //Comenzamos IGUALDAD
		RR1 = D(R7 + 8);
		IF (RR1 == RR2) GT(12);
		RR1 = 0;
		GT(13);
L 12:	RR1 = 1;
L 13:	R7 = R7 + 8;
		D(R7) = RR1; //Final IGUALDAD
		RR1 = D(R7);
		IF(RR1 < 1) GT(14);
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 8
		R7 = R7 - 236;
		U(R7 + 0) = 'I';
		U(R7 + 4) = 'n';
		U(R7 + 8) = 't';
		U(R7 + 12) = 'r';
		U(R7 + 16) = 'o';
		U(R7 + 20) = 'd';
		U(R7 + 24) = 'u';
		U(R7 + 28) = 'z';
		U(R7 + 32) = 'c';
		U(R7 + 36) = 'a';
		U(R7 + 40) = ' ';
		U(R7 + 44) = 'u';
		U(R7 + 48) = 'n';
		U(R7 + 52) = ' ';
		U(R7 + 56) = 'n';
		U(R7 + 60) = '�';
		U(R7 + 64) = '�';
		U(R7 + 68) = 'm';
		U(R7 + 72) = 'e';
		U(R7 + 76) = 'r';
		U(R7 + 80) = 'o';
		U(R7 + 84) = ' ';
		U(R7 + 88) = 'e';
		U(R7 + 92) = 'n';
		U(R7 + 96) = 't';
		U(R7 + 100) = 'e';
		U(R7 + 104) = 'r';
		U(R7 + 108) = 'o';
		U(R7 + 112) = ' ';
		U(R7 + 116) = 'c';
		U(R7 + 120) = 'u';
		U(R7 + 124) = 'y';
		U(R7 + 128) = 'o';
		U(R7 + 132) = ' ';
		U(R7 + 136) = 'f';
		U(R7 + 140) = 'a';
		U(R7 + 144) = 'c';
		U(R7 + 148) = 't';
		U(R7 + 152) = 'o';
		U(R7 + 156) = 'r';
		U(R7 + 160) = 'i';
		U(R7 + 164) = 'a';
		U(R7 + 168) = 'l';
		U(R7 + 172) = ' ';
		U(R7 + 176) = 'd';
		U(R7 + 180) = 'e';
		U(R7 + 184) = 's';
		U(R7 + 188) = 'e';
		U(R7 + 192) = 'a';
		U(R7 + 196) = ' ';
		U(R7 + 200) = 'c';
		U(R7 + 204) = 'a';
		U(R7 + 208) = 'l';
		U(R7 + 212) = 'c';
		U(R7 + 216) = 'u';
		U(R7 + 220) = 'l';
		U(R7 + 224) = 'a';
		U(R7 + 228) = 'r';
		U(R7 + 232) = ' ';
		R1=0x11ffc; //COMIENZA IMPRIMIR
		R2=R7; //POSICION PILA A IMPRIMIR
		R3=59; //NUMERO CARRACTERES
		R0=15; //RETORNO
		GT(putf_);
L 15:
		R1=0x11ffc ; //COMIENZA IMPRIMIR
		R2 = 10; //POSICION PILA A IMPRIMIR
		R3 = -3; //IMPRIMIR SALTO LINEA
		R0=16; //RETORNO
		GT(putf_);
L 16:
		R1 = R6;
		R1 = R1 - 8;
		R0=17; //RETORNO
		GT(scanf_);
L 17:
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 16
		R7 = R7 - 8; // LLAMADA: reservamos espacio para meter R6 actual. La etiqueta vale -> 18 
		R5 = R7; //Metemos en R5 la dir donde va a estar R6 
		R7 = R7 - 8; //Dejamos un hueco
		P(R7) = 18; //Metemos en ese hueco la etiqueta a la que ir cuando acabe la llamada
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = R1 - 8;
		RR3 = D(R1);
		D(R7) = RR3;
		P(R5) = R6; //Guardo el R6 como puntero en donde apunta R5
		R6 = R5; //Pongo ahora R6 en donde apunta R5
		GT(19);
L 18://Fin codigo LLAMADA 
 		R1 = R6;
		R1 = R1 - 16;
		RR1 = D(R7); //Cojo lo de la cima, que deberia ser el resultado de la funcion
		D(R1) = RR1; //Voy a la variable y meto el resultado
		R7 = R6 - 16;
		R7 = R7 - 172;
		U(R7 + 0) = 'E';
		U(R7 + 4) = 'l';
		U(R7 + 8) = ' ';
		U(R7 + 12) = 'r';
		U(R7 + 16) = 'e';
		U(R7 + 20) = 's';
		U(R7 + 24) = 'u';
		U(R7 + 28) = 'l';
		U(R7 + 32) = 't';
		U(R7 + 36) = 'a';
		U(R7 + 40) = 'd';
		U(R7 + 44) = 'o';
		U(R7 + 48) = ' ';
		U(R7 + 52) = 'd';
		U(R7 + 56) = 'e';
		U(R7 + 60) = 'l';
		U(R7 + 64) = ' ';
		U(R7 + 68) = 'c';
		U(R7 + 72) = 'a';
		U(R7 + 76) = 'l';
		U(R7 + 80) = 'c';
		U(R7 + 84) = 'u';
		U(R7 + 88) = 'l';
		U(R7 + 92) = 'o';
		U(R7 + 96) = ' ';
		U(R7 + 100) = 'd';
		U(R7 + 104) = 'e';
		U(R7 + 108) = 'l';
		U(R7 + 112) = ' ';
		U(R7 + 116) = 'f';
		U(R7 + 120) = 'a';
		U(R7 + 124) = 'c';
		U(R7 + 128) = 't';
		U(R7 + 132) = 'o';
		U(R7 + 136) = 'r';
		U(R7 + 140) = 'i';
		U(R7 + 144) = 'a';
		U(R7 + 148) = 'l';
		U(R7 + 152) = ' ';
		U(R7 + 156) = 'e';
		U(R7 + 160) = 's';
		U(R7 + 164) = ':';
		U(R7 + 168) = ' ';
		R1=0x11ffc; //COMIENZA IMPRIMIR
		R2=R7; //POSICION PILA A IMPRIMIR
		R3=43; //NUMERO CARRACTERES
		R0=20; //RETORNO
		GT(putf_);
L 20:
		R1 = R6;
		R1 = R1 - 16;
		R2=R1; //POSICION PILA A IMPRIMIR
		R1=0x11ff8 ; //COMIENZA IMPRIMIR
		R3=-1; //IMRIMIR DIGITO
		R0=21; //RETORNO
		GT(putf_);
L 21:
		R1=0x11ffc ; //COMIENZA IMPRIMIR
		R2 = 10; //POSICION PILA A IMPRIMIR
		R3 = -3; //IMPRIMIR SALTO LINEA
		R0=22; //RETORNO
		GT(putf_);
L 22:
		GT(11);
L 14:	R7 = R7 + 8;
		R7 = R7 - 8; //AQUI COMIENZA EL IF
		P(R7) = R6;
		R6 = R7;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 2; //Cojo el valor y lo pongo en la cima de la pila 
		RR2 = D(R7); //Comenzamos IGUALDAD
		RR1 = D(R7 + 8);
		IF (RR1 == RR2) GT(24);
		RR1 = 0;
		GT(25);
L 24:	RR1 = 1;
L 25:	R7 = R7 + 8;
		D(R7) = RR1; //Final IGUALDAD
		RR1 = D(R7);
		IF(RR1 < 1) GT(26);
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 8
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 16
		R7 = R7 - 136;
		U(R7 + 0) = 'I';
		U(R7 + 4) = 'n';
		U(R7 + 8) = 't';
		U(R7 + 12) = 'r';
		U(R7 + 16) = 'o';
		U(R7 + 20) = 'd';
		U(R7 + 24) = 'u';
		U(R7 + 28) = 'z';
		U(R7 + 32) = 'c';
		U(R7 + 36) = 'a';
		U(R7 + 40) = ' ';
		U(R7 + 44) = 'l';
		U(R7 + 48) = 'a';
		U(R7 + 52) = ' ';
		U(R7 + 56) = 'b';
		U(R7 + 60) = 'a';
		U(R7 + 64) = 's';
		U(R7 + 68) = 'e';
		U(R7 + 72) = ' ';
		U(R7 + 76) = 'd';
		U(R7 + 80) = 'e';
		U(R7 + 84) = ' ';
		U(R7 + 88) = 'l';
		U(R7 + 92) = 'a';
		U(R7 + 96) = ' ';
		U(R7 + 100) = 'p';
		U(R7 + 104) = 'o';
		U(R7 + 108) = 't';
		U(R7 + 112) = 'e';
		U(R7 + 116) = 'n';
		U(R7 + 120) = 'c';
		U(R7 + 124) = 'i';
		U(R7 + 128) = 'a';
		U(R7 + 132) = ' ';
		R1=0x11ffc; //COMIENZA IMPRIMIR
		R2=R7; //POSICION PILA A IMPRIMIR
		R3=34; //NUMERO CARRACTERES
		R0=27; //RETORNO
		GT(putf_);
L 27:
		R1=0x11ffc ; //COMIENZA IMPRIMIR
		R2 = 10; //POSICION PILA A IMPRIMIR
		R3 = -3; //IMPRIMIR SALTO LINEA
		R0=28; //RETORNO
		GT(putf_);
L 28:
		R1 = R6;
		R1 = R1 - 8;
		R0=29; //RETORNO
		GT(scanf_);
L 29:
		R7 = R7 - 156;
		U(R7 + 0) = 'I';
		U(R7 + 4) = 'n';
		U(R7 + 8) = 't';
		U(R7 + 12) = 'r';
		U(R7 + 16) = 'o';
		U(R7 + 20) = 'd';
		U(R7 + 24) = 'u';
		U(R7 + 28) = 'z';
		U(R7 + 32) = 'c';
		U(R7 + 36) = 'a';
		U(R7 + 40) = ' ';
		U(R7 + 44) = 'e';
		U(R7 + 48) = 'l';
		U(R7 + 52) = ' ';
		U(R7 + 56) = 'e';
		U(R7 + 60) = 'x';
		U(R7 + 64) = 'p';
		U(R7 + 68) = 'o';
		U(R7 + 72) = 'n';
		U(R7 + 76) = 'e';
		U(R7 + 80) = 'n';
		U(R7 + 84) = 't';
		U(R7 + 88) = 'e';
		U(R7 + 92) = ' ';
		U(R7 + 96) = 'd';
		U(R7 + 100) = 'e';
		U(R7 + 104) = ' ';
		U(R7 + 108) = 'l';
		U(R7 + 112) = 'a';
		U(R7 + 116) = ' ';
		U(R7 + 120) = 'p';
		U(R7 + 124) = 'o';
		U(R7 + 128) = 't';
		U(R7 + 132) = 'e';
		U(R7 + 136) = 'n';
		U(R7 + 140) = 'c';
		U(R7 + 144) = 'i';
		U(R7 + 148) = 'a';
		U(R7 + 152) = ' ';
		R1=0x11ffc; //COMIENZA IMPRIMIR
		R2=R7; //POSICION PILA A IMPRIMIR
		R3=39; //NUMERO CARRACTERES
		R0=30; //RETORNO
		GT(putf_);
L 30:
		R1=0x11ffc ; //COMIENZA IMPRIMIR
		R2 = 10; //POSICION PILA A IMPRIMIR
		R3 = -3; //IMPRIMIR SALTO LINEA
		R0=31; //RETORNO
		GT(putf_);
L 31:
		R1 = R6;
		R1 = R1 - 16;
		R0=32; //RETORNO
		GT(scanf_);
L 32:
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 24
		R7 = R7 - 8; // LLAMADA: reservamos espacio para meter R6 actual. La etiqueta vale -> 33 
		R5 = R7; //Metemos en R5 la dir donde va a estar R6 
		R7 = R7 - 8; //Dejamos un hueco
		P(R7) = 33; //Metemos en ese hueco la etiqueta a la que ir cuando acabe la llamada
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = R1 - 8;
		RR3 = D(R1);
		D(R7) = RR3;
		P(R5) = R6; //Guardo el R6 como puntero en donde apunta R5
		R6 = R5; //Pongo ahora R6 en donde apunta R5
		GT(34);
L 33://Fin codigo LLAMADA 
 		R1 = R6;
		R1 = R1 - 24;
		RR1 = D(R7); //Cojo lo de la cima, que deberia ser el resultado de la funcion
		D(R1) = RR1; //Voy a la variable y meto el resultado
		R7 = R6 - 24;
		R7 = R7 - 180;
		U(R7 + 0) = 'E';
		U(R7 + 4) = 'l';
		U(R7 + 8) = ' ';
		U(R7 + 12) = 'r';
		U(R7 + 16) = 'e';
		U(R7 + 20) = 's';
		U(R7 + 24) = 'u';
		U(R7 + 28) = 'l';
		U(R7 + 32) = 't';
		U(R7 + 36) = 'a';
		U(R7 + 40) = 'd';
		U(R7 + 44) = 'o';
		U(R7 + 48) = ' ';
		U(R7 + 52) = 'd';
		U(R7 + 56) = 'e';
		U(R7 + 60) = 'l';
		U(R7 + 64) = ' ';
		U(R7 + 68) = 'c';
		U(R7 + 72) = 'a';
		U(R7 + 76) = 'l';
		U(R7 + 80) = 'c';
		U(R7 + 84) = 'u';
		U(R7 + 88) = 'l';
		U(R7 + 92) = 'o';
		U(R7 + 96) = ' ';
		U(R7 + 100) = 'd';
		U(R7 + 104) = 'e';
		U(R7 + 108) = ' ';
		U(R7 + 112) = 'l';
		U(R7 + 116) = 'a';
		U(R7 + 120) = ' ';
		U(R7 + 124) = 'p';
		U(R7 + 128) = 'o';
		U(R7 + 132) = 't';
		U(R7 + 136) = 'e';
		U(R7 + 140) = 'n';
		U(R7 + 144) = 'c';
		U(R7 + 148) = 'i';
		U(R7 + 152) = 'a';
		U(R7 + 156) = ' ';
		U(R7 + 160) = ' ';
		U(R7 + 164) = 'e';
		U(R7 + 168) = 's';
		U(R7 + 172) = ':';
		U(R7 + 176) = ' ';
		R1=0x11ffc; //COMIENZA IMPRIMIR
		R2=R7; //POSICION PILA A IMPRIMIR
		R3=45; //NUMERO CARRACTERES
		R0=35; //RETORNO
		GT(putf_);
L 35:
		R1 = R6;
		R1 = R1 - 24;
		R2=R1; //POSICION PILA A IMPRIMIR
		R1=0x11ff8 ; //COMIENZA IMPRIMIR
		R3=-1; //IMRIMIR DIGITO
		R0=36; //RETORNO
		GT(putf_);
L 36:
		R1=0x11ffc ; //COMIENZA IMPRIMIR
		R2 = 10; //POSICION PILA A IMPRIMIR
		R3 = -3; //IMPRIMIR SALTO LINEA
		R0=37; //RETORNO
		GT(putf_);
L 37:
		GT(23);
L 26:	R7 = R7 + 8;
		R7 = R7 - 8; //AQUI COMIENZA EL IF
		P(R7) = R6;
		R6 = R7;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = P(R1);
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 3; //Cojo el valor y lo pongo en la cima de la pila 
		RR2 = D(R7); //Comenzamos IGUALDAD
		RR1 = D(R7 + 8);
		IF (RR1 == RR2) GT(39);
		RR1 = 0;
		GT(40);
L 39:	RR1 = 1;
L 40:	R7 = R7 + 8;
		D(R7) = RR1; //Final IGUALDAD
		RR1 = D(R7);
		IF(RR1 < 1) GT(41);
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 8
		R7 = R7 - 236;
		U(R7 + 0) = 'I';
		U(R7 + 4) = 'n';
		U(R7 + 8) = 't';
		U(R7 + 12) = 'r';
		U(R7 + 16) = 'o';
		U(R7 + 20) = 'd';
		U(R7 + 24) = 'u';
		U(R7 + 28) = 'z';
		U(R7 + 32) = 'c';
		U(R7 + 36) = 'a';
		U(R7 + 40) = ' ';
		U(R7 + 44) = 'l';
		U(R7 + 48) = 'a';
		U(R7 + 52) = ' ';
		U(R7 + 56) = 'p';
		U(R7 + 60) = 'o';
		U(R7 + 64) = 's';
		U(R7 + 68) = 'i';
		U(R7 + 72) = 'c';
		U(R7 + 76) = 'i';
		U(R7 + 80) = 'o';
		U(R7 + 84) = 'n';
		U(R7 + 88) = ' ';
		U(R7 + 92) = 'd';
		U(R7 + 96) = 'e';
		U(R7 + 100) = ' ';
		U(R7 + 104) = 'l';
		U(R7 + 108) = 'a';
		U(R7 + 112) = ' ';
		U(R7 + 116) = 'r';
		U(R7 + 120) = 'i';
		U(R7 + 124) = 's';
		U(R7 + 128) = 't';
		U(R7 + 132) = 'a';
		U(R7 + 136) = ' ';
		U(R7 + 140) = 'd';
		U(R7 + 144) = 'e';
		U(R7 + 148) = ' ';
		U(R7 + 152) = 'f';
		U(R7 + 156) = 'i';
		U(R7 + 160) = 'b';
		U(R7 + 164) = 'o';
		U(R7 + 168) = 'n';
		U(R7 + 172) = 'a';
		U(R7 + 176) = 'c';
		U(R7 + 180) = 'c';
		U(R7 + 184) = 'i';
		U(R7 + 188) = ' ';
		U(R7 + 192) = 'q';
		U(R7 + 196) = 'u';
		U(R7 + 200) = 'e';
		U(R7 + 204) = ' ';
		U(R7 + 208) = 'd';
		U(R7 + 212) = 'e';
		U(R7 + 216) = 's';
		U(R7 + 220) = 'e';
		U(R7 + 224) = 'a';
		U(R7 + 228) = ':';
		U(R7 + 232) = ' ';
		R1=0x11ffc; //COMIENZA IMPRIMIR
		R2=R7; //POSICION PILA A IMPRIMIR
		R3=59; //NUMERO CARRACTERES
		R0=42; //RETORNO
		GT(putf_);
L 42:
		R1=0x11ffc ; //COMIENZA IMPRIMIR
		R2 = 10; //POSICION PILA A IMPRIMIR
		R3 = -3; //IMPRIMIR SALTO LINEA
		R0=43; //RETORNO
		GT(putf_);
L 43:
		R1 = R6;
		R1 = R1 - 8;
		R0=44; //RETORNO
		GT(scanf_);
L 44:
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 16
		R7 = R7 - 8; // LLAMADA: reservamos espacio para meter R6 actual. La etiqueta vale -> 45 
		R5 = R7; //Metemos en R5 la dir donde va a estar R6 
		R7 = R7 - 8; //Dejamos un hueco
		P(R7) = 45; //Metemos en ese hueco la etiqueta a la que ir cuando acabe la llamada
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = R1 - 8;
		RR3 = D(R1);
		D(R7) = RR3;
		P(R5) = R6; //Guardo el R6 como puntero en donde apunta R5
		R6 = R5; //Pongo ahora R6 en donde apunta R5
		GT(46);
L 45://Fin codigo LLAMADA 
 		R1 = R6;
		R1 = R1 - 16;
		RR1 = D(R7); //Cojo lo de la cima, que deberia ser el resultado de la funcion
		D(R1) = RR1; //Voy a la variable y meto el resultado
		R7 = R6 - 16;
		R7 = R7 - 144;
		U(R7 + 0) = 'E';
		U(R7 + 4) = 'l';
		U(R7 + 8) = ' ';
		U(R7 + 12) = 'r';
		U(R7 + 16) = 'e';
		U(R7 + 20) = 's';
		U(R7 + 24) = 'u';
		U(R7 + 28) = 'l';
		U(R7 + 32) = 't';
		U(R7 + 36) = 'a';
		U(R7 + 40) = 'd';
		U(R7 + 44) = 'o';
		U(R7 + 48) = ' ';
		U(R7 + 52) = 'p';
		U(R7 + 56) = 'a';
		U(R7 + 60) = 'r';
		U(R7 + 64) = 'a';
		U(R7 + 68) = ' ';
		U(R7 + 72) = 'e';
		U(R7 + 76) = 's';
		U(R7 + 80) = 't';
		U(R7 + 84) = 'a';
		U(R7 + 88) = ' ';
		U(R7 + 92) = 'p';
		U(R7 + 96) = 'o';
		U(R7 + 100) = 's';
		U(R7 + 104) = 'i';
		U(R7 + 108) = 'c';
		U(R7 + 112) = 'i';
		U(R7 + 116) = 'o';
		U(R7 + 120) = 'n';
		U(R7 + 124) = ' ';
		U(R7 + 128) = 'e';
		U(R7 + 132) = 's';
		U(R7 + 136) = ':';
		U(R7 + 140) = ' ';
		R1=0x11ffc; //COMIENZA IMPRIMIR
		R2=R7; //POSICION PILA A IMPRIMIR
		R3=36; //NUMERO CARRACTERES
		R0=47; //RETORNO
		GT(putf_);
L 47:
		R1 = R6;
		R1 = R1 - 16;
		R2=R1; //POSICION PILA A IMPRIMIR
		R1=0x11ff8 ; //COMIENZA IMPRIMIR
		R3=-1; //IMRIMIR DIGITO
		R0=48; //RETORNO
		GT(putf_);
L 48:
		R1=0x11ffc ; //COMIENZA IMPRIMIR
		R2 = 10; //POSICION PILA A IMPRIMIR
		R3 = -3; //IMPRIMIR SALTO LINEA
		R0=49; //RETORNO
		GT(putf_);
L 49:
		GT(38);
L 41:	R7 = R7 + 8;
		R7 = R7 - 8; // LLAMADA: reservamos espacio para meter R6 actual. La etiqueta vale -> 50 
		R5 = R7; //guardamos la direccion donde va a estar R6 
		R7 = R7 - 8;
		P(R7) = 50;
		P(R5) = R6;
		R6 = R5;
		GT(51);
L 50://Fin codigo LLAMADA 
 L 38:		R7 = R6;
		R6 = P(R7);
		R7 = R7 + 8; //AQUI TERMINA EL IF
L 23:		R7 = R6;
		R6 = P(R7);
		R7 = R7 + 8; //AQUI TERMINA EL IF
L 11:		R7 = R6;
		R6 = P(R7);
		R7 = R7 + 8; //AQUI TERMINA EL IF
		GT(-2);
L 19:		R7 = R6 - 8; //Cmienza la funcion
		//La direccion es 8
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 16
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 24
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 1; //Cojo el valor y lo pongo en la cima de la pila 
		R1 = R6;
		R1 = R1 - 24;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 24;
		R7 = R7 - 8; //AQUI COMIENZA EL WHILE
		P(R7) = R6;
		R6 = R7;
L 52:	
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 1; //Cojo el valor y lo pongo en la cima de la pila 
		RR2 = D(R7); //Comenzamos MAYOR
		RR1 = D(R7 + 8);
		IF (RR1 > RR2) GT(53);
		RR1 = 0;
		GT(54);
L 53:	RR1 = 1;
L 54:	R7 = R7 + 8;
		D(R7) = RR1; //Final MAYOR
		RR1 = D(R7);
		IF (RR1 == 0) GT(55); //Comprobación WHILE
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 24;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		RR2 = D(R7); //Comenzamos MULTIPLICACION
		RR1 = D(R7 + 8);
		RR1 = RR1 * RR2;
		R7 = R7 + 8;
		D(R7) = RR1; //Final MULTIPLICACION
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 24;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 0;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 1; //Cojo el valor y lo pongo en la cima de la pila 
		RR2 = D(R7); //Comenzamos RESTA
		RR1 = D(R7 + 8);
		RR1 = RR1 - RR2;
		R7 = R7 + 8;
		D(R7) = RR1; //Final RESTA
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 16;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 0;
		GT(52);
L 55:		R7 = R6;
		R6 = P(R7);
		R7 = R7 + 8; //AQUI TERMINA EL WHILE
		R5 = P(R6);
		R2 = P(R6 - 8);
		R7 = R6 + 8;
		R1 = R6;
		R1 = R1 - 24;
		R7 = R7 - 8;
		RR1 = D(R1);
		D(R7) = RR1;
		R6 = R5;
		GT(R2);
L 46:		R7 = R6 - 8; //Cmienza la funcion
		//La direccion es 8
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 16
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 24
		R7 = R7 - 8; //AQUI COMIENZA EL IF
		P(R7) = R6;
		R6 = R7;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 1; //Cojo el valor y lo pongo en la cima de la pila 
		RR2 = D(R7); //Comenzamos IGUALDAD
		RR1 = D(R7 + 8);
		IF (RR1 == RR2) GT(57);
		RR1 = 0;
		GT(58);
L 57:	RR1 = 1;
L 58:	R7 = R7 + 8;
		D(R7) = RR1; //Final IGUALDAD
		RR1 = D(R7);
		IF(RR1 < 1) GT(59);
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 0; //Cojo el valor y lo pongo en la cima de la pila 
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 24;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 0;
		GT(56);
L 59:	R7 = R7 + 8;
		R7 = R7 - 8; //AQUI COMIENZA EL IF
		P(R7) = R6;
		R6 = R7;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 2; //Cojo el valor y lo pongo en la cima de la pila 
		RR2 = D(R7); //Comenzamos IGUALDAD
		RR1 = D(R7 + 8);
		IF (RR1 == RR2) GT(61);
		RR1 = 0;
		GT(62);
L 61:	RR1 = 1;
L 62:	R7 = R7 + 8;
		D(R7) = RR1; //Final IGUALDAD
		RR1 = D(R7);
		IF(RR1 < 1) GT(63);
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 1; //Cojo el valor y lo pongo en la cima de la pila 
		R1 = R6;
		R1 = P(R1);
		R1 = P(R1);
		R1 = R1 - 24;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 0;
		GT(60);
L 63:	R7 = R7 + 8;
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 8
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 16
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 1; //Cojo el valor y lo pongo en la cima de la pila 
		RR2 = D(R7); //Comenzamos RESTA
		RR1 = D(R7 + 8);
		RR1 = RR1 - RR2;
		R7 = R7 + 8;
		D(R7) = RR1; //Final RESTA
		R1 = R6;
		R1 = R1 - 16;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 16;
		R7 = R7 - 8; // LLAMADA: reservamos espacio para meter R6 actual. La etiqueta vale -> 64 
		R5 = R7; //Metemos en R5 la dir donde va a estar R6 
		R7 = R7 - 8; //Dejamos un hueco
		P(R7) = 64; //Metemos en ese hueco la etiqueta a la que ir cuando acabe la llamada
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		P(R5) = R6; //Guardo el R6 como puntero en donde apunta R5
		R6 = R5; //Pongo ahora R6 en donde apunta R5
		GT(46);
L 64://Fin codigo LLAMADA 
 		R1 = R6;
		R1 = R1 - 8;
		RR1 = D(R7); //Cojo lo de la cima, que deberia ser el resultado de la funcion
		D(R1) = RR1; //Voy a la variable y meto el resultado
		R7 = R6 - 16;
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 24
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 32
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 2; //Cojo el valor y lo pongo en la cima de la pila 
		RR2 = D(R7); //Comenzamos RESTA
		RR1 = D(R7 + 8);
		RR1 = RR1 - RR2;
		R7 = R7 + 8;
		D(R7) = RR1; //Final RESTA
		R1 = R6;
		R1 = R1 - 32;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 32;
		R7 = R7 - 8; // LLAMADA: reservamos espacio para meter R6 actual. La etiqueta vale -> 65 
		R5 = R7; //Metemos en R5 la dir donde va a estar R6 
		R7 = R7 - 8; //Dejamos un hueco
		P(R7) = 65; //Metemos en ese hueco la etiqueta a la que ir cuando acabe la llamada
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = R1 - 32;
		RR3 = D(R1);
		D(R7) = RR3;
		P(R5) = R6; //Guardo el R6 como puntero en donde apunta R5
		R6 = R5; //Pongo ahora R6 en donde apunta R5
		GT(46);
L 65://Fin codigo LLAMADA 
 		R1 = R6;
		R1 = R1 - 24;
		RR1 = D(R7); //Cojo lo de la cima, que deberia ser el resultado de la funcion
		D(R1) = RR1; //Voy a la variable y meto el resultado
		R7 = R6 - 32;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = R1 - 8;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = R1 - 24;
		RR3 = D(R1);
		D(R7) = RR3;
		RR2 = D(R7); //Comenzamos SUMA
		RR1 = D(R7 + 8);
		RR1 = RR1 + RR2;
		R7 = R7 + 8;
		D(R7) = RR1; //Final SUMA
		R1 = R6;
		R1 = P(R1);
		R1 = P(R1);
		R1 = R1 - 24;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 32;
L 60:		R7 = R6;
		R6 = P(R7);
		R7 = R7 + 8; //AQUI TERMINA EL IF
L 56:		R7 = R6;
		R6 = P(R7);
		R7 = R7 + 8; //AQUI TERMINA EL IF
		R5 = P(R6);
		R2 = P(R6 - 8);
		R7 = R6 + 8;
		R1 = R6;
		R1 = R1 - 24;
		R7 = R7 - 8;
		RR1 = D(R1);
		D(R7) = RR1;
		R6 = R5;
		GT(R2);
L 34:		R7 = R6 - 8; //Cmienza la funcion
		//La direccion es 8
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 16
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 24
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 32
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 40
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 48
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 1; //Cojo el valor y lo pongo en la cima de la pila 
		R1 = R6;
		R1 = R1 - 48;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 48;
		R7 = R7 - 8; //AQUI COMIENZA EL IF
		P(R7) = R6;
		R6 = R7;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 0; //Cojo el valor y lo pongo en la cima de la pila 
		RR2 = D(R7); //Comenzamos MENOR
		RR1 = D(R7 + 8);
		IF (RR1 < RR2) GT(67);
		RR1 = 0;
		GT(68);
L 67:	RR1 = 1;
L 68:	R7 = R7 + 8;
		D(R7) = RR1; //Final MENOR
		RR1 = D(R7);
		IF(RR1 < 1) GT(69);
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 0; //Cojo el valor y lo pongo en la cima de la pila 
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		RR2 = D(R7); //Comenzamos RESTA
		RR1 = D(R7 + 8);
		RR1 = RR1 - RR2;
		R7 = R7 + 8;
		D(R7) = RR1; //Final RESTA
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 40;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 0;
		GT(66);
L 69:	R7 = R7 + 8;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 40;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 0;
		R7 = R7 - 8; //AQUI COMIENZA EL IF
		P(R7) = R6;
		R6 = R7;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = P(R1);
		R1 = R1 - 24;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 0; //Cojo el valor y lo pongo en la cima de la pila 
		RR2 = D(R7); //Comenzamos IGUALDAD
		RR1 = D(R7 + 8);
		IF (RR1 == RR2) GT(71);
		RR1 = 0;
		GT(72);
L 71:	RR1 = 1;
L 72:	R7 = R7 + 8;
		D(R7) = RR1; //Final IGUALDAD
		RR1 = D(R7);
		IF(RR1 < 1) GT(73);
		R7 = R7 - 8; //AQUI COMIENZA EL IF
		P(R7) = R6;
		R6 = R7;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = P(R1);
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 0; //Cojo el valor y lo pongo en la cima de la pila 
		RR2 = D(R7); //Comenzamos IGUALDAD
		RR1 = D(R7 + 8);
		IF (RR1 == RR2) GT(75);
		RR1 = 0;
		GT(76);
L 75:	RR1 = 1;
L 76:	R7 = R7 + 8;
		D(R7) = RR1; //Final IGUALDAD
		RR1 = D(R7);
		IF(RR1 < 1) GT(77);
		GT(-2);
		GT(74);
L 77:	R7 = R7 + 8;
L 74:		R7 = R6;
		R6 = P(R7);
		R7 = R7 + 8; //AQUI TERMINA EL IF
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 0; //Cojo el valor y lo pongo en la cima de la pila 
		R1 = R6;
		R1 = P(R1);
		R1 = P(R1);
		R1 = R1 - 32;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 0;
		GT(70);
L 73:	R7 = R7 + 8;
L 70:		R7 = R6;
		R6 = P(R7);
		R7 = R7 + 8; //AQUI TERMINA EL IF
L 66:		R7 = R6;
		R6 = P(R7);
		R7 = R7 + 8; //AQUI TERMINA EL IF
		R7 = R7 - 8; //AQUI COMIENZA EL FOR
		P(R7) = R6;
		R6 = R7;
		R7 = R7 - 8; //Asigno espacio para la variable
		//La direccion es 8
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 0; //Cojo el valor y lo pongo en la cima de la pila 
		R1 = R6;
		R1 = R1 - 8;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 8;
L 78:	
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = R1 - 8;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 40;
		RR3 = D(R1);
		D(R7) = RR3;
		RR2 = D(R7); //Comenzamos MENOR
		RR1 = D(R7 + 8);
		IF (RR1 < RR2) GT(79);
		RR1 = 0;
		GT(80);
L 79:	RR1 = 1;
L 80:	R7 = R7 + 8;
		D(R7) = RR1; //Final MENOR
		RR1 = D(R7);
		IF (RR1 == 0) GT(81); //Comprobación FOR
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = R1 - 8;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 1; //Cojo el valor y lo pongo en la cima de la pila 
		RR2 = D(R7); //Comenzamos SUMA
		RR1 = D(R7 + 8);
		RR1 = RR1 + RR2;
		R7 = R7 + 8;
		D(R7) = RR1; //Final SUMA
		R1 = R6;
		R1 = R1 - 8;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 8;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 48;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 24;
		RR3 = D(R1);
		D(R7) = RR3;
		RR2 = D(R7); //Comenzamos MULTIPLICACION
		RR1 = D(R7 + 8);
		RR1 = RR1 * RR2;
		R7 = R7 + 8;
		D(R7) = RR1; //Final MULTIPLICACION
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 48;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 8;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 48;
		RR3 = D(R1);
		D(R7) = RR3;
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 32;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 8;
		GT(78);
L 81:		R7 = R6;
		R6 = P(R7);
		R7 = R7 + 8; //AQUI TERMINA EL FOR
		R7 = R7 - 8; //AQUI COMIENZA EL IF
		P(R7) = R6;
		R6 = R7;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 16;
		RR3 = D(R1);
		D(R7) = RR3;
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 0; //Cojo el valor y lo pongo en la cima de la pila 
		RR2 = D(R7); //Comenzamos MENOR
		RR1 = D(R7 + 8);
		IF (RR1 < RR2) GT(83);
		RR1 = 0;
		GT(84);
L 83:	RR1 = 1;
L 84:	R7 = R7 + 8;
		D(R7) = RR1; //Final MENOR
		RR1 = D(R7);
		IF(RR1 < 1) GT(85);
		R7 = R7 - 8; //Creo espacio para meter valor
		D(R7) = 1; //Cojo el valor y lo pongo en la cima de la pila 
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 48;
		RR3 = D(R1);
		D(R7) = RR3;
		RR2 = D(R7); //Comenzamos DIVISION
		RR1 = D(R7 + 8);
		RR1 = RR1 / RR2;
		R7 = R7 + 8;
		D(R7) = RR1; //Final DIVISION
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 48;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 0;
		R7 = R7 - 8; //Creo espacio para meter valor
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 48;
		RR3 = D(R1);
		D(R7) = RR3;
		R1 = R6;
		R1 = P(R1);
		R1 = R1 - 32;
		RR1 = D(R7);
		D(R1) = RR1;
		R7 = R6 - 0;
		GT(82);
L 85:	R7 = R7 + 8;
L 82:		R7 = R6;
		R6 = P(R7);
		R7 = R7 + 8; //AQUI TERMINA EL IF
		R5 = P(R6);
		R2 = P(R6 - 8);
		R7 = R6 + 8;
		R1 = R6;
		R1 = R1 - 32;
		R7 = R7 - 8;
		RR1 = D(R1);
		D(R7) = RR1;
		R6 = R5;
		GT(R2);
L 51:		R7 = R6 - 8; //Cmienza la funcion
		R7 = R7 - 124;
		U(R7 + 0) = 'N';
		U(R7 + 4) = 'o';
		U(R7 + 8) = ' ';
		U(R7 + 12) = 'h';
		U(R7 + 16) = 'a';
		U(R7 + 20) = ' ';
		U(R7 + 24) = 'd';
		U(R7 + 28) = 'i';
		U(R7 + 32) = 'c';
		U(R7 + 36) = 'h';
		U(R7 + 40) = 'o';
		U(R7 + 44) = ' ';
		U(R7 + 48) = 'u';
		U(R7 + 52) = 'n';
		U(R7 + 56) = 'a';
		U(R7 + 60) = ' ';
		U(R7 + 64) = 'o';
		U(R7 + 68) = 'p';
		U(R7 + 72) = 'c';
		U(R7 + 76) = 'i';
		U(R7 + 80) = '�';
		U(R7 + 84) = '�';
		U(R7 + 88) = 'n';
		U(R7 + 92) = ' ';
		U(R7 + 96) = 'v';
		U(R7 + 100) = '�';
		U(R7 + 104) = '�';
		U(R7 + 108) = 'l';
		U(R7 + 112) = 'i';
		U(R7 + 116) = 'd';
		U(R7 + 120) = 'a';
		R1=0x11ffc; //COMIENZA IMPRIMIR
		R2=R7; //POSICION PILA A IMPRIMIR
		R3=31; //NUMERO CARRACTERES
		R0=86; //RETORNO
		GT(putf_);
L 86:
		R1=0x11ffc ; //COMIENZA IMPRIMIR
		R2 = 10; //POSICION PILA A IMPRIMIR
		R3 = -3; //IMPRIMIR SALTO LINEA
		R0=87; //RETORNO
		GT(putf_);
L 87:
		R5 = P(R6); //Guardamos en R5 el R6 antiguo
		R2 = P(R6 - 8); //Guardamos en R2 la etiqueta de retorno
		R7 = R6 + 8;
		R6 = R5; //Hacemos que R6 vuelva a su antiguo lugar
		GT(R2); //Vamos a la etiqueta de retorno
END
