// Una fábrica de tanques los hace de forma de cilindro y de esfera. 
// En ambos envases debemos rotular el volumen en m3 y el peso en kg.
// Modele una clase base Tanque con un constructor que reciba el peso,
// 	un método para consultarlo, y un método virtual para calcular su volumen.
// 	Modele la clase hija Cilindro que se construirá a partir de los argumentos 
// 	adicionales radio y altura, cuya fórmula de volumen es: área de la base * altura,
// 	donde el área de la base se calcula como pi * radio^2; y otra clase hija Esfera 
// 	con el radio como argumento adicional, cuya fórmula de volumen es: 4/3 * pi *radio^3.
// 	En el programa principal debe usar un único puntero de tipo Tanque
// 	para crear primero un Cilindro y mostrar su volumen, y luego una Esfera y también mostrar su volumen.

#include <iostream>
using namespace std;

class Tanque{
	float m_peso;
public:
	virtual ~Tanque(){};
	Tanque(float peso) : m_peso(peso){}
	float ConsultarPeso(){return m_peso;}
	virtual float CalcularVolumen()=0;
};

class CilindroTanque : public Tanque{
	float m_radio;
	float m_altura;
public:
	CilindroTanque(float radio, float altura, float peso) : Tanque(peso), m_radio(radio), m_altura(altura){}
	float CalcularVolumen() override {
		return (3.14 * m_radio * m_radio *m_altura);
	}
	
};

class EsferaTanque : public Tanque{
	float m_radio;
public:
	EsferaTanque(float radio, float peso) : Tanque(peso), m_radio(radio){}
	float CalcularVolumen() override {
		return (3.14 * m_radio * m_radio * m_radio * (4.0/3));
	}
};


int main() {
	Tanque *t = new CilindroTanque(5, 2, 6);
	cout<<t->CalcularVolumen()<<endl;
	delete t;
	t = new EsferaTanque(5, 2);
	cout<<t->CalcularVolumen();
	delete t;
	return 0;
}

