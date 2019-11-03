#include <iostream>
using namespace std;
int map[20][20],order[1000],n, m,dir[7];
int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
int x, y, k;
void changeDice(int dirs) {
	int arr[7];
	for (int i = 0; i < 7; i++) arr[i] = dir[i];
	int temp;
	switch (dirs) {
	case 1: // µ¿
		dir[4] = arr[6];
		dir[1]=  arr[4];
		dir[3] = arr[1];
		dir[6] = arr[3];
		break;
	case 2: // ¼­
		dir[3] = arr[6];
		dir[1] = arr[3];
		dir[4] = arr[1];
		dir[6] = arr[4];
 		break;
	case 3: // ºÏ
		dir[5] = arr[6];
	    dir[1] = arr[5];
		dir[2] = arr[1];
		dir[6] =arr[2];
		break;
	case 4: // ³²
		dir[2] = arr[6];
		dir[6] = arr[5];
		dir[5] = arr[1];
		dir[1] = arr[2];
		break;
	}
}
void Go(int xpos, int ypos, int index) {
	if (index == k) return;
	int x = xpos + dx[order[index]];
	int y = ypos + dy[order[index]];
	if (x >= 0 && y >= 0 && x < m && y < n) {
		changeDice(order[index]);
		if (map[y][x] == 0) map[y][x] = dir[6];
		else {
			dir[6] = map[y][x];
			map[y][x] = 0;
		}	
	    cout << dir[1] << endl;
		Go(x, y, index + 1);
	}
	else Go(xpos, ypos, index + 1);
}

int main() {
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) cin >> order[i];
	Go(x, y, 0);
}