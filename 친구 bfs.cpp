#include <iostream>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
vector <int> v[51];
bool visit[51];
int bfs(int s) {
	memset(visit, 0, sizeof(visit));
	queue <pair<int, int>> q;
	q.push({ s,0 });
	int res = 0;
	visit[s] = 1;
	while (!q.empty()) {
		int ss = q.front().first;
		int d = q.front().second;
		q.pop();
		if (d == 1) res++;
		if (d == 2) {
			res++;
			continue;
		}
		for (auto a : v[ss]) {
			if (!visit[a]) q.push({ a, d + 1 }), visit[a] = 1;
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int k = 0; k < s.length(); k++) {
			if (s[k] == 'Y') v[i].push_back(k);
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, bfs(i));
	}
	cout << res << "\n";
}