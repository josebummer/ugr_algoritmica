#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

class Nodo{
public:
  Nodo(char v, Nodo *p, int h){
    valor = v;
    padre = p;
    nhijos = h;
  }
  Nodo(const Nodo &n){
    valor = n.getValor();
    padre = n.getPadre();
    nhijos = n.getHijos();
  }
  char getValor() const{
    return valor;
  }
  Nodo* getPadre() const{
    return padre;
  }
  int getHijos() const{
    return nhijos;
  }
  void eliminarHijo(){
    nhijos--;
  }
  bool operator <(const Nodo &otro) const{
    return (this->nhijos <= otro.getHijos());
  }
  bool operator ==(const Nodo &otro) const{
    return (valor == otro.valor && padre == otro.getPadre());
  }
private:
  char valor;
  Nodo *padre;
  int nlados;
  int nhijos;
};

int main(){
  set<Nodo> candidatos;
  set<Nodo> aux;
  unordered_set<char> solucion;

  Nodo a('A',0,3);
  Nodo b('B',&a,1);
  Nodo c('C',&a,0);
  Nodo d('D',&a,2);
  Nodo e('E',&b,1);
  Nodo f('F',&d,0);
  Nodo g('G',&d,0);
  Nodo h('H',&e,0);

  candidatos.insert(a);
  candidatos.insert(b);
  candidatos.insert(c);
  candidatos.insert(d);
  candidatos.insert(e);
  candidatos.insert(f);
  candidatos.insert(g);
  candidatos.insert(h);

  set<Nodo>::iterator p;
  set<Nodo>::iterator ab;

  while(candidatos.begin()->getPadre() != 0 && !candidatos.empty()){
    solucion.insert(candidatos.begin()->getPadre()->getValor());
    if( candidatos.begin()->getPadre()->getHijos() <= 1 ){
      bool salir = false;
      for( auto it = candidatos.begin(); it != candidatos.end() && !salir; ++it ){
        if(candidatos.begin()->getPadre()->getValor() == it->getValor()){
          p = it;
          salir = true;
        }
      }
      if(candidatos.begin()->getPadre() != 0 ){
        if(candidatos.begin()->getPadre()->getPadre() != 0){
          if(candidatos.begin()->getPadre()->getPadre()->getHijos() > 1){
            candidatos.begin()->getPadre()->getPadre()->eliminarHijo();
          }
          else{
            salir = false;
            for( auto it = candidatos.begin(); it != candidatos.end() && !salir; ++it ){
              if(candidatos.begin()->getPadre()->getPadre()->getValor() == it->getValor()){
                ab = it;
                salir = true;
              }
            }
            candidatos.erase(ab);
          }
        }
      }
      candidatos.erase(p);
    }
    else{
      candidatos.begin()->getPadre()->eliminarHijo();
    }
    candidatos.erase(candidatos.begin());
    int tam = candidatos.size();
    candidatos.swap(aux);
    candidatos.clear();
    for( int i = 0; i < tam; i++ ){
      Nodo n = *(aux.begin());
      aux.erase(aux.begin());
      candidatos.insert(n);
    }
  }

  cout << endl;
  for(auto it = solucion.begin(); it != solucion.end(); ++it){
    cout << *it << " ";
  }
  cout << endl;

  return 0;
}
