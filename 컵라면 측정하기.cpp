#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	double a,b, c ,d;
	cin >> a >> b >> c;
	d = (max(b, c) - min(b, c)) / 2.0;
	printf("%.6lf", (a*a - d * d));
}