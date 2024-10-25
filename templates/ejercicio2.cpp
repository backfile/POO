//Ejercicio 2
//	1. Implemente una función clamp(...) que reciba como parámetros una variable (por referencia) y dos valores
//	indicando los lí mites superior e inferior para el valor de dicha variable. Si el valor de la variable supera su
//	máximo, este debe ajustarse al máximo valor permitido. De la misma forma si el valor es inferior al mínimo.
//	2. Pruebe la función templatizada desde un programa cliente. Explique el error que ocurre al invocar la función
//	con float f=0.5; clamp(f, 0, 1); ¿Cómo lo solucionaría?

#include <iostream>
using namespace std;

template <typename T>
void clamb(T &a, T b, T c){
	if(a > b) a = b;
	if(a<c) a = c;
}

int main() {
	int valor = 10;
	clamb (valor, 2, 5);
	cout << valor << endl;
	string a = "aa";
	string b = "b";
	string z = "z";
	clamb(a, z, b);
	cout << a;
	return 0;
}

