#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v, tree(400000);

int init(int s, int e, int node) {
	if (s == e) return tree[node] = v[s];
	int m = (s + e) / 2;
	return tree[node] = min(init(s, m, node * 2), init(m + 1, e, node * 2 + 1));
}

int qurey(int s, int e, int le, int ri, int node) {
	if (e < le || ri < s) return 987654321;
	if (le <= s && e <= ri) return tree[node];
	int m = (s + e) / 2;
	return min(qurey(s, m, le, ri, node * 2), qurey(m + 1, e, le, ri, node * 2 + 1));
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, a; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a; v.push_back(a);
	}
	init(0, n - 1, 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout << qurey(0, n - 1, a - 1, b - 1, 1) << "\n";
	}
}