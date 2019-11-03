#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int number;
	cin >> number;
	int *array = new int[number + 1];
	for (int i = 0; i < number; i++) cin >> array[i];
	for (int i = 0; i < number; i++) cout << array[i] << endl;
}
