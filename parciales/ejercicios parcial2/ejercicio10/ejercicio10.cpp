//    Ejercicio 1 (25 pts) Un archivo “discurso.txt” contiene la transcripción de un discurso
//    de un político importante. El político en cuestión tiene la mala costumbre de usar
//    palabrotas en su discurso. Sus asesores han decidido modificar la transcripción para
//    no molestar a los votantes más susceptibles. Para ello han generado un archivo
//    “palabrotas.txt”, con la lista de las que usa con más frecuencia. Escriba un programa
//    c++ que modifique el archivo del discurso reemplazando todas las palabrotas por
//    “***beep***”. No hay palabras cortadas en el texto y puede haber 2 o mas palabrotas
//    en una línea..

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	
	vector<string> malaspalabras;
	ifstream archi2("palabrotas.txt");
	if(!archi2) throw runtime_error("error al abrir el archivo.");
	string malapalabra;
	while(archi2 >> malapalabra) {
		malaspalabras.push_back(malapalabra);
	}
	archi2.close();
	
	vector<string> vec;
	ifstream archi("discurso.txt" );
	if(!archi) throw runtime_error("Error al abrir el archivo.");
	
	string linea;
	while(getline(archi,linea)) {
		vec.push_back(linea);
	}
	
	for(size_t i=0;i<vec.size();i++) { 
		linea = vec[i];
		for(size_t j=0;j<malaspalabras.size();j++) {
			while(linea.find(malaspalabras[j]) != string::npos) {
				int pos = linea.find(malaspalabras[j]);
				int len = malaspalabras[j].length();
				linea.replace(pos,len,"***beep***");
				vec[i] = linea;
			}
		}
	}
	archi.close();
	
	ofstream archi3("discurso.txt",ios::trunc );
	if(!archi3) throw runtime_error("Error al abrir el archivo.");
	
	for(size_t i=0;i<vec.size();i++) { 
		linea = vec[i];
		cout << linea << endl;
		archi3 << linea << endl;
	}
	
	
	
	
	return 0;
}
