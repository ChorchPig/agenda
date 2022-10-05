#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

typedef struct{
    unsigned int zona, region, num;
} telefono;

typedef struct{
    char *nombre, *apellido, *correo;
    telefono tel;
} contacto;

enum{
    topeStr=20
};
void confirmarSalida (int *);
void verificarMemoria (void *, int);
void mostrarAgenda(contacto *, unsigned int);
void modificarDatos(contacto *, unsigned int, unsigned int, char*);
int ordenar(const void *, const void *);
#endif
