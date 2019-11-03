#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, n = 0;
	cin >> t;
	while (t--) {
		char s[21];
		int k;
		cin >> s;
		if (s[1] == 'd') {
			cin >> k;
			n |= (1 << k);
		}
		if (s[1] == 'e') {
			cin >> k;
			n &= ~(1 << k);
		}
		if (s[1] == 'h') {
			cin >> k;
			if (n &(1 << k)) cout << 1 << "\n";
			else cout << 0 << "\n";		
		}
		if (s[1] == 'o') {
			cin >> k;
			n ^= (1 << k);
		}
		if (s[1] == 'l') n = (1 << 21) - 1;
		if (s[1] == 'm') n = 0;
	}
	system("pause");
}