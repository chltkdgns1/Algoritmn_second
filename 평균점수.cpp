#include <iostream>
using namespace std;

int main() {
	int array[6];
	int temp = 0;
	for (int i = 0; i < 5; i++) {
		cin >> array[i];
		if (array[i] < 40) array[i] = 40;
		temp += array[i];
	}
	cout << temp / 5 << endl;
}