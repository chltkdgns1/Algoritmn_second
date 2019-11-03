#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
typedef long long ll;
using namespace std;
class Data {
public:
	ll a, b, d;
};
vector <pair<int,int>> x,y,z;
vector <Data> v;
int d[100001];
bool cmp(Data &a, Data &b) {
	return a.d < b.d;
}
ll abs1(ll a) {
	if (a < 0) return -a;
	else return a;
}
void go(vector <pair<int, int>> e) {
	for (int i = 0; i < e.size(); i++) {
		if (!i) {
			Data d; d.d = abs1(e[i].first - e[i + 1].first);
			d.a = e[i].second, d.b = e[i + 1].second;
			v.push_back(d);
		}
		else if (i == e.size() - 1) {
			Data d; d.d = abs1(e[i].first - e[i - 1].first);
			d.a = e[i].second, d.b = e[i - 1].second;
			v.push_back(d);
		}
		else {
			Data a, b;
			a.a = e[i].second, a.b = e[i + 1].second;
			b.a = e[i].second, b.b = e[i - 1].second;
			a.d = abs1(e[i].first - e[i + 1].first);
			b.d = abs1(e[i].first - e[i - 1].first);
			v.push_back(a), v.push_back(b);
		}
	}
}
int find(int x) {
	if (d[x] == x) return x;
	return d[x] = find(d[x]);
}
bool _union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	d[y] = x;
	return true;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	if (n == 1) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 1; i <= n; i++) d[i] = i;
	for (int i = 1; i <= n; i++) {
		int a, b, c; cin >> a >> b >> c;
		x.push_back({ a,i }), y.push_back({ b,i }), z.push_back({ c,i });
	}
	sort(x.begin(), x.end()), sort(y.begin(), y.end()),sort(z.begin(), z.end());
	go(x), go(y), go(z);

	sort(v.begin(), v.end(),cmp);
	ll res = 0;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].a, y = v[i].b;
		if (_union(x, y)) {
			res += v[i].d;
		}
	}
	cout << res << "\n";
}