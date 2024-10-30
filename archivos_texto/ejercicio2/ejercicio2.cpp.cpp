//a) Escriba una función que reciba el nombre de un alumno y dos notas, y modifique el archivo reemplazando las dos
//notas de ese alumno.
//b) Escriba una función que lea la lista del archivo y genere otro archivo de texto promedios.txt con una tabla
//donde cada línea posea el nombre, el promedio, y la condición final de cada uno de los alumnos. Ayuda: utilice
//manipuladores de flujo (setw, right, left, fixed, setprecision) para dar formato a la tabla del archivo que se
//genera en b.

//b) Escriba una función que lea la lista del archivo y genere otro archivo de texto promedios.txt con una tabla
//donde cada línea posea el nombre, el promedio, y la condición final de cada uno de los alumnos. Ayuda: utilice
//manipuladores de flujo (setw, right, left, fixed, setprecision) para dar formato a la tabla del archivo que se
//genera en b.	
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Alumno{
	string nombre;
	int nota1;
	int nota2;
}; 

void generar_promedio_archivo(vector<Alumno>v){
	ofstream archi_escribir2("promedio.txt");
	if(!archi_escribir2.is_open()){
		throw runtime_error("No se a podido abrir el archivo");
	}
	for(size_t i=0;i<v.size();i++) { 
		archi_escribir2 << v[i].nombre << " - Promedio: " << (v[i].nota1 + v[i].nota2) / 2 << endl;
	}
	archi_escribir2.close();
}

void cambiar_notas(string nombre_alumno, int nota1, int nota2, vector<Alumno>&v){
	Alumno aux;
	aux.nombre = nombre_alumno;
	aux.nota1 = nota1;
	aux.nota2 = nota2;
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].nombre == nombre_alumno){
			v[i] = aux;
		}
	}
	ofstream archi_escribir("lista.txt");
	if(!archi_escribir.is_open()){
		throw runtime_error("No se a podido abrir el archivo");
	}
	for(size_t i=0;i<v.size();i++) { 
		archi_escribir << v[i].nombre << endl;
		archi_escribir << v[i].nota1 << " " << v[i].nota2 << endl;
	}
	archi_escribir.close();
}

int main() {
	vector<Alumno>v;
	ifstream archi_lec("lista.txt");
	if(!archi_lec.is_open()){
		throw runtime_error("No se a podido abrir el archivo");
	}
	
	Alumno aux;
	while(getline(archi_lec, aux.nombre)){
		archi_lec >> aux.nota1 >> aux.nota2;
		archi_lec.ignore();
		v.push_back(aux);
	}
	archi_lec.close();
	cambiar_notas("Garcia Ana", 10, 1, v);
	generar_promedio_archivo(v);
	
	return 0;
}

