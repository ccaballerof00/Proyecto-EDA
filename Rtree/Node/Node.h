#ifndef PROYECTO_EDA_NODE_H
#define PROYECTO_EDA_NODE_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

struct MBR {

    vector<pair<double,double>> LimitesCordenadas;
    int CantidadDimensiones;

    //Iniciamos con la cantidad de dimensiones que vamos a utilizar
    MBR(int Cantidad_Dimensiones){
        this->CantidadDimensiones = Cantidad_Dimensiones;
    };

    void Generar_MBR( vector<pair<double,double>> Coordenaditas){

        vector<pair<double,double>> MBR_final;

        for(int i = 0; i < CantidadDimensiones;i++)
        {
            MBR_final.push_back(make_pair(1e7,-(1e7)));
        }
        for(auto i : Coordenaditas)
        {
            if(i.first < MBR_final[0].first)
            {
                MBR_final[0].first = i.first;
            }
            if(i.first > MBR_final[0].second)
            {
                MBR_final[0].second = i.first;
            }

            if(i.second < MBR_final[1].first)
            {
                MBR_final[1].first = i.second;
            }

            if(i.second > MBR_final[1].second)
            {
                MBR_final[1].second = i.second;
            }

        }

        LimitesCordenadas = MBR_final;
    }
};


#endif //PROYECTO_EDA_NODE_H
