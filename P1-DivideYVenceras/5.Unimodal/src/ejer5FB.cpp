#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

int unimodalFB(const vector<int> &v){
  for(int i = 1; i < v.size()-1; i++){
    if(v[i-1] < v[i] && v[i+1] < v[i]){
      return v[i];
    }
  }
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
  r = unimodalFB(v);
  tdespues = high_resolution_clock::now();

  tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
  cout << n << " " << tiempo_transcurrido.count() << endl;

  return 0;

}
