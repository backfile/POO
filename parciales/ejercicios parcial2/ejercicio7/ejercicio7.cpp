 //Ejercicio 2 (30 ptos)
//Se dispone de un archivo de textos llamado “datos.txt” generado por un equipo que mide una vez al día la
//altura del río. Para simplificar, suponer que todos los meses tienen 30 días; entonces el archivo tendrá
//30*12=360 datos.
//a) Escriba un programa C++ que lea el archivo y organice todos los datos en un único contenedor STL.
//b) Obtenga el mayor valor de cada mes, y genere con estos 12 valores un nuevo vector donde cada posición
//contenga una terna de datos: nro de mes, valor máximo de ese mes, y cuántas veces se repitió ese valor
//máximo en el mes.
//c) Ordene el nuevo vector de mayor a menor (según el valor máximo de cada terna) y luego guarde estas 12
//ternas en un archivo binario “máximos.dat“


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;




struct Datos{
	int mes;
	int maximo;
	int rep;
};


bool operator<(Datos a, Datos b){return a.maximo < b.maximo;}

void guardar_binario(vector<Datos>v){
	ofstream arch("maximos.dat", ios::binary);
	if(!arch) throw runtime_error("Error al abrir el archivo");
	Datos aux;
	for(size_t i=0;i<v.size();i++) { 
		aux = v[i];
		arch.write(reinterpret_cast<char*>(&aux), sizeof(Datos));
	}
	
}

int main() {
	ifstream arch("datos.txt");
	int aux;
	vector<int>valores;
	vector<Datos>v;
	for(int i=0;i<360;i++) { 
		arch >> aux;
		valores.push_back(aux);
	}
	
	int cont = 0;
	int indice = 1;
	int mayor = 0;
	int rep = 0;
	cout << valores.size() << endl;
	for(size_t i=0;i<360;i++) {
		cont ++;
		
		
		if(valores[i] > mayor){
			rep = 1;
			mayor = valores[i];
		} else if(valores[i] == mayor){
			rep++;
		}
		
		if(cont == 30){
			Datos a = {indice, mayor, rep};
			v.push_back(a);
			indice++;
			mayor = 0;
			rep = 0;
			cont = 0;
		}
		
	}
	
	for(auto &x : v) cout << "Mes: " << x.mes << " Maximo: "<<x.maximo << " Repeticiones: " << x.rep<<endl;
	
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	
	
	cout << "Archivo modificado: " <<endl;
		
	for(auto &x : v) cout << "Mes: " << x.mes << " Maximo: "<<x.maximo << " Repeticiones: " << x.rep<<endl;
	
	guardar_binario(v);
	
	return 0;
}

