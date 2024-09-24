//a) Diseñe una clase para representar un viaje que guarde y permita consultar la siguiente información: ciudades de origen y
//destino, medio de transporte (un string, por ej "avión”), y distancia (en kms).
// b) Implemente 3 clases que representen viajes en tres medios de transportes específicos: en avión, en auto y en colectivo.
//Cada una de estas clases debe permitir obtener el tiempo del viaje de la siguiente forma:
//en auto: t = distancia/110 + .5*(distancia%110) // se viaja a 110km/h, con un descanso de 30m cada 2h
//en avión: t = 2+distancia/900 // se viaja a 900km/h, pero hay que estar 2 horas antes en el aeropuerto
//en colectivo: t = distancia/90 // se viaja a 90km/h, sin esperas antes ni paradas
//c) Implemente una función que reciba un vector de viajes y retorne el tiempo total (la suma).
//d) Escriba un programa cliente que genere un vector con 3 viajes: de Rosario a Paraná en auto (200km), de Paraná a Buenos
//Aires en avión (400km), y de Buenos Aires a Rosario en colectivo (320km). El programa debe usar la función para obtener
//y luego mostrar el tiempo total.


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Viaje {
	string origen,destino,transporte;
	int distancia;
public:
	Viaje(string m_origen,string m_destino,string m_transporte,float m_distancia):origen(m_origen),destino(m_destino),transporte(m_transporte),distancia(m_distancia){};
	virtual float TiempoDeViaje() = 0;
	int VerDistancia() {return distancia;}
	virtual ~Viaje() {}
};
class Avion : public Viaje{
public:
	Avion(string m_origen,string m_destino,string m_transporte,float m_distancia): Viaje(m_origen,m_destino,m_transporte,m_distancia){};
	float TiempoDeViaje() override {
		float t = 2+this->VerDistancia()/900;
		return t;
	}
	
	
};
class Auto  : public Viaje{
public:
	Auto(string m_origen,string m_destino,string m_transporte,float m_distancia): Viaje(m_origen,m_destino,m_transporte,m_distancia){};
	float TiempoDeViaje() override {
		float t = (this->VerDistancia()/110) + 0.5*(this->VerDistancia() % 110);
		return t;
	}
	
};
class Colectivo : public Viaje {
public:
	Colectivo(string m_origen,string m_destino,string m_transporte,float m_distancia): Viaje(m_origen,m_destino,m_transporte,m_distancia){};
	float TiempoDeViaje() override {
		float t = this->VerDistancia()/90;
		return t;
	}
	
};

float Funcion(vector<Viaje*> viajes) {
	float tiempo = 0;
	for(size_t i=0;i<viajes.size();i++) { 
		tiempo += viajes[i]->TiempoDeViaje();
		cout << tiempo << "tiempo del viaje : " << i << endl;
	}
	return tiempo;
}

int main() {
	
	vector<Viaje*> v;
	v.push_back(new Auto("Rosario","Parana","Auto",200));
	v.push_back(new Avion("Parana","Buenos Aires","Avion",400));
	v.push_back(new Colectivo("Buenos Aires","Rosario","Colectivo", 320));
	
	cout << Funcion(v);
	
	
	return 0;
}
