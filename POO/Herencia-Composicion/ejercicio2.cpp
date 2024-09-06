//Ejercicio 2
//	Utilice las clases Alumno y Docente del ejercicio anterior para crear una clase Curso que modele el cursado de
//	una materia. Cada curso tiene un nombre, un profesor a cargo y un número máximo de alumnos. Implemente un
//	método AgregarAlumno(...) que permita agregar un alumno al curso (si es que no se llegó al cupo), y otro método
//	MejorPromedio(...) que devuelva el alumno con mejor promedio. Proponga los constructores y métodos extra que
//	considere necesarios

#include <iostream>
#include <string>
#include <vector>
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
	float verPromedio(){return m_prom;}
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

class Curso{
string m_nombre_curso;
Docente m_profe;
vector<Alumno>v;
int m_cantidad_max;
public: 
	Curso(string nombre_curso, Docente profe, int cantidad_max) : m_nombre_curso(nombre_curso), m_profe(profe), m_cantidad_max(cantidad_max){} 
	void AgregarAlumno(Alumno alumno);
	Alumno MejorPromedio();
};

void Curso::AgregarAlumno(Alumno alumno){
	v.push_back(alumno);
}

Alumno Curso::MejorPromedio(){
	int mayor = 0;
	int indice = -1;
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].verPromedio() > mayor){
			mayor = v[i].verPromedio();
			indice = i;
		}
	}
	return v[indice];
}

int main() {
	int fechaHoy = 20240906;
	Alumno alumno("Franco", "Caraffa", 20050915, 9, 10);	
	Docente docente("Pablo", "Novara", 20050815, 20190901);
	
	cout << docente.CalcularAntiguedad(fechaHoy)<<endl;
	cout << docente.verNombre()<<endl;
	cout << alumno.CalcularEdad(fechaHoy)<<endl;
	cout << alumno.verApellido()<<endl;
	
	Curso matematicas("Matematicas", docente, 10);
	matematicas.AgregarAlumno(alumno);
	
	cout << matematicas.MejorPromedio().verNombre()<< endl;

	
	
	
	
	return 0;
}

