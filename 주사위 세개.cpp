#include <iostream>
#include <algorithm>
using namespace std;

int d[7];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 3; i++) {
		int a; cin >> a; d[a]++;
	}
	int index = 0;
	for (int i = 1; i <= 6; i++) {
		if (d[i] == 2) {
			cout << 1000 + i * 100 << "\n";
			return 0;
		}
		else if (d[i] == 3) {
			cout << 10000 + i * 1000 << "\n";
			return 0;
		}
		else if (d[i]) index = i;
	}
	cout << 100 * index << "\n";
}