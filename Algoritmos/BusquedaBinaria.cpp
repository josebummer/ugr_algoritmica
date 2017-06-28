/*
Implementaciones de distintos algoritmos.

Realizados por: Jose Antonio Ruiz Millan

Algoritmica 2016/2017
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//devuelve la posicion del elemento a buscar
//se asume que en vector esta de forma creciente y sin elementos repetidos
int bbinaria(int elem, const vector<int> &v, int ini, int fin){
	int mitad = (ini + fin)/2;
	if( v[mitad] == elem ) return mitad;
	if(ini < fin){
		if( v[mitad] < elem ) return bbinaria(elem,v,mitad+1,fin);
		if( v[mitad] > elem ) return bbinaria(elem,v,ini,mitad-1);	
	}
	return -1;
}

int main(){
	srand (time(NULL));
	
	vector<int> v;
	
	for(int i = 100; i < 500; i++){
		v.push_back(i);
	}
	
	int elem = 324;
	cout << "El elemento se encuentra en la pos: " << bbinaria(elem,v,0,v.size()-1) << endl;
	
	return 0;
}
