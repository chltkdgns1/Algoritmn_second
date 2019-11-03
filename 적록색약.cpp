#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

char map[100][100];
char map2[100][100];
bool check[100][100];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n;
void bfs(int xpos,int ypos,int version) {
	queue <pair<int, int>> q;
	q.push({ xpos,ypos });
	char c;
	if(version == 0) c = map[ypos][xpos];
	else c = map2[ypos][xpos];
	check[ypos][xpos] = true;
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = x1 + dx[i];
			int y = y1 + dy[i];
			if (x >= 0 && y >= 0 && x < n && y < n) {
				if (version == 0) {
					if (map[y][x] == c && check[y][x] == false) {
						map[y][x] = 0;
						check[y][x] = true;
						q.push({ x,y });
					}
				}
				else {
					if (map2[y][x] == c && check[y][x] == false) {
						map2[y][x] = 0;
						check[y][x] = true;
						q.push({ x,y });
					}
				}
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		strcpy(map2[i], map[i]);
	}
	int key1 = 0, key2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0) {
				bfs(j, i,0);
				key1++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map2[i][j] == 'G') map2[i][j] = 'R';
			check[i][j] = false;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map2[i][j] != 0) {
				bfs(j, i,1);
				key2++;
			}
		}
	}
	cout << key1 << " " << key2 << endl;
}