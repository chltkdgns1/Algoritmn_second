#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int d; cin >> d;
		int index = 0;
		for (int i = 0; i <= d; i++) {
			if (d - (i + i * i) < 0) {
				index = i;
				break;
			}
		}
		cout << index - 1 << "\n";
	}
}