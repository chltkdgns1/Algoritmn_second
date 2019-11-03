#include <iostream>
using namespace std;
long long deep[300001];
long long p;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int d, n, cnt = 0;
	long long max = 0;
	cin >> d >> n;
	for (int i = 1; i <= d; i++) cin >> deep[i];
	for (int i = 1; i <= n; i++) {
		cin >> p;
		if (max < p) max = p;
		else {
			d--;
			if (d < 0) {
				cout << "0" << endl;
				return 0;
			}
			continue;
		}
		if(d == 0) {
			cout << "0" << endl;
			return 0;
		}
		for (int j = 1; j <= d; j++) {
			if (deep[j] < max) {
				d = j - 2;
				if (d < 0) {
					cout << "0" << endl;
					return 0;
				}
				break;
			}
			else if (j == d) {
				d--;
				if (d < 0) {
					cout << "0" << endl;
					return 0;
				}
			}
		}
	}
	cout << d + 1 << endl;
}
