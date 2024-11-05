//Un color en un programa se suele modelar mediante 3 valores numéricos (entre 0 y 1)
//que indican cuánto de luz roja(r), cuánto de luz verde(g) y cuánto de luz azul(b) hay que mezclar para
//formarlo. Escriba una clase Color para representar un color de esta forma, con:
//- un constructor que reciba los 3 valores, y métodos para consultarlos.
//- una sobrecarga para el operador + que permita sumar dos colores. Por ej, si el primero tiene los
//valores r=1, g=0.5, b=0, y el 2do r=0.2, g=0.2, b=0.2, el resultado tendrá r=1.2, g=0.7, b=0.2 (se suma
//rojo con rojo, verde con verde y azul con azul).
//- un método Normalizar que corrija los valores: si alguno es mayor a 1, que se le asigne 1. Por ej: r=1.2,
//g=0.7, b=0.2 pasaría a ser r=1, g=0.7, b=0.2.
//- una sobrecarga para mostrar un color por pantalla (debe mostrar los tres valores identificándolos con
//las letras r, g y b. Por ej: "r=1.2, g=0.7, b=0.2")
//b) En un videojuego, el personaje principal va cambiando de color a medida que adquiere poderes.
//Cada vez que obtiene un nuevo poder el color del poder se suma a su color actual. Implemente una
//clase Personaje con:
//- Un constructor que reciba el nombre del jugador y su color inicial, y métodos para consultarlos.
//- Un método TienePoder que reciba el nombre de un poder y retorne true si el personaje ya lo tiene (la
//clase deberá guardar internamente los nombres de los poderes que tiene el personaje).
//- Un método AgregarPoder que reciba el nombre (string) y el color de un poder. Si el personaje ya tenía
//ese poder, el método debe retornar false. Si no lo tenía debe debe actualizar el color normalizado del
//personaje (es decir, sumarlo al que tenía y normalizar el resultado) y retornar true.//	


#include <iostream>
#include <vector>
using namespace std;

class Color{
	float m_r, m_g, m_b;
public:
	Color(float r, float g, float b) : m_r(r), m_g(g), m_b(b) {}
	float VerR(){return m_r;}
	float VerG(){return m_g;}
	float VerB(){return m_b;}
	Color operator+(Color b){
		this->m_r = this->m_r + b.VerR();
		this->m_g = this->m_g + b.VerG();
		this->m_b = this->m_b + b.VerB();
		return *this;
	}
	void Normalizar(){
		if(m_r > 1){
			m_r = 1;
		}
		if(m_g > 1){
			m_g = 1;
		}
		if(m_b > 1){
			m_b = 1;
		}
	}
};

class Personaje{
	string m_nombre;
	Color m_color;
	vector<string>poderes;
public:
	Personaje(string nombre, Color color): m_nombre(nombre), m_color(color) {}
	string VerNombe(){return m_nombre;}
	Color VerColor(){return m_color;}
	bool TienePoder(string poder){
		for(size_t i=0;i<poderes.size();i++) { 
			if(poderes[i] == poder){
				return true;
			}
		}
		return false;
	}
	bool AgregarPoder(string poder, Color color){
		if(this->TienePoder(poder)){
			return false;
		}
		this->m_color + color;
		this->m_color.Normalizar();
		return true;
		
	}
};

ostream & operator<<(ostream &i, Color b){
	i << "r=" << b.VerR() << ", g=" << b.VerG()<< ", b=" << b.VerB(); 
	return i;
} 

int main() {
	Color a(1, 0.6, 0.2);
	cout << a <<endl; 
	a.Normalizar();
	cout << a <<endl;;
	Color b(1, 0.2, 0.4);
	a + b;
	cout << a <<endl;
	a.Normalizar();
	cout << a << endl;
	
	cout << "Personaje: " << endl;
	Color a2(1, 0.6, 0.2);
	Color b2(1, 0.2, 0.4);
	Personaje c("Franco", a2);
	cout << c.VerColor()<<endl;
	c.AgregarPoder("Furia", b2);
	cout << c.VerColor();
	return 0;
}

