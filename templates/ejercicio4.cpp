//Ejercicio 3 (30 pts) Implemente dos funciones templatizadas. a) Primero la función leer la cual recibe
//el nombre de un archivo de texto y almacena su contenido en un vector de la STL. Se puede asumir que
//el tipo de dato se puede leer con el operador >>. b) Otro método llamado guardar que recibe un vector
//de la STL de tipo genérico y almacena su contenido en un archivo de texto, ingresando en cada línea un
//registro diferente. Se puede asumir que el tipo de dato puede ser escrito usando el operador <<. d)
//Implemente una función main donde se cree un vector de flotantes de 100 elementos, generados
//aleatoriamente en el rango [0,1], y lo almacene con el método guardar, y luego lo vuelva a leer con el
//método leer y muestre su resultado en la consola.
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



template<typename T>
vector<T> Leer(string nombre_archi) {
	vector<T> vec;
	ifstream archi(nombre_archi);
	if(!archi) 
		throw runtime_error("Error al inicializar el archivo de texto del ejercicio.");
	
	T dato;
	while(archi >> dato) {
		vec.push_back(dato);
	}
	return vec;
}

template<typename D>
	bool Guardar(vector<D> vec) {
	ofstream archi ("registro.txt");
	if(!archi)
		throw runtime_error("Error al inicializar el archivo de texto del ejercicio.");
	
	for(D &x : vec) {
		archi << x << endl;
	}
	
	return true;
}
	
	
int main() {
	
	vector<float> vec;
	for(int i=0;i<100;i++) { 
		vec.push_back(rand()4/0.67);
		cout << vec[i] << " ";
	}
	cout << "\n\n\n";
	
	
	Guardar(vec);
	string archivo = "registro.txt";
	vector<float> vector2 = Leer<float>(archivo);
	
	for(auto &x : vector2) {
		cout << x << " ";
	}
	
	
	return 0;
}
