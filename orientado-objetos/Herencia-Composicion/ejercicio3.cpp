//Implemente una clase Monomio para representar un monomio de la forma a*xn a partir de un coeficiente y un
//exponente, con un método Evaluar(...) que reciba un real y retorne el valor del monomio evaluado con ese real, y los
//demás métodos que considere necesarios. Implemente, luego, una clase Polinomio que reutilice la clase Monomio
//para modelar un polinomio, y añada un método Evaluar(...) para evaluar un polinomio en un valor x real dado. ¿Qué
//relación debe haber entre las clases Monomio y Polinomio

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Monomio{
float m_coeficiente;
int m_exponente;
public:
	Monomio(float coeficiente, int exponente) : m_coeficiente(coeficiente), m_exponente(exponente){}
	float Evaluar(int real);
};

float Monomio::Evaluar(int real){
	int rta = m_coeficiente * pow(real, m_exponente);
	
	return rta;
}

	
class Polinomio{
	vector<Monomio>v;
public:
	float Evaluar(int real){
		int sum = 0;
		for(size_t i=0;i<v.size();i++) { 
			sum += v[i].Evaluar(real);
		}
	return sum;
	}
	void AgregarMonomio(Monomio mono);
};

void Polinomio::AgregarMonomio(Monomio mono){
	v.push_back(mono);
}

int main() {
	Monomio mono1(4, 1);
	Monomio mono2(6, 1);
	Monomio mono3(5, 2);
	
	Polinomio poli1;
	poli1.AgregarMonomio(mono1);
	poli1.AgregarMonomio(mono2);
	poli1.AgregarMonomio(mono3);
	cout << poli1.Evaluar(2);
	return 0;
}

