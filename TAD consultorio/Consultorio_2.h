#include <iostream>
#include "ColaDinamicaPerfe.h"
#include "ListaPerfe.h"

struct paciente{
    paciente(int id = 0):id_(id){}

    bool operator ==(const paciente& A)
    {
        return(A.id_ == id_);
    }

private:
    int id_;
};

struct medico{
    medico(int id = 0):id_(id){}

    void meter(const paciente& A)
    {
        pacientes.push(A);
    }

    void atender()
    {
        pacientes.pop();
    }

    bool vacia()
    {
        return pacientes.vacia();
    }

    paciente consulta()
    {
        return pacientes.frente();
    }

    bool operator ==(const medico& A)
    {
        return(A.id_ == id_);
    }

private:
    int id_;
    Cola<paciente> pacientes;
};

class consultorio{
    Lista<medico> consul;
public:

    consultorio() = default;
    void alta_medico(const medico& A);
    void baja_medico(const medico& A);
    void incluir_paciente(const medico& M,const paciente& A);
    paciente consultar(const medico& A);
    void atender(const medico& A);
    bool cola_vacia(const medico& A);

}

void consultorio::alta_medico(const medico& A)
{
    typename Lista<medico>::posicion pos = consul.buscar(A);
    assert( !(consul.fin() == pos));
    pos = consul.primera();
    consul.insertar(A,pos);
}

void consultorio::baja_medico(const medico& A)
{
    typename Lista<medico>::posicion pos = consul.buscar(A);
    if(!(pos == consul.fin()))
    {
        consul.eliminar(pos);
    }
}

void consultorio::incluir_paciente(const medico& M,const paciente& A)
{
    typename Lista<medico>::posicion pos = consul.buscar(M);
    assert(!(consul.fin() == pos));
    consul.elemento(pos).meter(A);
}

paciente consultorio::consultar(const medico& A)
{
    return consul.elemento(consul.buscar(A)).consulta();
}

void consultorio::atender(const medico& A)
{
    consul.elemento(consul.buscar(A)).atender()
}

bool cola_vacia(const medico& A)
{
    return consul.elemento(consul.buscar(A)).vacia();
}
