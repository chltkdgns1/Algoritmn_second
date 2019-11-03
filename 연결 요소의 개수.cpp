#include <iostream>
#include <queue>
using namespace std;
int map[1001][1001];
bool check[1001];
int n, m, a, b;
void dfs(int n1) {
	check[n1] = true;
	for (int i = 1; i <= n; i++) {
		if (map[n1][i] == 1 && check[i] == false) {
			dfs(i);
		}
	}

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
}