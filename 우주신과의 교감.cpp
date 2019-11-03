#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector <pair<int, int>> v;
int d[1001];
int find(int x) {
	if (x == d[x]) return x;
	return d[x] = find(d[x]);
}
bool _union(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return false;
	d[b] = a;
	return true;
}
class Data {
public:
	int a, b;
	double d;
};

vector <Data> e;
bool cmp(const Data&a, const Data&b) {
	return a.d < b.d;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 1; i <= n; i++) d[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		_union(a, b);
	}
	for (int i = 0; i < n-1; i++) {
		for (int k = i + 1; k < n; k++) {
			double r = sqrt(pow(v[i].first - v[k].first, 2) +
				pow(v[i].second - v[k].second, 2));
			e.push_back({ i + 1,k + 1,r });
		}
	}
	sort(e.begin(), e.end(), cmp);
	double res = 0;
	for (int i = 0; i < e.size(); i++) {
		int a = e[i].a, b = e[i].b;
		if (_union(a, b)) res += e[i].d;
	}
	printf("%.2lf\n", res);
}