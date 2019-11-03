#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int dis[11][11];
int arr[11];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) dis[i][k] = (i == k) ? 0 : INF;
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) cin >> dis[i][k];
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			for (int z = 0; z < n; z++) {
				if (dis[k][i] + dis[i][z] < dis[k][z]) {
					dis[k][z] = dis[k][i] + dis[i][z];
				}
			}
		}
	}
	int cnt = 0, res = INF;
	for (int i = 0; i < n; i++) {
		if (i == m) continue;
		arr[cnt] = i;
		cnt++;
	}
	int a = m;
	do {
		int t = 0;
		for (int i = 0; i < cnt; i++) {
			t += dis[a][arr[i]];
			a = arr[i];
		}
		a = m;
		res = min(res, t);
	} while (next_permutation(arr, arr + cnt));
	cout << res << "\n";
}