#include <iostream>
using namespace std;
int arr[2][101];
int c_index = 0;
int check_index[20];
int main() {
	int n, t, data, cnt = 0, index_cnt = 1, min = 2000, min_cnt = 0;
	cin >> n >> t;
	for (int i = 0; i < t; i++) {
		cin >> data;
		if (cnt == n) {
			if (arr[0][data] == 0) {
				for (int i = 1; i <= 100; i++) if (min > arr[0][i] && arr[0][i]!= 0) min = arr[0][i];
				for (int i = 1; i <= 100; i++) {
					if (arr[0][i] == min && arr[0][i] != 0) {
						check_index[c_index] = i;
						c_index++;
					}
				}
				min_cnt = index_cnt + 1;
				for (int i = 0; i < c_index; i++) {
					if (min_cnt > arr[1][check_index[i]]) min_cnt = arr[1][check_index[i]];
				}
				for (int i = 0; i < c_index; i++) {
					if (min_cnt == arr[1][check_index[i]]) {
						arr[1][check_index[i]] = 0;
						arr[0][check_index[i]] = 0;
					}
				}
				for (int i = 0; i < 20; i++) check_index[i] = 0;
				c_index = 0; min = 2000;
				arr[0][data] ++;
				arr[1][data] = index_cnt;
				index_cnt++;
			}
			else arr[0][data]++;
		}
		else {
			if (arr[0][data] != 0) arr[0][data]++;
			else {
				arr[0][data]++;
				arr[1][data] = index_cnt;
				cnt++; index_cnt++;
			}
		}
	}
	for (int i = 1; i <= 100; i++) {
		if (arr[0][i] != 0) cout << i << " ";
	}
	cout << endl;
}