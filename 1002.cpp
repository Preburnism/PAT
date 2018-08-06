#include <iostream>

using namespace std;
//
int main(){
	int k = 0, k1, k2;
	int n;
	double temp;
	double a[1001] = { 0 };

	cin >> k1;
	for (int i = 0; i < k1; i++){	
		cin >> n;
		cin >> temp;
		a[n] += temp;
	}

	cin >> k2;
	for (int i = 0; i < k2; i++){
		cin >> n;
		cin >> temp;
		a[n] += temp;
	}
	for (int i = 0; i < 1001; i++){
		if (a[i] != 0)
			k++;
	}
	cout << k;
	for (int i = 1000; i >= 0; i--){
		if (a[i] != 0){
			printf(" %d %.1f", i, a[i]);
		}
	}
	return 0;
}