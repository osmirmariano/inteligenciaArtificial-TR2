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

            for(x = 1; x < k; x++){
                soma = 0.0;
                double distancia;

                for(y = 0; y < valorTotal; y++){
                    soma += pow(clusters[x].getValorCentral(y) - point.getValores(y), 2.0);
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
        Kmeans(int k, int pontosTotal, int maxInteracoes){
            this->k = k;
            this->pontosTotal = pontosTotal;
            this->valorTotal = valorTotal;
            this->maxInteracoes = maxInteracoes;
        };

        void percorre(vector<Ponto>&pontos){
            int x, y, z;

            if(k > pontosTotal)
                return 0;

            vector<int> indiceProibido;

            for(x = 0; x < k; i++){
                while(true){
                    int indicePonto = rand()%pontosTotal;

                    if(find(indiceProibido.begin(), indiceProibido.end(), indicePonto) = indiceProibido.end()){
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
                bool feito = true;

                for(x = 0; x < pontosTotal; x++){
                    int idAntigoCluster = pontos[x].getCluster();
                    int idCentroProx = getIdProxCentro(pontos[x]);

                    //Se diferente o ponto mudou de grupo
                    if(idAntigoCluster != idCentroProx){
                        if(idAntigoCluster != -1)
                            clusters[idAntigoCluster].removePonto(pontos[x].getIdPonto());

                        pontos[x].setCluster(idCentroProx);
                        clusters[idCentroProx].adiconarPonto(ponto[x]);
                        feito = false;//pq mudou de grupo
                    }
                }
            }

            //Recalcular o centro de cada cluster
            for(x = 0; x < k; x++){
                for(y = 0; y < valorTotal; y++){
                    int totalPontosCluster = clusters[x].getTotalPontos();
                    double soma  = 0.0;

                    if(totalPontosCluster > 0){
                        for(z = 0; z < totalPontosCluster; z++){
                            soma += clusters[x].getPonto(z).getValores(y);
                        }
                        clusters[x].setValorCentral(y, soma/totalPontosCluster);
                    }
                }
            }

            if(feito == true || interacao >= maxInteracoes){
                cout << "Encerrando interação: " << interação << endl << endl;
                break;
            }
            interacao++;
            
            //Mostrar elementos no clusters
            for(x = 0; x < k; x++){
                int totalPontosCluster clusters[x].getTotalPontos();

                cout << "Cluster: " << clusters[x].getIdPonto + 1 << endl;

                for(y = 0; y < totalPontosCluster; y++){
                    cout << "Ponto: " << clusters[x].getPonto(j).getIdPonto() + 1 << ": ";
                    for(z = 0; z < valorTotal; z++){
                        cout << clusters[x].getPonto(y).getValores(z) << " ";
                    }
                    string nomePonto = clusters[x].getPonto(y).getNome();

                    if(nomePonto != "")
                        cout << " - " << nomePonto;
                }   
                cout << endl;
            }

            cout << "Valores Cluster: ";
            for(y = 0; y < valorTotal; y++)
                cout << clusters[y].getValorCentral(y) << " ";
        }   cout << endl << endl;

};