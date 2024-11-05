//Ejercicio 3 [30 pts] Defina Carta (clase o struct) para representar a un naipe que tiene un número y un
//palo. Diseñe una clase llamada Mazo que permita manejar los datos de un grupo de cartas. La clase
//debe poseer métodos para: a) Guardar los datos de las cartas en un archivo binario. b) Cargar los datos
//de los cartas desde un archivo binario. c) Agregar una nueva carta . d) Eliminar una carta indicando su
//palo y número, e) retornar una carta dada su posición en el mazo. Tener en cuenta que no hay cartas
//repetidas en el mazo.

#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

class Carta{
	int m_numero;
	string m_palo;
public: 
	Carta(int numero, string palo) : m_numero(numero), m_palo(palo){}
	int VerNumero(){return m_numero;}
	string VerPalo(){return m_palo;}
};

class Mazo{
	string m_nombre_archivo;
	vector<Carta>v;
public:
	Mazo(string nombre_archivo) : m_nombre_archivo(nombre_archivo) {
		int asd;
		char asd2[256];
		ifstream arch(m_nombre_archivo, ios::ate);
		int cantidad_bytes = arch.tellg();
		int cantidad_cartas = cantidad_bytes / (sizeof(asd) + sizeof(asd2));
		
		arch.seekg(0);
		
		for(int i=0;i<cantidad_cartas;i++) { 
			
			int numero;
			arch.read(reinterpret_cast<char*>(asd2), sizeof(asd2));
			arch.read(reinterpret_cast<char*>(&numero), sizeof(numero));
			string palo = asd2;
			Carta a(numero, palo);
			v.push_back(a);
		}
	}

	void AgregarCarta(Carta a){
		for(size_t i=0;i<v.size();i++) { 
			if((a.VerNumero() == v[i].VerNumero()) and (a.VerPalo() == v[i].VerPalo())){
				return;
			}
		}
		
		v.push_back(a);
		ofstream arch(m_nombre_archivo, ios::binary|ios::app);
		if(!arch){
			throw runtime_error("No se abrio el archivo");
		}
		string palo = a.VerPalo();
		int numero = a.VerNumero();
		char aux[256];
		strcpy(aux, palo.c_str());
		arch.write(reinterpret_cast<char*>(aux), sizeof(aux));
		arch.write(reinterpret_cast<char*>(&numero), sizeof(numero));
	};
	void VerCartasBinarios(){
		vector<Carta>vec;
		int asd;
		char asd2[256];
		ifstream arch(m_nombre_archivo, ios::ate);
		int cantidad_bytes = arch.tellg();
		int cantidad_cartas = cantidad_bytes / (sizeof(asd) + sizeof(asd2));
		cout << "Cantidad de cartas: " << cantidad_cartas << endl;
	
		arch.seekg(0);
		
		for(int i=0;i<cantidad_cartas;i++) { 
		
			int numero;
			arch.read(reinterpret_cast<char*>(asd2), sizeof(asd2));
			arch.read(reinterpret_cast<char*>(&numero), sizeof(numero));
			string palo = asd2;
			Carta a(numero, palo);
			vec.push_back(a);
		}
		for(auto &x : vec){
			cout << "Palo: " << x.VerPalo() << "  Numero: " << x.VerNumero() << endl;
		}
		
	}
};

int main() {
	Mazo m("mazo.dat");
	Carta a(10, "Oro");
	Carta b(10, "Espada");
	Carta c(16, "Basto");
	m.AgregarCarta(a);
	m.AgregarCarta(b);
	m.AgregarCarta(c);
	m.VerCartasBinarios();
	
	
	return 0;
}

