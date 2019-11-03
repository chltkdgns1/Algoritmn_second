#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a; cin >> a;
		int t = a * a;
		int cnt = 0;
		bool check = 0;
		string x = to_string(a), y= to_string(t);
		int ylen = y.length(), xlen = x.length();
		for (int i = ylen - 1; i >= ylen - xlen; i--) {
			if (y[i] != x[xlen - 1 - cnt]) {
				check = 1; break;
			}
			cnt++;
		}
		if (check) cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
}