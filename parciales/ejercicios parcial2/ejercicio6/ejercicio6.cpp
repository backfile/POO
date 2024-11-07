//Ejercicio 1 (30 ptos)

//a) Diseñe una función genérica promedio(...) que reciba una lista (list) de datos de cualquier tipo y calcule el
//promedio de los elementos.
//b) Escriba un programa en C++ que sea un cliente de la función promedio(...). El programa debe invocar la
//función tres veces para las siguientes listas:
//i) Una lista de números flotantes ingresados por el usuario desde el teclado.
//ii) Una lista de números enteros generados aleatoriamente en el rango de 1 a 100.
//iii) Una lista de números complejos (struct Complejo { float p_real, p_imag; }) que deben leerse
//desde un archivo binario "complejos.dat". Nota: implemente todas las funciones auxiliares que considere
//necesarias para que el programa funcione.	
#include <list>
#include <iostream>


#include <fstream>
#include <stdexcept>
using namespace std;

struct Complejo{
	float p_real;
	float p_imag;
};

Complejo operator+(Complejo a, Complejo b){
	Complejo c;
	c.p_real = a.p_real + b.p_real;
	c.p_imag = a.p_imag + b.p_imag;
	return c;
} 

Complejo operator/(Complejo a, int b){
	Complejo c;
	c.p_imag = a.p_imag / b;
	c.p_real = a.p_real / b;
	return c;
}

void escribir_binario(list<Complejo>v){
	ofstream arch("complejos.dat", ios::binary);
	if(!arch) throw runtime_error("No se abrio el archivo");
	Complejo aux;
	for(auto &x : v){
		aux = x;
	/*	cout << aux.p_imag <<" aca" <<endl;*/
		arch.write(reinterpret_cast<char*>(&aux), sizeof(Complejo));
	}
	
	arch.close();
}

list<Complejo> leer_binario(){
	ifstream arch("complejos.dat", ios::binary|ios::ate);
	if(!arch) throw runtime_error("No se abrio el archivo");
	list<Complejo>v;
	Complejo aux;
	int lecturas = arch.tellg()/sizeof(aux);
	arch.seekg(0);
	for(int i=0;i<lecturas;i++) { 
		arch.read(reinterpret_cast<char*>(&aux), sizeof(aux));
		v.push_back(aux);
	}
	return v;
}
	
template<typename T>
T promedio(list<T>l){
	T cont = T();
	for(T x : l){
		cont = cont + x;
	}
	T prom = cont/l.size();
	return prom;  
}


int main() {
	list<float>vf;
	int n;
	cin >> n;
	float aux;
	for(int i=0;i<n;i++) { 
		cin >> aux;
		vf.push_back(aux);
	}
	
	list<int>vi;
	for(int i=0;i<100;i++) { 
		int aux2 = (rand()%100) + 1;
		vi.push_back(aux2);
	}
	
	float promvf = promedio(vf);
	int promvt = promedio(vi);
	
	list<Complejo>lista = {{10, 10}, {20, 20}, {100, 100}};
	escribir_binario(lista);
	list<Complejo>nuevaLista = leer_binario();

	Complejo a = promedio(nuevaLista);
	
	cout << "Float prom: " << promvf <<endl;
	cout << "Int prom: " << promvt << endl;
	cout << "Promedio real: " << a.p_real << " Promedio img: "<< a.p_imag<<endl;
	
	
	return 0;
}

