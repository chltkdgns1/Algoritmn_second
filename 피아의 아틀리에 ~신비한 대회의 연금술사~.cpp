#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int z[11][4][4]; // 재료
char cz[12][5][5]; // 재료의 색상
pair <int, char> map[5][5]; // 격자판
int n;
void rotation(int index) { // index 번째 재료의 회전
	int t1[4][4]; char t2[5][5];
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			t1[k][3 - i] = z[index][i][k];
			t2[k][3 - i] = cz[index][i][k];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			z[index][i][k] = t1[i][k];
			cz[index][i][k] = t2[i][k];
		}
	}
}
int res;
void dfs(int cnt, vector <int> v) {
	if (cnt == 3) { 
		int r = 0, b = 0, g = 0, y = 0;
		for (int i = 0; i < 5; i++) {
			for (int k = 0; k < 5; k++) {
				if (map[i][k].second == 'R') r += map[i][k].first;
				else if (map[i][k].second == 'B') b += map[i][k].first;
				else if (map[i][k].second == 'G') g += map[i][k].first;
				else if (map[i][k].second == 'Y')y += map[i][k].first;
			}
		}
		int d = 7 * r + 5 * b + 3 * g + 2 * y;
		if (res < d) res = d; 
		return;
	}
	pair <int, char> m[5][5];
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			m[i][k] = map[i][k]; 
		}
	}
	int index = v[cnt];
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; k++) {
			for (int w = 0; w < 4; w++) {
				rotation(index);
				for (int q = 0; q < 4; q++) {
					for (int r = 0; r < 4; r++) {
						int x = k + r, y = i + q;
						map[y][x].first += z[index][q][r];
						map[y][x].first = map[y][x].first < 0 ? 0 : map[y][x].first;
						map[y][x].first = map[y][x].first > 9 ? 9 : map[y][x].first;
						if(cz[index][q][r] != 'W') map[y][x].second = cz[index][q][r];
					}
				}
				dfs(cnt + 1,v);
				for (int i = 0; i < 5; i++) {
					for (int k = 0; k < 5; k++) {
						map[i][k] = m[i][k]; // 초기화
					}
				}
			}
		}
	}
}
vector <int> v;
void ranNum(int cnt,int index) {
	if (cnt == 3) {
		vector <int> d = v;
		do {
			dfs(0, d);
		}while(next_permutation(d.begin(), d.end()));
		return;
	}
	if (index > n) return;
	v.push_back(index);
	ranNum(cnt + 1, index + 1);
	v.pop_back();
	ranNum(cnt, index + 1);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < 4; k++) {
			for (int r = 0; r < 4; r++) {
				cin >> z[i][k][r];
			}
		}
		for (int k = 0; k < 4; k++) {
			for (int r = 0; r < 4; r++) {
				cin >> cz[i][k][r];
			}
		}
	}
	ranNum(0, 1);
	cout << res << "\n";
}