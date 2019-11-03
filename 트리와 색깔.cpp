#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000007
using namespace std;
typedef long long ll;
vector <int> v[200001];
int l[200001], r[200001], arr[200001], brr[200001];
vector <int> tree[200000 * 3 + 1];
int cnt;

void dfs(int s) {
	l[s] = ++cnt;
	for (auto a : v[s]) if (!l[a]) dfs(a);
	r[s] = cnt;
}

vector <int> init(int s, int e, int node) {
	if (s == e) {
		tree[node].push_back(brr[s]);
		return tree[node];
	}
	else {
		int m = (s + e) / 2;
		vector <int> a = init(s, m, node * 2), b =init(m + 1, e, node * 2 + 1),e;
		int c = 0, d = 0;
		while (c != a.size() && d != b.size()) {
			if (a[c] < b[d]) e.push_back(a[c]), c++;
			else e.push_back(b[d]), d++;
		}
		while (c != a.size()) {
			e.push_back(a[c]), c++;
		}
		while (d != b.size()) {
			e.push_back(b[d]), d++;
		}
		return tree[node] = e;
	}
}

ll qurey(int s, int e, int node, int l,int r,int f) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return (upper_bound(tree[node].begin(), tree[node].end(), f) - tree[node].begin()) % INF;
	}
	int m = (s + e) / 2;
	return (qurey(s, m, 2 * node, l, r, f) + qurey(m + 1, e, 2 * node + 1, l, r, f)) % INF;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, c; cin >> n >> m >> c;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) brr[l[i]] = arr[i];
	init(1, n, 1);
	ll res = 0;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		res = (res + qurey(1, n, 1, l[a], r[a],b))%INF;
	}
	cout << res << "\n";
}