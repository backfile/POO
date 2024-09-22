//Ej3(25pts) Escriba una función que reciba 2 punteros indicando el comienzo y el final de un arreglo, y
//un entero m. La función debe generar un nuevo arreglo que contenga m veces cada elemento del
//arreglo original. Por ej, si el arreglo original es {2,4,6,8} y m=3, entonces el arreglo generado debe ser
//{2,2,2,4,4,4,6,6,6,8,8,8} (se repite 3 veces cada uno). Escriba una programa cliente que permita al
//usuario cargar un arreglo de n elementos (n es dato que ingresa el usuario), y muestre los arreglos que
//genera la función para cada valor de m desde 2 hasta 5 (incluido).

#include <iostream>
using namespace std;

int* funcion(int *p, int *f, int m){
   int tamanio = (f - p);
   int *pnuevo = new int[tamanio * m];
   int v = 0;
   for(int i=0;i<tamanio;i++) { 
	   for(int j=0;j<m;j++) {
		   pnuevo[v] = p[i];
		   v++;
	   }
   }
   cout << "Para m = " << m << endl;
   for(int i=0;i<tamanio*m;i++) { 
	   cout << pnuevo[i];
   }
   cout <<endl;
   return pnuevo;
}

int main() {
	int n;
	cin >> n;
	int *p = new int[n];
	for(int i=0;i<n;i++) { 
		cin >> p[i];   
	}
	for(int m=2;m<=5;m++) { 
		funcion((p+0), (p+n), m);
	}
	
	delete[]p;

	return 0;
}

