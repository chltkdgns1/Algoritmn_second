#include <iostream>
#include <vector>
using namespace std;
vector <int> v[401];
bool check[401];
bool dfs(int num, int ch) {
	if (num == ch) {
		return true;
	}
	for (int i = 0; i < v[num].size(); i++) {
		if (check[v[num][i]] == false) {
			check[v[num][i]] = true;
			bool re = dfs(v[num][i], ch);
			if (re == true) return true;
		}
		else {
			if (v[num][i] == ch) return true;
		}
	}
	return false;
}

int main() {
	int n, m, a, b ,c;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> a >> b;
		check[a] = true;
		if (dfs(a, b) == true) cout << -1 << "\n"; 
		else {
			if (dfs(b, a) == true) { cout << 1 << "\n";}
			else cout << 0 << "\n";
		}
		for (int i = 1; i <= n; i++) check[i] = 0;
	}
}