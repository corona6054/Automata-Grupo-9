#include <stdio.h>
#include <stdlib.h>

int obtener_columna(int);
int potencia(int base, unsigned int exp);

int main() {
	
	int i=0;
	int signo = 1;
	int longitud = 0;
	int numerofinal = 0;
	int estado = 0;
	int estado_salida = 4;
	int estado_rechazo = 5;	
	char caracter;
    int columna;
	int matriz[6][5]={ {1,3,2,5,5},
					   {5,5,2,5,5},
					   {5,2,2,4,5},
					   {5,5,5,4,5},
					   {5,5,5,5,5},
					   {5,5,5,5,5} };
	
	char cadena[100];
	printf("Ingrese una cadena: ");
	scanf("%s", cadena);
	caracter = cadena[0];

	//cantidad de unidades para las potencias de 10
	while (cadena[longitud]!='\0')	  
	{
		longitud++;
	};
	longitud = longitud - 1;

	// lee primer caracter si es negativo o cero
if (obtener_columna(cadena[0])==0){      
	signo = -1;
	columna = obtener_columna(caracter);
		estado = matriz[estado][columna];
		i++;
		caracter = cadena[i];
} 
else
	if (obtener_columna(cadena[0])==0)
	{
		signo = -1;
	}

	//lee el resto de caracteres menos el signo
	while(estado!=estado_salida && estado!=estado_rechazo){       
		if(caracter!='\0')	
		// total = numero * (10^ posicion)
		numerofinal = numerofinal + (caracter - 48) * (potencia(10, longitud - i));	

		columna = obtener_columna(caracter);
		estado = matriz[estado][columna];
		i++;
		caracter = cadena[i];
	}	

	if (estado == estado_salida)
	{
		numerofinal = numerofinal * signo;
		printf("Numero final: %d \n",numerofinal);
	}
	else
		printf("Error léxico\n");
}


int obtener_columna(int c){
	if (c == 45)  // '-'
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

int potencia(int base, unsigned int exp) {
    int i, resultado = 1;
    for (i = 0; i < exp; i++)
        resultado = resultado * base;
    return resultado;
 }
