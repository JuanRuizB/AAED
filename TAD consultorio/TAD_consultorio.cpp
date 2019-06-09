#include <iostream>
#include "ListaPerfe.h"
#include "ColaDinamicaPerfe.h"

using namespace std;

class consultorio {

	typedef int paciente;

	struct Medico {
		Medico(int i,Cola<consultorio::paciente> x);
		Cola<consultorio::paciente> Pac_;
		int ID_;
		bool operator ==(consultorio::Medico a, consultorio::Medico b);
	};

	Lista< consultorio::Medico> m_;

public:

	consultorio();
	void dar_alta(int x);
	void dar_baja(Cola<paciente>& x);
	void insertar_paciente(paciente x);
	paciente& consultar(int id);
	void atender(int id);
	void pacientes_espera(int id);

};

consultorio::Medico::Medico(int i,Cola<consultorio::paciente> x)
{
	ID_ = i;
	Pac_ = x;
}

bool consultorio::Medico::operator ==(consultorio::Medico& a, consultorio::Medico& b)
 {
	if(a.ID_ == b.ID_) return true;
	else return false;
}

consultorio::consultorio()
{
	Lista<consultorio::Medico> m_;
}

void consultorio::dar_alta(int x)
{
	if(m_.primera() != m_.fin())
	{
	Cola<consultorio::paciente> v;
	consultorio::Medico m(x,v);
	if(!m_.buscar(m))
	{
	Lista<consultorio::Medico>::posicion p = m_.primera();
	m_.insertar(m,p);
	}
}
}