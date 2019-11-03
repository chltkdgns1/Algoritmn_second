#include <iostream>
#include <string>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	long long c = 0, d = 0;
	for (int i = 0; i < a.length(); i++) c += a[i] - 48;
	for (int i = 0; i < b.length(); i++) d += b[i] - 48;
	cout << d * c << "\n";
}