#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "prototipos.h"

int main(){
    setlocale(LC_ALL, "spanish");
    unsigned int cantContactos=0;
    printf("¿Cuántos contactos vas a guardar?\n");
    scanf("%u", &cantContactos);
    contacto *agenda=(contacto *)malloc(cantContactos*sizeof(contacto));
    verificarMemoria(agenda, 1);
    int option=1;
    unsigned int longitudStr=0, topeStr=0;
    unsigned int persona; //Para modificar información
    printf("Longitud máxima de un string: ");
    scanf("%u", &topeStr);
    char *buffer=malloc(topeStr*sizeof(char)); //Para medir la longitud de strings
    verificarMemoria(buffer, 2);

    for(int i=0; i<cantContactos; i++){//Ingreso de datos
        printf("Ingrese el nombre del %u° contacto (máximo de %u letras): ", i+1, topeStr);
        scanf(" %s", buffer);
        longitudStr=calcularLongitudString(buffer);
        agenda[i].nombre=(char *)malloc(longitudStr*sizeof(char));
        verificarMemoria(agenda[i].nombre, 3);
        memcpy(agenda[i].nombre, buffer, longitudStr);
        printf("\nIngrese el apellido del %u° contacto (máximo de %u letras): ", i+1, topeStr);
        scanf(" %s", buffer);
        longitudStr=calcularLongitudString(buffer);
        agenda[i].apellido=(char *)malloc(longitudStr*sizeof(char));
        verificarMemoria(agenda[i].apellido, 4);
        memcpy(agenda[i].apellido, buffer, longitudStr);
        printf("\nIngrese el correo del %u° contacto (máximo de %u letras): ", i+1, topeStr);
        scanf(" %s", buffer);
        longitudStr=calcularLongitudString(buffer);
        agenda[i].correo=(char *)malloc(longitudStr*sizeof(char));
        verificarMemoria(agenda[i].correo, 5);
        memcpy(agenda[i].correo, buffer, longitudStr);

        printf("\nNúmero de la zona del teléfono: ");
        scanf("%u", &agenda[i].tel.zona);
        printf("\nNúmero de la región del teléfono: ");
        scanf("%u", &agenda[i].tel.region);
        printf("\nResto del número del teléfono: ");
        scanf("%u", &agenda[i].tel.num);
    }

    while(option!=0){ //Inicio de menú
        printf("\nSeleccione una opción: \n");
        printf("1. Modificar datos 2. Ordenar agenda ");
        printf("3. Mostrar agenda 0. Salir del programa \n");
        scanf("%i", &option);
        switch(option){
            case 0: confirmarSalida(&option); break;
            case 1: {
                printf("¿Qué contacto vas a cambiar?\n");
                scanf("%u", &persona);
                if(persona<0 || persona>cantContactos-1){ //Verifica que agenda[persona] exista
                    while(persona<0 || persona>cantContactos-1){
                        printf("Contacto inexistente, vuela a intentarlo.\n");
                        scanf("%u", &persona);
                    }
                }
                modificarDatos(&agenda[persona], longitudStr, topeStr, buffer);
                } break;
            case 2: qsort(agenda, cantContactos, sizeof(contacto), ordenar); break;
            case 3: mostrarAgenda(agenda, cantContactos); break;
            default : printf("No se seleccionó una opción existente");
        }
    }

    for(int i=0; i<cantContactos; i++){ //Liberación de memoria de agenda
        free(agenda[i].nombre);
        free(agenda[i].apellido);
        free(agenda[i].correo);
    }
    free(agenda);
    free(buffer);
    return 0;
}
