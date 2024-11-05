//Se desea gestionar la venta de entradas de un teatro. Una sala de teatro est� compuesta por butacas y cada sala
//puede tener diferente n�mero de butacas. a) Cada butaca tiene un tipo (cadena), un precio y un estado (si est�
//libre u ocupada). Codifique una clase Butaca que tenga un constructor para cargar tipo y precio; y m�todos para
//modificar o consultar sus datos, entre otras funcionalidades que considere necesarias. b) Defina una clase Sala que,
//reutilizando la clase Butaca, guarde el nombre de la sala y la lista de butacas. La misma deber� tener:
//� Un constructor que reciba el nombre de la sala.
//� Un m�todo que permita agregar varias butacas de un mismo tipo y precio a la sala.
//� Un m�todo para registrar la compra de una entrada recibiendo el n�mero de butaca. El m�todo debe verificar
//que la butaca est� libre y retornar true si la compra se puede hacer, o false si ya estaba ocupada.
//� Nota: asuma que el n�mero se determina por el orden en que se agreg� esa butaca a la sala
//� Un m�todo para obtener la recaudaci�n total de una funci�n
//� Un m�todo para obtener el porcentaje de ocupaci�n de la sala

#include <iostream>
#include <vector>
using namespace std;

class Butaca{
	string m_tipo;
	int m_precio;
	bool m_libre = true;
public:
	Butaca(int precio, string tipo) : m_precio(precio), m_tipo(tipo){}
	int VerPrecio(){return m_precio;}
	string VerTipo(){return m_tipo;}
	bool VerDisponibilidad(){return m_libre;}
	void OcuparButaca(){
		m_libre = true;
	}
		void DesocuparButaca(){
			m_libre = false;
		}
			void CambiarPrecio(int nuevoPrecio){
				m_precio = nuevoPrecio;
			}
				
};

class Sala{
	string m_nombre;
	vector<Butaca>butacas;
public:
	Sala(string nombre) : m_nombre(nombre) {}
	void AgregarButaca(int precio, string tipo){
		Butaca nuevaButaca(precio, tipo);
		butacas.push_back(nuevaButaca);
	}
	bool RegistrarCompra(int nro_butaca){
		return butacas[nro_butaca].VerDisponibilidad();
	}
	float recaudacionTotal(){
		float count;
		for(size_t i=0;i<butacas.size();i++) { 
			count += butacas[i].VerPrecio();
		}
		return count;
	}
	int porcentajeOcupacion(){
		int count;
		for(size_t i=0;i<butacas.size();i++) { 
			if(butacas[i].VerDisponibilidad() == false){
				count ++;
			}
		}
		int porcentaje = (count * 100) / butacas.size();
		return porcentaje;
	}
};



int main() {
	
	return 0;
}

