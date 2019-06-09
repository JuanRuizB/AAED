#include <iostream>
#include "ListaPerfe.h"

using namespace std;


class simbolo{
	enum trazo {DERECHA,IZQUIERDA,SUBIR,BAJAR}
	Lista<trazo> sim_;

public:
	simbolo(){}
	void insertar(trazo& x);
	void eliminar(unsigned n);
	simbolo simetricoX();
	simbolo simetricoY();
	simbolo simetricoXY();
}


void simbolo::insertar(trazo& x)
{
	sim_.insertar(x,sim_.fin());
}

void simbolo::eliminar(unsigned n)
{
	Lista<trazo>::posicion p = sim_.fin();
	do{
		p = sim_.anterior(p);
		sim_.eliminar(p);
		--n;
	}while(n != 0);
}

simbolo simbolo::simetricoX()
{
	simbolo simetrico;
	Lista<trazo>::posicion p = sim_.primera();

	while(p != sim_.fin()){

		switch(sim_.elemento(p))
		{
			case DERECHA:
				simetrico.insertar(DERECHA);
			break;

			case IZQUIERDA:
				simetrico.insertar(IZQUIERDA);
			break;

			case SUBIR:
				simetrico.insertar(BAJAR);
			break;

			case BAJAR:
				simetrico.insertar(SUBIR);
			break;
		}
		p = sim_.siguiente(p);
	}
	return simetrico;
}

simbolo simbolo::simetricoY()
{
	simbolo simetrico;
	Lista<trazo>::posicion p = sim_.primera();

	while(p != sim_.fin()){

		switch(sim_.elemento(p))
		{
			case DERECHA:
				simetrico.insertar(IZQUIERDA);
			break;

			case IZQUIERDA:
				simetrico.insertar(DERECHA);
			break;

			case SUBIR:
				simetrico.insertar(SUBIR);
			break;

			case BAJAR:
				simetrico.insertar(BAJAR);
			break;
		}
		p = sim_.siguiente(p);
	}
	return simetrico;
}

simbolo simbolo::simetricoXY()
{
	simbolo simetrico;
	Lista<trazo>::posicion p = sim_.primera();

	while(p != sim_.fin()){

		switch(sim_.elemento(p))
		{
			case DERECHA:
				simetrico.insertar(IZQUIERDA);
			break;

			case IZQUIERDA:
				simetrico.insertar(DERECHA);
			break;

			case SUBIR:
				simetrico.insertar(BAJAR);
			break;

			case BAJAR:
				simetrico.insertar(SUBIR);
			break;
		}
		p = sim_.siguiente(p);
	}
	return simetrico;
}