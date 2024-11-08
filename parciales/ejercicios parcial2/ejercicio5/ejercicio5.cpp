//Eje 3 (30pts) a) Escriba una función genérica llamada dosmay_up(...) que reciba una lista (std::list) como
//parámetro. La función debe encontrar los 2 mayores y moverlos a las dos primeras posiciones de la lista (el
// orden del resto de los elementos no debe modificarse). Por ejemplo, si recibe {2,5,7,6,8,0,1} debe quedar
//{8,7,2,5,6,0,1}. Además, la función debe retornar true si los dos mayores son iguales, o false si son diferentes.
//b) Escriba un programa cliente para probar la función con una lista de struct Ficha { string nombre; int edad; },
//y muestre los nombres de los dos mayores.	

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;


struct Ficha{
	string nombre;
	int edad;
};

bool operator<(Ficha a, Ficha b){return a.edad < b.edad;}
bool operator==(Ficha a, Ficha b){return a.edad == b.edad;}

template<typename T>
bool dosmay_up(list<T>l){
	auto it = max_element(l.begin(), l.end());
	int max = *it;
	l.erase(it);
	auto it2 = max_element(l.begin(), l.end());
	int max2 = *it2;
	l.erase(it2);
	l.push_front(max2);
	l.push_front(max);
	for(auto &x : l) cout << x<< " ";
	if(*it == *it2) return true;
	return false;
}

int main() {
	list<int>a = {2, 5, 10, 2, 8};
	dosmay_up(a);
	return 0;
}

