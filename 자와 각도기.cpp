#include <iostream>
using namespace std;
bool table[361];
int main() {
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	table[0] = true;
	for (int i = 0; i < n; i++) {
		int d = 0; cin >> d;
		for (int j = 0; j < 360; j++) {
			if (!table[j])
				continue;
			for (int k = 1; k < 360; k++) {
				table[(j + k * d) % 360] = table[(360 * 360 + j - k * d) % 360] = true;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		int d; cin >> d;
		if (table[d]) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
	return 0;
}