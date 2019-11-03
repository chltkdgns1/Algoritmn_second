#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int i = 0;
	while (1) {
		if (1 << i >= n) break;
		i++;
	}
	int d = 1 << i;
	int cnt = 0;
	if (n == d) {
		cout << (1 << i) << " " << 0 << "\n";
		return 0;
	}
	while (d) {
		d /= 2;
		cnt++;
		if (!(n - d)) {
			cout << (1 << i) << " " << cnt << "\n";
			break;
		}
		if (d > n) continue;
		n -= d;
	}
}