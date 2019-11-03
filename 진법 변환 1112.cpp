#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	string t;
	if (k > 0) {
		bool br = 0;
		if (n < 0) { br = 1, n = -n; }
		while (n) {
			t += n % k + 48;
			n /= k;
		}
		reverse(t.begin(), t.end());
		if (br) {
			string s;
			s += '-' + t;
			cout << s << "\n";
			return 0;
		}
		cout << t << "\n";
	}
	else {
		while (n != 0) {
			if (n > 0) {
				t += n % k + 48;
				n /= k;
			}
			else {
				if (n % k == 0) {
					t += n % k + 48;
					n /= k;
				}
				else {
					t += -((n / k + 1) * k - n) + 48;
					n = n / k + 1;
				}
			}
		}
		reverse(t.begin(), t.end());
		cout << t << "\n";
	}
}