#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>

using namespace std;

class Individuo{
	private:
		string classe;
		double a, b, c, d;
		
	public:
		Individuo(double a, double b, double c, double d, string classe){
			this->a = a;
			this->b = b;
			this->c = c;
			this->d = d;
			this->classe = classe;
		};

		~Individuo();

		string getClasse(){
			return classe;
		};
		
		double getA(){
			return a;
		};

		double getB(){
			return b;
		};

		double getC(){
			return c;
		};

		double getD(){
			return d;
		};
	
};