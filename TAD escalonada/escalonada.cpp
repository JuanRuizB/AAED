//No esta perfe

#include <iostream>
#include "ListaPerfe.h"

using namespace std;

class escalon;

class funcion
{
public:	
	funcion(double x, double y):x_(x), y_(y){}
	~funcion(){escalones.~Lista();}
	void anhadirSalto(double x, double y);
	void eliminarSalto(double x);
	double calcularValorPunto(double x);
	double minimoFuncion();
	double maximoFuncion();
	double translacion(double w, double z);
	void ver();
private:
	double x_,y_;
	Lista<escalon> escalones;
};


class escalon
{
public:	
	escalon(){}
	escalon(double x, double y):x_(x), y_(y){}
	double X()const {return x_;}
	double Y()const {return y_;}
	double& X() 	{return x_;}
	double& Y() 	{return y_;}	
private:
	double x_, y_;
};

bool operator ==(escalon e1, escalon e2)
{
	if((e1.X() == e2.X())) return 1;
	else return 0;
}

void funcion::anhadirSalto(double x, double y)
{
	escalon aux(x,y);
	if(escalones.primera() == escalones.fin())
	{
		escalones.insertar(aux, escalones.primera());
	}

	else
	{
		Lista<escalon>::posicion pos = escalones.buscar(aux);
		if(pos == escalones.fin())
		{
			escalones.insertar(aux, escalones.fin()); //No existia escalon con la misma X.
		}
		else 
		{
			escalones.eliminar(pos);
			escalones.insertar(aux, escalones.fin());
		}// El escalon coincide con otro 

	}//Ya había algún salto en la Lista
}

void funcion::eliminarSalto(double x)
{
	escalon aux(x,0);
	Lista<escalon>::posicion pos = escalones.buscar(aux);
		if(pos == escalones.fin())
		{
			cout << "No existe salto con x = " << x << endl;
		}
		else 
		{
			escalones.eliminar(pos);
		}
}

double funcion::calcularValorPunto(double x)
{
	double x2,x3;
	Lista<escalon>::posicion pos = escalones.primera();
	Lista<escalon>::posicion fin = escalones.fin();

	if (pos == fin) return y_;

	while (pos != fin)
	{	
		x2 = escalones.elemento(pos).X();
		x3 = escalones.elemento(escalones.siguiente(pos)).X();
		if(escalones.siguiente(pos) == fin) 
		{
			if( ((x2-x) <=0) and ((x_-x) > 0) )	return escalones.elemento(pos).Y();
			else return y_;
		}
		if( ((x2-x) <=0) and ((x3-x) > 0) ) return escalones.elemento(pos).Y();

		pos = escalones.siguiente(pos);
	}
}

double funcion::minimoFuncion()
{
	Lista<escalon>::posicion pos = escalones.primera();
	Lista<escalon>::posicion fin = escalones.fin();

	if (pos == fin) return y_;
	

	double minimo = escalones.elemento(pos).Y();
	pos = escalones.siguiente(pos);

	while (pos != fin)
	{
		if(escalones.elemento(pos).Y() < minimo) minimo = escalones.elemento(pos).Y();


		pos = escalones.siguiente(pos);
	}
	return minimo;
}

double funcion::maximoFuncion()
{
	Lista<escalon>::posicion pos = escalones.primera();
	Lista<escalon>::posicion fin = escalones.fin();

	if (pos == fin) return y_;
	
	double maximo = escalones.elemento(pos).Y();
	pos = escalones.siguiente(pos);

	while (pos != fin)
	{
		if(escalones.elemento(pos).Y() > maximo) maximo = escalones.elemento(pos).Y();


		pos = escalones.siguiente(pos);
	}
	return maximo;
}

double funcion::translacion(double w, double z)
{
	Lista<escalon>::posicion pos = escalones.primera();
	Lista<escalon>::posicion fin = escalones.fin();

	x_ = x_ + w;
	y_ = y_ + z;

	while (pos != fin)
	{
		escalones.elemento(pos).X() += w; 
		escalones.elemento(pos).Y() += z;

		pos = escalones.siguiente(pos);
	}
}

void funcion::ver()
{
	Lista<escalon>::posicion pos = escalones.primera();
		Lista<escalon>::posicion fin = escalones.fin();

		cout << "(" << x_ << " , " << y_ << ")" << endl;
		while (pos != fin)
		{
			cout << "(" << escalones.elemento(pos).X() << " , " << escalones.elemento(pos).Y() << ")" << endl;
			pos = escalones.siguiente(pos);
		}
}

int main()
{
	funcion f(2 , 0);	
	f.anhadirSalto(5,5);
	f.anhadirSalto(10,2);
	f.anhadirSalto(9,3);
	f.anhadirSalto(6,1);
	f.ver();
	double i;
	cin >> i;
	cout << endl << endl << "Maximo: " << f.maximoFuncion() << endl << "Minimo: " << f.minimoFuncion() << endl << "Valor en el punto " << i << ": " << f.calcularValorPunto(i);
}