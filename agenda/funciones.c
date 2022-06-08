#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

void limpiarBuffer(char buffer[], int longitud){
    for(int i=0; i<longitud; i++){
        buffer[i]=' ';
    }
}

int calcularLongitudString(char buffer[]){
    int i=0, longitud=1;
    while(buffer[i]!='\0'){
        longitud++;
        i++;
    }
    return longitud;
}

void confirmarSalida (int *option){
    printf("Est�s por salir del programa, para confirmar esta acci�n presione 0.\n");
    scanf("%u", option);
}

void mostrarAgenda(contacto *agenda, unsigned int cantContactos){
    for(int i=0; i<cantContactos; i++){
        printf("Nombre y Apellido: '%s %s'.\n", agenda[i].nombre, agenda[i].apellido);
        printf("Correo: '%s'.\n", agenda[i].correo);
        printf("N�mero del tel�fono: +%u %u %u\n", agenda[i].tel.zona, agenda[i].tel.region, agenda[i].tel.num);
    }
}

void modificarDatos(contacto *agenda, unsigned int longitud, unsigned int tope, char *buffer){
    int option=0;
    printf("�Qu� dato vas a modificar? \n 1. Nombre y apellido 2. Correo, 3. Tel�fono");
    scanf("%i", &option);
    switch(option){
        case 1 : {
            printf("Ingrese el nuevo nombre del contacto (m�ximo de %u letras): ", tope);
            scanf(" %s", buffer);
            longitud=calcularLongitudString(buffer);
            free(agenda->nombre);
            agenda->nombre=(char *)malloc(longitud*sizeof(char));
            memcpy(agenda->nombre, buffer, longitud);
            limpiarBuffer(buffer, tope);
            printf("Ingrese el nuevo apellido del contacto (m�ximo de %u letras): ", tope);
            scanf(" %s", buffer);
            longitud=calcularLongitudString(buffer);
            free(agenda->apellido);
            agenda->apellido=(char *)malloc(longitud*sizeof(char));
            memcpy(agenda->apellido, buffer, longitud);
            limpiarBuffer(buffer, tope);
        }break;
        case 2 : {
            printf("Ingrese el nuevo correo del contacto (m�ximo de %u letras): ", tope);
            scanf(" %s", buffer);
            longitud=calcularLongitudString(buffer);
            free(agenda->correo);
            agenda->correo=(char *)malloc(longitud*sizeof(char));
            memcpy(agenda->correo, buffer, longitud);
            limpiarBuffer(buffer, tope);
        }break;
        case 3 : {
            printf("\nN�mero de la zona del tel�fono: ");
            scanf("%u", &agenda->tel.zona);
            printf("\nN�mero de la regi�n del tel�fono: ");
            scanf("%u", &agenda->tel.region);
            printf("\nResto del n�mero del tel�fono: ");
            scanf("%u", &agenda->tel.num);
        } break;
        default : printf("No se seleccion� una opci�n existente");
    }
}
