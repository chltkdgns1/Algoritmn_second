#include <iostream>
#include <vector>
using namespace std;

vector <int> v[100001];
int d[100001];
bool visit[100001];

void dfs(int s, int par) {
	visit[s] = 1;
	d[s] = par;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (!visit[y]) {
			dfs(y, s);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 1);
	for (int i = 2; i <= n ; i++) cout << d[i] << "\n";
}