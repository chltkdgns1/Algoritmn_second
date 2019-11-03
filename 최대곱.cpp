#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long long s, k, sum = 1, temp1, temp2;
	cin >> s >> k;
	temp1 = s / k;
	temp2 = s - temp1 * k;
	for (int i = 1; i <= k - temp2; i++) sum *= temp1;
	for (int i = 1; i <= temp2; i++) sum *= (temp1 + 1);
	cout << sum << endl;
}

