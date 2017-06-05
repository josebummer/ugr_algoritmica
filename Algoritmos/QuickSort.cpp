#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int mayor(int uno,int dos, int &pos){
	int m = (uno > dos)?uno:dos;
	pos = (m == uno)?0:1;
	return m;
}

int pivoteo(vector<int> &v, int ini, int fin){
	int i;
	int p = mayor(v[ini],v[ini+1],i);
	i = (i == 0)?ini:ini+1;
	
	int k = i;
	int j = fin+1;
	int l = fin;
	while(k < l){
		while(v[l] > p){
			l--;
		}
		while(k < l && v[k] <= p){
			k++;
		}
		if( k < l){
			int aux = v[k];
			v[k] = v[l];
			v[l] = aux;	
		}
	}
	int aux = v[i];
	v[i] = v[l];
	v[l] = aux;
	
	return l;
}

void insercion(vector<int> &v){
	if(v.size() != 1){
		int min;
		int pos;
	
		for(int j = 0; j < v.size();j++){
			min = v[j];
			pos = j;
			for(int i = j; i < v.size(); i++){
				if( min > v[i] ){
					min = v[i];
					pos = i;
				}
			}
			int aux = v[j];
			v[j] = min;
			v[pos] = aux;	
		}	
	}
}

void QuickSort(vector<int> &v, int ini, int fin){
	if((fin-ini) > 128){
		int pivote = pivoteo(v,ini,fin);
//		for(int i =ini; i <= fin;i++){
//			cout << v[i] << " ";
//		}
//		cout << endl << "pivote " << pivote << " ini " << ini << " fin " << fin << endl;
//		cin.get();
		QuickSort(v,ini,pivote-1);
		QuickSort(v,pivote+1,fin);
	}
	else{
		insercion(v);
	}
}

int main(){
	srand (time(NULL));
	
	vector<int> v;
	int n;
	
	for(int i = 0; i < 1000; i++){
		n = rand()%1000;
		v.push_back(n);
	}
	
	cout << "for sin ordenar: " << endl;
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	
	QuickSort(v,0,v.size()-1);
//	insercion(v);
	
	cout << "for ordenado: " << endl;
	
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	
	return 0;
}
