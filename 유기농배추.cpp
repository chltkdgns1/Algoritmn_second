#include <iostream>
using namespace std;

int map[51][51] = { 0 };
bool map_[51][51] = { false};
void Go(int xpos, int ypos);

int CntMap();
int m, n;
int total_cnt = 0;
int main() {
	int test_case;
	int k;
	int xpos, ypos;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> m >> n >> k; 
		for (int j = 0; j < k; j++) {
			cin >> xpos >> ypos;
			map[ypos][xpos] = 1;
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[j][k] != 0) {
					map_[j][k] = true;
					Go(k, j);
				}
			}
		}
		cout<<CntMap()<<endl;
	}
}

int CntMap() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				cnt++;
			}
		}
	}
	return cnt;
}

void Go(int xpos, int ypos) {
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int xpos_, ypos_;
	for (int i = 0; i < 4; i++) {
		xpos_ = xpos + dx[i];
		ypos_ = ypos + dy[i];
		if (xpos_ != -1 && xpos_ != m && ypos_ != -1 && ypos_ != n) {
			if (map[ypos_][xpos_] != 0 && map_[ypos_][xpos_] == false) {
				map_[ypos_][xpos_] = true;
				map[ypos_][xpos_] = map[ypos][xpos] + 1;
			}
		}
	}
}





/*
#include <iostream>
using namespace std;

int map[51][51] = { 0 };
int map_[51][51] = {0};
void Go(int xpos, int ypos);
void PrintMap();
int m, n;
int total_cnt = 0;
int main() {
	int test_case;
	int k;
	int xpos, ypos;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> m >> n >> k; // 가로 길이 m 세로길이 n
		for (int j = 0; j < k; j++) {
			cin >> xpos >> ypos;
			map[ypos][xpos] = 1;
		}
		PrintMap();
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[j][k] == 1) {
					map_[j][k] = true;
					Go(k, j);
				}
			}
		}
		PrintMap();
		cout << total_cnt << endl;
	}
	system("pause");
}

void PrintMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map_[i][j] << " ";
		}
		cout << endl;
	}
}
void Go(int xpos,int ypos) {
	int dir_cnt = 0;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int xpos_, ypos_;
	for (int i = 0; i < 4; i++) {
		xpos_ = xpos + dx[i];
		ypos_ = ypos + dy[i];
		if (xpos != -1 && xpos != m && ypos != -1 && ypos != n) {
			if (map[ypos_][xpos_] == 1  && map_[ypos_][xpos_] == false) {
				map_[ypos_][xpos_] = true;
				dir_cnt++;
			}
		}
	}
	if (dir_cnt == 0) {
		total_cnt++;
		cout << "toltal_cnt : " << total_cnt << endl;
		cout << "xpos : " << xpos << " ypos : " << ypos << endl;
	}
}
*/