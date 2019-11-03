#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
vector <int> r;
int find(int u)  { 
	if (u == v[u]) return u;
	return v[u] = find(v[u]);
}
void merge(int e, int t) {
	e = find(e); t = find(t);
	if (e == t) return;
	v[e] = t;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n,m;
	cin >> n >> m;
	r.assign(n + 1, 1);
	for (int i = 0; i <= n; i++) v.push_back(i);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!a) merge(b, c);
		else {
			if (find(b) == find(c)) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
}
