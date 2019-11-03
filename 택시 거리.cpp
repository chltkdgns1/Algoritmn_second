#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int map[1001][1001];
vector <pair<int, int>> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			if (map[i][k]) v.push_back({ k,i });
		}
	}
	cout << abs(v[0].first - v[1].first) + abs(v[0].second - v[1].second) << "\n";
}