#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define INF 987654321
#define fi first
#define se second
using namespace std;
typedef pair <int, int> pii;

class Data {
public:
	int next, cos, index;
};

vector <Data> v[100001];
int deep[100001], par[100001], _size[100001], dfsn[100001];
int tree[400001], gp[100001], cnt, g = 1, n;
int ve[100001], h[100001];
vector <pair <pii, int> > E;

void dfs(int s, int p) {
	_size[s] = 1;
	for (auto a : v[s]) {
		if (a.next == p) continue;
		dfs(a.next, s);
		_size[s] += _size[a.next];
	}
}

void hld(int s, int p, int dp) {
	int node = dfsn[s] = ++cnt;
	gp[node] = g;
	deep[node] = dp;
	if (h[g] == -1) h[g] = dfsn[s];

	vector <int> z;

	for (auto a : v[s]) {
		if (a.next == p) continue;
		z.push_back(a.next);
	}

	if (z.empty()) {
		g++;
		return;
	}

	sort(z.begin(),z.end(), [](int a, int b) {
		return _size[a] > _size[b];
	});
	for (auto a : z) {
		hld(a, s, dp + 1);
		par[dfsn[a]] = node;
	}
}

int update(int s, int e, int node, int k, int val) {
	if (s == e) return tree[node] = val;
	int m = (s + e) / 2;
	if (k <= m) return tree[node] = max(tree[node * 2 + 1], update(s, m, 2*node, k, val));
	else return tree[node] = max(tree[node * 2], update(m + 1, e, 2*node + 1, k, val));
}

int rangeMax(int s, int e, int node, int l, int r) {
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return tree[node];
	int m = (s + e) / 2;
	return max(rangeMax(s, m, 2 * node, l, r), rangeMax(m + 1, e, 2 * node + 1, l, r));
}

int ret(int a, int b) {
	a = dfsn[a];
	b = dfsn[b];
	int res = -INF;
	while (gp[a] != gp[b]) {
		int c = h[gp[a]], d = h[gp[b]];
		if (deep[c] > deep[d]) {
			res = max(res, rangeMax(1, n , 1, c, a));
			a = par[c];
		}
		else {
			res = max(res, rangeMax(1, n , 1, d, b));
			b = par[d];
		}
	}
	res = max(res, rangeMax(1, n , 1, min(a, b) + 1 , max(a, b)));
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, c; cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c,i });
		v[b].push_back({ a,c,i });
		E.push_back({ {a,b},c });
	}

	fill(h, h + 100001, -1);
	dfs(1, 0);
	hld(1, 0, 0);

	for (int i = 0; i < E.size(); i++) {
		if (dfsn[E[i].fi.fi] > dfsn[E[i].fi.se]) ve[i] = dfsn[E[i].fi.fi];
		else ve[i] = dfsn[E[i].fi.se];
		update(1, n, 1, ve[i], E[i].se);
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n , 1, ve[b - 1], c);
		}
		else {
			cout << ret(b, c) << "\n";
		}
	}
}