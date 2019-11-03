#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <pair<int,int>> v[100001];
bool visit[100001];
int longest; // 1번루트노드를 기준으로 가장 긴 정점
int len; // 길이
void dfs(int s,int d) {
	visit[s] = 1;
	int t = 0;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i].first;
		if (!visit[y]) {
			dfs(y,v[s][i].second + d);
		}
	}
	if (len < d) {
		len = d;
		longest = s;
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		while (1) {
			int b, c;
			cin >> b;
			if (b == -1) break;
			cin >> c;
			v[a].push_back({ b,c });
		}
	}
	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	dfs(longest, 0);
	cout << len << "\n";
}