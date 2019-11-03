#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map <string, string> m;
unordered_map <string, int> e;

string find(string a) {
	if (a == m[a]) {
		return a;
	}
	return m[a] = find(m[a]);
}
void _union(string a, string b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		cout << e[a] << "\n";
		return;
	}
	e[a] += e[b];
	m[b] = a;
	cout << e[a] << "\n";
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			if (!e[a]) m[a] = a, e[a]++;
			if (!e[b]) m[b] = b, e[b]++;
			_union(a, b);
		}
		m.clear(), e.clear();
	}
}