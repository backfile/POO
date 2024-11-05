#include <iostream>
#include <vector>
using namespace std;

class Tecla{
	string m_nombre;
	bool estaApretada = false;
public:
	Tecla(string nombre) : m_nombre(nombre){}
	string VerNota(){return m_nombre;}
	void Apretar(){estaApretada = true;}
	void Soltar(){estaApretada = false;}
	bool EstaApretada(){return estaApretada;}
};

class Pedal{
	float presion;
public:
	Pedal(){
		presion = 0;
	}
	void ModificarPresion(int nro_presion){
		presion = nro_presion;
	}
	int VerPresion(){
		return presion;
	}
};

class Instrumento{
	string m_nombre;
public:
	Instrumento(string nombre) : m_nombre(nombre){}
	string VerNombre(){return m_nombre;}
	virtual string Sonido() = 0;
	virtual ~Instrumento(){}
};

class Piano : public Instrumento{
	Pedal pedal;
	vector<Tecla>teclas = {Tecla("do"), Tecla("re"), Tecla("mi"), Tecla("fa"), Tecla("sol"), Tecla("la"), Tecla("si")};
public:
	Piano() : Instrumento("Piano"){}
	void ApretarTecla(int nro_tecla){
		teclas[nro_tecla].Apretar();
	}
	void SoltarTecla(int nro_tecla){
		teclas[nro_tecla].Soltar();
	}
	void PresionarPedal(int nro_presion){
		pedal.ModificarPresion(nro_presion);
	}
	string Sonido(){
		string sonido;
		for(size_t i=0;i<teclas.size();i++) { 
			if(teclas[i].EstaApretada()){
				sonido = sonido + teclas[i].VerNota();
			};
		}
		return sonido;
	}
};

void mostrarEnPantalla( Instrumento *t){
	cout << "El " << t->VerNombre() << " suena: " << t->Sonido() << endl;
}

int main() {
	Piano *t = new Piano();
	t->ApretarTecla(2);
	mostrarEnPantalla(t);
	t->SoltarTecla(2);
	mostrarEnPantalla(t);
	return 0;
}

