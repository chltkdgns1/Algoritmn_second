#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int map[100][100];
bool check[100][100];
int data_arr[10000];
int index;
int n, m, k;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void bfs(int xpos, int ypos) {
	queue <pair<int, int>> q;
	q.push({ xpos,ypos });
	check[ypos][xpos] = true;
	int cnt = 1;
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = x1 + dx[i];
			int y = y1 + dy[i];
			if (x >= 0 && y >= 0 && x < m && y < n) {
				if (map[y][x] == 0 && check[y][x] == false) {
					map[y][x] = 1;
					cnt++;
					check[y][x] = true;
					q.push({ x,y });
				}
			}
		}
	}
	data_arr[index++] = cnt;
}
int main() {
	int x1, y1, x2, y2;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1;  j < x2; j++) {
				map[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				bfs(j, i);
			}
		}
	}
	cout << index << endl;
	sort(data_arr, data_arr + index);
	for (int i = 0; i < index; i++) cout << data_arr[i] << " ";
	cout << endl;
}