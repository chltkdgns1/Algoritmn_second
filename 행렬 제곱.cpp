#include <iostream>
using namespace std;
typedef long long ll;
ll map[6][6], res[6][6],temp[6][6],n, m;
void calc(ll arr[6][6], ll brr[6][6]) {
	ll crr[6][6] = {};
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			for (int e = 0; e < n; e++) {
				crr[i][k] += (arr[e][k] * brr[i][e]);
				crr[i][k] %= 1000;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			res[i][k] = crr[i][k];
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> map[i][k];
			res[i][k] = map[i][k];
		}
	}
	bool br = 0;

	if (m == 1) {
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n; k++) {
				cout << map[i][k] % 1000 << " ";
			}
			cout << "\n";
		}
		return 0;
	}

	while (1) {
		ll i;
		if (m < 2) break;
		for (i = 2; i <= m; i <<= 1) calc(res, res);
		if (!br) {
			for (int i = 0; i < n; i++) {
				for (int k = 0; k < n; k++) {
					temp[i][k] = res[i][k];
					res[i][k] = map[i][k];
				}
			}
			br = 1;
		}
		else{
			calc(res,temp);
			for (int i = 0; i < n; i++) {
				for (int k = 0; k < n; k++) {
					temp[i][k] = res[i][k];
					res[i][k] = map[i][k];
				}
			}
		}
		m -= (i / 2);
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			res[i][k] = temp[i][k];
		}
	}
	for (ll i = 0; i < m; i++) calc(res, map);
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cout << res[i][k] << " ";
		}
		cout << "\n";
	}
}