#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector <int> v[101];
bool visit[101];
int d[101];

void dfs(int s,int st) {
	if(s != st) d[s]++;
	d[st]++;
	visit[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (!visit[y]) dfs(y,st);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, i);
		memset(visit, 0, sizeof(visit));
	}
	for (int i = 1; i <= n; i++) {
		cout << n - d[i] << "\n";
	}
}