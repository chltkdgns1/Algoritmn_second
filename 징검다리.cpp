#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector <int> &v, int e, int m) {
	int s = -1, g, cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (s == -1) g = v[i];
		else g = v[i] - v[s];

		if (g < m) cnt++;
		else s = i;
	}
	return cnt;
}

int solution(int d, vector<int> v, int e) {
	int l = 0, r = d, m;
	v.push_back(d);
	sort(v.begin(), v.end());

	int res = 0;
	while (l <= r) {
		m = (l + r) / 2;
		int t = solve(v, e, m);
		if (t < e) l = m + 1;
		else if (t > e) r = m - 1, res = r;
		else l = m + 1, res = m;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, d, e; cin >> n >> d >> e;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	cout << solution(d, v, e) << "\n";
	system("pause");
}