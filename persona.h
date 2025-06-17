#ifndef PERSONA_H
#define PERSONA_H

struct Persona {
    int id;
    char nombre[50];
};

struct Persona crearPersona(int id, const char* nombre);
void imprimirPersona(struct Persona p);

#endif
