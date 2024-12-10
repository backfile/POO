//Ejercicio 1 (30 pts) Implemente una clase Examen para modelar el enunciado
//	completo de un examen, reutilizando la clase Ejercicio. La clase Examen debe
//	tener: a) Un constructor que reciba el nombre de la materia y la fecha del
//	examen, y métodos para consultar ambos datos. b) Un método para agregar un
//	Ejercicio al Examen. c) Uno o más métodos que dado un número de Ejercicio,
//	permitan consultar los datos del mismo. d) Un método CalcularCalificacion
//	que reciba un vector<int> con las notas de un alumno en cada ejercicio y
//	retorne su nota, calculada como porcentaje sobre la suma de los puntajes
//	máximos de todos los ejercicios (esta suma no siempre es 100).

#include <iostream>
#include <vector>
using namespace std;

class Ejercicio{
	int m_puntaje;
	string m_enunciado;
	bool m_solo_libres;
public:
	Ejercicio(int puntaje, string enunciado, bool solo_libres) : m_puntaje(puntaje), m_enunciado(enunciado), m_solo_libres(solo_libres){};
	string VerEnunciado(){return m_enunciado;}
	int VerPuntajeMaximo(){return m_puntaje;}
};

class Examen{
int m_fecha;
string m_materia;
vector<Ejercicio>ejercicios;
public:
	Examen(string materia, int fecha) : m_fecha(fecha), m_materia(materia) {};
	int VerFecha(){return m_fecha;}
	string VerMateria(){return m_materia;}
	void AgregarEjercicio(Ejercicio ejercicio){
		ejercicios.push_back(ejercicio);
	}
	int VerEjercicioPuntaje(int num){
		return ejercicios[num].VerPuntajeMaximo();
	}
	string VerEjercicioEnunciado(int num){
		return ejercicios[num].VerEnunciado();
	}
	int CalcularCalificacion(vector<int>notas){
		int cont = 0;
		int punt_max = 0;
		
		for(size_t i=0;i<ejercicios.size();i++) { 
			punt_max += ejercicios[i].VerPuntajeMaximo();
		}
		
		for(size_t i=0;i<notas.size();i++) { 
			cont += notas[i]; 
		}
		
		return (cont%punt_max * 100) / punt_max;
	}
};


int main() {
	Examen examen("Matemáticas", 20230923);
	
	Ejercicio ejercicio1(10, "Resuelve la ecuación 2x + 3 = 7", false);
	Ejercicio ejercicio2(15, "Demuestra el teorema de Pitágoras", true);
	Ejercicio ejercicio3(20, "Calcula la derivada de la función f(x) = 3x^2 + 2x", false);
	
	examen.AgregarEjercicio(ejercicio1);
	examen.AgregarEjercicio(ejercicio2);
	examen.AgregarEjercicio(ejercicio3);
	
	cout << "Materia: " << examen.VerMateria() << endl;
	cout << "Fecha: " << examen.VerFecha() << endl;
	
	for(int i = 0; i < 3; i++) {
		cout << "Ejercicio " << i + 1 << ": " << examen.VerEjercicioEnunciado(i)
			<< " (Puntaje: " << examen.VerEjercicioPuntaje(i) << ")" << endl;
	}
	
	vector<int> notas = {10, 15, 18};  // Ejemplo de calificaciones
	cout << "Calificación final: " << examen.CalcularCalificacion(notas) << "%" << endl;
	
	return 0;
}

