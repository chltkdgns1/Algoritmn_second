#include <iostream>
using namespace std;
char arr[10][10];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int r, c;
void Go(int xpos, int ypos) {
	int x, y;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		x = xpos + dx[i];
		y = ypos + dy[i];
		if (x >= 0 && y >= 0 && x < c && y < r) {
			if (arr[y][x] == '.') cnt++;
		}
		else cnt++;
	}
	if (cnt == 3 || cnt == 4) arr[ypos][xpos] = 'c';
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) cin >> arr[i][j];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'X') {
				Go(j, i);
			}
		}
	}
	int y_first = 0, y_end = 0;
	int x_first = 0, x_end = 0;
	int cnt = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'c') arr[i][j] = '.';
			if (arr[i][j] == 'X') {
				cnt++;
				if (cnt == 1) y_first = i;
				y_end = i;
			}
		}
	}
	cnt = 0;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			if (arr[j][i] == 'X') {
				cnt++;
				if (cnt == 1) x_first = i;
				x_end = i;
			}
		}
	}
	for (int i = y_first; i <= y_end; i++) {
		for (int j = x_first; j <= x_end; j++) cout << arr[i][j];
		cout << endl;
	}
}