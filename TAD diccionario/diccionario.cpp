#include <stdio.h>
#include <string>
#include "ListaPerfe.h"
#include <cstring>
#include <iostream>


using namespace std;

class Traduccion
{
public:
	Traduccion(){}
	Traduccion(string palingles):inglesa(palingles){}
	void anhadir(string palesp);
	void eliminar(string palesp);
	void consultar();
	Lista<string>::posicion existeTrad(string palesp);
	string Inglesa()const{return inglesa;}
private:
	Lista<string>traduccion;
	string inglesa;

};


class diccionario
{
public:
	diccionario(){}
	void InsertarTradEsp(string esp, string eng);
	void EliminarTradEsp(string esp, string eng);
	void Consultar(string eng);
	~diccionario(){}

private:
	Lista<Traduccion> traducciones;
};

void diccionario::InsertarTradEsp(string esp, string eng)
{
	Lista<Traduccion>::posicion pos = traducciones.primera();
	Lista<Traduccion>::posicion fin = traducciones.fin();

	bool encontrada = false;

	while(pos != fin && !encontrada)
	{
		if (traducciones.elemento(pos).Inglesa() == eng) encontrada = true;
		else pos = traducciones.siguiente(pos);
	}//Si encontrada = true, pos contiene donde esta
		if(encontrada)traducciones.elemento(pos).anhadir(esp);
		else traducciones.elemento(fin).anhadir(esp); //

}

void diccionario::EliminarTradEsp(string esp, string eng)
{
	Lista<Traduccion>::posicion pos = traducciones.primera();
	Lista<Traduccion>::posicion fin = traducciones.fin();

	bool encontrada = false;

	while(pos != fin && !encontrada)
	{
		if (traducciones.elemento(pos).Inglesa() == eng) encontrada = true;
		else pos = traducciones.siguiente(pos);
	}//Si encontrada = true, pos contiene donde esta

	if(encontrada) traducciones.eliminar(pos);	
}

void diccionario::Consultar(string eng)
{
	Lista<Traduccion>::posicion pos = traducciones.primera();
	Lista<Traduccion>::posicion fin = traducciones.fin();

	bool encontrada = false;

	while(pos != fin && !encontrada)
	{
		if (traducciones.elemento(pos).Inglesa() == eng) encontrada = true;
		else pos = traducciones.siguiente(pos);
	}//Si encontrada = true, pos contiene donde esta

	if (encontrada) traducciones.elemento(pos).consultar();
	else cout << "La palabra " << eng << " no esta registrada." << endl;
}



void Traduccion::anhadir(string palesp)
{
	Lista<string>::posicion fin = traduccion.fin();
	Lista<string>::posicion pos = existeTrad(palesp);

	if(pos == fin)  traduccion.insertar(palesp, traduccion.fin());
		
}

void Traduccion::eliminar(string palesp)
{
	Lista<string>::posicion fin = traduccion.fin();
	if(existeTrad(palesp) != fin) traduccion.eliminar(existeTrad(palesp));
}

void Traduccion::consultar()
{
	cout << "La palabra " << inglesa << " tiene las siguiente traducciones:" << endl;
	Lista<string>::posicion pos = traduccion.primera();
	Lista<string>::posicion fin = traduccion.fin();

	while (pos != fin)
	{
		cout << traduccion.elemento(pos) << "." << endl;
	} 
}

Lista<string>::posicion Traduccion::existeTrad(string palesp)
{
	Lista<string>::posicion pos = traduccion.primera();
	Lista<string>::posicion fin = traduccion.fin();

	while (pos != fin )
	{
		if(traduccion.elemento(pos) == palesp) return pos;
		else pos = traduccion.siguiente(pos);
	}

	return pos;
}


int main()
{
	diccionario ola;
	ola.InsertarTradEsp("hola", "hello");
}