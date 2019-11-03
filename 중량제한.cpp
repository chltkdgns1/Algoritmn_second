#include <iostream>
#include <vector>
using namespace std;
vector <pair<int,int>> v[100000];
int key1, key2;
bool check[100001];
bool dfs(int key1,int c) {
	if (key1 == key2) {
		return true;
	}
	for (int i = 0; i < v[key1].size(); i++) {
		int x = v[key1][i].first;
		int y = v[key1][i].second;
		if (check[x] == false && y >= c ) {
			check[x] = true;
			if (dfs(x, c) == true) return true;
		}
	}
	return false;
}
int main() {
	int n, m;
	int a, b, c;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (!v[a].empty()) {
			int cnt = 0;
			for (int i = 0; i < v[a].size(); i++) {
				if (v[a][i].first == b) {
					cnt++;
					if (v[a][i].second < c) {
						v[a][i].second = c;
						v[b][i].second = c;
					}
				}
			}
			if (cnt == 0) {
				v[a].push_back({ b,c });
				v[b].push_back({ a,c });
			}
		}
		else if (v[a].empty()) {
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
		}
	}
	cin >> key1 >> key2;
	int key_max = 0;
	for (int i = 0; i < v[key1].size(); i++) {
		if (key_max < v[key1][i].second) key_max = v[key1][i].second;
	}
	int left = 0, right = key_max, mid;
	int max = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		bool t = dfs(key1, mid);
		if (t == false) right = mid - 1;
		else {
			if (max < mid) max = mid;
			left = mid + 1;
		}
		for (int i = 1; i <= n; i++) check[i] = 0;
	}
	cout << max << "\n";
}