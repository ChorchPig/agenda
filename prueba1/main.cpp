#include <iostream>
#include "prototipos.h"

int main(){
    int option=1, cantContactos=0, aux=0;
    std::cout<<"How many contacts are you going to save?\n";
    std::cin>>cantContactos;
    contacto *agenda=new contacto[cantContactos];
    for(int i=0; i<cantContactos; i++){
        std::cout<<"#"<<i+1<<" contact.\n";
        agenda[i].setContacto();
    }
    while(option){
        std::cout<<"Select an option";
        std::cout<<"\n\t1. Change data \n\t2. Sort agenda ";
        std::cout<<"\n\t3. Show agenda \n\t0. Exit program \n";
        std::cin>>option;
        switch(option){
            case 0: confirmarSalida(&option); break;
            case 1: {
                std::cout<<"What contact do you want to change the data of?\n";
                std::cin>>aux;
                agenda[aux].setContacto();
            } break;
            case 2: std::cout<<"Option 2 selected\n"; break;
            case 3: {
                for(int i=0; i<cantContactos; i++){
                    agenda[i].mostrarContacto();
                }
            } break;
            default : std::cout<<"No option selected\n";
        }
    }
    delete []agenda;
    return 0;
}
