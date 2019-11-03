#include <iostream>  
#include <string>  
#include <math.h>

using namespace std;

int main()
{

	int arr[5] = { 0, };
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	int answer = 0;
	for (int i = 1; i < 1000000; i++) {
		int res = 3;
		for (int j = 0; j < 5; j++) {
			if (i%arr[j] == 0) {
				res--;
			}
			if (res == 0) {
				cout << i;
				return 0;
			}
		}
	}

	return 0;
}
