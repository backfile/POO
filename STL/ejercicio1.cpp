//    Ejercicio 2 [25 pts] Escriba una función genérica para cualquier tipo de elemento llamada
//    lista_a_vector(...) que reciba un std::list y retorne un std::vector que contenga los elementos de la lista
//    de entrada, sin repetidos. Escriba un programa cliente que genere una lista con 30 enteros aleatorios,
//    utilice la función para pasarlos a un vector, y muestre el vector en pantalla.

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

template<typename T>
vector<T> lista_a_vector(list<T> lista) {
	
	vector<T> retorno;
	auto it = lista.begin();
	while(it != lista.end()) {
		if(find(retorno.begin(),retorno.end(),*it) == retorno.end()) {
			retorno.push_back(*it);
		}
		it++;
	}
	
	for(auto &x : retorno) {
		cout << x << " ";
	}
	
	return retorno;
}


int main() {
	
	list<int> lista;
	for(int i=0;i<20;i++) { 
		lista.push_back(rand()%20);
	}
	for(auto &x : lista) {
		cout << x << " ";
	}
	cout << "\n";
	
	lista_a_vector(lista);
	
	
	return 0;
}
