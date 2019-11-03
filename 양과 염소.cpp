#include <iostream>
using namespace std;
 
int a, b; // a b 그램
int n; // 양 염소 합 수
int w; // 전체 사료
// a 3 b 4 일 때 
// w 20 
int main() {
	int cnt = 0;
	int two_cnt = 0;
	int temp_a=0;
	int temp_b=0;
	cin >> a >> b >> n >> w;
	if (1 <= a && a <= 1000 && 1 <= b && b <= 1000 && 2 <= n && n <= 1000 && 2 <= w && n <= 1000000) {
		while (w >= 0) {
			cnt++;
			w = w - a;
			if (w%b == 0 && w>=b && cnt+w/b==n) {
				two_cnt++;
				if (two_cnt == 2) {
					//cout << "cnt : " << cnt << endl;
					//cout << "w/b : " << w / b << endl;
					cout << "-1" << endl;
					//system("pause");
					return 0;
				}
				temp_a = cnt;
				temp_b = w / b;
				//cout << "cnt : " << cnt << endl;
				//cout << "w/b : " << w / b << endl;
			}
		}
		if (temp_a == 0 && temp_b == 0) {
			cout << "-1" << endl;
		}
		else {
			cout << temp_a << " " << temp_b << endl;
		}
		system("pause");
	}
}

/*
while (1) {
			cnt++;
			w = w - a;
			if (w%b == 0) {
				two_cnt++;
				if (two_cnt == 2) {
					cout << "-1" << endl;
					return 0;
				}
			}
		}

*/