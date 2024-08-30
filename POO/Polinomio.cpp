#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//Diseñe una clase Polinomio que contenga:
//	1. un constructor que reciba el grado el polinomio e inicialice sus coeficientes en 0.
//	2. un método que permita cambiar un coeficiente.
//	3. un método evaluar que permita evaluar el polinomio para un valor dado de la variable x.
//	4. el/los métodos que considere necesarios para poder mostrar un polinomio desde un programa cliente.
//	5. una función que permita sumar dos polinomios retornando un tercer polinomio con el resultado (ej. p_res =
//	Sumar(p1, p2);). ¿Cómo variaría si en lugar de ser una función libre fuera un método de la clase?
//	Verifique el funcionamiento de la función Sumar(...) mediante un programa cliente

class Polinomio{
private:
	vector<float>v;
public:
	Polinomio(int grado);
	float Evaluar(int variable);
	void CambiarCoeficiente(int grado, float valor);
};

Polinomio::Polinomio(int grado){
	v.resize(grado+1, 0);
}

void Polinomio::CambiarCoeficiente(int grado, float valor){
	v[grado] = valor;
}

float Polinomio::Evaluar(int variable){
	float rta;
	for(int i=0;i<v.size();i++) {
		rta += pow(variable, i)*v[i];
	}
	return rta;
}
	
int main() {
	int grado;
	cout<<"Ingrese el grado del polinomio"<<endl;
	cin>>grado;
	Polinomio poli(grado);
	float coeficiente;
	for(int i=0;i<=grado;i++) {
		cout<<"Ingrese el valor del coeficiente x elevado a la "<<i<<endl;
		cin>>coeficiente;
		poli.CambiarCoeficiente(i, coeficiente);
	}
	int x;
	cout<<"Ingrese el valor de x para evaluar el Polinomio"<<endl;
	cin >> x;
	float rta = poli.Evaluar(x);
	cout<<"Valor total: "<<rta;
	return 0;
}

