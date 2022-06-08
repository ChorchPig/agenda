#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
typedef struct{
    unsigned int zona, region, num;
} telefono;

typedef struct{
    char *nombre, *apellido, *correo;
    telefono tel;
} contacto;
#endif // ESTRUCTURAS_H_INCLUDED
