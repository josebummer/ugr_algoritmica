#include<iostream>
#include<list>
#include<vector>
using namespace std;


list<int> visitas_proveedor_greedy( const list<int> &tienda_abierta, int dias_que_aguanto, int dias_totales ){
  // Éste método devuelve una lista de enteros que corresponden a los números de día que el granjero tiene que comprar fertilizante
  // El algoritmo empieza desde el primer día que abre la tienda. (tienda_abierta contiene el 0)

  // tienda_abierta es una lista de enteros que corresponden a los números de día que la tienda abre.
  // dias_que_aguanto es un entero que corresponde con el número de días que el granjero aguanta sin fertilizante
  // días totales es el número total de días para el que cual se quiere programar las visitas_proveedor_greedy


  // False significa que ese día la tienda no abre. True que sí lo hace.

  // Primero inicializamos a false todos los días
  vector<bool> dias;
  for( int i = 0; i < dias_totales; i++ ){
    dias.push_back(false);
  }

  // Ponemos como true los días que la tienda sí abre.
  // Se presupone que la distancia entre los elementos true es menor o igual a dias_que_aguanto
  for( list<int>::const_iterator it = tienda_abierta.begin(); it != tienda_abierta.end(); ++it ){
    dias[*it] = true;
  }



  // Solucionamos el problema mediante un algoritmo greedy
  list<int> solucion;
  bool fin = false;
  int i = 0;
  int j;
  int dia_sol;
  solucion.push_back(i);

  while( !fin ){

    for( j = i+1; j <= dias_que_aguanto+i && j < dias_totales; j++ ){
      if( dias[j] == true ) dia_sol = j;
      if( j == dias_totales-1 ) fin = true;
    }

    i = dia_sol;
    solucion.push_back(dia_sol);
  }

  return solucion;
}



int main(){

  int dias_totales = 30;
  int dias_que_aguanto = 4;

  list<int> tienda_abierta;
  // Días que la tienda abre: 0, 2, 3, 6, 9, 10, 13, 14, 15, 19, 21, 23, 27, 28, 29

  tienda_abierta.push_back(0);
  tienda_abierta.push_back(2);
  tienda_abierta.push_back(3);
  tienda_abierta.push_back(6);
  tienda_abierta.push_back(9);
  tienda_abierta.push_back(10);
  tienda_abierta.push_back(13);
  tienda_abierta.push_back(14);
  tienda_abierta.push_back(15);
  tienda_abierta.push_back(19);
  tienda_abierta.push_back(21);
  tienda_abierta.push_back(23);
  tienda_abierta.push_back(27);
  tienda_abierta.push_back(28);
  tienda_abierta.push_back(29);


  list<int> solucion;
  solucion = visitas_proveedor_greedy( tienda_abierta, dias_que_aguanto, dias_totales );

  cout << "Solución: El granjero debe comprar los días: ";
  for( list<int>::iterator it = solucion.begin(); it != solucion.end(); ++it ){
    cout << *it << " ";
  }

  cout << endl;

}
