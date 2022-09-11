#include <stdio.h>
#include <stdlib.h>

int obtener_columna(int);

void main(){
    int i=0;
    int estado = 0;
	int estado_salida = 3;
	int estado_rechazo = 4;	
	char caracter;
    int columna;
	int matriz[5][5]={ {4,2,1,4,4},
					   {0,1,1,3,4},
					   {0,4,4,3,4},
					   {4,4,4,4,4},
					   {4,4,4,4,4}};

    char cadena[100];
	printf("Ingrese una cadena: ");
	scanf("%s", cadena);
	caracter = cadena[0];

    while(estado!=estado_salida && estado!=estado_rechazo){       
		columna = obtener_columna(caracter);
		estado = matriz[estado][columna];
		i++;
		caracter = cadena[i];
	}	

    if (estado == estado_salida)
	{
		printf("Correcto \n");
	}
	else
		printf("Error léxico\n");
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


 
