#include <iostream>
using namespace std;

//Se tiene un arreglo dinámico de n enteros, y se quiere aumentar su tamaño a un nuevo tamaño c. Implemente una
//función redimensionar() que reserve dinámicamente memoria para un nuevo arreglo que contenga lugar suficiente
//para guardar c datos (los n datos anteriores y los c-n nuevos). Copie en la nueva memoria los datos del vector viejo
//e inicialice con ceros los nuevos elementos. La memoria del primer arreglo debe ser liberada y el struct actualizado
//para que el programa cliente pueda seguir operando con el nuevo arreglo. La función debería poder invocarse de la
//siguiente manera:


struct arreglo{
	int *P;
	int N;
};


void redimensionar(arreglo &a, int c){
	int *nuevopuntero;
	nuevopuntero = new int[c];
	for(size_t i=0;i<a.N;i++) { 
		*(nuevopuntero +i) = *(a.P+i);
	}
	for(size_t i=a.N; i<c; i++){
		*(nuevopuntero +i) = 0; 
	}

	delete a.P;
	a.N = c;
	a.P = nuevopuntero;
}


int main() {
	arreglo a;
	cin >> a.N;
	a.P = new int[a.N];
	for(size_t i=0;i<a.N;i++) { 
		*(a.P+i) = rand()%1000-501 + 1000;
	}
	int c = 10;
	redimensionar(a, c);
	for(size_t i=0; i<c; i++){
		cout << *(a.P +i)<<endl;
	}
	return 0;
}

