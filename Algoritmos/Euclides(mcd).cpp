/*
Implementaciones de distintos algoritmos.

Realizados por: Jose Antonio Ruiz Millan

Algoritmica 2016/2017
*/

#include <iostream>

using namespace std;

//Asumimos que m > n
int mcdEuclides(int m, int n){
	int t;
	while(m > 0){
		t = m;
		m = n%m;
		n = t;
	}
	return n;
}

int main(){
	int m = 468;
	int n = 221;
	
	cout << "mcd(" << m << "," << n << ") = " << mcdEuclides(m,n) << endl;
	
	return 0;
}
