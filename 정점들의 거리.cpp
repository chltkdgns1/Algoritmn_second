#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector <pair<int,int>> v[40001];
vector <int> e[40001];
int dist[40001];
int deep[40001];
bool visit[40001];
int par[40001][20];
void dfs(int root,int dis,int deeps) { // 맨 처음 들어가는 노드가 루트노드에 해당됨
	visit[root] = 1;
	for (int i = 0; i < v[root].size(); i++) {
		int y = v[root][i].first;
		if (!visit[y]) {
			e[y].push_back(root);
			dist[y] = dis + v[root][i].second;
			deep[y] = deeps + 1;
			par[y][0] = root;
			dfs(y,dist[y],deeps + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,k;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[b].push_back({ a, c });
		v[a].push_back({ b,c });
	}
	dist[1] = 0;
	dfs(1,0,1);
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		long long t = dist[a] + dist[b];
		while (a != b) {
			if (deep[a] > deep[b]) a = e[a][0];
			else if (deep[a] < deep[b]) b = e[b][0];
			else {
				a = e[a][0];
				b = e[b][0];
			}
		}
		t -= 2 * dist[a];
		cout << t << "\n";
	}
}

/*
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_N 40000
using namespace std;
int n, m, visited[MAX_N + 1], dph[MAX_N + 1], par[MAX_N + 1][20], dist[MAX_N + 1], x, y, z;
vector<vector<pair<int, int>>>vt;
void dfs(int v, int dh, int dis) {
	visited[v] = true;
	dph[v] = dh;
	dist[v] = dis;
	for (auto u : vt[v]) {
		if (visited[u.first])
			continue;
		dfs(u.first, dh + 1, dis + u.second);
		par[u.first][0] = v;
	}
}
void f() {
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
	}
}

int lca(int x, int y) {
	if (dph[x] > dph[y])
		swap(x, y);
	for (int i = 0; i <= 19; i++) {
		if (dph[y] - dph[x] > 0)
			y = par[y][i];
	}
	if (x == y)return x;
	for (int i = 19; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			x = par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}

int main() {
	scanf("%d", &n);
	vt.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d%d", &x, &y, &z);
		vt[x].push_back({ y,z });
		vt[y].push_back({ x,z });
	}
	dfs(1, 0, 0);
	f();
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &x, &y);
		int qlca = lca(x, y);
		printf("%d\n", dist[x] + dist[y] - 2 * dist[qlca]);
	}
	return 0;
}

*/