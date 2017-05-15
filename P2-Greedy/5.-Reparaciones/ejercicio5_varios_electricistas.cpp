#include<iostream>
#include<queue>
using namespace std;

int main(){

  priority_queue<int,vector<int>, greater<int> > cola;
  int n_electricistas=3;
  int n_reparaciones=8;
  vector<int> reparaciones;
  vector<int> electricista;

  reparaciones.push_back(1);
  reparaciones.push_back(9);
  reparaciones.push_back(3);
  reparaciones.push_back(7);
  reparaciones.push_back(10);
  reparaciones.push_back(8);
  reparaciones.push_back(4);
  reparaciones.push_back(5);

  cout << endl;
  cout << "----LISTA DE REPARACIONES PENDIENTES----" << endl;
  for(int i = 0; i < n_reparaciones; i++){
    cout << "Reparacion de duración "<< reparaciones[i] << endl;
  }
  cout << endl;
  for(int i = 0; i < n_reparaciones; i++){
    cola.push(reparaciones[i]);
  }


  while(!cola.empty()){
    for(int i = 0; i < n_electricistas && !cola.empty(); i++){
      electricista.push_back(cola.top());
      cout << "Electricista " << i << " elige reparación de duración " << electricista[i] << endl;
      cola.pop();
    }
    electricista.clear();
  }
  
  return 0;
}
