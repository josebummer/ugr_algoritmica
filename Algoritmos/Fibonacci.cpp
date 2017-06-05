#include <iostream>

using namespace std;

int fibpd(int n){
	int F[n+1];
	F[0] = 0; F[1] = 1;
	for(int i = 2; i <= n; i++){
		F[i] = F[i-1]+F[i-2];
	}
	return F[n];
}

int fib(int n){
	if(n < 2 ) return n;
	return fib(n-1) + fib(n-2);
}

int main(){
	int n = 45;
	
	cout << "Fibonacci " << n << ": " << fibpd(n) << endl;
	cout << "Fibonacci " << n << ": " << fib(n) << endl;
	
	return 0;
}
