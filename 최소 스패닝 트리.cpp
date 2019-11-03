#include <iostream>
#include <vector>
using namespace std;

/*

Prim MST �˰���

������ :

�ϴ� ���� ���̰� ���� ������ �� �ִ� ����̴�.
�׸��� �˰����� �ּ��� ������� �����ϴ� �������� ���� �װ��� �ɱ��ϴ�
������ �ʿ��ϴ�.
Prim �˰����� �ϴ� �ð��ʰ��� �ɸ���. �� ������ ���� ���� ���� ����� �����ϴµ�
�ɸ��� �ð��� ������ ������ �ش��ϴ� �ð��� �ɷ��� �ð��ʰ���

���� 

1. Kruskal MST �˰���

�׸��� �˰����� ����Ѵ�. ������ �ʿ������� �̹� ������ �� �˰����̴�.
���� ����

1 �� ó�� ���� ������ ���� Ʈ�� ���տ� �ִ´�.

2. ���� Ʈ�� ���� ���� ������ �� ���� ����ġ�� ���� ������ �����Ѵ�.

3. ����� ������ Ʈ�� ���� ���ο� �ִ´�.

4 2 - 3 �� �ݺ��ؼ� �����ϴٰ� ������ ������ n - 1 ���� �Ǹ� �����Ѵ�.

*/
vector <pair<int,int>> v[10001]; 
vector <int> e; // �������� ����
bool visit[10001];
long long total;
void searchLowLine() {
	int min = 987654321;
	int b;
	for (int i = 0; i < e.size(); i++) {
		for (int k = 0; k < v[e[i]].size(); k++) {
			int y = v[e[i]][k].second; // ���� ���
			int x = v[e[i]][k].first; // ���� ����
			if (min > y && !visit[x]) { // ���� ������ �̹� �湮�� ���̸� �ȵ�
				min = y; b = x;
			}
		}
	}
	visit[b] = 1;
	e.push_back(b);
	total += min;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, r;
	cin >> n >> r;
	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	e.push_back(1); // �� ó�� ���� ������ ���� Ʈ�� ���տ� �ִ´�.
	visit[1] = 1;
	for (int i = 0; i < n - 1; i++) {
		searchLowLine();
	}
	cout << total << "\n";
}