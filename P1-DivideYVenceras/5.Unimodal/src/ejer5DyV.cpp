#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

/*

  v = {1, 2, 3, 4, 5, 6, 5, 4, 3}

*/

int unimodal(const vector<int> &v,int ini, int fin){

  int p = 0;
  vector<int> v1;
  int mitad;
  mitad = (ini+fin)/2;

  if((fin-ini) > 2){
    if( v[mitad-1] < v[mitad] && v[mitad+1] > v[mitad] ){
      p = unimodal(v,mitad+1,fin);
    }
    else if( v[mitad-1] > v[mitad] && v[mitad+1] < v[mitad] ){
      p = unimodal(v,ini,mitad-1);
    }
    else if(v[mitad-1] < v[mitad] && v[mitad+1] < v[mitad] ){
      p = v[mitad];
    }
  }
  else if( v[mitad-1] < v[mitad] && v[mitad+1] < v[mitad] ){
    p = v[mitad];
  }

  return p;
}

int main(int argc, char *argv[]){

  int r;
  vector<int> v;

  high_resolution_clock::time_point tantes,tdespues;
  duration<double> tiempo_transcurrido;

  if(argc != 2){
    cout << endl << "Introduce el numero de elementos del vector." << endl;
    return -1;
  }

  int n = atoi(argv[1]);
  for(int i=0; i<n; i++){
      v.push_back(i);
  }

  tantes = high_resolution_clock::now();
  r = unimodal(v,0,v.size()-1);
  tdespues = high_resolution_clock::now();

  tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
  cout << n << " " << tiempo_transcurrido.count() << endl;
  
  return 0;

}
