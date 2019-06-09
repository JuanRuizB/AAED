#include <iostream>
#include "ListaPerfe.h"

using namespace std;

class mueble{
	double pos;
	double ancho;
public:

	mueble(double p = 0, double a = 0);

	double Verposicion() const;
	void modificarPos(double p);
	double anchura() const;
};

mueble::mueble(double p, double a):pos(p),ancho(a) {}

void mueble::modificarPos(double p)
{
	pos = p;
}



double mueble::Verposicion() const
{
	return pos;
}

double mueble::anchura() const
{
	return ancho;
}

class cocina{
	Lista<mueble> muebles;
	double tam;

public:

	cocina(double n):tam(n){}
	~cocina(){muebles.~Lista();}

	bool cabe(double p,double a);
	void insertar(double p,double a);
	mueble consultar(unsigned i);
	void eliminar(unsigned i);
	void mover(unsigned i);
};

bool cocina::cabe(double p,double a)
{
	if(tam < p + a) return false;

	Lista<mueble>::posicion ini = muebles.primera();
	Lista<mueble>::posicion fin = muebles.fin();

	if(ini == fin ) return true;
	bool s = true;
	while(ini != fin)
	{

		if(muebles.elemento(ini).Verposicion() > p && muebles.elemento(ini).Verposicion() < p+a)
		    s = false;

		if(muebles.elemento(ini).Verposicion() + muebles.elemento(ini).anchura() > p 
		 && muebles.elemento(ini).Verposicion() + muebles.elemento(ini).anchura() < p+a)
			s = false;

		ini = muebles.siguiente(ini);
	}
	return s;
}

void cocina::insertar(double p,double a)
{
	if(cabe(p,a))
	{
	Lista<mueble>::posicion ini = muebles.primera();
	Lista<mueble>::posicion po = muebles.siguiente(ini);
	Lista<mueble>::posicion fin = muebles.fin();

	if (po == fin){

		if((muebles.elemento(ini).Verposicion() + muebles.elemento(ini).anchura()) < p)
		{
			mueble x(p,a);
			muebles.insertar(x, po);
		}
		else
	 		muebles.insertar(mueble(p,a), ini);
	}

	while(ini != fin)
	{


		if(muebles.elemento(ini).Verposicion() + muebles.elemento(ini).anchura() < p 
		   && muebles.elemento(po).Verposicion() > a )
		{
			mueble y(p,a);
			muebles.insertar(y,po);
		}
		ini = po;
		po = muebles.siguiente(po);

	}		
	}else
	cout << "No cabe." << endl;
}

mueble cocina::consultar(unsigned i)
{
	Lista<mueble>::posicion ini = muebles.primera();
	Lista<mueble>::posicion fin = muebles.fin();

	for(unsigned j = 0;j != i; j++)
	{
		assert(ini != fin);
		ini = muebles.siguiente(ini);
	}
	return muebles.elemento(ini);
}

void cocina::eliminar(unsigned i)
{
	Lista<mueble>::posicion ini = muebles.primera();
	Lista<mueble>::posicion fin = muebles.fin();

	for(unsigned j = 0; j != i;j++)
	{
	assert(ini != fin);
	ini = muebles.siguiente(ini);
	}
	muebles.eliminar(ini);
}

void cocina::mover(unsigned i)
{
	if(i == 1) 
	{
		muebles.elemento(muebles.primera()).modificarPos(0.0);
	}else{
		Lista<mueble>::posicion ini = muebles.primera();
		Lista<mueble>::posicion fin = muebles.fin();
		for(unsigned j = 0; j != i;j++)
		{
			assert(ini != fin);
			ini = muebles.siguiente(ini);
		}
		Lista<mueble>::posicion p = muebles.anterior(ini);

		muebles.elemento(ini).modificarPos(muebles.elemento(p).Verposicion() + muebles.elemento(p).anchura());
	}	
}


int main(int argc, char const *argv[])
{
	cocina c(140);
	c.insertar(1,2);
	c.insertar(6,2);
	c.insertar(4,1);
	c.insertar(15,1);
	c.insertar(3.1,0.5);
	cout << c.consultar(2).Verposicion()<<" ";
	c.mover(2);
	cout << c.consultar(2).Verposicion();
}



