#include <iostream>
using namespace std;

//Escriba una funci�n que utilice punteros para buscar y retornar la direcci�n de un entero dentro de un arreglo. Se
//pasan como par�metros el arreglo, su tama�o y el entero a buscar. Si el dato no se encuentra, debe retornar
//la direcci�n de memoria nula (nullptr). �Desde un programa cliente, c�mo se obtiene el �ndice del elemento
//encontrado cuando la funci�n no devuelve nullptr?

struct arreglo{
	int *P;
	int N;
};


int* f(arreglo a, int x){
	for(size_t i=0;i<a.N;i++) { 
		if(*(a.P+i)== x){
			return (a.P+i);
		}
	}
	return nullptr;
}




int main() {
	arreglo a;
	cin >> a.N;
	int num;
	a.P = new int [a.N];
	for(size_t i=0;i<3;i++) { 
		cin >> *(a.P+i); 
	}
		
	int *nuevopuntero = f(a, 42);
	cout<<nuevopuntero;
			
	return 0;
}

