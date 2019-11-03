#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int dis[51][51];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= 50; i++) {
		for (int k = 1; k <= 50; k++) {
			if (i == k) dis[i][k] = 0;
			else dis[i][k] = INF;
		}
	}
	while(1){
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		dis[a][b] = 1;
		dis[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				if (dis[a][i] + dis[i][b] < dis[a][b]) {
					dis[a][b] = dis[a][i] + dis[i][b];
				}
			}
		}
	}
	int min = INF;
	vector <int> v;
	for (int i = 1; i <= n; i++) {
		int max = 0;
		for (int k = 1; k <= n; k++) {
			if (max < dis[i][k] && dis[i][k] != INF) max = dis[i][k];
		}
		if (min > max) {
			min = max;
			if (v.empty()) v.push_back(i);
			else v.clear(),v.push_back(i);
		}
		else if (min == max) v.push_back(i);
	}
	cout << min << " " << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
}