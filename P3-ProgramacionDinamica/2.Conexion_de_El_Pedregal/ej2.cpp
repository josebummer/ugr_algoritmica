#include <iostream>
#include <cstdlib>

using namespace std;

#define INF -1;
#define N 5

void inicializarMatriz(int m[][N]){
  m[0][0] = 0;
  m[0][1] = 6;
  m[0][2] = 3;
  m[0][3] = INF;
  m[0][4] = INF;
  m[1][0] = 4;
  m[1][1] = 0;
  m[1][2] = INF;
  m[1][3] = 1;
  m[1][4] = INF;
  m[2][0] = INF;
  m[2][1] = INF;
  m[2][2] = 0;
  m[2][3] = 5;
  m[2][4] = 1;
  m[3][0] = INF;
  m[3][1] = 3;
  m[3][2] = INF;
  m[3][3] = 0;
  m[3][4] = INF;
  m[4][0] = INF;
  m[4][1] = INF;
  m[4][2] = INF;
  m[4][3] = 2;
  m[4][4] = 0;
}

void cabecera(char &letra){
  cout << "    ";
  for(int i = 0; i < N; i++){
    cout << letra << " ";
    letra+=1;
  }
  cout << endl << endl;
  letra = 'A';
}

int main(int argc, char const *argv[]) {

  //Descomentar para introducir los parametros a mostrar por pantalla

  // if(argc != 3){
  //   cout << "Debe poner dos parametros para indicar la fila y columna que quiere visualizar." << endl;
  //   return -1;
  // }
  //
  // int f = atoi(argv[1]);
  // int c = atoi(argv[2]);
  //
  // if(f < 0 || f > 4 || c < 0 || c > 4){
  //   cout << "La fila y columna deben ser >=0 y <=4." << endl;
  //   return -1;
  // }

  int M[N][N];
  int aux;

  //El grafo representado esta en el libro de Verdegay en la pag 233
  inicializarMatriz(M);

  char letra = 'A';
  cabecera(letra);

  for(int k = 0; k < N; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        aux = (M[i][k] < M[k][j])?M[i][k]:M[k][j];
        if((M[i][j] < aux) && (i != j)) M[i][j] = aux;
      }
    }
  }

  // cout << M[f][c] << endl;

  for(int i = 0; i < N; i++){
    cout << letra << "   ";
    letra+=1;
    for(int j = 0; j < N; j++){
      cout << M[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
