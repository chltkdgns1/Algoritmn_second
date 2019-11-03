#include <iostream>
#include <algorithm>
using namespace std;
int arr[8];
int brr[8];
int index[5];
int main() {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
		brr[i] = arr[i];
	}
	sort(arr, arr + 8);
	int sum = 0;
	for (int i = 3; i < 8; i++) sum += arr[i];
	for (int i = 0; i < 8; i++) {
		for (int j = 3; j < 8; j++) {
			if (brr[i] == arr[j]) {
				index[cnt] = i;
				cnt++;
			}
		}
	}
	sort(index, index + 5);
	cout << sum << endl;
	for (int i = 0; i < 5; i++) cout << index[i] + 1 << " ";
	cout << endl;
	system("pause");
}