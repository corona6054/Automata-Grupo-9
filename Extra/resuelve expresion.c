//RESUELVE EXPRESION CON PRECEDENCIA DE OPERADORES UTILIZANDO UNA LISTA SIMPLEMENTE ENLAZADA
#include <stdio.h>
#include <stdlib.h>

//FORMATO DE LOS NODOS
typedef struct _nodo {
    float operando;
    char operador;
    struct _nodo *siguiente;
} Nodo;

//PROTOTIPOS DE FUNCIONES
Nodo * crear(float,char);  //CREA EL PRIMER NODO DE LA LISTA
void mostrarLista(Nodo *);   //MUESTRA LA LISTA ENTERA
Nodo * agregar(float,char,Nodo *);  //AGREGAR NODO AL FINAL SABIENDO EL ULTIMO ANTERIOR
Nodo * buscarPrimeroMultiplicativo(Nodo *);   //DEVUELVE EL NODO DONDE ENCUENTRA OPERADOR MULTIPLICATIVO
Nodo * buscarPrimeroAditivo(Nodo *);   //DEVUELVE EL NODO DONDE ENCUENTRA OPERADOR ADITIVO
void reducirOperacion(Nodo *);  //DADO UN NODO REALIZA LA OPERACION
float resolverLista(Nodo *); //REDUCE LA LISTA A UN SOLO NODO DEVOLVIENDO EL RESULTADO

//FUNCION MAIN
void main()
{
    Nodo *lista;
    Nodo *ultimo;
    float resultado;
    
    
    //CREAR LA LISTA CON LA EXPRESION 6/8-100/67+23*4 QUE DEBERIA DAR 91.2575
    lista  =   crear(6,'/');
    ultimo = agregar(8,'-',lista);
    ultimo = agregar(100,'/',ultimo);
    ultimo = agregar(67,'+',ultimo);
    ultimo = agregar(23,'*',ultimo);
    ultimo = agregar(4,'=',ultimo);
    
    //MOSTRAR LA LISTA
    mostrarLista(lista);
    
    //RESUELVO LA LISTA
    resultado = resolverLista(lista);
    
    printf("\n");
    mostrarLista(lista);
    
    printf("%f\n", resultado);
    
}


//CODIGO DE FUNCIONES UTILIZADAS
void mostrarLista(Nodo * lista) {
    Nodo *nodo = lista; 
    do {
        printf("%f\n",nodo->operando);
        printf("%c\n",nodo->operador);
        nodo = nodo->siguiente;
    } while (nodo != NULL);   
}

Nodo * agregar(float operando,char operador, Nodo * ultimo){
    Nodo * nuevoNodo;    
    nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->operando = operando;
    nuevoNodo->operador = operador;
    ultimo->siguiente = nuevoNodo;
    return nuevoNodo;
}

Nodo * buscarPrimeroMultiplicativo(Nodo * lista) {
    Nodo * nodo;
    nodo = lista;
    do {
        if (nodo->operador == '*' || nodo->operador == '/') return nodo;
        nodo = nodo->siguiente;
    } while (nodo != NULL);
    return NULL;
}

Nodo * buscarPrimeroAditivo(Nodo * lista) {
    Nodo * nodo;
    nodo = lista;
    do {
        if (nodo->operador == '+' || nodo->operador == '-') return nodo;
        nodo = nodo->siguiente;
    } while (nodo != NULL);
    return NULL;
}

void reducirOperacion(Nodo * nodoOperacion) {
    Nodo * nodoABorrar;
    switch (nodoOperacion->operador) {
        case '+': {
            nodoOperacion->operando = nodoOperacion->operando + nodoOperacion->siguiente->operando;
            nodoOperacion->operador = nodoOperacion->siguiente->operador;
            nodoABorrar = nodoOperacion->siguiente;
            nodoOperacion->siguiente = nodoOperacion->siguiente->siguiente;
            free(nodoABorrar);
            break;
        }
        case '-': {
            nodoOperacion->operando = nodoOperacion->operando - nodoOperacion->siguiente->operando;
            nodoOperacion->operador = nodoOperacion->siguiente->operador;
            nodoABorrar = nodoOperacion->siguiente;
            nodoOperacion->siguiente = nodoOperacion->siguiente->siguiente;
            free(nodoABorrar);
            break;
        }    
        case '*': {
            nodoOperacion->operando = nodoOperacion->operando * nodoOperacion->siguiente->operando;
            nodoOperacion->operador = nodoOperacion->siguiente->operador;
            nodoABorrar = nodoOperacion->siguiente;
            nodoOperacion->siguiente = nodoOperacion->siguiente->siguiente;
            free(nodoABorrar);
            break;
        }   
        case '/': {
            nodoOperacion->operando = nodoOperacion->operando / nodoOperacion->siguiente->operando;
            nodoOperacion->operador = nodoOperacion->siguiente->operador;
            nodoABorrar = nodoOperacion->siguiente;
            nodoOperacion->siguiente = nodoOperacion->siguiente->siguiente;
            free(nodoABorrar);
            break;
        }
    }
}

Nodo * crear(float operando, char operador) {
    Nodo * nuevoNodo;
    nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->operando = operando;
    nuevoNodo->operador = operador;
    return nuevoNodo;
}

float resolverLista(Nodo * lista) {
    Nodo * posicion;
    //REDUCIR DIVISION O MULTIPLICACION
    posicion = buscarPrimeroMultiplicativo(lista);
    while (posicion != NULL) {
        reducirOperacion(posicion);
        posicion = buscarPrimeroMultiplicativo(lista);
    }       
    //REDUCIR SUMA O RESTA
    posicion = buscarPrimeroAditivo(lista);
    while (posicion != NULL) {
        reducirOperacion(posicion);
        posicion = buscarPrimeroAditivo(lista);
    }      
    return lista->operando;
}


