#include <stdio.h>
#include <string.h>
#include "persona.h"

struct Persona crearPersona(int id, const char* nombre) {
    struct Persona p;
    p.id = id;
    strncpy(p.nombre, nombre, sizeof(p.nombre) - 1);
    p.nombre[sizeof(p.nombre) - 1] = '\0';
    return p;
}

void imprimirPersona(struct Persona p) {
    printf("ID: %d\n", p.id);
    printf("Nombre: %s\n", p.nombre);
}
