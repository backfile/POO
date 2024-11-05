//Escriba un programa abra el archivo generado en el ejercicio anterior y solicite al usuario que ingrese un entero, un
//flotante y una posición. El programa debe sobrescribir el par en la posición ingresada por el usuario por el nuevo par.
//Luego muestre la lista de datos en consola mostrando un par por línea.	

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream arch("grupo.dat", ios::binary|ios::in|ios::out);
	if(!arch){
		throw runtime_error("No se a podido abrir el archivo");
	}
	int entero;
	float flotante;
	int p;
	cout << "Ingrese el entero: "<<endl;
	cin >> entero;
	cout << "Ingrese el flotante: "<<endl;
	cin >> flotante;
	cout << "Ingrese la posicion: "<<endl;
	cin >> p;
	arch.seekp((sizeof(entero)+sizeof(flotante))*p);
	arch.write(reinterpret_cast<char*>(&entero), sizeof(entero));
	arch.write(reinterpret_cast<char*>(&flotante), sizeof(flotante));
	arch.seekg(0);
	
	
	for(int i=0;i<200;i++) { 
		int n_num;
		float n_num2;
		arch.read(reinterpret_cast<char*>(&n_num), sizeof(n_num));
		arch.read(reinterpret_cast<char*>(&n_num2), sizeof(n_num2));
		cout << "PAR NUMERO: " << i << "  "<< n_num << "  " << n_num2 << endl;
	}
	return 0;
}

