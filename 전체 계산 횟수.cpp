#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b;
	cin >> a >> b;
	int t = a;
	while (a) {
		a /= b;
		t += a;
	}
	cout << t << "\n";
}