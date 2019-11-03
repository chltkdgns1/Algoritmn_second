#include <iostream>
using namespace std;
int n, m;
char map[51][51];
char check[2][8][8] = {
	{{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'} },
	{{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'} }
};

int min1 = 10000;
void Go(int xpos, int ypos) {
	if (xpos + 7 >= m) {
		Go(0, ypos + 1);
		return;
	}
	else if (ypos + 7 >= n) return;
	for (int k = 0; k < 2; k++) {
		int cnt = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (map[i + ypos][j + xpos] != check[k][i][j]) {
					cnt++;
				}
			}
		}
		if (min1 > cnt) min1 = cnt;
	}
	Go(xpos + 1, ypos);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> map[i];
	Go(0, 0);
	cout << min1 << endl;
}