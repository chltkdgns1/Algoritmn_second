#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector <pair<int, int>> v[100001];
ll tree[400001];

int _size[100001], par[100001], dfsn[100001];
int h[100001], group[100001], cnt, g = 1, deep[100001], arr[100001], n, rdfsn[100001];

void dfs(int s, int p) {
	_size[s] = 1;
	for (auto a : v[s]) {
		if (a.first == p) continue;
		dfs(a.first, s);
		_size[s] += _size[a.first];
	}
}

void hld(int s, int p, int d) {
	int t = dfsn[s] = ++cnt;
	rdfsn[t] = s;
	deep[t] = d;
	group[t] = g;
	if (h[g] < 0) h[g] = t;
	vector <int> e;
	for (auto a : v[s]) {
		if (a.first == p) continue;
		e.push_back(a.first);
	}
	if (e.empty()) {
		g++;
		return;
	}
	sort(e.begin(), e.end(), [](int a, int b) {
		return _size[a] > _size[b];
	});
	for (auto a : e) {
		hld(a, s, d + 1);
		par[dfsn[a]] = t;
	}
}

ll qurey1(int s, int e, int node, int l, int r) {
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return tree[node];
	int m = (s + e) / 2;
	return qurey1(s, m, node * 2, l, r) + qurey1(m + 1, e, node * 2 + 1, l, r);
}

ll len(int a, int b) {
	a = dfsn[a], b = dfsn[b];
	ll res = 0;
	while (group[a] != group[b]) {
		int ah = h[group[a]], bh = h[group[b]];
		if (deep[ah] > deep[bh]) {
			res += qurey1(1, n, 1, ah, a);
			a = par[ah];
		}
		else {
			res += qurey1(1, n, 1, bh, b);
			b = par[bh];
		}
	}
	if (a == b) return res;
	res += qurey1(1, n, 1, min(a, b) + 1, max(a, b));
	return res;
}

int cal(int s, vector <int> &v, int k) {
	for (auto a : v) {
		k -= s - a;
		if (k <= 0) {
			k += s - a;
			return rdfsn[s - k];
		}
		s = par[a];
		k--;
		if (!k) return rdfsn[s];
	}
}

void countver(int a, int b, int c) {
	int s = dfsn[a], e = dfsn[b];
	int z = 0, d = 0, t = 0;
	vector <int> vv, ee;

	if (a == b || c == 1) {
		cout << a << "\n";
		return;
	}

	while (group[s] != group[e]) {
		int ah = h[group[s]], bh = h[group[e]];
		if (deep[ah] > deep[bh]) {
			z += s - ah + 1;
			vv.push_back(ah);
			s = par[ah];
		}
		else {
			d += e - bh + 1;
			ee.push_back(bh);
			e = par[bh];
		}
	}

	t = max(s, e) - min(s, e) + z + d;
	c--;
	a = dfsn[a], b = dfsn[b];
	if (c <= z) cout << cal(a, vv, c) << "\n";
	else if (z < c && c < t - d) {
		if (deep[s] > deep[e]) cout << rdfsn[s - (c - z)] << "\n";
		else cout << rdfsn[s + c - z] << "\n";
	}
	else {
		if (!(t - c)) cout << rdfsn[b] << "\n";
		else cout << cal(b, ee, t - c) << "\n";
	}
}


ll init(int s, int e, int node) {
	if (s == e) return tree[node] = arr[s];
	int m = (s + e) / 2;
	return tree[node] = init(s, m, node * 2) + init(m + 1, e, node * 2 + 1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, c, d; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	fill(h, h + 100001, -1);
	dfs(1, -1);
	hld(1, -1, 1);

	for (int i = 1; i <= n; i++) {
		int p = dfsn[i];
		for (auto a : v[i]) {
			int u = dfsn[a.first];
			if (deep[p] < deep[u]) {
				arr[u] = a.second;
			}
		}
	}
	init(1, n, 1);
	int m; cin >> m;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			cout << len(b, c) << "\n";
		}
		else {
			cin >> d;
			countver(b, c, d);
		}
	}
}