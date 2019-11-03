#include <iostream>
using namespace std;
int main() {
	double pie = 3.141592653589793;
	int r;
	cin >> r;
	pie = pie * (double)(r*r);
	printf("%.6lf\n", pie);
	cout << 2 * r*r << endl;
}