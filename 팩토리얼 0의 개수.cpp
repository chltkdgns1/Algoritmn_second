#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a = 0, b = 0; ; cin >> n;
	for (int i = n; i >= 1; i--) {
		int k = i;
		while (!(k % 2)) {
			a++;
			k /= 2;
		}
		while (!(k % 5)) {
			b++;
			k /= 5;
		}
	}
	cout << min(a, b) << "\n";
}