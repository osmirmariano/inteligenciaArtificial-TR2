#ifndef PONTO_H
#define PONTO_H

#include <iostream>
#include <vector>

using namespace std;

class Ponto{
    private: 
        int idPonto, idCluster;
        vector<double> valores; //Conjunto de atributos
        //int totalValores;
        string nome;//Teste

    public:
        //Construtor
        Ponto(int idPonto, vector<double>& valores, string nome = ""){
            int x;
            this->idPonto = idPonto;
            //totalValores = valores.size();
            
            for(x = 0; x < valores.size(); x++){
                this->valores.push_back(valores[x]);
            }
            this->nome = nome;
            idCluster = -1; //Incialmente não tem cluster por isso -1
        }

        //Pega atributo idPonto
        int getIdPonto(){
            return idPonto;
        }

        void setCluster(int idCluster){
            this->idCluster = idCluster;
        }

        int getCluster(){
            return idCluster;
        }

        double getValores(int a){
            return valores[a];
        }

        int getTotalValores(){
            return valores.size();
        }

        void adicionarValores(double valor){
            valores.push_back(valor);
        }

        string getNome(){
            return nome;
        }
};
#endif //PONTO