#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace std::chrono;

bool bBinaria(const vector <int> &arr){


    for(int i=0; i<arr.size(); i++){
	    if(arr[i]==i){
		      return true;
	    }
    }

    return false;

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
    for(int i=1; i<=n/2; i++){
        arr.push_back(n/2+i);
        arr.push_back(n/2+i);
        arr.push_back(n/2+i);
        arr.push_back(n/2+i);
    }

    tantes = high_resolution_clock::now();
    resultado = bBinaria(arr);
    tdespues = high_resolution_clock::now();

    tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
    cout << n << " " << tiempo_transcurrido.count() << endl;

    return 0;
}
