//Ej 2 (30pts) a) Escriba un programa C++ que lea un archivo de texto "inscriptos.txt" con los nombres de los
//inscriptos a un sorteo (hay uno por l�nea). b) Solo se admite el formato "Apellido, Nombre", pero se sabe que
//hay datos mal cargados. Si una l�nea no tiene apellido y nombre separados por coma (por ej: "Juan Alberto
//Perez") deber� corregirse asumiendo que el apellido es la �ltima palabra (el ejemplo deber�a quedar "Perez,
//Juan Alberto"). c) Luego deber� eliminar los datos repetidos (dejando solamente uno de cada uno) ya que
//hubo personas que se anotaron varias veces. d) Finalmente actualice el archivo guardando los nuevos datos
//(solo los v�lidos, y sin repetidos) agregando adem�s un n�mero de l�nea/participante antes de cada uno.

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;


vector<string> Corregir(vector<string>v){
	vector<string>corregido;
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].find(",") == string::npos){
			size_t pos = v[i].rfind(" ");
			string apellido = v[i].substr(pos+1) ;
			string def = apellido + "," + " " + v[i].substr(0, pos);
			corregido.push_back(def);
			continue;
		}
		corregido.push_back(v[i]);
	}
	return corregido;
}
	
vector<string> EliminarRepetidos(vector<string>v){
	sort(v.begin(), v.end());
	auto it = unique(v.begin(), v.end());
	v.erase(it, v.end());
	return v;
}

vector<string> Leer(){
	ifstream arch("inscriptos.txt");
	if(!arch) throw runtime_error("Error al abrir el archivo");
	vector<string>v;
	string aux;
	while(getline(arch, aux)){
		v.push_back(aux);
	}
	return v;
}

void Escribir(vector<string>v)	{
	ofstream arch("inscriptos.txt");
	if(!arch) throw runtime_error("Error al abrir el archivo");
	for(size_t i=0;i<v.size();i++) { 
		arch << i << "- " << v[i] << endl; 
	}
}
	
int main() {
	vector<string>v = Leer();
	vector<string>b = Corregir(v);
	vector<string>c = EliminarRepetidos(b);
	Escribir(c);
	
	
	return 0;
}

