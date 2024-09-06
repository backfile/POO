#include <iostream>
#include <cstdlib>
using namespace std;

//Implemente una clase VectorDinamico que posea comoatributo un puntero a entero que apunte a la memoria donde
//se almacenan los datos. Dicha clase debe poseer:
//1. Un constructor que reciba el tamaño inicial del vector, reserve la memoria necesaria e inicialice los valores del
//vector de manera aleatoria.
//2. Un destructor que se encargue de liberar la memoria reservada.
//3. Un método Duplicar(...) que duplique la cantidad de memoria reservada manteniendo los datos que ya
//estaban en el vector e inicializando al azar los nuevos valores.
//4. Un método VerTamanio() para cosultar el tamaño del vector, y un método VerElemento(...) que reciba el
//número de elemento (índice) y devuelva su valor.
//5. Cree un programa cliente que muestre la utilización de todas las funciones implementadas.
//6. Explique: ¿Es necesario implementar un constructor de copia? ¿Por qué?


class vectorDinamico{
private:
	int *p;
	int m_tamanio;
	
public:
	vectorDinamico(int N);
	~vectorDinamico(){delete[]p;}
	vectorDinamico(const vectorDinamico &otro) = delete;
	void duplicar();
	int VerTamanio(){return m_tamanio;}
	int verElemento(int indice){return *(p + indice);}
};

vectorDinamico::vectorDinamico(int N){
	m_tamanio = N;
	p = new int[N];
	for(int i=0;i<N;i++) { 
		*(p + i) = rand()%100;
	}
}
	
void vectorDinamico::duplicar(){
	int *nuevoP = new int[m_tamanio * 2];
	for(int i=0;i<m_tamanio;i++) { 
		*(nuevoP + i) = *(p + i);
	}
	for(int i=m_tamanio;i<m_tamanio*2;i++) { 
		*(nuevoP + i) = rand()%100;
	}
	delete []p;
	p = nuevoP;
	m_tamanio = m_tamanio * 2;
	
}

int main() {
	vectorDinamico v(3);
	for(int i=0;i<v.VerTamanio();i++) { 
		cout<<v.verElemento(i)<<endl;
	}
	
	v.duplicar();
	
	for(int i=0;i<v.VerTamanio();i++) { 
		cout<<v.verElemento(i)<<endl;
	}
	return 0;
}

