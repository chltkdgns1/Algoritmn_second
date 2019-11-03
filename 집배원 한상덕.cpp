#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

char cm[51][51];
int m[51][51];
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
bool visit[51][51];
vector <int> v;
int n;

bool check(int x, int y) {
	if (0 <= x && x < n && 0 <= y && y < n) return true;
	return false;;
}
int solve(int x, int y, int low, int high) {
	if (visit[y][x] || !check(x, y) || m[y][x] < low || high < m[y][x]) return 0;
	
	visit[y][x] = 1;
	int t = 0;
	if (cm[y][x] == 'K') t++;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		t += solve(nx, ny, low, high);
	}
	return t;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	int s, e, cnt = 0;
	for (int i = 0; i < n; i++) cin >> cm[i];
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (cm[i][k] == 'P') s = k, e = i;
			else if (cm[i][k] == 'K') cnt++;
			cin >> m[i][k];
			v.push_back(m[i][k]);
		}
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int k = 0, res = 987654321;
	for (int i = 0; i < v.size(); i++) {
		while (1) {
			memset(visit, 0, sizeof(visit));
			if (solve(s, e, v[k], v[i]) != cnt) break;
			res = min(res, v[i] - v[k]);
			k++;
		}
	}
	cout << res << "\n";
}