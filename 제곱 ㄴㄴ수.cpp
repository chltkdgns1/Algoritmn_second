#include  <iostream>
#include <math.h>
using namespace std;

bool d[1000001];

int main() { 
	long long min, max;
	long long squre;
	cin >> min >> max;
	long long cnt = 0;

	for (long long i = 2; i <= sqrt(max); i++) {
		squre = i * i;
		for (int j = 0; i <= max; j += squre) {
			d[j] = true;
		}
	}


	//system("pause");
}


