#include <iostream>
using namespace std;

int* intercala(int *a, int *b, int *c, int *d) {
	int tamanio = (c - a) + (d - b);
	int lista1 = (c - a); // size a
	int lista2 = (d - b); // size b
	int *pnuevo = new int[tamanio];
	
	// i indice de a
	// j indice de b
	// k indice de nuevop
	int i = 0 , j = 0, k = 0;
	
	// Intercalar los elementos
	while (i < lista1 and j < lista2) {
		pnuevo[k++] = a[i++];  // Agregar de la primera lista 
		pnuevo[k++] = b[j++];  // Agregar de la segunda lista
	}
	
	// Si quedan elementos en la primera lista
	while (i < lista1) {
		pnuevo[k++] = a[i++];
	}
	
	// Si quedan elementos en la segunda lista
	while (j < lista2) {
		pnuevo[k++] = b[j++];
	}
	
	// Mostrar el resultado intercalado
	for (int i = 0; i < tamanio; i++) {
		cout << pnuevo[i] << " ";
	}
	cout << endl;
	
	return pnuevo;
}

int main() {
	int n, r;
	cin >> n >> r;
	
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> *(a + i);
	}
	
	int *b = new int[r];
	for (int i = 0; i < r; i++) {
		cin >> *(b + i);
	}
	
	intercala(a, b, (a + n), (b + r)); 
	
	delete[] a;
	delete[] b;
	
	return 0;
}
