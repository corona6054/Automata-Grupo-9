#include <stdio.h>
#include <stdlib.h>

int obtener_columna(int);
int obtener_columna_punto2(int);
int potencia(int base, unsigned int exp);
int devolvernum(char cadena[100], int posicion);
int calcularsig(char cadena[100]);
int sigoperador(char cadena[100], int posicion);
int possigtermino(char cadena[100], int posicion);

void main(){
	int estado = 0;
	int estado_salida = 3;
	int estado_rechazo = 4;	
	int matriz[5][5]={ {4,2,1,4,4},
					   {0,1,1,3,4},
					   {0,4,4,3,4},
					   {4,4,4,4,4},
					   {4,4,4,4,4}};

    char cadena[100];
	char caracter;
	printf("Ingrese una cadena: ");
	scanf("%s", cadena);
	caracter = cadena[0];

	int i=0;
	int columna;

	while(estado!=estado_salida && estado!=estado_rechazo){	
		columna = obtener_columna(caracter);
		estado = matriz[estado][columna];
		i++;
		caracter = cadena[i];
	}	
	if (estado == estado_salida)
	{
		printf("Correcto \n");
		calcularsig(cadena);
 	}
	else
		printf("Error léxico\n");

	int numerofinal = 0;
}

int obtener_columna(int c){
	if (c == 42 ||c == 43 ||c == 45)  // *,+,-
		return 0;
	else
		if (c == 48)  // '0'
			return 1;
		else
			if(c>48 && c<58) // 1-9
				return 2;
			else	
				if (c == '\0') // '\0'
					return 3;
				else
					return 4;  // Otros
}

int devolvernum(char cadena[100],int posicion) {
	int estado = 0;
	int estado_salida = 3;
	int estado_rechazo = 4;	
	int matriz[5][4]={ {1,2,4,4},
					   {4,4,3,3},
					   {2,2,3,3},
					   {4,4,4,4},
					   {4,4,4,4}};
	char caracter;
	caracter = cadena[posicion];
	int longitud = posicion;
	//cantidad de unidades para las potencias de 10
	while (cadena[longitud]>47 &&cadena[longitud]<58)	longitud++;
	longitud = longitud - 1;

	int i=posicion;
	int columna;
	int numerofinal = 0;

	while(estado!=estado_salida && estado!=estado_rechazo){    // total = numero * (10^ posicion) 
		columna = obtener_columna_punto2(caracter);
		if(columna==0||columna==1)	numerofinal = numerofinal + (caracter - 48) * (potencia(10, longitud - i));	
		estado = matriz[estado][columna];
		i++;
		caracter = cadena[i];
	}


	if (estado == estado_salida)
	{
		return numerofinal;
	}
	else
		printf("Error léxico\n");
	return 0;
}

int obtener_columna_punto2(int c){
		if (c == 48)  // '0'
			return 0;
		else
			if(c>48 && c<58) // 1-9
				return 1;
			else	
				if (c == '\0') // '\0'
					return 2;
				else
					return 3;  // Otros
}

int potencia(int base, unsigned int exp) {
    int i, resultado = 1;
    for (i = 0; i < exp; i++)
        resultado = resultado * base;
    return resultado;
 }
 
int sigoperador(char cadena[100],int posicion){
	int caracter=1;
	while (caracter != 42 && caracter != 43 &&caracter != 45 &&caracter != '\0')	{   // *,+,-, \0
		posicion++;
		caracter = cadena[posicion];
	}
	return caracter;
}

int calcularsig(char cadena[100]){
	
	int estado = 0;
	int estado_salida = 3;
	int estado_rechazo = 4;	
	int matriz[5][5]={ {4,2,1,4,4},
					   {0,1,1,3,4},
					   {0,4,4,3,4},
					   {4,4,4,4,4},
					   {4,4,4,4,4}};

	int i=0;
	int inicionum=1;
	int numeros = 0;
	int operador=0;
	int columna;
	int caracter = cadena[0];

	while(estado!=estado_salida && estado!=estado_rechazo){	
		columna = obtener_columna(caracter);
		estado = matriz[estado][columna];
		// calcula al inicio de un numero y se activa nuevamente despues de un operador
		if (inicionum == 1)
		{		
			numeros = devolvernum(cadena, i);
			operador = sigoperador(cadena, i);
			printf("Numeros: %d \n",numeros);
			printf("Operador: %c \n",operador);
			inicionum = 0;
		}
		if (columna==0)	inicionum = 1;
		i++;
		caracter = cadena[i];
	}	
}