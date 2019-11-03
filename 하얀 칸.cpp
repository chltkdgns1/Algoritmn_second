#include <iostream>
using namespace std;
char arr[8][8];
int main() {
	int f_cnt = 0;
	for (int i = 0; i < 8; i++) cin >> arr[i];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] == 'F') {
				if (i % 2 == 0) {
					if (j % 2 == 0) f_cnt++;
				}
				else {
					if (j % 2 == 1)f_cnt++;
				}
			}
		}
	}
	cout << f_cnt << endl;
}