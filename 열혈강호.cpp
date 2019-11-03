#include <iostream>
#include <vector>
using namespace std;
int d[1006];
bool check[1006];
vector <int> v[1006];
bool dfs(int s) {
	if (check[s]) return false;
	check[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int t = v[s][i];
		if (!d[t] || dfs(d[t])) {
			d[t] = s;
			return true;
		}
	}
	return false;
}
int main() {
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			v[i].push_back(b);
		}
	}
	int c = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < 2; k++) {
			fill(check , check + n + 1, 0);
			if (dfs(i)) c++;
		}
	}
	cout << c << "\n";
}