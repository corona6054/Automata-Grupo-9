//RESUELVE EXPRESION CON PRECEDENCIA DE OPERADORES UTILIZANDO UNA LISTA SIMPLEMENTE ENLAZADA
#include <stdio.h>
#include <stdlib.h>

//FORMATO DE LOS NODOS
typedef struct _nodo {
    float operando;
    char operador;
    struct _nodo *siguiente;
} Nodo;


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


