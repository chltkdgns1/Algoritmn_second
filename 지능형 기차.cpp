#include <iostream>
using namespace std;
int main() {
	int arr[4][2];
	for (int i = 0; i < 4; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	int data = 0 , max = 0;
	for (int i = 0; i < 4; i++) {
		data += arr[i][1] - arr[i][0];
		if (max < data) max = data;
	}
	cout << max << endl;
}