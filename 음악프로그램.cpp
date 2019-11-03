#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int d[1001];
vector <int> v[1001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, t; cin >> a;
		for (int k = 0; k < a; k++) {
			int b; cin >> b;
			if (!k) {
				t = b;
				continue;
			}
			v[t].push_back(b);
			d[b]++; t = b;
		}
	}
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		if (!d[i]) q.push(i);
	}
	vector <int> e;
	while (!q.empty()) {
		int x = q.front();
		e.push_back(x);
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (!(--d[y])) q.push(y);
		}
	}
	if (e.size() != n) cout << 0 << "\n";
	else for (auto a : e) cout << a << "\n";
}