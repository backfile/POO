//Ejercicio 1
//	1. Implemente una función templatizada llamada mayor(...) que reciba dos valores y devuelva el mayor.
//	Compruebe el correcto funcionamiento de la rutina utilizándola desde un programa cliente con valores de tipo
//	int, float y string
//	2. Programe unasobrecarga de la función mayor(...) que reciba un std::vector y retorne la posición del mayor
//	elemento del mismo. Pruebe la función sobrecargada desde un programa cliente con diversos tipos de datos.
//	3. Responda: ¿Servirán las funciones anteriores con datos del tipo mostrado en el recuadro? Justifique su
//	respuesta. Si responde que no, implemente los cambios necesarios.
//	struct Persona {
//	string nombre;
//	string apellido;
//	int dni;
//};



#include <iostream>
#include <vector>
using namespace std;

struct Persona{
	string nombre;
	string apellido;
	int dni;
};

template <typename T>
T mayor(T a, T b){
	if(a > b) {
		return a;
	}else{
		return b;
	}
}

bool operator>(Persona a, Persona b){
	if (a.dni < b.dni){
		return true; 
	}else{
		return false;
	}
}

	
template <typename T>
T mayor(vector<T>v){
	T mayor = v[0];
	for(size_t i=1;i<v.size();i++) { 
		if(v[i] > mayor){
			mayor = v[i];
		}
	}	
	return mayor;
}

int main() {
	int a = 20;
	int b = 10;
	int c = mayor(a, b);
	cout << c << endl; 
	string str1 = "asd";
	string str2 = "bcd";
	string strmayor = mayor(str1, str2);
	cout << strmayor << endl;
	vector<Persona>v;
	Persona persona1;
	persona1.nombre = "Franco";
	persona1.apellido = "Caraffa";
	persona1.dni = 46;
	Persona persona2;
	persona2.nombre = "Konrado";
	persona2.apellido = "Napoleon";
	persona2.dni = 47;
	v.push_back(persona1);
	v.push_back(persona2);
	Persona mayor1 = mayor(v);
	cout<<mayor1.nombre<<" "<<mayor1.apellido<<endl;
	
	return 0;
}

