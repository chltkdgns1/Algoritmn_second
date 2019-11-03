#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int dis[51][51];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			if (i == k) dis[i][k] = 0;
			else dis[i][k] = 987654321;
		}
	}

	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int k = 0; k < s.length(); k++) {
			if (s[k] == 'Y') dis[i][k + 1] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			for (int z = 1; z <= n; z++) {
				if (dis[k][z] > dis[k][i] + dis[i][z]) {
					dis[k][z] = dis[k][i] + dis[i][z];
				}
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int k = 1; k <= n; k++) {
			if (dis[i][k] == 1 || dis[i][k] == 2) cnt++;
		}
		res = max(res, cnt);
	}
	cout << res << "\n";
}