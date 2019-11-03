#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	double a, b; cin >> a >> b;
	printf("%.6lf", 2 * a + 2 * b*3.141592);
}