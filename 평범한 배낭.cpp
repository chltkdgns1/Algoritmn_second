#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>> v;
int dp[101][100001];
int n, k;
int solve(int index, int t) {
	if (t > k || index == v.size()) return 0;

	int &ref = dp[index][t];
	if (ref) return ref;

	ref = 0;
	if(t + v[index].first <= k) 
		ref = max(ref, solve(index + 1, t + v[index].first) + v[index].second);
	ref = max(ref, solve(index + 1, t));

	return ref;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}

	cout << solve(0, 0) << "\n";
}