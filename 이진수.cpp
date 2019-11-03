#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int cnt = 0;
		while (n) {
			if ((n % 2)) cout << cnt << " ";
			n /= 2;
			cnt++;
		}
		cout << "\n";
	}
}