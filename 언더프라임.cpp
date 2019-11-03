#include <iostream>
using namespace std;
int arr[100001];
int main() {
	int temp;
	int key_cnt = 0; // 언더프라임 갯수
	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		int j = 2;
		if (arr[i] == 0) {
			while (1) {
				if (i*j > 100000) break;
				arr[i*j] = 1 ;
				j++;
			}
		}
	}
	for (int i = a; i <= b; i++) {
		int cnt = 0; // 인수분해 갯수
		int sosu_cnt = 0;
		if (arr[i] == 0) continue;
		temp = i;
		for (int j = 2; j <= temp; j++) {
			if (temp % j == 0) {
				temp = temp / j;
				j--;
				cnt++;
			}
		}
		for (int j = 2; j <= cnt; j++) {
			if (cnt % j == 0) sosu_cnt++;
		}
		if (sosu_cnt == 1) key_cnt++;
	}
	cout << key_cnt << endl;
	system("pause");
}