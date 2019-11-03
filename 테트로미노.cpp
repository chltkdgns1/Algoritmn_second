#include <iostream>
#include <string.h>
using namespace std;
int map[500][500];
int n, m;
char figure1[2][4][4] = {
	{{1,1,1,1}},
	{ {1}, { 1 }, { 1 }, { 1 } }
};
char figure2[2][2] = { {1,1},{1,1} };
char figure3[8][3][3] = {
	{{1},{1},{1,1} },{{0,1},{0,1},{1,1} },
	{{1,1,1},{1} },{{1,1,1},{0,0,1} },
	{{1,1},{0,1},{0,1} },{{1,1},{1},{1} },
	{{0,0,1},{1,1,1} },{{1},{1,1,1}}
};
char figure4[4][3][3] = {
	{{1,0},{1,1},{0,1} },
{{0,1,1},{1,1,0}},
{{0,1},{1,1},{1,0} },
{{1,1,0},{0,1,1} }
};
char figure5[4][3][3] = {
	{{1,1,1},{0,1,0} },
{{0,1,0},{1,1,1} },
{{0,1}, {1,1},{0,1} },
{{1,0},{1,1},{1,0} }
};
char temp[4][4];
int max1 = 0;
void Go(int xpos, int ypos) {
	int sum = 0;
	int x_cnt = 0, y_cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (temp[i][j] == 1) {
				if (ypos + i >= n) y_cnt++;
				else if (xpos + j >= m) x_cnt++;
			}
		}
	}
	if (y_cnt >= 1) return;
	if (x_cnt >= 1) return Go(0, ypos + 1);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (temp[i][j] == 1) {
				sum += map[ypos + i][xpos + j];
			}
		}
	}
	if (max1 < sum) max1 = sum;
	Go(xpos + 1, ypos);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = figure1[k][i][j];
			}
		}
		Go(0, 0);
	}
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			temp[i][j] = figure2[i][j];
		}
	}
	Go(0, 0);
	memset(temp, 0, sizeof(temp));
	for (int k = 0; k < 8; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp[i][j] = figure3[k][i][j];
			}
		}
		Go(0, 0);
	}
	memset(temp, 0, sizeof(temp));
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp[i][j] = figure4[k][i][j];
			}
		}
		Go(0, 0);
	}
	memset(temp, 0, sizeof(temp));
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp[i][j] = figure5[k][i][j];
			}
		}
		Go(0, 0);
	}
	cout << max1 << endl;
}