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
