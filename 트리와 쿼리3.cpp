#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
typedef long long ll;

class tData {
public:
	int w; 
	bool ch; 
	tData() {w = INF, ch = 0; }
};

vector <int> v[100001];
vector <tData> tree(400001);
int _size[100001], par[100001], dfsn[100001];
int h[100001], group[100001], cnt, g = 1, deep[100001], arr[100001], n, rdfsn[100001];

void dfs(int s, int p) {
	_size[s] = 1;
	for (auto a : v[s]) {
		if (a == p) continue;
		dfs(a, s);
		_size[s] += _size[a];
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
		if (a == p) continue;
		e.push_back(a);
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

int qurey1(int s, int e, int node, int l, int r) {
	if (e < l || r < s || tree[node].w == INF) return INF;
	if (l <= s && e <= r) return tree[node].w;
	int m = (s + e) / 2;
	return min(qurey1(s, m, node * 2, l, r) ,qurey1(m + 1, e, node * 2 + 1, l, r));
}

int update(int s, int e, int node,int index) {
	if (e < index || index < s) return tree[node].w;
	if (s == e) {
		arr[index] = node;
		tree[node].ch = tree[node].ch == 1 ? 0 : 1;
		if (tree[node].ch) return tree[node].w = s ;
		return tree[node].w = INF;
	}
	int m = (s + e) / 2;
	if (tree[arr[index]].w != INF && tree[node].w == tree[arr[index]].w) tree[node].w = INF;
	int a = update(s, m, node * 2, index), b = update(m + 1, e, node * 2 + 1, index);
	return tree[node].w = min(a, b);
}

int f(int a, int b) {
	a = dfsn[a], b = dfsn[b];
	int res = INF;
	while (group[a] != group[b]) {
		int bh = h[group[b]];
		res = min(res, qurey1(1, n, 1, bh, b));
		b = par[bh];
	}
	res = min(res,qurey1(1, n, a, 1 , b));
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, c, d; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	fill(h, h + 100001, -1);
	dfs(1, -1);
	hld(1, -1, 1);

	int m; cin >> m;
	while (m--) {
		cin >> a >> b;
		if (a == 1) update(1, n, 1, dfsn[b]);
		else {
			int c = f(1, b);
			if (c != INF) cout << rdfsn[c] << "\n";
			else cout << -1 << "\n";
		}
	}
}