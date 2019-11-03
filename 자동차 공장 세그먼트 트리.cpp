#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int l[500001], r[500001],cnt;
ll tree[500001 * 4], lazy[500001 * 4], arr[500001], b[500001];
vector <int> v[500001];
void dfs(int s) {
	l[s] = ++cnt;
	for (auto a : v[s]) {
		if (!l[a]) dfs(a);
	}
	r[s] = cnt;
}
void init(int node,int s,int e) {
	if (s == e) tree[node] = b[s];
	else {
		int m = (s + e) / 2;
		init(node * 2, s, m);
		init(node * 2 + 1, m + 1, e);
	}
}
void _lazy(int node,int s,int e) {
	if (lazy[node]) {
		tree[node] += lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int node,int left, int right, int s, int e,ll data) {
	_lazy(node, s, e);
	if (right < s || e < left) return;
	if (left <= s && e <= right) {
		tree[node] += data;
		if (s != e) {
			lazy[node * 2] += data;
			lazy[node * 2 + 1] += data;
		}
		return;
	}
	int m = (s + e) / 2;
	update(node * 2, left, right, s, m, data);
	update(node * 2 + 1, left, right, m + 1, e, data);
}
ll qur(int node, int index, int s, int e) {
	_lazy(node, s, e);
	if (index < s || e < index) return 0;
	if (s == e) return tree[node];
	int m = (s + e) / 2;
	return qur(node*2, index, s, m) + qur(node*2 + 1, index, m + 1, e);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int b;
		if (i == 1) cin >> arr[i];
		else {
			cin >> arr[i] >> b;
			v[b].push_back(i);
		}
	}
	dfs(1);
	for (int i = 1; i <= n; i++) b[l[i]] = arr[i];
	init(1, 1, n);

	for (int i = 0; i < m; i++) {
		char c; ll a, b;
		cin >> c;
		if (c == 'p') {
			cin >> a >> b;
			update(1, l[a] + 1, r[a], 1, n, b);
		}
		else {
			cin >> a;
			cout << qur(1, l[a], 1, n) << "\n";
		}
	}
}