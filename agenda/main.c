#include <stdio.h>
#include <locale.h>
#include "funciones.c"
#include "estructuras.h"

int main(){
    setlocale(LC_ALL, "spanish");
    unsigned int cantContactos=0;
    printf("�Cu�ntos contactos vas a guardar?\n");
    scanf("%u", &cantContactos);
    contacto *agenda=(contacto *)malloc(cantContactos*sizeof(contacto));
    int option=1;//Variable control del while
    unsigned int longitud=0, tope=0; //Variable para reservar la memoria necesaria
    unsigned int persona; //Variable para modificar informaci�n
    printf("Longitud m�xima de un string: ");
    scanf("%u", &tope);
    char *buffer=malloc(tope*sizeof(char)); //Variable para medir la longitud de strings
    for(int i=0; i<cantContactos; i++){//Ingreso de datos
        printf("Ingrese el nombre del %u� contacto (m�ximo de %u letras): ", i+1, tope);
        scanf(" %s", buffer);
        longitud=calcularLongitudString(buffer);
        agenda[i].nombre=(char *)malloc(longitud*sizeof(char));
        memcpy(agenda[i].nombre, buffer, longitud);
        limpiarBuffer(buffer, tope);
        printf("\nIngrese el apellido del %u� contacto (m�ximo de %u letras): ", i+1, tope);
        scanf(" %s", buffer);
        longitud=calcularLongitudString(buffer);
        agenda[i].apellido=(char *)malloc(longitud*sizeof(char));
        memcpy(agenda[i].apellido, buffer, longitud);
        limpiarBuffer(buffer, tope);
        printf("\nIngrese el correo del %u� contacto (m�ximo de %u letras): ", i+1, tope);
        scanf(" %s", buffer);
        longitud=calcularLongitudString(buffer);
        agenda[i].correo=(char *)malloc(longitud*sizeof(char));
        memcpy(agenda[i].correo, buffer, longitud);
        limpiarBuffer(buffer, tope);

        printf("\nN�mero de la zona del tel�fono: ");
        scanf("%u", &agenda[i].tel.zona);
        printf("\nN�mero de la regi�n del tel�fono: ");
        scanf("%u", &agenda[i].tel.region);
        printf("\nResto del n�mero del tel�fono: ");
        scanf("%u", &agenda[i].tel.num);
    }

    while(option!=0){ //Inicio de men�
        printf("\nSeleccione una opci�n: \n");
        printf("1. Modificar datos 2. Orden alfab�tico (a-z) 3. Orden alfab�tico (z-a)");
        printf("4. Llamar a contacto 5. Mostrar agenda 0. Salir del programa \n");
        scanf("%i", &option);
        switch(option){
            case 0: confirmarSalida(&option); break;
            case 1: {
                printf("�Qu� contacto vas a cambiar?\n");
                scanf("%u", &persona); //No verifica que la posici�n persona exista
                modificarDatos(&agenda[persona], longitud, tope, buffer);
                } break;
            case 2: printf("Ud. se encuentra en la funci�n 'Orden alfab�tico (a-z)'.\n"); break;
            case 3: printf("Ud. se encuentra en la funci�n 'Orden alfab�tico (z-a)'.\n"); break;
            case 4: printf("Ud. se encuentra en la funci�n 'Llamar a contacto'.\n"); break;
            case 5: mostrarAgenda(agenda, cantContactos); break;
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
