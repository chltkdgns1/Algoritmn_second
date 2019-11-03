#include <iostream>
using namespace std;

int cnt = 0;

void Check(int number) {
	int array[4];
	int temp = number;
	int i = 0;
	while (number / 10 != 0) {
		array[i] = number % 10;
		number = number / 10;
		i++;
	}
	array[2] = number;
	if (array[0] - array[1] == array[1] - array[2]) {
		cnt++;
	}
}

int main() {
	int n;
	cin >> n;
	if (n >= 100) {
		cnt = 99;
		for (int i = 100; i <= n; i++) {
			Check(i);
		}
		cout << cnt << endl;
	}
	else {
		cnt = n;
		cout << cnt << endl;
	}
}