//Ejercicio 2
//	1. Implemente una funci�n clamp(...) que reciba como par�metros una variable (por referencia) y dos valores
//	indicando los l� mites superior e inferior para el valor de dicha variable. Si el valor de la variable supera su
//	m�ximo, este debe ajustarse al m�ximo valor permitido. De la misma forma si el valor es inferior al m�nimo.
//	2. Pruebe la funci�n templatizada desde un programa cliente. Explique el error que ocurre al invocar la funci�n
//	con float f=0.5; clamp(f, 0, 1); �C�mo lo solucionar�a?

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

