#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Programa{
  public:
    int tamanio;
    float frecuencia;
    float x;

    Programa(int t, float f){
      tamanio = t;
      frecuencia = f;
      x = f/t;
    }
};


int main(){

  int n_program = 8;

  Programa P1(9, 0.2);
  Programa P2(5, 0.1);
  Programa P3(2, 0.05);
  Programa P4(7, 0.05);
  Programa P5(8, 0.3);
  Programa P6(4, 0.1);
  Programa P7(1, 0.125);
  Programa P8(6, 0.075);

  vector<Programa> programas;
  programas.push_back(P1);
  programas.push_back(P2);
  programas.push_back(P3);
  programas.push_back(P4);
  programas.push_back(P5);
  programas.push_back(P6);
  programas.push_back(P7);
  programas.push_back(P8);

  for(int i = 0; i < n_program; i++){
    cout << "( " << programas[i].tamanio << " , " << programas[i].frecuencia << " , " << programas[i].x << " )" << endl;
  }

//ORDEN NO DECRECIENTE PARA EL TAMAÑO

  vector<Programa> creciente_tam;

  creciente_tam.push_back(P7);
  creciente_tam.push_back(P3);
  creciente_tam.push_back(P6);
  creciente_tam.push_back(P2);
  creciente_tam.push_back(P8);
  creciente_tam.push_back(P4);
  creciente_tam.push_back(P5);
  creciente_tam.push_back(P1);

  int Ttotal=0;
  int Tparcial=0;

  for(int i = 0; i < n_program; i++){
    for(int j = 0; j < i; j++){
      Tparcial = Tparcial + creciente_tam[j].tamanio;
    }
    Ttotal = Ttotal + (creciente_tam[i].frecuencia*Tparcial);
    Tparcial = 0;
  }
  cout << "Tiempo medio con orden de tamaño no decreciente: " << Ttotal << endl;

//ORDEN NO CRECIENTE PARA LA FRECUENCIA

  vector<Programa> decreciente_frec;

  decreciente_frec.push_back(P5);
  decreciente_frec.push_back(P1);
  decreciente_frec.push_back(P7);
  decreciente_frec.push_back(P2);
  decreciente_frec.push_back(P6);
  decreciente_frec.push_back(P8);
  decreciente_frec.push_back(P3);
  decreciente_frec.push_back(P4);

  Ttotal=0;
  Tparcial=0;

  for(int i = 0; i < n_program; i++){
    for(int j = 0; j < i; j++){
      Tparcial = Tparcial + decreciente_frec[j].tamanio;
    }
    Ttotal = Ttotal + (decreciente_frec[i].frecuencia*Tparcial);
    Tparcial = 0;
  }
  cout << "Tiempo medio con orden de frecuencia no creciente: " << Ttotal << endl;

//ORDEN NO CRECIENTE DE FRECUENCIA/TAMAÑO

  vector<Programa> decreciente_x;

  decreciente_x.push_back(P7);
  decreciente_x.push_back(P5);
  decreciente_x.push_back(P3);
  decreciente_x.push_back(P6);
  decreciente_x.push_back(P1);
  decreciente_x.push_back(P2);
  decreciente_x.push_back(P8);
  decreciente_x.push_back(P4);

  Ttotal=0;
  Tparcial=0;

  for(int i = 0; i < n_program; i++){
    for(int j = 0; j < i; j++){
      Tparcial = Tparcial + decreciente_x[j].tamanio;
    }
    Ttotal = Ttotal + (decreciente_x[i].frecuencia*Tparcial);
    Tparcial = 0;
  }
  cout << "Tiempo medio con orden de frecuencia/tamaño no creciente: " << Ttotal << endl;

  return 0;
}
