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
		//Knn();
		
		double distanciaEuclidiana(Individuo individuo1, Individuo individuo2){
			int x;
			double soma;
			soma = pow((individuo1.getA() - individuo2.getA()), 2) +
				   pow((individuo1.getB() - individuo2.getB()), 2) +
				   pow((individuo1.getC() - individuo2.getC()), 2) +
				   pow((individuo1.getD() - individuo2.getD()), 2);
			return sqrt(soma);
		}

		string classificar(vector<Individuo> &individuos, Individuo novo, int k){
			int x;
			double distancia;
			//Verificando se k é par
			if(k % 2 == 0){
				k--;
				if(k <= 0)
					k = 1;
			}
			//pair ordena
			set<pair<double, int> > distanciaIndividuos;
			
			//Calculando a distância de cada amostra
			for(x = 0; x < individuos.size(); x++){
				distancia = distanciaEuclidiana(individuos[x], novo);
				distanciaIndividuos.insert(make_pair(distancia, x));
			}
			set<pair<double, int> >::iterator it;
			
			vector<int> contClasses(3);
	
			int contK = 0;

			for(it = distanciaIndividuos.begin(); it != distanciaIndividuos.end(); it++){
				if(contK == k) 
					break;
				
				string classe = individuos[it->second].getClasse();

				if(classe == "Iris-setosa")
					contClasses[0]++;
				else if(classe == "Iris-versicolor")
					contClasses[1]++;
				else
					contClasses[2]++;

				contK++;
			}
			
			string classificacaoClasse;
			
			if(contClasses[0] >= contClasses[1] && contClasses[0] >= contClasses[2])
				classificacaoClasse = "Iris-setosa";
			else if(contClasses[1] >= contClasses[0] && contClasses[1] >= contClasses[2])
				classificacaoClasse = "Iris-versicolor";
			else
				classificacaoClasse = "Iris-virginica";

			return classificacaoClasse;

		}	
};

#endif // KNN_H