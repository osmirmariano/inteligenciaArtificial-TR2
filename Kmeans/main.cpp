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
	
	cin >> pontosTotal >> valorTotal >> k >> maxInteracoes;

	vector<Ponto> pontos;
	string nomePonto;
	double valor;
	vector<double> valores;

	for(x < 0; x < pontosTotal; x++){
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