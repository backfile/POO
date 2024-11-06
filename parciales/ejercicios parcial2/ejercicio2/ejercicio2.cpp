//Ejercicio 2 [25 pts] Se dispone de un archivo de textos USUARIOS.TXT donde cada línea contiene el
//código, sector, el apellido y el nombre . El código es un número entero y el sector es una sola palabra, y
//cada usuario tiene un solo nombre y apellido separado por un espacio en blanco. Escriba una clase que
//posea entre sus métodos: a) la función GeneraPassword(), encargada de crear un password
//concatenando el sector con la primer letra del nombre y el apellido completo de cada usuario y otra
//función CreaBinario( ) que genere un archivo binario que contenga los datos referentes al código,
//nombre, apellido y password generado de cada usuario. Programa los métodos adicionales que
//considere necesarios.


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Usuario{
	string nombre;
	string apellido;
	string sector;
	int codigo;
};

struct UsuarioPass{
	string nombre;
	string apellido;
	string sector;
	int codigo;
	string pass;
};

class Archivo{
	string m_nombre_archivo;
public:
	Archivo(string nombre_archivo, Usuario a) : m_nombre_archivo(nombre_archivo){
		AnadirUsuario(a);
	}
	void AnadirUsuario(Usuario a){
		ofstream arch(m_nombre_archivo, ios::app);
		if(!arch) runtime_error("No se a podido abrir el archivo");
		arch << a.codigo << " " << a.sector << " " << a.apellido << " " << a.nombre << endl;
	}
	void generarContrasenia(){
		vector<Usuario>v;
		vector<UsuarioPass>f;
		fstream arch(m_nombre_archivo, ios::in|ios::out);
		if(!arch) runtime_error("No se a podido abrir el archivo");
		arch.seekg(0);
		int codigo;
		string nombre;
		string apellido;
		string sector;
		while(arch >> codigo){
			arch >> sector;
			arch >> apellido;
			arch >> nombre;
			Usuario aux;
			aux.codigo = codigo;
			aux.nombre = nombre;
			aux.apellido = apellido;
			aux.sector = sector;
			v.push_back(aux);
		   }
		for(size_t i=0;i<v.size();i++) { 
			string nombre = v[i].nombre;
			string apellido = v[i].apellido;
			string sector = v[i].sector;
			int codigo = v[i].codigo;
			string pass = sector + nombre[0] + apellido;
			UsuarioPass aux2;
			aux2.nombre = nombre;
			aux2.apellido = apellido;
			aux2.sector = sector;
			aux2.codigo = codigo;
			aux2.pass = pass;
			f.push_back(aux2);	
		}
		for(size_t i=0;i<f.size();i++) { 
			arch << f[i].codigo << " " << f[i].sector << " " << f[i].apellido << " " << f[i].nombre << " " << f[i].pass << endl;
		}
	  }
		
	};

int main() {
	Usuario b;
	b.nombre = "Franco";
	b.apellido = "Caraffa";
	b.codigo = 10;
	b.sector = "Centro";
	Archivo arch("USUARIOS.TXT", b);
    arch.generarContrasenia();
	return 0;
}

