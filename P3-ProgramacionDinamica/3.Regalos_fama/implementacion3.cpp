#include<iostream>
#include<vector>
using namespace std;

int main(){

  bool S[100][100];
  bool marca[100][100];
  vector<int> P;
  //int D = 18; //FALSE
  int D = 14; //TRUE
  int n = 5;

  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= (D/2); j++){
      S[i][j] = false;
      marca[i][j] = false;
    }
  }

  P.push_back(2);
  P.push_back(2);
  P.push_back(3);
  P.push_back(3);
  //P.push_back(8);//FALSE
  P.push_back(4);//TRUE

  for(int k = 0; k <= n; k++){
    S[0][k] = true;
  }
  for(int m = 1; m < (D/2); m++){
    S[m][0] = false;
  }
  for(int k = 1; k <= n; k++){
    for(int m = 1; m <= (D/2); m++){
      if(m < P[k]){
        S[m][k] = S[m][k-1];
        marca[m][k] = false;
      }
      else if( ( S[m - P[k]][k-1] == true ) && ( ( (m - P[k]) >= 0) && ( (k-1) >= 0 ) ) ){
        S[m][k] = true;
        marca[m][k] = true;
      }
      else{
        S[m][k] = S[m][k-1];
      }
    }
  }

  if(S[D/2][n] == true) cout << "TRUE" << endl;
  else cout << "FALSE" << endl;

  return 0;
}
