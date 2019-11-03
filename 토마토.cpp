#include <iostream>
#include <queue>
using namespace std;

int arr[1000][1000];
bool check[1000][1000];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int x2, y2;
queue <pair<int, int>> q;
void Go() {
	while (!q.empty()) {
		int xpos = q.front().first;
		int ypos = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xpos + dx[i];
			int ny = ypos + dy[i];
			if (nx >= 0 && ny >= 0 && nx < x2 && ny < y2) {
				if (check[ny][nx] == false && arr[ny][nx] == 0) {
					arr[ny][nx] = arr[ypos][xpos] + 1;
					check[ny][nx] = true;
					q.push({ nx,ny });
				}
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x2 >> y2;
	for (int i = 0; i < y2; i++) {
		for (int j = 0; j < x2; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < y2; i++) {
		for (int j = 0; j < x2; j++) {
			if (arr[i][j] == 1 && check[i][j] == false) {
				q.push({ j,i });
				check[i][j] = true;
			}
		}
	}
	Go();
	int max = 0, cnt = 0;
	for (int i = 0; i < y2; i++) {
		for (int j = 0; j < x2; j++) {
			if (max < arr[i][j]) max = arr[i][j];
			if (arr[i][j] == 0) cnt++;
		}
	}
	if (cnt != 0) cout << -1 << endl;
	else cout << max - 1 << endl;
}