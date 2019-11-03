#include <iostream>
#include <algorithm>
using namespace std;
int map[100][100];
int x = 3, y = 3; //  열 ,  행
class Data {
public: 
	int data, num; 
};
bool cmp(const Data&a, const Data&b) {
	if (a.num == b.num) return a.data < b.data;
	else return a.num < b.num;
}
int check[101];
Data d[101];
void R(int a,int b) { // 매개변수는 행의 갯수
	int t = x;
	for (int i = 0; i < a; i++) {
		for (int k = 0; k < b; k++) {
			check[map[i][k]]++;
		}
		int cnt = 0;
		for (int k = 1; k <= 100; k++) {
			if (check[k]) {
				d[cnt].data = k;
				d[cnt++].num = check[k];
			}
		}
		sort(d, d + cnt, cmp);
		int index = 0;
		for (int k = 0; k < cnt; k++) {
			map[i][index++] = d[k].data;
			map[i][index++] = d[k].num;
		}
		if (t < index) t = index;
		for (int k = index; k < t; k++) map[i][k] = 0;
		for (int i = 0; i <= 100; i++) {
			check[i] = 0;
			d[i].data = d[i].num = 0;
		}
	}
	x = t;
}

void C(int a,int b) { // 매개변수는 열의 갯수  
	int t = y;
	for (int i = 0; i < b; i++) {
		for (int k = 0; k < a; k++) {
			check[map[k][i]]++;
		}
		int cnt = 0;
		for (int k = 1; k <= 100; k++) {
			if (check[k]) {
				d[cnt].data = k;
				d[cnt++].num = check[k];
			}
		}
		sort(d, d + cnt, cmp);
		int index = 0;
		for (int k = 0; k < cnt; k++) {
			map[index++][i] = d[k].data;
			map[index++][i] = d[k].num;
		}
		if (t < index) t = index;
		for (int k = index; k < t; k++) map[k][i] = 0;
		for (int i = 0; i <= 100; i++) {
			check[i] = 0;
			d[i].data = d[i].num = 0;
		}
	}
	y = t;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int r, c, k;
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			cin >> map[i][k];
		}
	}
	int cnt = 0;
	while (1) {
		if (map[r - 1][c - 1] == k) {
			cout << cnt << "\n";
			break;
		}
		if (y >= x) {
			R(y, x);
			cnt++;
		}
		else {
			C(y, x);
			cnt++;
		}
		if (cnt > 100) { cout << -1 << "\n"; break; }
	}
}