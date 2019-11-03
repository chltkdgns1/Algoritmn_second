#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int idx[100001], g[100001], tg[100001], t;

bool cmp(int x, int y) {
	if (g[x] == g[y]) return g[x + t] < g[y + t];
	return g[x] < g[y];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;

	int n = s.length();
	for (int i = 0; i < n; i++) {
		idx[i] = i;
		g[i] = s[i] - 'a';
	}

	t = 1;
	g[n] = -1;

	while (t <= n) {
		sort(idx, idx + n, cmp);
		tg[idx[0]] = 0;

		for (int i = 1; i < n; i++) {
			if (cmp(idx[i - 1], idx[i])) {
				tg[idx[i]] = tg[idx[i - 1]] + 1;
			}
			else tg[idx[i]] = tg[idx[i - 1]];
		}

		for (int i = 0; i < n; i++) g[i] = tg[i];

		t <<= 1;
	}

	for (int i = 0; i < n; i++) cout << idx[i] << "\n";
}
