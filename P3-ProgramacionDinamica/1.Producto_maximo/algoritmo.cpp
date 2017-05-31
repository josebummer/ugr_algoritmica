#include <iostream>
using namespace std;


int MAX( int n, int C ){
  int T[n+1][C+1];
  for( int k=0; k<=n; k++ ){
    T[k][0] = 0;
  }
  for( int k=1; k<=C; k++ ){
    T[1][k] = k;
  }
  for( int k=2; k<=n; k++ ){
    for( int c=1; c<=C; c++ ){
      T[k][c] = 0;
      for( int x=1; x<=c; x++ ){
        if( x*T[k-1][c-x] > T[k][c] ) T[k][c] = x*T[k-1][c-x];
      }
    }
  }

  return T[n][C];
}

int main(){
  int sol = MAX(3,9);
  cout << "El producto máximo de 3 números que suman 9 es: " << sol << endl;
}
