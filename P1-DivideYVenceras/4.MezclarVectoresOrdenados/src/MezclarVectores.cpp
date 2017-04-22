#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int> mezclarVectores(const vector<int> &arreglo1 , const vector<int> &arreglo2){
  int x1=0, x2=0;
  vector<int> arreglo3;

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
  return arreglo3;
}

int main(int argc , char *argv[]){

  int j = 1;
  vector<vector<int> > matriz;
  high_resolution_clock::time_point tantes,tdespues;
  duration<double> tiempo_transcurrido;
  vector<int> v,mezcla;

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

  mezcla = matriz[0];

  tantes = high_resolution_clock::now();
  for( int i = 1; i < matriz.size(); i++){
    mezcla = mezclarVectores(mezcla,matriz[i]);
  }
  tdespues = high_resolution_clock::now();

  tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
  cout << tam << " " << tiempo_transcurrido.count() << endl;

  return 0;
}
