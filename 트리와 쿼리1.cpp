#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define INF 987654321
using namespace std;
const int MAX_ST = 1 << 18;

class Data {
public:
	int next, cos, index;
};

vector <Data> v[100001];
vector <int> ch[100001];
int deep[100001], par[100001], _size[100001], dfsn[100001];
int tree[MAX_ST], h[100001], gp[100001], cnt, g = 1;
int child[100001], n;

void dfs(int s, int p) {
	_size[s] = 1;
	for (auto a : v[s]) {
		if (a.next == p) continue;
		dfs(a.next, s);
		ch[s].push_back(a.next);
		_size[s] += _size[a.next];
	}
}

void hld(int s, int p, int dp) {

	int node = dfsn[s] = cnt++;
	gp[node] = g;
	deep[node] = dp;
	if (h[g] < 0) h[g] = node;
	if (ch[s].empty()) {
		g++;
		return;
	}


	int c = ch[s][0];
	for (int i = 1; i < ch[s].size(); i++) {
		int next = ch[s][i];
		if (_size[c] < _size[next]) c = next;
	}

	hld(c, s, dp + 1);
	par[dfsn[c]] = node;

	for (auto a : ch[s]) {
		if (a != c) hld(a, s, dp + 1);
		int w = dfsn[a];
		par[w] = node;
	}
}

void update(int index, int data) {
	index += MAX_ST / 2;
	tree[index] = data;
	while (index > 1) {
		index /= 2;
		tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
	}
}

int rangeMax(int s, int e, int node, int l, int r) {
	if (e <= l || r <= s) return -INF;
	if (l <= s && e <= r) return tree[node];
	int m = (s + e) / 2;
	return max(rangeMax(s, m, 2 * node, l, r), rangeMax(m, e, 2 * node + 1, l, r));
}

int ret(int a, int b) {
	a = dfsn[a];
	b = dfsn[b];
	int res = -INF;
	while (gp[a] != gp[b]) {
		int ah = h[gp[a]], bh = h[gp[b]];
		if (deep[ah] > deep[bh]) {
			res = max(res, rangeMax(0, MAX_ST / 2, 1, ah, a + 1));
			a = par[ah];
		}
		else {
			res = max(res, rangeMax(0, MAX_ST / 2, 1, bh, b + 1));
			b = par[bh];
		}
	}
	res = max(res, rangeMax(0, MAX_ST / 2, 1, min(a, b) + 1, max(a, b) + 1));
	return res;
}

void init() {
	for (int i = MAX_ST / 2 - 1; i > 0; --i)
		tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, c; cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		a--, b--;
		v[a].push_back({ b,c,i });
		v[b].push_back({ a,c,i });
	}

	dfs(0, -1);
	fill(h, h + 100000, -1);
	par[0] = -1;
	hld(0, -1, 1);

	fill(tree, tree + MAX_ST, -INF);
	for (int i = 0; i < n; i++) {
		int w = dfsn[i];
		for (auto a : v[i]) {
			int q = dfsn[a.next];
			if (deep[w] < deep[q]) {
				child[a.index] = q;
				tree[MAX_ST / 2 + q] = a.cos;
			}
		}
	}
	init();

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(child[b], c);
		}
		else {
			cout << ret(b - 1, c - 1) << "\n";
		}
	}
}