#include <iostream>
#include <algorithm>
using namespace std;
int arr[9];
int main() {
	int sum = 0, number;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				arr[i] = arr[j] = 100;
				sort(arr, arr + 9);
				for (int i = 0; i < 7; i++) cout << arr[i] << endl;
			}
		}
	}
}