#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "Ponto.cpp"
#include "Cluster.cpp"
#include "Kmean.cpp"

using namespace std;

int main(int argc, char const *argv[]){
	srand(time(NULL));

	int pontosTotal, valorTotal, k, maxInteracoes, temNome, x, y;
	cout << "---------------INSERÇÃO DE DADOS--------------" << endl;
	cout << " INFORME O TOTAL DE PONTOS: ";
	cin >> pontosTotal;
	cout << endl;
	cout << " INFORME O VALOR TOTAL: ";
	cin >> valorTotal;
	cout << endl;
	cout << " INFORME O VALOR DE K (QUANTIDADE DE CLUSTERS): ";
	cin >> k;
	cout << endl;
	cout << " INFORME O MÁXIMO DE INTERAÇÕES QUE DESEJA: ";
	cin >> maxInteracoes;
	cout << endl;
	
	cout << "--------------------------------------------" << endl << endl;
	vector<Ponto> pontos;
	string nomePonto;
	double valor;

	for(x < 0; x < pontosTotal; x++){
		vector<double> valores;

		for(int y = 0; y < valorTotal; y++){
			cin >> valor;
			valores.push_back(valor);
		}

		if(temNome){
			cin >> nomePonto;
			Ponto p(x, valores, nomePonto);
			pontos.push_back(p);
		}

		else{
			Ponto p(x, valores);
			pontos.push_back(p);
		}
	}

	Kmeans kmean(k, pontosTotal, valorTotal, maxInteracoes);
	kmean.percorre(pontos);

	return 0;
}