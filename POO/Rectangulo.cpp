//Cree una clase Rectangulo que posea:
//	1. Un constructor que permita crear el objeto a partir de la base y altura del rectángulo.
//	2. Otro constructor que permita crear el objeto a partir de las coordenadas (x, y) de dos vértices opuestos.
//	3. Métodos VerArea(...) y VerPerimetro(...) que calculen respectivamente el área y perímetro del rectángulo.
//	4. Un método EsCuadrado(...) que permita conocer si el rectángulo es cuadrado.
//	5. Cree un programa cliente donde utilice varias instancias de la clase Rectangulo. Cree los objetos
//	dinámicamente y no olvide borrarlos al terminar de utilizarlos.	

#include <iostream>
#include <cstdlib>
using namespace std;

class Rectangulo{
private:
	int m_base, m_altura;
public:
	Rectangulo(int base, int altura);
	Rectangulo(int x1, int y1, int x2, int y2);
	int VerArea(){return m_base*m_altura;}
	int VerPerimetro(){return (m_base*2 + m_altura*2);}
	bool EsCuadrado();
};


bool Rectangulo::EsCuadrado(){
	return m_base == m_altura;
}

Rectangulo::Rectangulo(int base, int altura){
	m_base = base;
	m_altura = altura;
}


Rectangulo::Rectangulo(int x1, int y1, int x2, int y2){
	m_base = abs(y2 - y1);
	m_altura = abs(x2 - x1);
	
}

int main() {
	Rectangulo *rect1 = new Rectangulo(10, 10); // Utilizando el primer constructor
	Rectangulo *rect2 = new Rectangulo(0, 0, 2, 2);

	cout<<rect1->VerArea()<<"  "<<rect1->EsCuadrado()<<endl;
	cout<<rect2->VerArea()<<"  "<<rect2->EsCuadrado()<<endl;;
	
	
	return 0;
}

