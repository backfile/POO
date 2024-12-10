///    Ejercicio 1 (35pts)
//    Implemente la función: tuple<int,int> eliminaRepetidos(int arreglo, int tam). La función recibe un puntero a un
//    arreglo dinámico y la cantidad de datos (enteros) contenidos en el mismo. Debe eliminar los elementos repetidos, mediante
//    el siguiente algoritmo:
//    crear un vector auxiliar con espacio suficiente para tantos elementos como el original
//    por cada elemento del vector original,
//    2.1 buscarlo en el auxiliar, si no está agregarlo
//    crear el vector definitivo, con espacio justo para la cant de elementos agregados al auxiliar
//    copiar los datos del auxiliar al definitivo
//    borrar los vectores original y auxiliar
//    retornar el definitivo y su nuevo tamaño en la tupla
//    Ej: si recibe [1,4,1,6,3,5,7,3,2,6,2,1,8,4] deberá retornar [1,4,6,3,5,7,8] ). Use solo notación de punteros (no use el operador
//    []) y no utilice la clase vector.

#include <iostream>

using namespace std;


bool busqueda(int *aux, int tam, int nro){
	for(int i=0;i<tam;i++) { 
		if(aux[i] == nro){
			return true;
		}
	}
	return false;
}

pair<int*,int> eliminaRepetidos(int *arreglo,int tam) {
	int *aux = new int[tam];
	int cont = 0;
	for(int i=0;i<tam;i++) { 
		bool rta = busqueda(aux, tam, arreglo[i]);
		if(rta == false){
			aux[cont] = arreglo[i];
			cont ++;
		}
	}
	int *definitivo = new int[cont];
	for(int i=0;i<cont;i++) { 
		definitivo[i] = aux[i];
	}
	pair<int*, int>tupla;
	tupla.first = definitivo;
	tupla.second = cont;
	return tupla;
}
int main() {
	// Definimos el arreglo dinámico
	int tam = 14;
	int* arreglo = new int[tam] {1, 4, 1, 6, 3, 5, 7, 3, 2, 6, 2, 1, 8, 4};
	
	// Llamamos a la función para eliminar los repetidos
	pair<int*, int> resultado = eliminaRepetidos(arreglo, tam);
	
	// Mostramos el resultado
	cout << "Arreglo sin repetidos: ";
	for (int i = 0; i < resultado.second; i++) {
		cout << *(resultado.first + i) << " "; // Usamos notación de punteros
	}
	cout << endl;
	
	// Liberamos la memoria dinámica
	delete[] arreglo;
	delete[] resultado.first;
	
	return 0;

}
