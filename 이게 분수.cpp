#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	double a, b, c, d;
	cin >> a >> b>> c >> d;
	double arr[5];
	arr[0] = a / c + b / d;
	arr[1] = c / d + a / b;
	arr[2] = d / b + c / a;
	arr[3] = b / a + d / c;
	double temp = -1;
	for (int i = 0; i < 4; i++) temp = max(temp, arr[i]);
	for (int i = 0; i < 4; i++) {
		if (temp == arr[i]) {
			cout << i << endl;
			break;
		}
	}
}
