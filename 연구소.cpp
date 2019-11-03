#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int arr[8][8];
bool check[8][8];
int data_arr[10000000];
int data_index;
int n, m , safe;
vector <int> v[64];
int v_index;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int bfs(int xpos, int ypos) {
	queue <pair<int, int>> q;
	q.push({ xpos,ypos });
	check[ypos][xpos] = true;
	int cnt = 0;
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = x1 + dx[i];
			int y = y1 + dy[i];
			if (x >= 0 && y >= 0 && x < m && y < n) {
				if (arr[y][x] == 0 && check[y][x] == false) {
					check[y][x] = true;
					q.push({ x,y });
					cnt++;
				}
			}
		}
	}
	return cnt;
}
void wall(int xpos, int ypos,int index) {
	arr[ypos][xpos] = 1;
	//cout << "index : " << index << " " << xpos << " " << ypos << endl;
	if (index == 2) {
		int sum = 0;
		for (int i = 0; i < v_index; i++) {
			sum += bfs(v[i][1], v[i][0]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				check[i][j] = false;
			}
		}
		data_arr[data_index++] = safe - sum - 3;
		arr[ypos][xpos] = 0;
		return;
	}
	for (int i = ypos; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				if (i == ypos && xpos < j) {
					wall(j, i, index + 1);
				}
				else if (i != ypos) {
					wall(j, i, index + 1);
				}
			}
		}
	}
	arr[ypos][xpos] = 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) safe++;
			else if (arr[i][j] == 2) {
				v[v_index].push_back(i);
				v[v_index].push_back(j);
				v_index++;
			}
 		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				wall(j, i, 0);
			}
		}
	}
	sort(data_arr, data_arr + data_index);
	cout << data_arr[data_index - 1] << endl;
}
