#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		double a;
		cin >> a;
		a *= (4.0 / 5.0);
		a *= 100; a = round(a);
		a /= 100;
		printf("$%.2lf\n", a);
	}
}