#include <iostream>
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (d >= 3600) a += d / 3600, d %= 3600;
	if (d >= 60) b += d / 60, d %= 60;
	c += d;
	b += c / 60, c %= 60;
	a += b / 60, b %= 60;
	a %= 24;
	cout << a << " " << b << " " << c << "\n";
}