#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void combinar(const vector<int> &arreglo1,const vector<int> &arreglo2, vector<int> &arreglo3)
{
    int x1=0, x2=0;

    while (x1<arreglo1.size() && x2<arreglo2.size()) {
        if (arreglo1[x1]<arreglo2[x2]) {
            arreglo3.push_back(arreglo1[x1]);
            x1++;
        }
        else if( arreglo1[x1]>arreglo2[x2] ) {
            arreglo3.push_back(arreglo2[x2]);
            x2++;
        }
        else{
          arreglo3.push_back(arreglo1[x1]);
          x1++;
          x2++;
        }
    }
    while (x1<arreglo1.size()) {
        arreglo3.push_back(arreglo1[x1]);
        x1++;
    }
    while (x2<arreglo2.size()) {
        arreglo3.push_back(arreglo2[x2]);
        x2++;
    }
}

void elimRepetidos(vector<int> &v)
{
    vector<int> vector1;
    vector<int> vector2;
    int n1, n2,i,j;

    if (v.size() > 1)
    {
        if (v.size()%2 == 0)
            n1=n2=(int) v.size() / 2;
        else
        {
            n1=(int) v.size() / 2;
            n2=n1+1;
        }
        for(i=0;i<n1;i++)
            vector1.push_back(v[i]);
        for(j=0;j<n2;i++,j++)
            vector2.push_back(v[i]);
        v.clear();
        elimRepetidos(vector1);
        elimRepetidos(vector2);
        combinar(vector1, vector2, v);
    }
}

int main(int argc , char *argv[]){
    vector<int> cad;
    high_resolution_clock::time_point tantes,tdespues;
    duration<double> tiempo_transcurrido;

    int tam = atoi(argv[1]);
    for( int i = tam ; i > 0; i-- ){
      cad.push_back(i);
      cad.push_back(i);
    }

    tantes = high_resolution_clock::now();
    elimRepetidos(cad);
    tdespues = high_resolution_clock::now();

    tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
    cout << cad.size() << " " << tiempo_transcurrido.count() << endl;

    return 0;
}
