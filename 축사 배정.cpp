#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector <int> v[201];
int d[201];
bool check[201];
bool dfs(int s) {

	for (auto a : v[s]) {
		if (check[a]) continue;
		check[a] = 1;
		if (!d[a] || dfs(d[a])) {
			d[a] = s;
			return 1;
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		for (int k = 0; k < a; k++) {
			int b; cin >> b;
			v[i].push_back(b);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		if (dfs(i)) cnt++;
	}
	cout << cnt << "\n";
}