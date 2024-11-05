//Escriba una clase para gestionar la tabla de las N mejores puntuaciones de un juego. La clase debe permitir ingresar
//un nuevo puntaje (y encargarse de ubicarlo en la posición de la tabla que corresponda, o descartarlo), consultar los
//datos, y almacenar y recuperar los mismos mediante un archivo binario.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Tabla{
 string m_nombre_archivo;
public:
	Tabla(string nombre_archivo) : m_nombre_archivo(nombre_archivo){}  
	void agregarPuntaje(float puntaje_nuevo){
		fstream arch(m_nombre_archivo, ios::binary|ios::out|ios::in|ios::ate);
		float puntaje;
		int tamanio_bytes = arch.tellg() ;
		int cant_floats = tamanio_bytes/sizeof(puntaje);
		vector<float>puntajes;
		
		arch.seekg(0);
		for(int i=0;i<cant_floats;i++) { 
			arch.read(reinterpret_cast<char*>(&puntaje), sizeof(puntaje));
			puntajes.push_back(puntaje);
		}	
		puntajes.push_back(puntaje_nuevo);
		sort(puntajes.begin(), puntajes.end());
		reverse(puntajes.begin(), puntajes.end());
		
		
		for(size_t i=0;i<puntajes.size();i++) { 
			cout << puntajes[i] << endl;
		}
		
		arch.seekp(0);
		for(size_t i=0;i<puntajes.size();i++) { 
			float flotante = puntajes[i];
			arch.write(reinterpret_cast<char*>(&flotante), sizeof(flotante));
		}
		
	}
	int buscarPosicion(float n_puntaje){
		fstream arch(m_nombre_archivo, ios::binary|ios::out|ios::in|ios::ate);
		float puntaje;
		int tamanio_bytes = arch.tellg() ;
		int cant_floats = tamanio_bytes/sizeof(puntaje);
		vector<float>puntajes;
		
		arch.seekg(0);
		for(int i=0;i<cant_floats;i++) { 
			arch.read(reinterpret_cast<char*>(&puntaje), sizeof(puntaje));
			if(n_puntaje == puntaje){
				cout << "Posicion: " << i;
			}
		}
		return -1;
	}
};

int main() {
	Tabla asd("Tabla.dat");

	asd.agregarPuntaje(2);
	asd.buscarPosicion(6.0);
	
	
	
	return 0;
}

