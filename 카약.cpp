#include <iostream>
#include <string>
using namespace std;
char map[51][51];
int p[11];
int main() {
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r ; i++) cin >> map[i];
	for (int i = 0; i < r; i++) {
		int index = 0;
		char d;
		for (int j = 0; j < c; j++) {
			if (map[i][j] >= 48 && map[i][j] <= 57) {
				index = j;
				d = map[i][j];
			}
		}
		if(index != 0) 	p[d - 48] = c - 1 - index;
	}
	for (int i = 1; i <= 9; i++) {
		if (p[i] != 0) cout << p[i] << "\n";
	}
	system("pause");
}