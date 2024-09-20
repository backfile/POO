#include <iostream>
using namespace std;

class Racional{
	float n_num, n_den;
public:
	Racional(int num, int den) : n_num(num), n_den(den){}
	int VerNum()const {return n_num;}
	int VerDen()const {return n_den;}
	Racional(){}
	Racional operator+(Racional b){
		Racional suma(this->n_num * b.VerDen() + b.VerNum() * this->n_den, this->n_den * b.VerDen());
		return suma;
	}
	Racional operator*(int b){ // Racional*entero
		Racional mul(this->n_num * b, this->n_den);
		return mul;
	}
	bool operator==(Racional b){
		return ((this->n_num/this->n_den) == (b.n_num/b.n_den));
	}
	bool operator!=(Racional b){
		return not(*this == b);
	}
	bool operator<(Racional b){
		return((this->n_num/this->n_den) < (b.n_num/b.n_den));
	}
	bool operator>(Racional b){
		return((this->n_num/this->n_den) > (b.n_num/b.n_den));
	}
	bool operator>=(Racional b){
		return(((*this == b) or (*this > b)));
	}
	bool operator<=(Racional b){
		return(((*this == b) or (*this < b)));
	}
	
};

ostream &operator<<(ostream &o, Racional b){
	o << b.VerNum() << "/" << b.VerDen(); 
	return o;
} 

istream &operator>>(istream &i, Racional &b){
	int x;
	int z;
	i >> x;
	i >> z;
	
	Racional nuevo(x, z);
	b = nuevo;
	return i;
} 


Racional operator*(int b, Racional a){ // La multiplicacion es conmutativa, esta sobrecarga es para entero*Racional
	return a*b;
}

int main() {
	Racional a(1, 2);
	Racional b(1, 4);
	
	Racional suma = a + b;
	cout<<suma.VerNum()<<"/"<<suma.VerDen()<<endl;
	
	Racional mul = a * 2;
	cout<<mul.VerNum()<<"/"<<mul.VerDen()<<endl;

	cout << (a >= b)<<endl;
	cout << (a == b)<<endl;
	cout << a << endl;

	Racional p;
	cin >> p;
	cout << p;
	return 0;
}

