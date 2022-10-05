#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "prototipos.h"

int main(){
    setlocale(LC_ALL, "spanish");
    unsigned int cantContactos=0;
    printf("�Cu�ntos contactos vas a guardar?\n");
    scanf("%u", &cantContactos);
    contacto *agenda=(contacto *)malloc(cantContactos*sizeof(contacto));
    verificarMemoria(agenda, 1);
    unsigned int longitudStr=0;
    unsigned int persona; //Para modificar informaci�n
    char *buffer=malloc(topeStr*sizeof(char));
    verificarMemoria(buffer, 2);

    for(int i=0; i<cantContactos; i++){//Ingreso de datos
        printf("Ingrese el nombre del %u� contacto (m�ximo de %u letras): ", i+1, topeStr);
        scanf(" %s", buffer);
        longitudStr=strlen(buffer)+1;
        agenda[i].nombre=(char *)malloc(longitudStr*sizeof(char));
        verificarMemoria(agenda[i].nombre, 3);
        memcpy(agenda[i].nombre, buffer, longitudStr);
        printf("\nIngrese el apellido del %u� contacto (m�ximo de %u letras): ", i+1, topeStr);
        scanf(" %s", buffer);
        longitudStr=strlen(buffer)+1;
        agenda[i].apellido=(char *)malloc(longitudStr*sizeof(char));
        verificarMemoria(agenda[i].apellido, 4);
        memcpy(agenda[i].apellido, buffer, longitudStr);
        printf("\nIngrese el correo del %u� contacto (m�ximo de %u letras): ", i+1, topeStr);
        scanf(" %s", buffer);
        longitudStr=strlen(buffer)+1;
        agenda[i].correo=(char *)malloc(longitudStr*sizeof(char));
        verificarMemoria(agenda[i].correo, 5);
        memcpy(agenda[i].correo, buffer, longitudStr);

        printf("\nN�mero de la zona del tel�fono: ");
        scanf("%u", &agenda[i].tel.zona);
        printf("\nN�mero de la regi�n del tel�fono: ");
        scanf("%u", &agenda[i].tel.region);
        printf("\nResto del n�mero del tel�fono: ");
        scanf("%u", &agenda[i].tel.num);
    }

    int option=1;
    while(option){ //Inicio de men�
        printf("\nSeleccione una opci�n: \n\t");
        printf("\n\t1. Modificar datos \n\t2. Ordenar agenda ");
        printf("\n\t3. Mostrar agenda \n\t0. Salir del programa \n");
        scanf("%i", &option);
        switch(option){
            case 0: confirmarSalida(&option); break;
            case 1: {
                printf("�Qu� contacto vas a cambiar?\n");
                scanf("%u", &persona);
                if(persona<0 || persona>cantContactos-1){
                    while(persona<0 || persona>cantContactos-1){
                        printf("Contacto inexistente, vuela a intentarlo.\n");
                        scanf("%u", &persona);
                    }
                }
                modificarDatos(&agenda[persona], longitudStr, topeStr, buffer);
                } break;
            case 2: qsort(agenda, cantContactos, sizeof(contacto), ordenar); break;
            case 3: mostrarAgenda(agenda, cantContactos); break;
            default : printf("No se seleccion� una opci�n existente");
        }
    }

    for(int i=0; i<cantContactos; i++){ //Liberaci�n de memoria de agenda
        free(agenda[i].nombre);
        free(agenda[i].apellido);
        free(agenda[i].correo);
    }
    free(agenda);
    free(buffer);
    return 0;
}
