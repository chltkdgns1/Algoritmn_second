#include <iostream>
typedef long long ll;
using namespace std;

ll p[100001],d[100001];
int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

ll _union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return d[x];
	d[x] += d[y];
	p[y] = x;
	return d[x];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		p[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout << _union(a, b) << "\n";
	}
}