//Ej 1 (30pts) Tres archivos binarios "humedad.dat", "precipitaciones.dat" y "temperatura.dat" contienen los
//datos registrados por tres sensores diferentes. Cada archivo contiene muchas mediciones, y por cada una
//guarda dos datos: un int con la fecha en formato aaaammdd, y un float con el valor de la medición. Escriba un
//programa que: a) Genere un nuevo archivo binario "mediciones.dat" que contenga todas las mediciones
//mezcladas, pero ordenadas por fecha. Por cada una deberá guardar tres datos: el tipo (un char 'h', 'p', o 't'), la
//fecha y el valor. b) Genere un archivo de texto "resumen.txt" donde guarde el máximo, el mínimo y el
//promedio de cada sensor.


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
using namespace std;

struct Pares{
	int fecha;
	float valor;
};

struct Ternas{
	int fecha;
	float valor;
	char tipo;
};

bool operator<(Ternas a, Ternas b){return a.fecha < b.fecha;}


void generar_resumen(vector<Ternas>a, vector<Ternas>b, vector<Ternas>c){
	vector<float>aint;
	vector<float>bint;
	vector<float>cint;
	for(Ternas &x : a) aint.push_back(x.valor);
	for(Ternas &x : b) bint.push_back(x.valor);
	for(Ternas &x : c) cint.push_back(x.valor);
	
	auto it_a_max = max_element(aint.begin(), aint.end());
	auto it_b_max = max_element(bint.begin(), bint.end());
	auto it_c_max = max_element(cint.begin(), cint.end());
	
	auto it_a_min = min_element(aint.begin(), aint.end());
	auto it_b_min = min_element(bint.begin(), bint.end());
	auto it_c_min = min_element(cint.begin(), cint.end());
	
	float prom_a = accumulate(aint.begin(), aint.end(), 0.0)/aint.size();
	float prom_b = accumulate(bint.begin(), bint.end(), 0.0)/bint.size();
	float prom_c = accumulate(cint.begin(), cint.end(), 0.0)/cint.size();
	
	ofstream archi("resumen.txt");
	archi << a[0].tipo << "\n" <<"Maximo: " <<*it_a_max << " Minimo: " << *it_a_min << "\n" << "Promedio: " << prom_a <<endl;
	archi << b[0].tipo << "\n" <<"Maximo: " <<*it_b_max << " Minimo: " << *it_b_min << "\n" << "Promedio: " << prom_b <<endl;
	archi << c[0].tipo << "\n" <<"Maximo: " <<*it_c_max << " Minimo: " << *it_c_min << "\n" << "Promedio: " << prom_c <<endl;
}

vector<Ternas> MezclarVector(vector<Ternas>a, vector<Ternas>b, vector<Ternas>c){
	vector<Ternas>def;
	for(Ternas &x : a) def.push_back(x);
	for(Ternas &x : b) def.push_back(x);
	for(Ternas &x : c) def.push_back(x);
	return def;
}

vector<Ternas> ObtenerDatos(string nombre_archivo){
	ifstream arch(nombre_archivo, ios::binary|ios::ate);
	if(!arch) throw runtime_error("No se abrió");
	int bytes = arch.tellg();
	int cant_pares = bytes/sizeof(Pares);
	vector<Ternas>vT;
	arch.seekg(0);
	Pares aux;
	Ternas aux2;
	for(int i=0;i<cant_pares;i++) { 
		arch.read(reinterpret_cast<char*>(&aux), sizeof(Pares));
		aux2 = {aux.fecha, aux.valor,  nombre_archivo[0]};
		vT.push_back(aux2);
	}
	return vT;
}

void generar_mediciones(vector<Ternas>v){
	ofstream arch("mediciones.dat", ios::binary);
	sort(v.begin(), v.end());
	for(int i=0;i<v.size();i++) { 
		Ternas aux = v[i];
		arch.write(reinterpret_cast<char*>(&aux), sizeof(Ternas));
	}
	
} 
	

int main() {
	vector<Ternas>vh = ObtenerDatos("huemdad.dat");
	vector<Ternas>vp = ObtenerDatos("precipitaciones.dat");
	vector<Ternas>vt = ObtenerDatos("temperatura.dat");
	
	vector<Ternas>def = MezclarVector(vh, vp, vt);
	
	return 0;
}

