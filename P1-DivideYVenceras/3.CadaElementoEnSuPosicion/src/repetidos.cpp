#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
using namespace std;
using namespace std::chrono;


bool en_su_posicion( const vector<int> &v, int ini, int fin, int &pos )
{
  int medio = (ini+fin)/2;
  if( v[medio] == medio ){
    pos = medio;
    return true;
  }

  if( ini - fin > 1 || ini - fin < -1 ){

    if( ( v[ini] > medio-1 || v[medio-1] < ini ) && ( v[medio+1] > fin || v[fin] < medio+1 ) ) return false;
    if( v[ini] > medio-1 || v[medio-1] < ini ) return en_su_posicion(v,medio+1,fin,pos);
    if( v[medio+1] > fin || v[fin] < medio+1 ) return en_su_posicion(v,ini,medio-1,pos);
    return ( en_su_posicion(v,medio+1,fin,pos) || en_su_posicion(v,ini,medio-1,pos) );

  }
  if( ini - fin == 1 || ini - fin == -1 ){
    return( v[ini] == ini || v[fin] == fin );
  }
  return false;
}



int main(int argc, char* argv[]){
  high_resolution_clock::time_point tantes,tdespues;
  duration<double> tiempo_transcurrido;

  vector<int> vec;
  int pos = 0;
  int n = atoi(argv[1]);

  for( int i=1; i<=n/2; i++ ){
    vec.push_back(n/2+i);
    vec.push_back(n/2+i);
    vec.push_back(n/2+i);
    vec.push_back(n/2+i);
  }

  tantes = high_resolution_clock::now();
  en_su_posicion(vec,0,vec.size()-1,pos);
  tdespues = high_resolution_clock::now();

  tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
  cout << n << " " << tiempo_transcurrido.count() << endl;

  return 0;
}
