#include <iostream>
using namespace std;

int collect_cnt = 0;
void SumW(int w, int n, int i, int j);
void InitBool(int n);
int CheckTrue(int n);

int array_bool[2][10001] = { false };
int array_[2][10001];
int direct1[4] = { 0,0,1,-1 };
int direct2[4] = { 1,-1,0,0 };

int main() {
	int test_case;
	int n; // 구역의 개수 /2
	int w; // 특수 소원대의 수
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> n >> w;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> array_[i][j];
			}
		}

	}
}

void InitBool(int n) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			array_bool[i][j] = false;
		}
	}
}

int CheckTrue(int n) {
	int cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			if (array_bool[i][j] == true) {
				cnt++;
			}
		}
	}
}

void SumW(int w, int n, int i, int j) {
	int return_cnt = 0;
	int tree_cnt = 0;
	int big_cnt = 0;
	int xpos, ypos;
	int cnt = 0;
	if (i == 0) {
		for (int k = 0; k < 3; k++) {
			ypos = i + direct1[k];
			xpos = j + direct2[k];
			if (xpos == -1) {
				xpos = n - 1;
			}
			else if (xpos == n) {
				xpos = 0;
			}
			if (array_[ypos][xpos] + array_[i][j] <= w && array_[ypos][xpos] != false) {
				tree_cnt++;
				big_cnt = CheckTrue(n);
				if (tree_cnt != 1) {
					InitBool(n);
				}
				array_bool[ypos][xpos] = true;
				array_bool[i][j] = true;
				if (j + 1 == n) {
					i++;
					j = 0;
				}
				else if (j + 1 == n && j == 1) {
					return;
				}
				SumW(w, n, i, j + 1);
				cnt++;
			}
		}
		if (cnt == 0) {
			if (j + 1 == n) {
				i++;
				j = 0;
			}
			else if (j + 1 == n && j == 1) {
				return;
			}
			SumW(w, n, i, j + 1);
		}
	}
	else {
		for (int k = 1; k < 4; k++) {
			ypos = i + direct2[k];
			xpos = j + direct1[k];
			if (xpos == -1) {
				xpos = n - 1;
			}
			else if (xpos == n) {
				xpos = 0;
			}
			if (array_[ypos][xpos] + array_[i][j] <= w && array_[ypos][xpos] != false) {
				return_cnt = 1;
				tree_cnt++;
				if (tree_cnt != 1) {
					InitBool(n);
				}
				array_bool[ypos][xpos] = true;
				array_bool[i][j] = true;
				if (j + 1 == n) {
					i++;
					j = 0;
				}
				else if (j + 1 == n && j == 1) {
					return;
				}
				SumW(w, n, i, j + 1);
				cnt++;
			}
		}
		if (cnt == 0) {
			if (j + 1 == n) {
				i++;
				j = 0;
			}
			else if (j + 1 == n && j == 1) {
				return;
			}
			SumW(w, n, i, j + 1);
		}
	}

	//return 1 + SumW(w,n,i,j + 1);
}


