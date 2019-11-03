#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
map <int, int> m;
vector <int> v, d,s;
vector <pair<int, int>> e, st;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		m[a] = i + 1;
	}
	for (int i = 0; i < v.size(); i++) e.push_back({ m[v[i]],v[i] });
	int cnt = 0;
	s.push_back(-987654321);
	for (int i = 0; i < e.size(); i++) {
		if (s.back() < e[i].first) {
			s.push_back(e[i].first);
			cnt++;
			st.push_back({ e[i].second, s.size() - 1});
		}
		else {
			int d = lower_bound(s.begin(), s.end(), e[i].first) - s.begin();
			s[d] = e[i].first;
			st.push_back({ e[i].second,d});
		}
	}
	int q = cnt;
	while (!st.empty()) {
		if (q == st.back().second) {
			d.push_back(st.back().first);
			st.pop_back();
			q--;
		}
		else st.pop_back();
	}
	sort(d.begin(), d.end());
	cout << cnt << "\n";
	for (int i = 0; i < d.size(); i++) cout << d[i] << " ";
}