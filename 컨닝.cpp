#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;


int dp[11][1 << 10], a, b;
int map[11];

bool check(int d) {
	for (int i = 0; i < b; i++) {
		if (d & (1 << i)) {
			if (d & (1 << (i + 1))) return false;
		}
	}
	return true;
}

bool check2(int c, int d) {
	for (int i = 0; i < b; i++) {
		if (c & (1 << i)) {
			if (d & (1 << (i + 1)) || d & (1 << (i - 1))) {
				return false;
			}
		}
	}
	return true;
}

int solve(int index,int d) {
	int &ref = dp[index][d];
	if (ref) return ref;

	int cnt = 0;
	for (int k = 0; k < b; k++) {
		if (d & (1 << k)) cnt++;
	}
	ref = cnt;
	if (index == a) return ref;

	int res = 0;
	for (int i = 0; i < (1 << b); i++) {
		if (map[index + 1] & i || !check(i) || !check2(d, i)) continue;
		res = max(res, solve(index + 1, i));
	}
	ref += res;
	return ref;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> a >> b;
		memset(dp, 0, sizeof(dp));
		memset(map, 0, sizeof(map));
		char c;
		for (int i = 1; i <= a; i++) {
			for (int k = 0; k < b; k++) {
				cin >> c;
				if (c == 'x') {
					map[i] |= (1 << k);
				}
			}
		}
		int res = 0;
		for (int i = 0; i < (1 << b); i++) {
			if (map[1] & i || !check(i)) continue;
			res = max(res,solve(1, i));
		}
		cout << res << "\n";
	}
	system("pause");
}

/*
		if (map[index] & i) continue;
		int cnt = 0;
		for (int k = 0; k < b; k++) {
			if (i & (1 << k)) cnt++;
		}
		ref = max(ref, solve(index + 1, i) + cnt);
*/