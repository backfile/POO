#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Parametro{
	string campo;
	string valor;
};

class ConfigFile{
	string n_nombre_archivo;
	vector<Parametro> v;
public:
	ConfigFile(string nombre_archivo) : n_nombre_archivo(nombre_archivo){
		
		Parametro aux;
		ifstream archi(nombre_archivo);
		if(!archi){
			throw runtime_error("No se a podido abrir el archivo");
		}
		
		string parametro_linea;
		while(getline(archi, parametro_linea)){
			if(parametro_linea[0] == '#'){
				continue;
			}
			int p = parametro_linea.find('=');
			aux.campo = parametro_linea.substr(0, p);
			aux.valor = parametro_linea.substr(p+1);
			v.push_back(aux);
		}
//		for(size_t i=0;i<v.size();i++) { 
//			cout << "Campo: " << v[i].campo << "Valor: " << v[i].valor <<endl; 
//		}
		
		archi.close();
	}
	string consultar_campo(string campo){
		for(size_t i=0;i<v.size();i++) { 
			if(v[i].campo == campo){
				return v[i].valor;
			} 
		}
		string error = "No se encontro";
		return error;
	}
	void modificar_campo(string campo, string nuevo_valor){
		for(size_t i=0;i<v.size();i++) { 
			if(v[i].campo == campo){
				v[i].valor = nuevo_valor;
			} 
		}
	}	
	void guardar_archivo(){
		ofstream archi2("nuevo.txt");
		if(!archi2){
			throw runtime_error("No se a podido abrir el archivo");
		}
		for(size_t i=0;i<v.size();i++) { 
			archi2 << v[i].campo << '=' << v[i].valor << endl;  
		}
	}
};

int main() {
	ConfigFile v("ConfigFile.txt");
	string valor = v.consultar_campo("materia");
	cout << valor << endl;
	v.modificar_campo("materia", "Casino, ganacias aseguradas");
	string valor2 = v.consultar_campo("materia");
	cout << valor2 << endl;
	v.guardar_archivo();
	return 0;
}

