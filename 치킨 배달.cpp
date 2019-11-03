#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int map[50][50];
int n, m;
class xypos {
public:
	int x, y;
	void fresh() { x = -1, y = -1; }
};
xypos xy[2500];
xypos xy_temp[2500];
int xy_index;
xypos peo[2500];
int peo_index;
int cnt1;
int min1 = 1000000;
void Go(int cnt,xypos g[],int index) {
	if (cnt == m) {
		int sum = 0;
		for (int i = 0; i < peo_index; i++) {
			int min = 1000000;
			for (int j = 0; j < cnt1; j++) {
				if (g[j].x != -1 && g[j].y != -1) {
					int num = abs(peo[i].x - g[j].x) + abs(peo[i].y - g[j].y);
					if (min > num) min = num;
				}
			}
			sum += min;
		}
		if (min1 > sum) min1 = sum;
		return;
	}	
	if (index == cnt1) return;
	g[index].fresh();
	Go(cnt - 1, g, index + 1);
	g[index].x = xy[index].x;
	g[index].y = xy[index].y;
	Go(cnt, g, index + 1);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				cnt1++;
				xy[xy_index].x = j;
				xy[xy_index].y = i;
				xy_temp[xy_index].x = j;
				xy_temp[xy_index].y = i;
				xy_index++;
			}
			else if (map[i][j] == 1) {
				peo[peo_index].x = j;
				peo[peo_index].y = i;
				peo_index++;
			}
		}
	}
	Go(cnt1, xy_temp, 0);
	cout << min1 << endl;
}

// 현재 생존한 치킨집
// g 는 제거할 치킨집의 인덱스  xy
// sum 은 치킨집 최소거리
//g 의 index 는 index