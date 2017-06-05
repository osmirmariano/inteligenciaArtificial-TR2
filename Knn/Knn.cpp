#ifndef KNN_H
#define KNN_H

#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include "Individuo.cpp"

using namespace std;

class Knn{
	public:
		double distanciaEuclidiana(Individuo individuo1, Individuo individuo2){
			int x;
			double soma;
			soma = pow((individuo1.getA() - individuo2.getA()), 2) +
				   pow((individuo1.getB() - individuo2.getB()), 2) +
				   pow((individuo1.getC() - individuo2.getC()), 2) +
				   pow((individuo1.getD() - individuo2.getD()), 2);
			return sqrt(soma);
		}

		//Função para classifica uma nova amostra
		string classificar(vector<Individuo> &individuos, Individuo novo, int k){
			int x;
			double distancia;
			//Verificando se k é par
			if(k % 2 == 0){
				k--;
				if(k <= 0)
					k = 1;
			}
			/* 
				distância de cada individuo para o conjunto do novo treinamento
				pair oredena em ordem decrescente
				set de pairs da distância de cada indivíduo o conjunto de treinamento para o novo exemplo
				cada pair é composto pela distância e o índice do indivíduo no vetor
			*/
			set<pair<double, int> > distanciaIndividuos;
			
			//Calculando a distância euclidiana do novo exemplo para cada amostra
			for(x = 0; x < individuos.size(); x++){
				distancia = distanciaEuclidiana(individuos[x], novo);
				distanciaIndividuos.insert(make_pair(distancia, x));
			}

			/*
				para verificar qual classe pertence o novo exemplo, basta verificar a classe mais frequente dos K
				vizinhos mais próximos 
			*/
			set<pair<double, int> >::iterator it;
			//Para indicar a contagem das classes
			vector<int> contClasses(3);
			string classe;
			int contK = 0;

			for(it = distanciaIndividuos.begin(); it != distanciaIndividuos.end(); it++){
				
				if(contK == k) 
					break;
				
				//classe vai recebe a classe do indivíduo, como o indice do elemento está armazendo no segundo elemento do par
				classe = individuos[it->second].getClasse();

				if(classe == "Iris-setosa")
					contClasses[0]++;
				else if(classe == "Iris-versicolor")
					contClasses[1]++;
				else
					contClasses[2]++;

				// if(classe == "B")
				// 	contClasses[0]++;
				// else if(classe == "R")
				// 	contClasses[1]++;
				// else
				// 	contClasses[2]++;

				contK++;
			}
			
			string classificacaoClasse;
			
			if(contClasses[0] >= contClasses[1] && contClasses[0] >= contClasses[2])
				classificacaoClasse = "Iris-setosa";
			else if(contClasses[1] >= contClasses[0] && contClasses[1] >= contClasses[2])
				classificacaoClasse = "Iris-versicolor";
			else
				classificacaoClasse = "Iris-virginica";

			// if(contClasses[0] >= contClasses[1] && contClasses[0] >= contClasses[2])
			// 	classificacaoClasse = "B";
			// else if(contClasses[1] >= contClasses[0] && contClasses[1] >= contClasses[2])
			// 	classificacaoClasse = "R";
			// else
			// 	classificacaoClasse = "L";
			return classificacaoClasse;

		}	
};

#endif // KNN_H