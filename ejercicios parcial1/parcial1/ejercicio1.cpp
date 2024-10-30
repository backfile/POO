//
//Ej1(30pts) a) Diseñe una clase Pasajero para guardar los datos de un pasajero de un vuelo de avión.
//La clase debe guardar un string con apellido y nombre, tipo de pasaje (estándar o 1ra clase) y peso del
//equipaje a despachar. Estos datos deben inicializarse en el constructor de la clase.
//
//- b) Reutilizando la clase Pasajero, diseñe una clase Vuelo para representar los datos de un vuelo. La
//	clase debe tener un constructor que permita definir los aeropuertos de origen y destino, y la cantidad de
//	asientos disponibles de cada tipo. Debe tener además:
//- c) un método para agregar un pasajero al vuelo; este método deberá retornar true si el pasajero debe
//	pagar por exceso de equipaje (si su equipaje supera los 15ks para un pasaje estándar, o los 30ks para
//	1ra clase).
//- d) un método para consultar la cantidad de asientos disponibles de un cierto tipo (el tipo será el
//	argumento, estándar o 1ra clase, y se calcula restando al total los ocupados por pasajeros ya
//	cargados).
//- e) un método para obtener el peso total del equipaje (sumando el de todos los pasajeros).
//	Declare en ambas clases todos los métodos que considere adecuados o necesarios, pero implemente
//	solo los constructores y los métodos que se piden explícitamente en c, d y e (para los demás, solo
//  escriba el prototipo)

#include <iostream>
#include <vector>
using namespace std;

class Pasajero{	
	string m_nombre, m_apellido;
	int m_tipo; // 0 para estandar, 1 para clase
	int m_peso;
public:
	Pasajero(string nombre, string apellido, int tipo, int peso) : m_nombre(nombre), m_apellido(apellido), m_tipo(tipo), m_peso(peso) {}
	int VerTipo(){return m_tipo;}
	int VerPeso(){return m_peso;}
};

class Vuelo{
	string m_origen, m_destino;
	int m_asientos_estandar, m_asientos_clase;
	vector<Pasajero>v;
public:
	Vuelo(string origen, string destino, int asientos_estandar, int asientos_clase): m_origen(origen), m_destino(destino), m_asientos_estandar(asientos_estandar), m_asientos_clase(asientos_clase){}
	bool AgregarPasajero(Pasajero p){
		v.push_back(p);
		if(p.VerTipo() == 0){
			m_asientos_estandar--;
		}else{
			m_asientos_clase--;
		}
		if(p.VerTipo() == 0 and p.VerPeso() > 15) return true;
		if(p.VerTipo() == 1 and p.VerPeso() > 30) return true;
		return false;
	}
	int PesoTotal(){
		int acumulador = 0;
		for(size_t i=0;i<v.size();i++) { 
			acumulador += v[i].VerPeso();
		}
		return acumulador;
	}
};

int main() {
	
	return 0;
}

