#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

typedef struct{
    unsigned int zona, region, num;
} telefono;

typedef struct{
    char *nombre, *apellido, *correo;
    telefono tel;
} contacto;

int calcularLongitudString(char[]);
void confirmarSalida (int *);
void mostrarAgenda(contacto *, unsigned int);
void modificarDatos(contacto *, unsigned int, unsigned int, char*);
int ordenarAZ(const void *, const void *);
int ordenarZA(const void *, const void *);
#endif
