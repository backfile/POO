#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<string>v;
	ifstream archi("texto.txt");
	if(!archi.is_open()){
		throw runtime_error("No se a podido abrir el archivo");
	}
	string palabra;
	int cont = 0;
	while(archi >> palabra){
		v.push_back(palabra);
		cont ++;
	}
	cout << "Se leyeron: " << cont << " palabras" << endl;
	sort(v.begin(), v.end());
	archi.close();
	ofstream archi2("texto.txt");
	if(!archi2.is_open()){
		throw runtime_error("No se a podido abrir el archivo");
	}
	
	for(size_t i=0;i<v.size();i++) { 
		archi2 << v[i] << endl;
	}
	
	
	return 0;
}

