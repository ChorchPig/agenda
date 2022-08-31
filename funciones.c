#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int calcularLongitudString(char buffer[]){
    int i=0, longitud=1;
    while(buffer[i]!='\0'){
        longitud++;
        i++;
    }
    return longitud;
}

void confirmarSalida (int *option){
    printf("Estás por salir del programa, para confirmar esta acción presione 0.\n");
    scanf("%u", option);
}

void verificarMemoria (void *ptr, int llamado){
    if(!ptr){
        perror("No se pudo reservar memoria. ");
        printf("Error en el llamado %i. ", llamado);
        exit(1);
    }
}

void mostrarAgenda(contacto *agenda, unsigned int cantContactos){
    for(int i=0; i<cantContactos; i++){
        printf("Nombre y Apellido: '%s %s'.\n", agenda[i].nombre, agenda[i].apellido);
        printf("Correo: '%s'.\n", agenda[i].correo);
        printf("Número del teléfono: +%u %u %u\n", agenda[i].tel.zona, agenda[i].tel.region, agenda[i].tel.num);
    }
}

void modificarDatos(contacto *agenda, unsigned int longitud, unsigned int tope, char *buffer){
    int option=0;
    printf("¿Qué dato vas a modificar? \n 1. Nombre y apellido 2. Correo, 3. Teléfono");
    scanf("%i", &option);
    switch(option){
        case 1 : {
            printf("Ingrese el nuevo nombre del contacto (máximo de %u letras): ", tope);
            scanf(" %s", buffer);
            longitud=calcularLongitudString(buffer);
            free(agenda->nombre);
            agenda->nombre=(char *)malloc(longitud*sizeof(char));
            verificarMemoria(agenda->nombre, 6);
            memcpy(agenda->nombre, buffer, longitud);
            printf("Ingrese el nuevo apellido del contacto (máximo de %u letras): ", tope);
            scanf(" %s", buffer);
            longitud=calcularLongitudString(buffer);
            free(agenda->apellido);
            agenda->apellido=(char *)malloc(longitud*sizeof(char));
            verificarMemoria(agenda->apellido, 7);
            memcpy(agenda->apellido, buffer, longitud);
        }break;
        case 2 : {
            printf("Ingrese el nuevo correo del contacto (máximo de %u letras): ", tope);
            scanf(" %s", buffer);
            longitud=calcularLongitudString(buffer);
            free(agenda->correo);
            agenda->correo=(char *)malloc(longitud*sizeof(char));
            verificarMemoria(agenda->correo, 8);
            memcpy(agenda->correo, buffer, longitud);
        }break;
        case 3 : {
            printf("\nNúmero de la zona del teléfono: ");
            scanf("%u", &agenda->tel.zona);
            printf("\nNúmero de la región del teléfono: ");
            scanf("%u", &agenda->tel.region);
            printf("\nResto del número del teléfono: ");
            scanf("%u", &agenda->tel.num);
        } break;
        default : printf("No se seleccionó una opción existente");
    }
}

int ordenar(const void *str1, const void *str2){
    int comparacion, option=0;
    contacto *p1=(contacto *)str1;
    contacto *p2=(contacto *)str2;
    char *nombre1=(char *)p1->nombre;
    char *nombre2=(char *)p2->nombre;
    printf("Elija orden: \n1.A-Z 2. Z-A\n");
    scanf("%i", &option);
    switch(option){
        case 1 : comparacion=strcmp(nombre1, nombre2); break;
        case 2 : comparacion=strcmp(nombre2, nombre1); break;
        default : printf("Imposible comparar");
    }
    return comparacion;
}
