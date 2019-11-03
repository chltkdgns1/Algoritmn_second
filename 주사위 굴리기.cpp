#include <iostream>
using namespace std;

int map[20][20];
int order[1000];
int n, m;
int dice[7][2] = { {-1,-1},{1,6},{2,5},{3,4},{4,3},{5,2},{6,1} };
int dir[7][5] = { {0,-1,-1,-1,-1},
{0,3,4,2,5}, //1
{0,3,4,6,1}, //2
{0,6,1,2,5}, //3
{0,1,6,2,5}, //4
{0,3,4,1,6}, //5
{0,3,4,5,2}, //6
};
int datas[7];
int top = 1;
int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,-1,1};
int x, y, k;
void Go(int xpos, int ypos,int index,int place) {
	// 1 에서 북쪽으로 가라고 한다면
	// 정리
	/*
	인덱스 1  2  3  4  5  6 
	       1  2  3  4  5  6
	       1에서 4 를 할경우 바닥은 5가 찍히고 
		   1 -> 6 2 5  3 4
		   현재 바닥상태 
	*/
	if (index == k) return;
	int x = xpos + dx[order[index]];
	int y = ypos + dy[order[index]];
	if (x >= 0 && y >= 0 && x < m && y < n) {
		place = dir[place][order[index]];
		if (map[y][x] == 0) map[y][x] = datas[place];
		else {
			datas[place] = map[y][x];
			map[y][x] = 0;
		}
		//cout << place << " " << datas[place] << endl;
		//cout << datas[dice[place][1]] << endl;
		Go(x, y, index + 1, place);
	}
	else Go(xpos, ypos, index + 1, place);
}

int main() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) cin >> order[i];
	Go(x, y ,0,1);
	system("pause");
}