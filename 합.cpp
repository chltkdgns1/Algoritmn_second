#include <iostream>
using namespace std;

int main() {
	int number;
	int temp = 0;
	cin >> number;
	for (int i = 1; i <= number; i++) {
		temp += i;
	}
	cout << temp << endl;
}