//Ejercicio 3
//	Programe una clase templatizada llamada VectorDinamico (similar a la de la guía 2). La clase debe poseer:
//	1. Un constructor que reciba el tamaño inicial del vector, y reserve la memoria necesaria.
//	2. Un destructor que se encargue de liberar la memoria reservada.
//	3. Una sobrecarga del operador [] que reciba el número de elemento, devuelva su valor, y permita modificarlo.
//	4. Modifique o sobrecargue el constructor para que permita generar valores aleatorios con los cuales inicializar
//	las posiciones del arreglo que reserva.
//	5. Utilice la clase desde un programa cliente creando vectores aleatorios con diversos tipos de datos (int, double, string, etc)

#include <iostream>
using namespace std;

string GenerarPalabra(){
	string a = "Hola";
	return a;
}

template<typename T>
class VectorDinamico{
	T *p;
public:
	template<typename PF>
	VectorDinamico(int n, PF funcion){
		p = new T[n];
		for(int i=0;i<n;i++) { 
			p[i] = funcion();
		}
	}
	~VectorDinamico(){delete []p;}
	T& operator[](int indice) {return p[indice];}
};

int main() {
	VectorDinamico<int> v(10, rand);
	for(int i=0;i<10;i++) { 
		cout << v[i] << endl;
	}
	VectorDinamico<string> b(10, GenerarPalabra);
	for(int i=0;i<10;i++) { 
		cout << b[i] <<endl;
	}
	return 0;
}

