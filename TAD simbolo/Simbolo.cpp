#include <iostream>
#include "ListaPerfe.h"

using namespace std;

#define DERECHA 0
#define IZQUIERDA 1
#define ARRIBA 2
#define ABAJO 3



class Trazo;

class Simbolo
{
public:
	Simbolo(){}
	Simbolo(const Simbolo& s)
	{
		trazos_ = s.trazos_;
	}
	~Simbolo(){trazos_.~Lista();}
	void anhadirTrazo(int dir);
	void deshacerTrazos(int n);
	Simbolo simetriaX();
	Simbolo simetriaY();
	Simbolo simetriaXY();

	Lista<Trazo> trazos_;
};

class Trazo
{
public:
	Trazo(){}
	Trazo(int direccion):direccion_(direccion){}
	const int Direccion()const {return direccion_;}
	int &Direccion(){return direccion_;}
private: 
	int direccion_;
};



void Simbolo::anhadirTrazo(int dir)
	{
		Lista<Trazo>::posicion p = trazos_.fin();
		trazos_.insertar(dir, p);
	}

void Simbolo::deshacerTrazos(int n)
	{
		int i=0;
		while (i < n)
		{
			Lista<Trazo>::posicion p = trazos_.anterior(trazos_.fin());
			trazos_.eliminar(p);
			i++;

		}
	}

Simbolo Simbolo::simetriaX()
{
	Simbolo simetrico;
	Lista<Trazo>::posicion pos = trazos_.primera();
	Lista<Trazo>::posicion final = trazos_.fin();

	while (pos != final)
	{
		if (trazos_.elemento(pos).Direccion() == DERECHA)
		{
			simetrico.anhadirTrazo(DERECHA);
			pos = trazos_.siguiente(pos);
		}
		if (trazos_.elemento(pos).Direccion() == IZQUIERDA)
		{
			simetrico.anhadirTrazo(IZQUIERDA);
			pos = trazos_.siguiente(pos);
		}
		if (trazos_.elemento(pos).Direccion() == ARRIBA)
		{
			simetrico.anhadirTrazo(ABAJO);
			pos = trazos_.siguiente(pos);
		}
		if (trazos_.elemento(pos).Direccion() == ABAJO)
		{
			simetrico.anhadirTrazo(ARRIBA);
			pos = trazos_.siguiente(pos);
		}
	}
	return simetrico;
}

Simbolo Simbolo::simetriaY()
{
	Simbolo simetrico;
	Lista<Trazo>::posicion pos = trazos_.primera();
	Lista<Trazo>::posicion final = trazos_.fin();

	while (pos != final)
	{
		if (trazos_.elemento(pos).Direccion() == IZQUIERDA)
		{
			simetrico.anhadirTrazo(DERECHA);
			pos = trazos_.siguiente(pos);
		}
		if (trazos_.elemento(pos).Direccion() == DERECHA)
		{
			simetrico.anhadirTrazo(IZQUIERDA);
			pos = trazos_.siguiente(pos);
		}
		if (trazos_.elemento(pos).Direccion() == ARRIBA)
		{
			simetrico.anhadirTrazo(ARRIBA);
			pos = trazos_.siguiente(pos);
		}
		if (trazos_.elemento(pos).Direccion() == ABAJO)
		{
			simetrico.anhadirTrazo(ABAJO);
			pos = trazos_.siguiente(pos);
		}
	}
	return simetrico;
}
Simbolo Simbolo::simetriaXY()
{
	Simbolo simetrico;
	simetrico.trazos_ = trazos_;
	simetrico.trazos_ = (simetrico.simetriaY()).trazos_;
	simetrico.trazos_ = (simetrico.simetriaX()).trazos_;
	return simetrico;
}

int main()
{
	Simbolo jose;
	jose.anhadirTrazo(DERECHA);
	jose.anhadirTrazo(ARRIBA);
	jose.anhadirTrazo(IZQUIERDA);
	jose.anhadirTrazo(ABAJO);
	Simbolo sim = jose.simetriaX();
	Simbolo simY= jose.simetriaY();
	Simbolo simXY=jose.simetriaXY();
	Simbolo hola = jose;
	hola.deshacerTrazos(2);

	cout <<"BORRO   "<< hola.trazos_.elemento(hola.trazos_.anterior(hola.trazos_.fin())).Direccion()<<"   BORRO" << endl;

	Lista<Trazo>::posicion pos = sim.trazos_.primera();







	pos = jose.trazos_.primera();
	for (int i = 0; i < 4; ++i)
	{
		cout << jose.trazos_.elemento(pos).Direccion();
		
		pos = jose.trazos_.siguiente(pos);
	}
	cout << "  ORIGINAL" <<endl;
	


	pos = sim.trazos_.primera();
	for (int i = 0; i < 4; ++i)	
	{
		cout << sim.trazos_.elemento(pos).Direccion();
		
		pos = sim.trazos_.siguiente(pos);
	}
	cout << "  SIMETRIA X" <<endl;

	pos = simY.trazos_.primera();
	for (int i = 0; i < 4; ++i)
	{
		cout << simY.trazos_.elemento(pos).Direccion();
		
		pos = simY.trazos_.siguiente(pos);
	}
	cout << "  SIMETRIA Y" <<endl;

	pos = simXY.trazos_.primera();
	for (int i = 0; i < 4; ++i)
	{
		cout << simXY.trazos_.elemento(pos).Direccion();
		
		pos = simXY.trazos_.siguiente(pos);
	}
	cout << "  SIMETRIA XY" <<endl;




}