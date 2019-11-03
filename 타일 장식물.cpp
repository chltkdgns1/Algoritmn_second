#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define inf 987654321
using namespace std;


int dp[201][101]; // 값은 수정해야하는 값
vector <vector<int>> vv;
vector <int> ee;

int solve(int s, int idx) {
	if (idx == ee.size() - 1) {
		if (s == ee[idx]) return 0;
		return inf;
	}

	int &ref = dp[s][idx];
	if (ref) return ref;

	ref = inf;

	int t = (ee[idx] != s);
	for(auto a : vv[s]){
		ref = min(ref,solve(a, idx + 1) + t);
	}
	return ref;
}

int solution(int n, int m, vector<vector<int>> v, int k,
	vector<int> e) {
	vv = vector<vector<int>>(n + 1);
	ee = e;

	memset(dp, 0, sizeof(dp));

	for (auto a : v) {
		vv[a[0]].push_back(a[1]);
		vv[a[1]].push_back(a[0]);
	}

	int res = solve(ee[0], 0);
	if (res == inf) return -1;
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	vector <vector<int>> map(m);
	vector <int> v;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		map[i].push_back(a);
		map[i].push_back(b);
	}
	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	cout << solution(n, m, map, k, v) << "\n";

	system("pause");
}