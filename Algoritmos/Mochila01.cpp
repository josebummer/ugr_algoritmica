/*
Problema de la mochila 0-1 donde N determina el numero de elementos y WM el tamaño maximo de la mochila, editar estos valores para cambiar el resultado.
En el main se encutran los vectores donde van almacenadas las ganancias y los pesos de los elementos. Modificarlos para cambiar el resultado.

Implementaciones de distintos algoritmos.

Realizados por: Jose Antonio Ruiz Millan

Algoritmica 2016/2017
*/

#include <iostream>
#include <vector>

using namespace std;

#define N 4
#define WM 5

int mochila(int W, const vector<int> &w, const vector<int> &b){
	int M[N+1][WM+1];
	int n = w.size();
	
	for(int i = 0 ; i <= n;i++){
		M[i][0] = 0;
	}
	for(int i = 0; i <= W; i++){
		M[0][i] = 0;
	}
	
	for(int i = 1; i <= n;i++){
		for(int j = 1; j <= W; j++){
			if(w[i-1] <= j)
				M[i][j] = (M[i-1][j] > M[i-1][j-w[i-1]]+b[i-1])?M[i-1][j]:M[i-1][j-w[i-1]]+b[i-1];
			else
				M[i][j] = M[i-1][j];
		}
	}
//	for(int i = 0; i <= n;i++){
//		for(int j = 0; j <= W; j++){
//			cout << M[i][j] << "\t";
//		}
//		cout << endl;
//	}
//	cout << endl;
	
	return M[n][W];
}

int main(){
	vector<int> w,b;
	w.push_back(2);
	b.push_back(3);
	w.push_back(3);
	b.push_back(4);
	w.push_back(4);
	b.push_back(5);
	w.push_back(5);
	b.push_back(6);
	
	cout << mochila(WM,w,b) << endl;
}
