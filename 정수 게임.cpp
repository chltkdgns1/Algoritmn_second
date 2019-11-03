#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
bool d[101];
vector <int> v, e, q;

ll res;
int n;

int uclid(int a, int b) {
	if (!(a%b)) return b;
	uclid(b, a%b);
}

ll _union() {
	ll t = 1;
	for (int i = 0; i < q.size(); i++) {
		int y = q[i];
		int d = uclid(max(t, ll(v[y])), min(t, ll(v[y])));
		t = t * v[y] / d;
	}
	return n / t;
}

void solve(int n, int r, int cnt) {
	if (r > n) {
		if (!cnt) return;
		if (!(cnt % 2)) res -= _union();
		else res += _union();
		return;
	}
	q.push_back(r);
	solve(n, r + 1, cnt + 1);
	q.pop_back();
	solve(n, r + 1, cnt);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		e.push_back(a);
	}
	sort(e.begin(), e.end());
	for (int i = 0; i < e.size(); i++) {
		int r = e[i];
		if (!d[r]) {
			v.push_back(r);
			int k = 1;
			while (r*k <= 100) {
				d[r*k] = 1;
				k++;
			}
		}
	}
	solve(v.size() - 1, 0, 0);
	cout << n - res << "\n";
}