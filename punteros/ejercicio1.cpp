#include <iostream>
#include <cstdlib>
using namespace std;

//Utilizando notaci�n de punteros, generar un arreglo din�mico y lineal de N elementos num�ricos enteros, con valores
//aleatorios entre 1000 y 1500, y muestre en pantalla la direcci�n de memoria del mayor elemento. N es un dato
//ingresado por el usuario

int main() {
	
	int N;
	cin >> N;
	int *p = new int[N];
	for(size_t i=0;i<N;i++) { 
		*(p+i) = rand()% 501 + 1000;
	}
	
	
	int mayor = 0;
	int indice;
	for(size_t i=0;i<N;i++) {
		cout<<(p+i)<<"-----"<<*(p+i)<<endl;
		if(mayor < *(p+i)){
			mayor = *(p+i);
			indice = i;
		}
	}
	cout<< (p+indice)<<endl;
	cout<< mayor<<endl;
	delete[]p;
}
