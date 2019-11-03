#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

vector <int> v[10001];
vector <int> e[10001];
bool visit[10001];
bool check[10001];
long long dp[10001];

bool checkCircle(int s) {
	if (check[s]) return false;
	if (visit[s]) return false;
	visit[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (checkCircle(y) == true) e[s].push_back(y);
	}
	check[s] = 1;
	return true;
}

long long key;
long long dfs(int s) {
	if (dp[s] != -1) return dp[s];
	if (s == 2) {
		return 1;
	}
	for (int i = 0; i < e[s].size(); i++) {
		int y = e[s][i];
		dp[s] = (dp[s] + dfs(y));
	}
	return dp[s];
}

int main() {
	memset(dp, -1, sizeof(dp));
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; // ������ �Ϲ����� ������ ��
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);  // �Ϲ� �����̱� ������ �̷��� �޾���
	}
	// ���� ��ΰ� �������� Ȯ���� ��Ŭ�� �����Ǵ��� �ľ��ϸ��
	checkCircle(1);
	if (!check[2]) {
		cout << "inf" << "\n";
		return 0;
	}
	dfs(1); // ���� 2���������� ������ ��θ� ��� Ž��
	cout << dp[1];
}