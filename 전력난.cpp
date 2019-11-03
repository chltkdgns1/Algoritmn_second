#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class Data {
public:
	int a, b, c;
};
vector <Data> v;
bool cmp(Data &a, Data &b) {
	return a.c < b.c;
}
int d[200001];
int find(int x) {
	if (x == d[x]) return x;
	return d[x] = find(d[x]);
}
bool _union(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return 0;
	d[y] = x;
	return 1;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; 
	while (1) {
		v.clear();
		cin >> m >> n;
		if (!n && !m) break;
		int t = 0;
		for (int i = 0; i < n; i++) {
			int a, b, c; cin >> a >> b >> c;
			t += c;
			v.push_back({ a,b,c });
		}

		sort(v.begin(), v.end(), cmp);

		for (int i = 0; i < m; i++) d[i] = i;

		int sum = 0;
		for (auto a : v) {
			if (_union(a.a, a.b)) sum += a.c;
		}
		cout << t - sum << "\n";
	}
}