#include <iostream>
#include <vector>

using namespace std;

vector<int> G[20001];
int color[20001];      //1�϶��� ����, 2�϶��� �Ķ�, 0�϶��� ����X

void DFS(int node, int c) {
	color[node] = c;
	for (int i = 0; i < G[node].size(); i++) {
		int next = G[node][i];
		if (color[next] == 0) {
			DFS(next, 3 - c); //���� �������� �Ķ��̿����ϰ� �Ķ� ������ �����̿��� ��.
							//������ 3-1 = 2, 3-2 = 1
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			G[i].clear();
			color[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) {
			if (color[i] == 0) {
				DFS(i, 1);
			}
		}
		bool isBin = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < G[i].size(); j++) {
				int k = G[i][j];
				if (color[i] == color[k])
					isBin = false;
			}
		}
		if (isBin)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}
