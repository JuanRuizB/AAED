#include <iostream>
#include <string.h>

using namespace std;

class paciente{
	unsigned cod_;
	unsigned gravedad_;
public:

	paciente(unsigned cod = 0;unsigned gravedad = 0):cod_(cod),gravedad_(gravedad){}
	paciente(const paciente& a);
	unsigned gravedad() const;
	unsigned codigo() const;
};

	paciente::paciente(const paciente& a)
	{
		cod_ = a.codigo();
		gravedad_ = a.gravedad();
	}

	unsigned paciente::gravedad() const
	{
		return gravedad_;
	}

	unsigned paciente::codigo() const
	{
		return cod_;
	}



class Hospital{
	Lista<paciente> UCI;
	unsigned TAM_UCI;
	unsigned llena_UCI;
	Lista<paciente> Planta;
	unsigned TAM_Planta;
	unsigned llena_Planta;
	bool anomalia;

	void resolver_anomalia();

public:

	Hospital(unsigned tamUCI,unsigned tamPlanta):TAM_UCI(tamUCI)
	,TAM_Planta(tamPlanta),anomalia(false),llena_UCI(0),llena_Planta(0){}
	~Hospital() = default;

	void ingreso(unsigned cod, unsigned gravedad);
	void alta(unsigned cod);
	void muerte(unsigned cod);
	const Lista<paciente>& pacientesUCI() const;
	const Lista<paciente>& pacientesPlanta() const;
	const Lista<paciente>& pacientesgravedad() const;

};

void Hospital::resolver_anomalia()
{
	Lista<paciente>::posicion i,s;
	unsigned cont = 0;
	for(i = Planta.primera();i != Planta.fin(); i = Planta.siguiente(i))
	{
		if(5 >= Planta.elemento(i).gravedad())
		{
			s = i;
			cont++;
		}
	}
	UCI.insertar(Planta.elemento(s),UCI.fin());
	if(cont == 1) anomalia = false; 
}

void Hospital::ingreso(unsigned cod, unsigned gravedad)
{
	assert(gravedad >= 1 && gravedad <= 9);

	paciente in(cod,gravedad);
	
	if(gravedad <= 5)
	{
		if(TAM_UCI == llena_UCI)
		{
			unsigned max = 1;
			
			Lista<paciente>::posicion i,s;
			for(i = UCI.primera(); i != UCI.fin();i = UCI.siguiente(i))
			{
				if(max < UCI.elemento(i).gravedad()){
					s = i;
					max = UCI.elemento(i).gravedad();
				}
			}

			paciente aux(UCI.elemento(s));
			
			if(TAM_Planta == llena_Planta)
			{
			unsigned min = 6;
			
			Lista<paciente>::posicion k,s2;
			for(k = Planta.primera(); k != Planta.fin();k = Planta.siguiente(i))
			{
				if(min < Planta.elemento(k).gravedad()){
					s = k;
					min = Planta.elemento(k).gravedad();
				}
			}
			Planta.eliminar(s2);
			Planta.insertar(in,s2);
			}else{
			Planta.insertar(aux,Planta.fin());
			UCI.eliminar(s);
			UCI.insertar(in,UCI.fin());
			anomalia = true;
			}
		}else{
			UCI.insertar(in,UCI.fin());
			llena_UCI++;
		}
	}else{
		if(TAM_Planta == llena_Planta)
		{
			unsigned max2 = 6;
			
			Lista<paciente>::posicion j,s3;
			for(j = Planta.primera(); j != Planta.fin();j = Planta.siguiente(i))
			{
				if(max2 < Planta.elemento(j).gravedad()){
					s3 = j;
					max2 = Planta.elemento(j).gravedad();
				}
			}

			paciente aux(Planta.elemento(s3));
			Planta.eliminar(s3);
			Planta.insertar(in,s3);
		}else{
			Planta.insertar(in,Planta.fin());
			llena_Planta++;
		}
	}
}

void Hospital::alta(unsigned cod)
{
	bool e = false;
	Lista<paciente>::posicion i,s;
	for(j = Planta.primera();j != Planta.fin();j = Planta.siguiente(j))
	{
		if(cod == Planta.elemento(j).codigo()){
			Planta.eliminar(j);
			e = true;
		}
	}		
	if(e != true)
	{
		for(i = UCI.primera();i != UCI.fin();i = UCI.siguiente(i))
		{
			if(cod == UCI.elemento(i).codigo()){
				UCI.eliminar(i);
				e = true;
			}
		}
		if(e == true && anomalia == true) resolver_anomalia();
	}
	assert(e == true); 
}

void Hospital::muerte(unsigned cod)
{
	bool e = false;
	Lista<paciente>::posicion i,s;
	for(i = UCI.primera();i != UCI.fin();i = UCI.siguiente(i))
	{
		if(cod == UCI.elemento(i).codigo()){
			UCI.eliminar(i);
			e = true;
		}
	}
	if(e == true)
	{
		if(anomalia == true) resolver_anomalia();
	} else{
		
		for(j = Planta.primera();j != Planta.fin();j = Planta.siguiente(j))
		{
			if(cod == Planta.elemento(j).codigo()){
				Planta.eliminar(j);
				e = true;
			}
		}
	}
	assert(e == true); 
}
