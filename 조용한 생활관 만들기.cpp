#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector <int> v[200001];
int d[200001],t[200001]; // �� ��忡 ����� ��
bool visit[200001];
int max1;
void cal(int s){
	visit[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		p[y] = s; // �θ� ���
		if (max1 < d[y] * d[s]) max1 = d[y] * d[s];
		if (!visit[y]) cal(y);
	}
}

bool check(int s) {

}
void dfs(int s,int p,int s_index) { // bool ch �� �� ��� ���̿��� 
	// �־��� ��찡 ������ ���̴�.
	visit[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (max1 == d[y] * d[s]) {

		}
		if (!visit[y]) dfs(y,s,i);
	}
}
	
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		v[a].push_back(i + 1);
		v[i + 1].push_back(a);
	}
	for (int i = 1; i <=n; i++) {
		int a; cin >> a;
		d[i] = a;
	}

	cal(1);
	memset(visit, 0, sizeof(visit));

	while (1) {

	}
}