//    Ej 3 (30 ptos ) Escribir una clase genérica llamada OperaLista que posea como atributo una lista dinámica
//    (list). a) La clase debe poseer métodos para construir la lista a partir de un vector que se pasa como
//    parametro u métodos para b) Agregar un elemento c) Obtener la cantidad de elementos d) Ordenar la lista en
//    forma decreciente y retornar cuantas veces se repite el mayor elemento. e) Eliminar un elemento de la lista
//    cuya posición se pasa como parámetro f) un método para mostrar por pantalla los elementos de la lista.
//    Defina un programa cliente con 2 instancias de OperaLista empleando enteros y strings. Los datos deben
//    leerse de los archivos de texto listaenteros.txt y listastring.txt respectivamente. El programa debe mostrar
//    ambas listas, y cuantas veces se repite el mayor de cada una.

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

template<typename T>
class OperaLista {
	list<T> lista;
public:
	OperaLista(vector<T> v) {
		for(auto &x : v) {
			lista.push_back(x);
		}
	}
	void AgregarElemento(T elemento) {
		lista.push_back(elemento);
	}
	int CantElementos() {
		return(lista.size());
	}
	int OrdenarLista() {
		
		lista.sort(); // Ordeno de menor a mayor
		reverse(lista.begin(),lista.end());
		
		auto it = max_element(lista.begin(),lista.end()); // Busco el mayor
		
		int cont = 0;
		for(auto &x : lista) {
			
			if(x == *it) cont++; // Si x es igual al mayor cont++
		}
		return cont;
	}
	bool EliminarElemento(int posicion) {
		if(posicion >= lista.size()) return false;
		
		auto it = lista.begin();
		lista.erase(it+posicion);
		return true;
		
	}
	void MostrarDatos() {
		for(auto &x : lista) {
			cout << x << " " << endl;
		}
	}
	
};
int main() {
	
	vector<int> vec;
	ifstream archi("listaenteros.txt");
	if(!archi) throw runtime_error("Error al abrir el archivo.");
	int linea;
	while(archi >> linea) {
		vec.push_back(linea);    
	}
	archi.close();
	
	OperaLista<int> b(vec);
	
	
	
	vector<string> vec2;
	ifstream archi2("listastring.txt");
	if(!archi2) throw runtime_error("Error al abrir el archivo.");
	string linea2;
	while(getline(archi2,linea2)) {
		vec2.push_back(linea2);    
	}
	archi2.close();
	
	OperaLista<string> a(vec2);
	
	a.MostrarDatos();
	cout << "Lista sin ordenar esta arriba " << endl;
	a.OrdenarLista();
	a.MostrarDatos();
	
	
	
	return 0;
}
