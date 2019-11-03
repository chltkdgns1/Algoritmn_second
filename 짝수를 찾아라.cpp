#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int min = 987654321, s = 0;
		for (int i = 0; i < 7; i++) {
			int a; cin >> a;
			if (!(a % 2)) {
				if (min > a) min = a;
				s += a;
			}
		}
		cout << s << " " << min << "\n";
	}
}