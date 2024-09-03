//Se dispone del siguiente tipo de dato:
//	struct Alumno {
//		string nombre;
//		float nota;
//	};
//En base al mismo se desea crear una clase Curso para modelar el cursado de una materia. La clase deberá contener
//	el nombre de la materia y la cantidad de alumnos en el curso junto con una lista de los mismos. Proponga los
//	siguientes métodos:
//	1. Constructores y destructor según lo considere conveniente.
//	2. Un método que permita agregar un alumno recibiendo su nombre.
//	3. Un método que permita modificar la nota de un alumno (buscándolo por su nombre).
//	4. Métodos para poder consultar estos datos.
//	5. Un método que determine el promedio del curso.
//	6. Un método para obtener la calificación más alta y el nombre del alumno que la obtuvo.

#include <iostream>
#include <vector>
using namespace std;


struct Alumno{
	string nombre;
	float nota;
};

class Curso{
private:
	string materia_nombre;
	int cant_alum;
	vector<Alumno>v;
public:
	Curso(string nombre);
	void agregar_alumno(string nombre_alumno);
	void agregar_alumno(string nombre_alumno, float nota);
	void modificar_nota(string nombre_alumno, float nota);
	float consultar_nota(string nombre_alumno);
	float promedio();
	pair<string, float> obtener_nota_alta();
};

Curso::Curso(string nombre){
	materia:nombre = nombre;
}

void Curso::agregar_alumno(string nombre_alumno){
	Alumno alum;
	alum.nombre = nombre_alumno;
	v.push_back(alum);
	cant_alum ++;
}

void Curso::agregar_alumno(string nombre_alumno, float nota){
	Alumno alum;
	alum.nombre = nombre_alumno;
	alum.nota = nota;
	v.push_back(alum);
	cant_alum ++;
}

	
void Curso::modificar_nota(string nombre_alumno, float nota){
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].nombre == nombre_alumno){
			v[i].nota = nota;
		}
	}
}
float Curso::consultar_nota(string nombre_alumno){
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].nombre == nombre_alumno){
			return v[i].nota; 
		}
	}
	return -1;
}
float Curso::promedio(){
	int acum;
	for(size_t i=0;i<v.size();i++) { 
		acum += v[i].nota;
	}
	return (acum / cant_alum);
}
pair<string, float> Curso::obtener_nota_alta(){
	pair<string, float>p;
	int mayor = 0;
	string nombre;
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].nota > mayor){
			mayor = v[i].nota;
			nombre = v[i].nombre;
		}
	}
	p.first = nombre;
	p.second = mayor;
	return p;
}


int main() {
	
	// Codigo para utilizar la clase...
	
	return 0;
}

