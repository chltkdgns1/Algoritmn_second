#include <iostream>
#include <vector>
using namespace std;

vector <int> v[201];
vector <int> e;
bool visit[201];
void dfs(int s) {
	visit[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (!visit[y]) {
			dfs(y);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			int a; cin >> a;
			if (a) v[i].push_back(k);
		}
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a; e.push_back(a);
	}
	dfs(e[0]);
	for (int i = 0; i < m; i++) {
		if (!visit[e[i]]) {
			cout << "NO" << "\n";
			return 0;
		}
	}
	cout << "YES" << "\n";
}