#include <iostream>
using namespace std;
int arr[11];
int index;
void itoArr(int n) {
	int sample[11] = { 0 };
	int i = 0;
	while (n != 0) {
		sample[i] = n % 10;
		i++;
		n = n / 10;
	}
	index = i;
	for (int j = 0; j < index; j++) {
		arr[j] = sample[i - 1];
		i--;
	}
}

int main() {
	int n;
	cin >> n;
	itoArr(n);
	int right= 1;
	int left = 1;
	for (int i = 0; i < index - 1; i++) {
		left *= arr[i];
		for (int j = i + 1; j < index; j++) {
			right *= arr[j];
		}
		if (left == right) {
			cout << "YES" << endl;
			return 0;
		}
		right = 1;
	}
	cout << "NO" << endl;
}