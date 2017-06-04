#include <iostream>
#include <vector>
#include "Individuo.cpp"
#include "Knn.cpp"

using namespace std;

int main(int argc, char const *argv[]){
	vector<Individuo> individuos;
	int k = 3, x;
	int tamTreinamento = 105;
	double a, b, c, d;
	string classe, classeObtida;
	Knn knn;

	for(x = 0; x < tamTreinamento; x++){
		cin >> a >> b >> c >> d >> classe;
		individuos.push_back(Individuo(a, b, c, d, classe));
	}

	int acertos = 0;
	int tamTestes = 150 - tamTreinamento;

	for(x = 0; x < tamTestes; x++){
		cin >> a >> b >> c >> d >> classe;
		Individuo ind(a, b, c, d, classe);
		classeObtida = knn.classificar(individuos, ind, k);
		
		cout << "Classe esperada: " << classe << endl;
		cout << "Classe obtida: " << classeObtida << endl << endl;

		if(classe == classeObtida)
			acertos++;
	}
	

	cout << "---------------------------------------------------" << endl;
	cout << "QUANTIDADE DE K VIZINHOS: " << k << endl;
	cout << acertos << " ACERTOS DE UM TOTAL DE " << tamTestes << " TESTES" << endl;

	return 0;
}
