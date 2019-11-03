#include <iostream>
using namespace std;
int arr[100];
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int max = 0;
	for (int i = 1; i <= a; i++) {
		for (int k = 1; k <= b; k++) {
			for (int j = 1; j <= c; j++) {
				arr[j + k + i]++;
				if (max < arr[j + k + i]) {
					max = arr[j + k + i]; 
				}
			}
		}
	}
	for (int i = 1; i <= a + b + c; i++) {
		if (max == arr[i]) {cout << i << "\n"; break;}
	}
}