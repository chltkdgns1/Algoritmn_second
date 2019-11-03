#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector <int> v[1001];
int d[1001];
bool check[1001];
bool dfs(int s) {
	if (check[s]) return false;
	check[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (!d[y] || dfs(d[y])) {
			d[y] = s;
			return true;
		}
	}
	return false;
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	set <int> s;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			v[i].push_back(b);
			s.insert(b);
		}
	}
	int c = 0;
	for (int i = 1; i <= n; i++) {
		fill(check + 1, check + 1 + n, 0);
		if (dfs(i)) c++;
	}
	for (int i = 1; i <= n  ; i++) {
		fill(check + 1, check + 1 + n, 0);
		if (dfs(i)) {
			c++;
			k--;
			if (!k) break;
		}
	}
	cout << c << "\n";
}