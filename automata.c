#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int columna(int);
int esPalabraLeng(const char*);

int main(int argc,char *argv[]) {
	
	char vector[]="17t23456";
	if(esPalabraLeng(vector))
		printf("pertenece");
	else
		printf("NO pertenece");
	return 0;
}
int columna(int c){
	if(c=='+')
		return 0;
	else
		if(c=='-')
			return 1;
		else
			return 2;
}
//1 cuando es aceptacion
int esPalabraLeng(const char* cadena)
{
	static int tt[4][3] = {{1,1,2},
						   {3,3,2},
						   {3,3,2},
						   {3,3,3}};
	int e=0;
	int i=0;
	//ver si los caracteres pertenecen al alfabeto
	int c=cadena[0];
	//3454453+456345+634+5645634+56345634+5

	while(c != '\0' && e!=3){
		e=tt[e][columna(c)];
		i++;
		c=cadena[i];
	}
	if(e==2)
		return 1;
	else
		return 0;
}