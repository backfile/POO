//    Ejercicio 2 (25 pts) Escriba una función genérica para buscar y reemplazar un dato dentro de
//    un archivo binario. La función debe recibir el nombre del archivo y dos datos (A y B) del tipo
//    genérico. Suponiendo que el archivo contiene elementos de dicho tipo, buscar todas las
//    ocurrencias de A, y reemplazarlas por B. No utilice arreglos, vectores ni otros contenedores
//    auxiliares (trabaje directamente sobre el archivo).

#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
void Buscar(string archivo,T a, T b) {
	fstream archi(archivo, ios::binary | ios::ate | ios::in | ios::out);
	if(!archi) throw runtime_error("Error al abrir el archivo.");
	
	int cantBytes = archi.tellg();
	int CantDatos = cantBytes/ sizeof(T);
	archi.seekg(0);archi.seekp(0);
	
	T dato;
	for(int i=0;i<CantDatos;i++) { 
		size_t pos = archi.tellg();
		archi.read(reinterpret_cast<char*>(&dato),sizeof(T));
		if(dato == a) {
			archi.seekp(pos);
			archi.write(reinterpret_cast<char*>(&b),sizeof(T));
		} 
	}
}

int main() {
	
	return 0;
}
