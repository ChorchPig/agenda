#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

class contacto{
    private:
        std::string nombre, apellido, correo;
        int telefono;
    public:
        void setContacto();
        void mostrarContacto();
};

void confirmarSalida(int *);
#endif // PROTOTIPOS_H_INCLUDED
