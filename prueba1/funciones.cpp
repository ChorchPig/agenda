#include <iostream>
#include "prototipos.h"

void confirmarSalida(int *option){
    std::cout<<"You are about to exit the program, press 0 to confirm: ";
    std::cin>>*option;
}
void contacto::setContacto(){
        std::cout<<"Name: ";
        std::cin>>nombre;
        std::cout<<"Last Name: ";
        std::cin>>apellido;
        std::cout<<"Email: ";
        std::cin>>correo;
        std::cout<<"Phone number: ";
        std::cin>>telefono;
}

void contacto::mostrarContacto(){
        std::cout<<"Name: "<<nombre<<"\n";
        std::cout<<"Last Name: "<<apellido<<"\n";
        std::cout<<"Email: "<<correo<<"\n";
        std::cout<<"Phone number: "<<telefono<<"\n";
}
