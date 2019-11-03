#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;


bool visit[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;

int dfs(int x,int y, vector<vector<int>>&maps){
	visit[y][x] = 1;
	int res = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
			if (!visit[ny][nx] && maps[y][x] == maps[ny][nx]) {
				res += dfs(nx, ny,maps);
			}
		}
	}
	return res;
}
vector<int> solution(int a, int b, vector<vector<int>> map) {
	n = a, m = b;

	int number_of_area = 0;
	int max_size_of_one_area = 0;

	memset(visit, 0, sizeof(visit));

	int cnt = 0;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (map[i][k] && !visit[i][k]) {
				int t = dfs(k, i, map);
				mx = max(mx, t);
				cnt++;
			}
		}
	}

	number_of_area = cnt;
	max_size_of_one_area = mx;

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	int m, n; cin >> m >> n;
	vector <vector<int>> map(m);
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < n; k++) {
			int a; cin >> a;
			map[i].push_back(a);
		}
	}

	vector <int> e = solution(m, n, map);
	for (auto a : e) cout << a << " ";
}