#include <stdio.h>
#include "persona.h"
#include "nodo.h"

extern void insertarPrimero(struct Persona p);
extern void insertarUltimo(struct Persona p);
extern void insertarEnPosN(int pos, struct Persona p);
extern void imprimeInicioAFin();
extern void imprimerFinAInicio();
extern void buscaPorId(int id);
extern void eliminaPorId(int id);
extern int getTam();

int main() {
    struct Persona p1 = crearPersona(1, "tutis");
    struct Persona p2 = crearPersona(2, "colay");
    struct Persona p3 = crearPersona(3, "chronos");
    struct Persona p4 = crearPersona(4, "milo");

    printf("insertando al principio:\n");
    insertarPrimero(p1);
    imprimeInicioAFin();

    printf("insertando al final:\n");
    insertarUltimo(p2);
    imprimeInicioAFin();

    printf("nsertando en posicion 2:\n");
    insertarEnPosN(2, p3);
    imprimeInicioAFin();

    printf("insertando en posicion 1:\n");
    insertarEnPosN(1, p4);
    imprimeInicioAFin();

    printf("impresion de fin a inicio:\n");
    imprimerFinAInicio();

    printf("buscando persona con id 3:\n");
    buscaPorId(3);

    printf("buscando persona con id 99:\n");
    buscaPorId(99);

    printf("eliminando persona con id 4:\n");
    eliminaPorId(4);
    imprimeInicioAFin();

    printf("eliminando persona con id 2:\n");
    eliminaPorId(2);
    imprimeInicioAFin();

    printf("liminando persona con id 1:\n");
    eliminaPorId(1);
    imprimeInicioAFin();

    printf("intentando eliminar persona con id 99:\n");
    eliminaPorId(99);

    printf("tamaño final de la lista: %d\n", getTam());

    return 0;
}

