#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;



void maximizaContenedores(vector < pair<int, int> > &v, vector < pair<int, int> > &s, int k)
{
    bool continua = true;
    int i = 0;

    while(continua){
        if(k-v[i].second >= 0){
             s.push_back(v[i]);
             k -= v[i].second;
             i++;
        }
        else{
             continua = false;
        }
    }
}

void maximizaToneladas(vector < pair<int, int> > &v, vector < pair<int, int> > &s, int k)
{
    bool continua = true;
    int i = 0;

    while(continua){
        if(v[i].second > k && i < v.size()){
             i++;
        }
        else if(k-v[i].second >= 0 && i < v.size()){
             s.push_back(v[i]);
             k -= v[i].second;
             i++;
        }
        else{
             continua = false;
        }
    }
}



int main(int argc , char *argv[]){
    vector < pair<int, int> > menorPeso;
    vector < pair<int, int> > mayorPeso;
    vector < pair<int, int> > solucion1;
    vector < pair<int, int> > solucion2;
    int total = 0;    
    int k = atoi(argv[2]);//Toneladas del contenedor
    int tam = atoi(argv[1]);

    for( int i = tam ; i > 0; i-- ){
      mayorPeso.push_back(pair<int, int> (i, i));
    }

    for( int i = 0 ; i < tam; i++ ){
      menorPeso.push_back(pair<int, int> (i, i));
    }

    maximizaContenedores(menorPeso, solucion1, k);

     //Muestra objetos introducidos
     cout << "Optimiza Numero de contenedores para "  << k << " toneladas" <<endl;
     for( int i = 0 ; i < solucion1.size(); i++ ){
      total += solucion1[i].second;
      cout << "Contenedor " << solucion1[i].first << " con peso " << solucion1[i].second  <<" ---> Peso total = " << total << endl;
    }
     
     total = 0;

     maximizaToneladas(mayorPeso, solucion2, k);     
     
     cout << "----------------------------------------------"  << endl;
     cout << "Optimiza Numero de toneladas"  << endl;
     for( int i = 0 ; i < solucion2.size(); i++ ){
      total += solucion2[i].second;
      cout << "Contenedor " << solucion2[i].first << " con peso " << solucion2[i].second  <<" ---> Peso total = " << total << endl;
    }

    return 0;
}
