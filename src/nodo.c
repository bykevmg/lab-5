z#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "nodo.h"

struct Nodo* primero = NULL;
struct Nodo* ultimo = NULL;

int getTam(){
    
    int cont = 0;
    if(primero==NULL){
        return cont;
    }
    
    else{
        struct Nodo* actual = primero;
        
        while(actual->siguiente != NULL){
            cont++;
            actual = actual->siguiente;
        }
    }
    
    return cont+1;
}


void insertarUltimo(struct Persona p) {
    if (primero == NULL) {
        primero = malloc(sizeof(struct Nodo));
        primero->p = malloc(sizeof(struct Persona));
        *(primero->p)      = p;
        primero->anterior   = NULL;
        primero->siguiente  = NULL;
        
        
        // es valido?
        ultimo = primero;
    } else {
        struct Nodo* actual = primero;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = malloc(sizeof(struct Nodo));
        struct Nodo* siguiente = actual->siguiente;
        siguiente->p = malloc(sizeof(struct Persona));
        *(siguiente->p) = p;
        siguiente->anterior = actual;
        siguiente->siguiente = NULL;
        ultimo = siguiente;
    }
}

void insertarPrimero(struct Persona p){
    
    if(primero == NULL){
        primero = malloc(sizeof(struct Nodo));
        primero->p = malloc(sizeof(struct Persona));
        *(primero->p) = p;
        primero->siguiente = NULL;
        primero->anterior= NULL;
        ultimo = primero;
    }
    
    else{
        struct Nodo* actual = malloc(sizeof(struct Nodo));
        actual->p = malloc(sizeof(struct Persona));
        *(actual->p) = p;
        actual->siguiente = primero;
        actual->anterior = NULL;
        primero->anterior = actual;
        primero = actual;
    }
    
}




void imprimeInicioAFin(){
    
    if (primero == NULL){
        printf("La lista está vacía\n");
        return;
        
        
    }
    struct Nodo* actual = primero;
    
    while (actual != NULL) {
        
        imprimirPersona( *(actual->p) );  
        actual = actual->siguiente;
        
        
    }
}


void imprimerFinAInicio(){
    
    if (primero == NULL){
        printf("La lista está vacía\n");
        return;
        
    }
    
     struct Nodo* actual = ultimo;
     
     while(actual != NULL){
         imprimirPersona( *(actual->p) );
         actual = actual->anterior;
     }
    
    
}


void buscaPorId(int idS){
 
 
    bool encontrado = false;
 
    if(primero == NULL){
        printf("Lista vacia");
    }
    
    struct Nodo* actual = primero;
    
    while(actual->siguiente != NULL){
        
        if(actual->p->id == idS){
            printf("Persona encontrado: \n");
            imprimirPersona( *(actual->p));
            encontrado = true;
        }
        
        actual = actual->siguiente;
    }
 
    if(encontrado == false){
        printf("Persona no encontrada con id: %d\n", idS);
    }


 
    
}




void eliminaPorId(int idS){
    
    bool eliminado = false;
    
    
    
    if(primero == NULL){
        printf("No hay nada que eliminar");
    }
    
    if (primero->p->id == idS && primero->siguiente == NULL) {
        free(primero->p);
        free(primero);
        primero = NULL;
        ultimo  = NULL;
        printf("Persona eliminada con id: %d\n", idS);
        return;
    }
    
    if (primero->p->id == idS) {
        struct Nodo* actual = primero;
        primero = primero->siguiente;
        primero->anterior = NULL;
        free(actual->p);
        free(actual);
        printf("Persona eliminada con id: %d\n", idS);
        return;
    }

    

    struct Nodo* actual = primero->siguiente;
    while (actual != NULL) {
        if (actual->p->id == idS) {
         
            if (actual->siguiente == NULL) {
                ultimo = actual->anterior;
                ultimo->siguiente = NULL;
            } else {
                
                actual->anterior->siguiente = actual->siguiente;
                
                actual->siguiente->anterior = actual->anterior;
            }
            free(actual->p);
            free(actual);
            printf("Persona eliminada con id: %d\n", idS);
            return;
        }
        actual = actual->siguiente;
    }
    
    if(eliminado == false){
        printf("Persona no encontrada con id: %d\n", idS);
    }
    
    
}

void insertarEnPosN(int pos, struct Persona p){
    

    
    struct Nodo* nuevo = malloc(sizeof(struct Nodo));
    nuevo->p = malloc(sizeof(struct Persona));
    *(nuevo->p) = p;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;


    if (pos < 1 || pos > getTam()) {
        printf("Esa pos no es valida el tam es de %d\n", getTam());
        return;
    }

    if (pos == 1) {
        if (primero != NULL) {
            primero->anterior = nuevo;
            nuevo->siguiente  = primero;
        } else {
            ultimo = nuevo;
        }
        primero = nuevo;
        return;
    }

    if (pos == getTam()) {
        ultimo->siguiente = nuevo;
        nuevo->anterior   = ultimo;
        ultimo            = nuevo;
        return;
    }

    int cont = 1;
    struct Nodo* actual = primero;
    while (cont < pos - 1) {
        actual = actual->siguiente;
        cont++;
    }

    nuevo->siguiente                = actual->siguiente;
    nuevo->anterior                 = actual;
    actual->siguiente->anterior     = nuevo;
    actual->siguiente               = nuevo;
}
