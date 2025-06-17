#include <stdio.h>
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
