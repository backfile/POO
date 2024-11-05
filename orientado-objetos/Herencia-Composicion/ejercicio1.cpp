//	a) Diseñe una clase Persona que contenga los siguientes atributos: apellido y nombre, y fecha de nacimiento. La
//	clase debe poseer, además, un método CalcularEdad(...) que permita obtener la edad actual de la persona en
//	base a la fecha de nacimiento y la fecha actual.
//	b) Implemente una clase Alumno para contener la siguiente información de un alumno: apellido y nombre, año de
//	nacimiento, promedio y cantidad de materias aprobadas. La clase debe poseer, además dos métodos adicionales:
//	AgregarMateria(...) para actualizar el promedio y la cantidad de materias cada vez que el alumno rinde una nueva
//	materia; y CalcularMeritoAcademico(...) que retorne el mérito académico del alumno, el cual se calcula como el
//	producto entre el promedio y la cantidad de materias aprobadas.
//	c) Cree, también, una clase Docente para modelar un docente a partir de la siguiente información: apellido y nombre,
//	año de nacimiento y fecha de ingreso. La clase debe poseer, además, un método CalcularAntiguedad(...) que
//	calcule la antigüedad del docente en base a su fecha de ingreso y la fecha actual.
//	Notas: Para b) y c) proponga una jerarquía de clases adecuada para evitar repetir atributos. Implemente todos los
//	constructores y los métodos adicionales que considere adecuados.
//	d) Codifique un programa cliente que cree instancias de Alumno y Docente y utilice sus métodos para verificar su
//	correcto funcionamiento.
//	e) Finalmente responda:
//	• Puede crearse un objeto de tipo persona? ¿Para qué podría servir?
//	• ¿Existe alguna clase abstracta en la jerarquía

#include <iostream>
#include <string>
using namespace std;

class Persona{
	string m_apellido, m_nombre;
	int m_fecha_nac;
public:
	int CalcularEdad(int fecha_hoy);
	string verNombre(){return m_nombre;}
	string verApellido(){return m_apellido;}
	Persona(string nombre, string apellido, int fecha_nac) : m_nombre(nombre), m_apellido(apellido), m_fecha_nac(fecha_nac){}
	
};


int Persona::CalcularEdad(int fecha_hoy){
	return(fecha_hoy - m_fecha_nac)/10000;
}

class Alumno : public Persona{
	float m_prom;
	int m_materias_aprobadas;
	
	
public:
	void AgregarMateria(int nota);
	Alumno(string nombre, string apellido, int fecha_nac, float prom, int materias_aprobadas) : Persona(nombre, apellido, fecha_nac), m_prom(prom), m_materias_aprobadas(materias_aprobadas){}  
};

void Alumno::AgregarMateria(int nota){
	m_materias_aprobadas ++;
	m_prom = (m_prom * (m_materias_aprobadas - 1)) / m_materias_aprobadas;
}


class Docente : public Persona{
	int m_fecha_ingreso;
public:
	int CalcularAntiguedad(int fecha_hoy);
	Docente(string nombre, string apellido, int fecha_nac, int fecha_ingreso) : Persona(nombre, apellido, fecha_nac), m_fecha_ingreso(fecha_ingreso){}  
};

int Docente::CalcularAntiguedad(int fecha_hoy){
	return (fecha_hoy-m_fecha_ingreso)/10000;
}

int main() {
	int fechaHoy = 20240906;
	Alumno alumno("Franco", "Caraffa", 20050915, 9, 10);	
	Docente docente("Pablo", "Novara", 20050815, 20190901);
	
	cout << docente.CalcularAntiguedad(fechaHoy)<<endl;
	cout << docente.verNombre()<<endl;
	cout << alumno.CalcularEdad(fechaHoy)<<endl;
	cout << alumno.verApellido()<<endl;
	
	
	
	return 0;
}

