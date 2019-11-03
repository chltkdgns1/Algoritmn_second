#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int dp1[1000][2];
int dp2[1000][2];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, a, b; cin >> n;

		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));

		vector <pair<int, int>> v;

		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}

		dp1[0][0] = v[0].first;

		for (int i = 1; i < v.size(); i++) {
			dp1[i][0] + v[i].first;

		}

		dp2[0][1] = v[0].second;
	}
}