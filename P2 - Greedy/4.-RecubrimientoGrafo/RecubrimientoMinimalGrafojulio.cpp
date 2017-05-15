#include <iostream>
#include <queue>
#include <list>
#include <unordered_set>

using namespace std;

class funtor{
public:
  bool operator()( const pair<char,list<char> > &a , const pair<char,list<char> > &b ){
    return (a.second.size() < b.second.size());
  }
};

int main(){
  priority_queue<pair<char,list<char> >, vector<pair<char,list<char> > >, funtor > candidatos;
  list<char> solucion,aux;
  unordered_set<char> cargados;

  aux.clear();
  aux.push_back('B');
  aux.push_back('H');
  candidatos.push(pair<char,list<char> >('A',aux));
  aux.clear();
  aux.push_back('A');
  aux.push_back('C');
  aux.push_back('E');
  candidatos.push(pair<char,list<char> >('B',aux));
  aux.clear();
  aux.push_back('D');
  aux.push_back('E');
  //DESCOMENTAR PARA NO OPTIMO;
  aux.push_back('B');
  candidatos.push(pair<char,list<char> >('C',aux));
  aux.clear();
  aux.push_back('C');
  aux.push_back('I');
  candidatos.push(pair<char,list<char> >('D',aux));
  aux.clear();
  aux.push_back('B');
  aux.push_back('C');
  aux.push_back('F');
  candidatos.push(pair<char,list<char> >('E',aux));
  aux.clear();
  aux.push_back('G');
  aux.push_back('E');
  candidatos.push(pair<char,list<char> >('F',aux));

  //DESCOMENTAR PARA QUE NO DE LA SOLUCION OPTIMA

  aux.clear();
  aux.push_back('F');
  candidatos.push(pair<char,list<char> >('G',aux));
  aux.clear();
  aux.push_back('A');
  candidatos.push(pair<char,list<char> >('H',aux));
  aux.clear();
  aux.push_back('D');
  candidatos.push(pair<char,list<char> >('I',aux));

  int completo = candidatos.size();


  while(cargados.size() < completo){
    cargados.insert(candidatos.top().first);
    int ant = cargados.size();
    for(auto it = candidatos.top().second.begin(); it != candidatos.top().second.end(); ++it){
      cargados.insert(*it);
    }
    int des = cargados.size();
    if( ant != des ){
      solucion.push_back(candidatos.top().first);
    }
    candidatos.pop();
  }

  cout << endl;
  for(auto it = solucion.begin(); it != solucion.end(); ++it){
    cout << *it << " ";
  }
  cout << endl;

  return 0;
}
