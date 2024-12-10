//a) Escriba una clase abstracta IA para representar a una inteligencia artificial que responde
//	preguntas. La clase debe recibir el nombre de la misma en su constructor, guardarlo y tener un método
//	para consultarlo. Debe tener además un método virtual ObtenerRespuesta que reciba una pregunta y
//	retorne una respuesta (ambas serán strings).
//	b) Implemente 2 clases representando 2 inteligencias diferentes:
//	- Memory: Debe recibir en su constructor una lista de preguntas y respuestas. El método
//	ObtenerRespuesta debe buscar la pregunta en esa lista y retornar la respuesta correspondiente. Si la
//	pregunta no está en la lista, debe elegir una respuesta al azar.
//	- Multivac: El método ObtenerRespuesta debe responder a todo con "Datos insuficientes para una
//	respuesta esclarecedora.".
//	c) Escriba una función que reciba una IA (que pueda ser cualquiera, una de las 2 implementadas en b,
//	o incluso otra) y permita al usuario ingresar preguntas y ver las respuestas hasta que ingrese "Salir".


//	Escriba un programa cliente que permita al usuario elegir uno de los dos tipos de inteligencia, cree la
//	instancia de la clase adecuada e invoque con ella a la función. Nota: en el main, donde se debería
//	carga u obtener la lista de preguntas y respuestas para Memory, solo declare la o las variables
//	necesarias y ponga simplemente una comentario diciendo “// aquí debería cargar la lista”	
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
class IA{
string m_nombre;
public:
	IA(string nombre) : m_nombre(nombre){}
	string VerNombre(){return m_nombre;}
	virtual string ObtenerRespuesta(string pregunta) = 0;
};

class Memory : public IA{
vector<string>m_preguntas;
vector<string>m_respuestas;
public:
	Memory(string nombre, vector<string>preguntas, vector<string>respuestas) : IA(nombre), m_preguntas(preguntas), m_respuestas(respuestas){} 
	string ObtenerRespuesta(string pregunta) override{
		for(size_t i=0;i<m_preguntas.size();i++) {
			if(m_preguntas[i] == pregunta){
				return m_respuestas[i];
			} 
		}	
		return m_respuestas[rand()%m_preguntas.size()];
	}
};

class Multivac : public IA{
public:
	Multivac(string nombre) : IA(nombre){}
	string ObtenerRespuesta(string pregunta) override{
		string rta = "Datos insuficientes para una respuesta esclarecedora";
		return rta;
	}
};

void RecibirIA(IA &x){
	string pregunta;
	getline(cin, pregunta);
	while(pregunta!="salir"){
		cout << x.ObtenerRespuesta(pregunta) << endl;
		getline(cin, pregunta);
	}
	
}

int main() {
	Multivac m("konra");
	vector<string>preguntas = {"como estas?"};
	vector<string>respuestas = {"bien"};
	Memory f("franco", preguntas, respuestas);
	RecibirIA(m);
	RecibirIA(f);
	return 0;
}

