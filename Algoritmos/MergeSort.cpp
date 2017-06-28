/*
Implementaciones de distintos algoritmos.

Realizados por: Jose Antonio Ruiz Millan

Algoritmica 2016/2017
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <ctime>

using namespace std;

//Asumimos que el vector es de tamaño 2^n

void combinar(const vector<int> &izq, const vector<int> &der, vector<int> &res){
	int i1 = 0, i2 = 0;
	res.clear();
	
	while( i1 < izq.size() && i2 < der.size()){
		if(izq[i1] < der[i2]){
			res.push_back(izq[i1]);
			i1++;
		}
		else{
			res.push_back(der[i2]);
			i2++;
		}	
	}
	if(i1 == izq.size() && i2 != der.size()){
		while(i2 < der.size()){
			res.push_back(der[i2]);
			i2++;
		}
	}
	if(i2 == der.size() && i1 != izq.size()){
		while(i1 < izq.size()){
			res.push_back(izq[i1]);
			i1++;
		}
	}
}

void dividir(const vector<int> &v, vector<int> &izq, vector<int> &der){
	int mitad = v.size()/2;
	izq.clear();
	der.clear();
	
	for(int i = 0 ; i < mitad; i++){
		izq.push_back(v[i]);
	}
	for(int i = mitad ; i < v.size(); i++){
		der.push_back(v[i]);
	}
}

void MergeSort(vector<int> &v){
	vector<int> izq,der;
	if(v.size() != 1){
		dividir(v,izq,der);
		MergeSort(izq);
		MergeSort(der);
		combinar(izq,der,v);
	}	
}

int main(){
	srand (time(NULL));
	
	vector<int> v;
	int n;
	
	for(int i = 0; i < 2048; i++){
		n = rand()%500;
		v.push_back(n);
	}
	
	cout << "for sin ordenar: " << endl;
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	
	MergeSort(v);
	cout << "for ordenado: " << endl;
	
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	
}
