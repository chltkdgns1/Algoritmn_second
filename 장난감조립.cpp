#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int d[101];
class Data {
public:
	int arr[101];
	Data() {
		for (int i = 0; i < 101; i++) arr[i] = 0;
	}
};
Data dat[101];
vector <pair<int,int>> v[101];
vector <int> e;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m; cin >> n >>m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a]++;
		dat[b].arr[b] = 1;
		v[b].push_back({ a,c });
	}
	queue <int> q;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (!d[i]) {
			e.push_back(i);
			q.push(i);
		}
	}
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		for (int i = 0; i < v[s].size(); i++) {
			int y = v[s][i].first;
			d[y]--;
			for(int k=0;k<e.size();k++){
				dat[y].arr[e[k]] += dat[s].arr[e[k]] * v[s][i].second;
			}
			if (!d[y]) q.push(y);
		}
	}
	for (int k = 0; k < e.size(); k++) {
		cout << e[k] << " " << dat[n].arr[e[k]] << "\n";
	}
}