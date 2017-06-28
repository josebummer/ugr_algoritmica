/*
Implementaciones de distintos algoritmos.

Realizados por: Jose Antonio Ruiz Millan

Algoritmica 2016/2017
*/

#include <iostream>

using namespace std;

int multRusa(int multiplicador, int multiplicando){
	int total=0;
	
	while(multiplicador>0){
		if(multiplicador%2!=0){
			total+=multiplicando;
		}
		multiplicador>>=1;
		multiplicando<<=1;
	}
	return total;
}

int main(){
	
	int i=128;
	int j=254;
	
	cout << i << "x" << j << " = " << multRusa(i,j) << endl;
	cout << i << "x" << j << " = " << i*j << endl;
	return 0;
}
