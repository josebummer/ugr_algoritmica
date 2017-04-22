#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

int FuerzaBruta(const vector<int> &v){
  int inv = 0;
  for(int i = 0; i < v.size()-1; i++)
    for(int j = i+1; j < v.size(); j++)
      if(v[i] > v[j]) inv++;
  return inv;
}


int main(){

  vector<int> v;

  high_resolution_clock::time_point tantes,tdespues;
  duration<double> tiempo_transcurrido;

  for(int i = 1000000; i > 0; i-- ){
    v.push_back(i);
  }

  int tama = v.size();

  tantes = high_resolution_clock::now();
  int x = FuerzaBruta(v);
  tdespues = high_resolution_clock::now();

  cout << "Inversiones: " << x << endl;

  tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
  cout << "Tamaño: " << tama << " " << "Tiempo transcurrido: " << tiempo_transcurrido.count() << endl;

  return 0;

}
