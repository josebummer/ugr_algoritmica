#include <iostream>
#include <vector>
#include<chrono>
using namespace std;
using namespace std::chrono;



void eliminar_repetidos( vector<int> &vec ){
  vector<int> sinrep;
  bool encontrado = false;

  for( unsigned int i=0; i<vec.size(); i++ ){
    for( unsigned int j=i+1; j<vec.size(); j++ ){
      if( vec[i] == vec[j] ){
        encontrado = true;
      }
    }
    if( !encontrado ) sinrep.push_back(vec[i]);
    encontrado = false;
  }

  vec.clear();
  for( unsigned int i=0; i<sinrep.size(); i++ ){
    vec.push_back(sinrep[i]);
  }

}




int main(int argc , char *argv[]){

  high_resolution_clock::time_point tantes,tdespues;
  duration<double> tiempo_transcurrido;

  vector<int> v;
  int tam = atoi(argv[1]);
  for( int i = tam ; i > 0; i-- ){
      v.push_back(i);
      v.push_back(i);
  }

  tantes = high_resolution_clock::now();
  eliminar_repetidos(v);
  tdespues = high_resolution_clock::now();


  tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
  cout << v.size() << " " << tiempo_transcurrido.count() << endl;

return 0;
}
