//En un juego el usuario controla una part�cula que debe moverse por la pantalla e ir
//absorbiendo otras part�culas m�s peque�as. Al tocar una part�cula m�s peque�a, la del jugador la
//absorbe y entonces crece en tama�o. Pero si intenta absorber una m�s grande, pierde una vida.
//a) Dise�e una clase Particula. Debe tener un constructor que reciba su radio, y un m�todo para obtener
//su �rea (pi x r al cuadrado). b) Implemente una sobrecarga del operador < para comparar dos part�culas seg�n su
//radio. c) Implemente una sobrecarga para el operador += que permita sumar dos part�culas (el
//resultado debe guardarse en la primera). La part�cula resultante debe tener un �rea igual a la suma de
//las dos originales (entonces, si a1 y a2 son las �reas originales, el radio de la nueva ser� v((a1+a2)/??) ).
//d) Implemente una clase Jugador que represente la part�cula del jugador. Esta, adem�s de su radio,
//debe tener una cantidad de vidas (que se reciba como argumento en su constructor).
//e) Implemente una funci�n libre (no ser� m�todo de ninguna clase) colision que reciba al jugador y otra
//part�cula contra la cual colisiona. Si la otra es menor a la del jugador, debe sumar ambas en la del
//jugador (es decir, crece la del jugador). Si la otra es mayor o igual, debe restarle una vida al jugador. La
//funci�n retornar� false cuando las vidas lleguen a 0; true en caso contrario.//		

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

