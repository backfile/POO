#include <iostream>
using namespace std;

//Diseñe una clase Cilindro que modele un cilindro con el objetivo de calcular el volumen del cuerpo conociendo el
//radio de su base y la altura del mismo.
//1. La interfaz pública de la clase debe estar compuesta por los métodos AsignarDatos(...) y ObtenerVolumen(...)
//para asignar los datos del problema y obtener el volumen del cuerpo.
//2. Escriba unprogramacliente que utilice dicha clase. Defina 2 instancias de Cilindro llamadas c1 y c2. El objeto
//c1 debe utilizar datos ingresados por el usuario, mientras que para c2 utilice 5.3cm y 10.2cm para el radio y la
//altura respectivamente.
//3. Agregue un constructor a la clase Cilindro que reciba 2 parámetros para inicializar el radio y la altura. Luego
//intente compilar nuevamente el programa. ¿Puede explicar por qué se produce un error? Proponga una
//solución.

class Cilindro{
private: 
	float radio;
	float altura;
	
public:
	Cilindro();
	Cilindro(float r, float altura);
	void AsignarDatos(int r, int a);
	float ObtenerVolumen();
};

void Cilindro::AsignarDatos(int r, int a){
	radio = r,
	altura = a;
}

float Cilindro::ObtenerVolumen(){
   return (3.14 * radio * radio * altura);
}

Cilindro::Cilindro(float r, float a){
	radio = r;
	altura = a;
}

Cilindro::Cilindro(){
	
}

int main() {
	Cilindro cl;
	float radio, altura;
	cout<<"Ingrese el radio del Cilindro"<<endl;
	cin>>radio;
	cout<<"Ingrese la altura del Cilindro"<<endl;
	cin>>altura;
	cl.AsignarDatos(radio, altura);
	float rta = cl.ObtenerVolumen();
	cout<<"El volumen es: "<<rta<<endl;
	
	Cilindro nuevoCilindro(20,40);
	rta = nuevoCilindro.ObtenerVolumen();
	cout<<"El volumen es: "<<rta<<endl;
	return 0;
}

