#include <iostream>
#include <queue>
using namespace std;
int n, m;
int map[101][101];
int data_list[101];
int data_index = 1;
bool check[101];
void bfs(int number) {
	queue <int> q;
	q.push(number);
	check[number] = true;
	int cnt = 1, total=0;
	while (1) {
		int len = q.size();
		if (len == 0) {
			data_list[data_index++] = total;
			break;
		}
		for (int i = 0; i < len; i++) {
			int x = q.front();
			q.pop();
			for (int j = 1; j <= n; j++) {
				if (map[x][j] == 1 && check[j] == false) {
					check[j] = true;
					q.push(j);
					total += cnt;
				}
			}
		}
		cnt++;
	}

}
int main() {
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		bfs(i);
		for (int i = 1; i <= n; i++) check[i] = 0;
	}
	int min = 9999;
	int index;
	for (int i = 1; i <= n; i++) {
		if (min > data_list[i]) {
			min = data_list[i];
			index = i;
		}
	}
	cout << index << endl;
}