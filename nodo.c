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
