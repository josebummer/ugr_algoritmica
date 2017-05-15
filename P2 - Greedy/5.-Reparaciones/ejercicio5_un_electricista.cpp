#include<iostream>
#include<queue>
using namespace std;

int main(){

  priority_queue<int,vector<int>, greater<int> > cola;
  vector<int> reparaciones;

  reparaciones.push_back(1);
  reparaciones.push_back(9);
  reparaciones.push_back(3);
  reparaciones.push_back(7);
  reparaciones.push_back(10);
  reparaciones.push_back(8);
  reparaciones.push_back(4);
  reparaciones.push_back(5);

  vector<int>::iterator it;
  cout << endl;
  cout << "----LISTA DE REPARACIONES PENDIENTES----" << endl;
  for(it = reparaciones.begin(); it != reparaciones.end(); ++it){
    cout << "Reparacion de duración "<< *it << endl;
  }
  cout << endl;
  for(it = reparaciones.begin(); it != reparaciones.end(); ++it){
    cola.push(*it);
  }
  cout << "----ORDEN EN EL QUE EL ELECTRICISTA ELIGE LAS REPARACIONES----" << endl;
  while(!cola.empty()){
    cout << "Electricista elige reparación de duración: " << cola.top() << endl;
    cola.pop();
  }



  return 0;
}
