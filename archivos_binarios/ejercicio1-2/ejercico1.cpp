//a) Escriba a través de un programa C++ un archivo binario llamado grupo.dat, formado por un conjunto de 200 pares
//de números generados aleatoriamente. Cada par de datos se conforma por un entero y un flotante.
//b) Escriba otro programa que lea el archivo generado por el primero para verificar si se escribieron correctamente.

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int num;
	float num2;
	ofstream arch("grupo.dat", ios::binary);
	if(!arch){
		throw runtime_error("No se a podido abrir el archivo");
	}
	for(int i=0;i<200;i++) { 		
		num = rand()%200;
		num2 = (rand()%200)/0.54;
		arch.write(reinterpret_cast<char*>(&num), sizeof(num));
		arch.write(reinterpret_cast<char*>(&num2), sizeof(num2));
	};
	arch.close();
	ifstream arch2("grupo.dat", ios::binary);
	if(!arch2){
		throw runtime_error("No se a podido abrir el archivo");
	}
	int n_num;
	float n_num2;
	for(int i=0;i<200;i++) { 
		arch2.read(reinterpret_cast<char*>(&n_num), sizeof(n_num));
		arch2.read(reinterpret_cast<char*>(&n_num2), sizeof(n_num2));
		cout << "PAR NUMERO: " << i << "  "<< n_num << "  " << n_num2 << endl;
	}
	return 0;
}

