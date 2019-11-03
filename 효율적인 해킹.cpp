#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> v1[10001];
vector <int> v2[10001];
bool check[10001];
int n, m;
int dfs(int number) {
	check[number] = true;
	int cnt = 1;
	for (int i = 0; i < v2[number].size(); i++) {
		if (check[v2[number][i]] == false) {
			cnt += dfs(v2[number][i]);
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v1[a].push_back(b);
		v2[b].push_back(a);
	}
	int max = 0;
	queue <pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
			int data = dfs(i);
			for (int i = 1; i <= n; i++) check[i] = 0;
			if (max == 0) {
				max = data;
				q.push({ i,data });
			}
			else if (max < data) {
				while (!q.empty()) q.pop();
				q.push({ i, data });
				max = data;
			}
			else if (max == data) q.push({ i, data });	
	}
	while (!q.empty()) {
		cout << q.front().first << " ";
		q.pop();
	}
	cout << endl;
}