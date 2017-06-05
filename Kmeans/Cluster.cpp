#ifndef CLUSTER_H
#define CLUSTER_H

#include <iostream>
#include <vector>
#include "Ponto.cpp"

using namespace std;

class Cluster{
    private:
        int idCluster;
        vector<double> valorCentral; //Centro para cada atributo
        vector<Ponto> pontos; //Pontos pertence ao cluster

    public:
        //Construtor
        Cluster(int idCluster, Ponto ponto){
            int x;
            this->idCluster = idCluster;
           int totalValores = ponto.getTotalValores();
            
            for(x = 0; x < totalValores; x++){
                valorCentral.push_back(ponto.getValores(x));
            }
            pontos.push_back(ponto);
        }

        //Adiconar ponto ao cluster
        void adicionarPonto(Ponto ponto){
            pontos.push_back(ponto);
        }

        bool removePonto(int idPonto){
            int x, totalPontos;
            totalPontos = pontos.size();

            for(x = 0; x < totalPontos; x++){
                if(pontos[x].getIdPonto() == idPonto){
                    pontos.erase(pontos.begin( )+ x);
                    return true;
                }
            }
            return false;
        }

        double getValorCentral(int a){//a = indice
            return valorCentral[a];
        }

        void setValorCentral(int a, double valor){
            valorCentral[a] = valor;
        }

        Ponto getPonto(int a){//acessar o objeto que está no cluster
            return pontos[a];
        }

        int getTotalPontos(){//Retorna a quantidade de pontos
            return pontos.size();
        }

        int getIdCluster(){
            return idCluster;
        }
};
#endif //CLUSTER