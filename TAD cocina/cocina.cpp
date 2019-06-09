#include <iostream>
#include "listaPerfe.h"
using namespace std;

class mueble;

class cocina 
{
public:
	cocina(double n):longitud(n), longitudLista(0){}
	~cocina(){muebles.~Lista();}
	bool Cabe(double pos, double anc);
	void anhadir(double pos, double anc);
	mueble VerMuebleIesimo(int i);
	void EliminarMuebleIesimo(int i);
	void MoverIesimo(int i);
private:
	double longitud;
	Lista<mueble> muebles;
	int longitudLista;

};


class mueble
{
public:
	mueble(){}
	mueble(double pos, double anc):posicion(pos),ancho(anc){}
	double VerAncho()const {return ancho;}
	double VerPosicion()const {return posicion;}
	void ModPos(double pos){posicion = pos;}
private:
	double posicion,ancho;
};


bool operator == (mueble m1, mueble m2)
{
	if((m1.VerAncho() == m2.VerAncho()) && (m1.VerPosicion() == m2.VerPosicion())) return 1;
	else return 0;

}

bool cocina::Cabe(double pos, double anc)
{
	int ocupa = pos+anc;
	if(ocupa > longitud) return 0;

	bool bien = false;

	Lista<mueble>::posicion posi = muebles.primera();
	Lista<mueble>::posicion fin = muebles.fin();

	if(posi == fin) return 1;

	while(posi != fin)
	{
		int pos2, anc2;
		pos2 = muebles.elemento(posi).VerPosicion();
		anc2 = muebles.elemento(posi).VerAncho();
		int ocupa2 = pos2+anc2;
		if(ocupa2  < pos) bien = true;  //Cabe por la derecha
		if(ocupa <  pos2) bien = true;  //Cabe por la izquierda

		posi = muebles.siguiente(posi);
	}
	return bien;
}

void cocina::anhadir(double pos, double anc)
{
	if(Cabe(pos, anc))
	{
		muebles.insertar(mueble(pos, anc),muebles.fin());
		longitudLista++;
	}  
	else cout << "Mira macho vete a la mierda" << endl;
}

mueble cocina::VerMuebleIesimo(int i)
{
	i--;
	if(i > longitudLista) return mueble(-1,-1);
	double posiciones[longitudLista],anchos[longitudLista];
	Lista<mueble>::posicion pos = muebles.primera();
	Lista<mueble>::posicion fin = muebles.fin();
	
	int j = 0;

	while (pos != fin)
	{
		posiciones[j] =  muebles.elemento(pos).VerPosicion();
		anchos[j] = muebles.elemento(pos).VerAncho();
		j++;
		pos = muebles.siguiente(pos);
	}
	int k = 0, l = 0;
	while (k < j)
	{
	double aux;
	int m = k, ind;
	double minimo = longitud + 1;
	while (m < j)
	{	
		if(posiciones[m] < minimo) 
			{
			minimo = posiciones[m];
			ind = m;
			}
			m++;
	}
	aux = posiciones[k];
	posiciones[k] = posiciones[ind];
	posiciones[ind] = aux;

	aux = anchos[k];
	anchos[k] = anchos[ind];
	anchos[ind] = aux;

	k++;
	}

	pos = muebles.buscar(mueble(posiciones[i], anchos[i]));
	return muebles.elemento(pos);

}

void cocina::EliminarMuebleIesimo(int i)
{
	if ((VerMuebleIesimo(i).VerAncho()) == -1.0) cout << "NO EXISTE MAQUINA";
	else
	{
		Lista<mueble>::posicion pos = muebles.buscar(VerMuebleIesimo(i));
		muebles.eliminar(pos);
	} //ELSE
}

void cocina::MoverIesimo(int i)
{
	if ((VerMuebleIesimo(i).VerPosicion()) == -1) cout << "NO EXISTE MAQUINA";	
	else
	{
	if (i == 1)
		{
			muebles.elemento(muebles.buscar(VerMuebleIesimo(i))).ModPos(0);
		}	
	else
	{
		double nuevoPos = VerMuebleIesimo(i-1).VerPosicion() + 0.0001f;
		muebles.elemento(muebles.buscar(VerMuebleIesimo(i))).ModPos(nuevoPos);
	}



	} //ELSE

}


int main(int argc, char const *argv[])
{
	cocina c(140);
	c.anhadir(1,2);
	c.anhadir(6,2);
	c.anhadir(4,1);
	c.anhadir(15,1);
	c.anhadir(3.1,0.5);
	cout << c.VerMuebleIesimo(2).VerPosicion()<<" ";
	c.MoverIesimo(2);
	cout << c.VerMuebleIesimo(2).VerPosicion();
}

