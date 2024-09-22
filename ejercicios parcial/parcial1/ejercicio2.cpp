//Ej2(25pts) a) Escriba una función llamada espejo que reciba 2 punteros indicando el comienzo y el final
//de un arreglo, y genere un nuevo arreglo que sea el doble de largo que el original, y contenga primero
//los elementos del arreglo original en el orden original, y luego todos los elementos menos el último, pero
//en el orden inverso. Por ejemplo, si el arreglo original contiene {1,2,3,4,5}, el nuevo debe contener
//{1,2,3,4,5,4,3,2,1}. b) Escriba una programa cliente que permita al usuario cargar un arreglo de n
//elementos (n es dato que ingresa el usuario), y muestre el arreglo que genera la función.

#include <iostream>
#include <vector>
using namespace std;

int* Espejo(int *p, int *f, int n){
	int *newp = new int[n*2];
	for(int i=0;i<n;i++) { 
		newp[i] = p[i];
	}
	int cont = n-2;
	int cont2 = n;
	for(int i=0;i<n-1;i++) { 
		newp[cont2] = newp[cont];
		cont2++;
		cont--;
	}	
	return newp;
}
	
	int main() {
		int n;
		cin>>n;
		int *p = new int[n];
		for(int i=0;i<n;i++) { 
			cin >> p[i]; 
		}
		int *newp = Espejo(p, p+(n-1), n);
		for(int i=0;i<n*2-1;i++) { 
			cout << newp[i];
		}
		delete [] p;
		delete [] newp;
		return 0;
	}
 	
