#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;



void mezclar2vectores(const vector<int> &arreglo1,const vector<int> &arreglo2, vector<int> &arreglo3)
{
    int x1=0, x2=0;

    while (x1<arreglo1.size() && x2<arreglo2.size()) {
        if (arreglo1[x1]<arreglo2[x2]) {
            arreglo3.push_back(arreglo1[x1]);
            x1++;
        }
        else if( arreglo1[x1]>arreglo2[x2] ) {
            arreglo3.push_back(arreglo2[x2]);
            x2++;
        }
        else{
          arreglo3.push_back(arreglo1[x1]);
          x1++;
          x2++;
        }
    }
    while (x1<arreglo1.size()) {
        arreglo3.push_back(arreglo1[x1]);
        x1++;
    }
    while (x2<arreglo2.size()) {
        arreglo3.push_back(arreglo2[x2]);
        x2++;
    }
}




vector<int> mezclarKvectores(vector<vector<int>> v){

  vector<vector<int>> v1;
  vector<vector<int>> v2;
  vector<int> r1;
  vector<int> r2;
  vector<int> r;

  if(v.size() > 2){

    for(int i = 0; i < v.size(); i++){
      if(i < v.size()/2){
        v1.push_back(v[i]);
      }
      else{
        v2.push_back(v[i]);
      }
    }

    r1 = mezclarKvectores(v1);
    r2 = mezclarKvectores(v2);
  }
  else{
    r1 = v[0];
    r2 = v[1];
  }

  mezclar2vectores(r1, r2, r);

  return r;
}

int main(int argc , char *argv[]){

    vector<vector<int>> matriz;
    vector<int> v,mezcla;
    high_resolution_clock::time_point tantes,tdespues;
    duration<double> tiempo_transcurrido;
    int j = 0;

    if(argc != 3){
      cout << endl << "Introduce el nombre del programa, el numero de vectores, y el tamaño de los vectores." << endl;
      return -1;
    }

    int tam = atoi(argv[2]);
    int nvectores = atoi(argv[1]);

    for(int i = 0; i < nvectores; i++){
      int fin = j+tam;
      while(j < fin){
        v.push_back(j);
        j++;
      }
      matriz.push_back(v);
      v.clear();
    }

    tantes = high_resolution_clock::now();
    mezcla = mezclarKvectores(matriz);
    tdespues = high_resolution_clock::now();

    tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
    cout << tam << " " << tiempo_transcurrido.count() << endl;

    return 0;
}
