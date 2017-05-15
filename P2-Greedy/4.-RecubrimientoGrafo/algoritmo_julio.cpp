#include <iostream>
#include <list>
#include <queue>
using namespace std;


class Nodo{
public:
  int prioridad;
  char nombre;
  list<char> adyacentes;

  Nodo(char c, list<char> ady){
    adyacentes = ady;
    nombre = c;
    prioridad = ady.size();
  }
};


bool comparar ( const Nodo& first, const Nodo& second)
{
  return ( first.prioridad > second.prioridad );
}





list<Nodo> recubrimiento_minimo( list<Nodo> &grafo ){

  for( list<Nodo>::iterator it = grafo.begin(); it != grafo.end(); ++it ){
    if( it->adyacentes.size() == 1 ) {
      for( list<Nodo>::iterator it2 = grafo.begin(); it2 != grafo.end(); ++it2 ){
        if( *(it->adyacentes.begin() ) == it2->nombre) {  it2->prioridad = 100000000;
        cout << it2->nombre << " dopado" << it2->prioridad << endl;
        it2->prioridad = 10000;
      }
      }
    }

  }

  grafo.sort(comparar);


  for( list<Nodo>::iterator it = grafo.begin(); it != grafo.end(); ++it ){
    cout << it->nombre << "_" << it->prioridad << "___";
  }
  list<Nodo> solucion;
  int total = 0;

  list<Nodo>::iterator it = grafo.begin();
int tam = grafo.size();
  while( total < tam ){
    cout << total << "-" << tam << endl;
    solucion.push_back(*it);
    total+=(it->adyacentes.size());
    total++;


      for( list<char>::iterator itc = it->adyacentes.begin(); itc != it->adyacentes.end(); ++itc ){
        for( list<Nodo>::iterator itt = grafo.begin(); itt != grafo.end(); ++itt ){
          cout << *itc << " comparo con " << itt->nombre << endl;
          if( *itc == itt->nombre ){
            cout << "333" << *itc << "-" << itt->nombre << "--" << itt->prioridad << endl;
            itt->prioridad--;
          }
        }
      }


    grafo.erase(it);
    grafo.sort(comparar);
    it = grafo.begin();


  }

  return solucion;

}



int main(){
  list<char> l;
  l.push_back('b');
  l.push_back('h');
  Nodo a('a',l);

  l.clear();
  l.push_back('c');
  l.push_back('a');
l.push_back('e');
  Nodo b('b',l);

  l.clear();
  l.push_back('f');
  Nodo g('g',l);

  l.clear();
  l.push_back('c');
  l.push_back('i');
  Nodo d('d',l);


  l.clear();
  l.push_back('g');
  l.push_back('e');
  Nodo f('f',l);

  l.clear();
  l.push_back('f');
  l.push_back('b');
    l.push_back('c');
  Nodo e('e',l);

  l.clear();
  l.push_back('a');
  Nodo h('h',l);

  l.clear();
  l.push_back('d');
  Nodo i('i',l);

  l.clear();
  l.push_back('b');
  l.push_back('e');
 l.push_back('d');
  Nodo c('c',l);



  list<Nodo> grafo;
  grafo.push_back(d);
  grafo.push_back(a);
  grafo.push_back(f);
  grafo.push_back(b);
  grafo.push_back(g);

  grafo.push_back(h);
  grafo.push_back(i);

  grafo.push_back(c);
  grafo.push_back(e);

  list<Nodo> sol = recubrimiento_minimo(grafo);
  cout << "Solución: " << endl << endl << endl;
  for( list<Nodo>::iterator it = sol.begin(); it != sol.end(); ++it ){
    cout << it->nombre << endl;
  }

}
