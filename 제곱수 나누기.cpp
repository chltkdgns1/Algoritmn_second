#include <iostream>
#include <math.h>
using namespace std;

int d[4] = { 4,9,25,49 };
int main() {
	int cnt = 0;
	long long number = 1000;
	for (int i = 8; i <= number; i++) {
		for (int j = 0; j < 4; j++) {
			if ((i*i) % d[j] == 0) {
				cnt = 1;
				break;
			}
		}
		if (cnt != 1) {
			cout << i * i << endl;
		}
		cnt = 0;
	}
	system("pause");
}