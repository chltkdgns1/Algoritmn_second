#include <iostream>
using namespace std;

int main() {
	int cnt = 2;
	int test_data = 2;
	int col;
	int a = 1, b = 1;
	cin >> col;
	if (col == 1) {
		cout << a << " " << b << endl;
		return 0;
	}
	a++;
	int data = a;
	while (1) {
		for (int i = 0; i < test_data; i++) {
			if (cnt == col) {
				cout << a << " " << b << endl;
				return 0;
			}
			cnt++;
			a--;
			b++;
		}
		test_data++;
		a = data + 1;
		b = 1;
		data++;
	}
}