#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace std::chrono;

bool bBinaria(const vector<int> &arr, int primero, int ultimo){
    int aux;
    bool res = false;

    aux = (primero+ultimo)/2;
    if(arr[aux]!=aux && (primero>=ultimo)){
	     return false;
    }

    if(arr[aux]==aux){
	     return true;
    }

    if(arr[aux]<aux){
	     res = bBinaria(arr, aux+1, ultimo);
    }

    else{
	     res = bBinaria(arr, primero, aux-1);
    }
    return res;
}

int main(int argc , char *argv[]){
    vector<int> arr;
    bool resultado;
    high_resolution_clock::time_point tantes,tdespues;
    duration<double> tiempo_transcurrido;

    if(argc != 2){
      cout << endl << "Introduce el numero de elementos del vector." << endl;
      return -1;
    }

    int n = atoi(argv[1]);
    for(int i=1; i<=n; i++){
        arr.push_back(i);
    }

    tantes = high_resolution_clock::now();
    resultado = bBinaria(arr, 0, arr.size()-1);
    tdespues = high_resolution_clock::now();

    tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
    cout << n << " " << tiempo_transcurrido.count() << endl;

    return 0;
}
