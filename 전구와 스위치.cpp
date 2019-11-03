#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a, b, c;
int cal(string a) {
	int cnt = 0;
	for (int i = 1; i < a.length(); i++) {
		if (a[i - 1] != b[i - 1]) {
			if (i == a.length() - 1) {
				a[i - 1] = b[i - 1];
				a[i] = a[i] == '0' ? '1' : '0';
			}
			else {
				a[i - 1] = b[i - 1];
				a[i] = a[i] == '0' ? '1' : '0';
				a[i + 1] = a[i + 1] == '0' ? '1' : '0';
			}
			cnt++;
		}
	}
	if (a != b) return 987654321;
	return cnt;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	cin >> a >> b;
	c = a;
	c[0] = c[0] == '0' ? '1' : '0';
	c[1] = c[1] == '0' ? '1' : '0';
	int d = min(cal(a), cal(c) + 1);
	if (d == 987654321) cout << -1 << "\n";
	else cout << d << "\n";
}