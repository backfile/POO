//En un juego el usuario controla una partícula que debe moverse por la pantalla e ir
//absorbiendo otras partículas más pequeñas. Al tocar una partícula más pequeña, la del jugador la
//absorbe y entonces crece en tamaño. Pero si intenta absorber una más grande, pierde una vida.
//a) Diseñe una clase Particula. Debe tener un constructor que reciba su radio, y un método para obtener
//su área (pi x r al cuadrado). b) Implemente una sobrecarga del operador < para comparar dos partículas según su
//radio. c) Implemente una sobrecarga para el operador += que permita sumar dos partículas (el
//resultado debe guardarse en la primera). La partícula resultante debe tener un área igual a la suma de
//las dos originales (entonces, si a1 y a2 son las áreas originales, el radio de la nueva será v((a1+a2)/??) ).
//d) Implemente una clase Jugador que represente la partícula del jugador. Esta, además de su radio,
//debe tener una cantidad de vidas (que se reciba como argumento en su constructor).
//e) Implemente una función libre (no será método de ninguna clase) colision que reciba al jugador y otra
//partícula contra la cual colisiona. Si la otra es menor a la del jugador, debe sumar ambas en la del
//jugador (es decir, crece la del jugador). Si la otra es mayor o igual, debe restarle una vida al jugador. La
//función retornará false cuando las vidas lleguen a 0; true en caso contrario.//		

#include <iostream>
#include <cmath>
using namespace std;

class Particula{
float m_radio;
public:
	Particula(float radio) :  m_radio(radio){}
	float ObtenerArea(){return (3.14*m_radio*m_radio);}
	float VerRadio(){return m_radio;}
	bool operator<(Particula b){
		return (this->m_radio < b.VerRadio());
	}
	Particula& operator+=(Particula b){
		this->m_radio = sqrt((this->ObtenerArea()+b.ObtenerArea())/3.14);
		return *this;
	}
};

class Jugador : public Particula{
int m_vidas;
public:
	Jugador(float radio, int vidas) : Particula(radio), m_vidas(vidas) {}
	void RestarVidas(){
		m_vidas--;
	}
	int VerVidas(){return m_vidas;}
	
};

bool Colision(Jugador &a, Particula b){
	if(b < a){
		a += b;
	}else{
		a.RestarVidas();
		if(a.VerVidas() == 0){
			return false;
		}
	}
	return true;
} 

int main() {
	Jugador a(5, 1);
	cout<<a.ObtenerArea()<<endl;
	Particula b(2);
	cout<<b.ObtenerArea()<<endl;
	Colision(a, b);
	cout << a.ObtenerArea()<<endl;
	
	Particula c(7);
	cout<<Colision(a, c);
	
	return 0;
}

