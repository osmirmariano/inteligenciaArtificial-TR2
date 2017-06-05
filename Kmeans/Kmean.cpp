#ifndef KMEANS_H
#define KMEANS_H

#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "Ponto.cpp"
#include "Cluster.cpp"

using namespace std;

class Kmeans{
    private:
        int k;
        int valorTotal, pontosTotal, maxInteracoes;
        vector<Cluster> clusters;

        //Função para retornar o id do centro mais próximo utilizando a distância euclidiana
        int getIdProxCentro(Ponto ponto){
            double soma = 0.0, distanciaMin;
            int idClusterCentro = 0;
            int x, y;

            for(x = 0; x < valorTotal; x++){
                soma += pow(clusters[0].getValorCentral(x) - ponto.getValores(x), 2.0);
            }

            distanciaMin = sqrt(soma);
            double distancia;

            for(x = 1; x < k; x++){
                soma = 0.0;
            
                for(y = 0; y < valorTotal; y++){
                    soma += pow(clusters[x].getValorCentral(y) - ponto.getValores(y), 2.0);
                }

                distancia = sqrt(soma);

                if(distancia < distanciaMin){
                    distanciaMin = distancia;
                    idClusterCentro = x;
                }
            }
            return idClusterCentro;
        };

    public:
        Kmeans(int k, int pontosTotal, int valorTotal, int maxInteracoes){
            this->k = k;
            this->pontosTotal = pontosTotal;
            this->valorTotal = valorTotal;
            this->maxInteracoes = maxInteracoes;
        };

        void percorre(vector<Ponto> &pontos){
            int x, y, z;
            bool feito;

            if(k > pontosTotal)
                return;

            vector<int> indiceProibido;

            for(x = 0; x < k; x++){
                while(true){
                    int indicePonto = rand()%pontosTotal;

                    if(find(indiceProibido.begin(), indiceProibido.end(), indicePonto) == indiceProibido.end()){
                        indiceProibido.push_back(indicePonto);
                        pontos[indicePonto].setCluster(x);
                        Cluster cluster(x, pontos[indicePonto]);
                        clusters.push_back(cluster);
                        break;
                    }
                }
            }
            int interacao =  1;

            while(true){
                feito = true;

                for(x = 0; x < pontosTotal; x++){
                    int idAntigoCluster = pontos[x].getCluster();
                    int idCentroProx = getIdProxCentro(pontos[x]);

                    //Se diferente o ponto mudou de grupo
                    if(idAntigoCluster != idCentroProx){
                        if(idAntigoCluster != -1)
                            clusters[idAntigoCluster].removePonto(pontos[x].getIdPonto());

                        pontos[x].setCluster(idCentroProx);
                        clusters[idCentroProx].adicionarPonto(pontos[x]);
                        feito = false;//pq mudou de grupo
                    }
                }
                double soma;
                int totalPontosCluster;
                //Recalcular o centro de cada cluster
                for(x = 0; x < k; x++){
                    for(y = 0; y < valorTotal; y++){
                        totalPontosCluster = clusters[x].getTotalPontos();
                        soma  = 0.0;

                        if(totalPontosCluster > 0){
                            for(z = 0; z < totalPontosCluster; z++){
                                soma += clusters[x].getPonto(z).getValores(y);
                            }
                            clusters[x].setValorCentral(y, soma/totalPontosCluster);
                        }
                    }
                }

                //Condição de parada
                if(feito == true || interacao >= maxInteracoes){
                    cout << "Encerrando interação: " << interacao << endl << endl;
                    break;
                }
                interacao++;
            }
            
            int totalPontosCluster;
            //Mostrar elementos no clusters
            for(x = 0; x < k; x++){
                totalPontosCluster = clusters[x].getTotalPontos();

                cout << "Cluster: " << clusters[x].getIdCluster() + 1 << endl;

                for(y = 0; y < totalPontosCluster; y++){
                    cout << "Ponto " << clusters[x].getPonto(y).getIdPonto() + 1 << ": ";
                    for(z = 0; z < valorTotal; z++){
                        cout << clusters[x].getPonto(y).getValores(z) << " ";
                    }
                    string nomePonto = clusters[x].getPonto(y).getNome();
                    cout << endl;
                    if(nomePonto != "")
                        cout << " - " << nomePonto;
                }   
                cout << endl;
            }

            cout << "Valores Cluster: ";
            for(y = 0; y < valorTotal; y++)
                cout << clusters[y].getValorCentral(y) << " ";
            cout << endl << endl;
        }   

};
#endif //KMEAN