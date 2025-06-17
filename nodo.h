#ifndef NODO_H
#define NODO_H

#include <stdbool.h>
#include "persona.h"

struct Nodo {
    struct Persona* p;
    struct Nodo* siguiente;
    struct Nodo* anterior;
};

extern struct Nodo* primero;
extern struct Nodo* ultimo;

int getTam();
void insertarUltimo(struct Persona p);
void insertarPrimero(struct Persona p);
void imprimeInicioAFin();
void imprimerFinAInicio();
void buscaPorId(int idS);
void eliminaPorId(int idS);
void insertarEnPosN(int pos, struct Persona p);

#endif
