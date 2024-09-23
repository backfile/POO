//a) Escriba una función que reciba 4 punteros indicando: el comienzo de un arreglo, un elemento del arreglo (que puede ser cualquiera de ellos),
// otro elemento del arreglo (que debe ser posterior al 2do argumento) y el final del arreglo (la dirección justo después del último elemento).
// La función debe generar un nuevo arreglo sin los elementos que estaban entre el 2do y 3er puntero. 
//Ejemplo: si el arreglo inicial es {11,22,33,44,55,66,77,88,99} y el 2do y 3er puntero apuntan al 33 y al 55 respectivamente,
// el nuevo arreglo debe ser {11,22,66,77,88,99}. b) Escriba un programa cliente para probar la función donde el usuario
// pueda cargar un arreglo indicando el tamaño y los elementos. El programa debe probar la invocación a la función 10 veces,
// utilizando en cada prueba dos posiciones del mismo generadas aleatoriamente para 2do y 3er argumento. 
//El programa debe mostrar el nuevo arreglo en cada prueba.
#include <iostream>
using namespace std;
int* Funcion(int *a,int *b, int *c, int *d) {
	int calculo = c-b; // = 2
	int tamanio = d-a-calculo; // = 7 - 2 = 5
	cout << calculo << " este es c-b " << endl;
	cout << tamanio << " este es el tamaño " << endl;
	int *pnuevo = new int[tamanio];
	int v = 0;
	
	for(int i=0;i<b-a;i++) { 
		pnuevo[i] = a[i];
		v++;
	}
	
	cout << "\n";
	
	for(int i=(c-a+1);i<d-a+1;i++) { 
		pnuevo[v] = a[i];
		v++;
	}
	
	for(int i=0;i<tamanio;i++) { 
		cout << pnuevo[i] << " ";
	}
	
	return pnuevo;
}

int main() {
	int n;
	cin >> n;
	int *p = new int[n];
	for(int i=0;i<n;i++) { 
		cin >> p[i];
	}
	int *pnuevo = Funcion((p),(p+2),(p+4),(p+n-1));
	delete[]p;
	delete[]pnuevo;
	return 0;
}
