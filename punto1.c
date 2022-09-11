#include <stdio.h>
#include <stdlib.h>

int obtener_columna(int);

int main() {

	char cadena[100];
	int i = 0;
	int cant_hexa = 0; 
	int cant_octa = 0; 
	int cant_dec = 0;	
	int estado = 0;
	int estado_salida = 5;
	int estado_rechazo = 6;		
	char caracter;
    int columna;
	int matriz[7][10]={{4,1,4,4,4,6,6,6,6,6},
					   {6,6,2,6,6,6,3,0,5,6},
					   {6,2,2,6,6,6,6,0,5,6},
					   {6,3,3,3,3,3,6,0,5,6},
					   {6,4,4,4,4,6,6,0,5,6},
					   {6,6,6,6,6,6,6,6,6,6},
					   {6,6,6,6,6,6,6,6,6,6}};

	printf("Ingrese una cadena: ");
	scanf("%s", cadena);
    
	caracter = cadena[0];
	if (caracter == '\0') {
		printf("Cadena vacía\n");
		return 0;
	}
	
	while(estado!=estado_salida && estado!=estado_rechazo){
		columna = obtener_columna(caracter);
		if (estado == 3 && (columna == 7 || columna == 8))   // Cuenta cantidad de hexadecimales
			cant_hexa++;
		if (estado == 2 && (columna == 7 || columna == 8))   // Cuenta cantidad de octales
			cant_octa++;		
		if (estado == 4 && (columna == 7 || columna == 8))   // Cuenta cantidad de decimales
			cant_dec++;
		if (estado == 1 && (columna == 7 || columna == 8))   // Cuenta al cero como un decimal
			cant_dec++;
		
		estado = matriz[estado][columna];
		i++;
		caracter = cadena[i];
	}	
		
	if(estado == estado_salida)
		printf("HEX: %d    OCTA: %d    DEC: %d\n", cant_hexa, cant_octa, cant_dec);
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
			if (c > 48 && c < 56) // [1,7]
				return 2;
			else
				if (c == 56) // 8
					return 3;
				else
					if (c == 57) // 9
						return 4;
					else
						if ((c > 65 && c < 103)||(c > 64 && c < 71)) // [a-fA-F]
							return 5;
						else
							if ((c == 120)||(c == 88)) // x|X
								return 6;
							else
								if (c == 38) // &
									return 7;
								else
									if (c == '\0') // '\0'
										return 8;
									else				// OTROS
										return 9;										
}
