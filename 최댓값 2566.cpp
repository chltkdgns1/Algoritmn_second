#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, c = 0;
	for (int i = 1; i <= 9; i++) {
		for (int k = 1; k <= 9; k++) {
			int x; cin >> x;
			if (c < x) {
				c = x, a = i, b = k;
			}
		}
	}
	cout << c << "\n";
	cout << a << " " << b << "\n";
}