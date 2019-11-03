#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, s; cin >> s >> n;
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			s += a * b;
		}
		cout << s << "\n";
	}
}