#include <iostream>
#include <math.h>
using namespace std;
int Distance(int x1, int y1, int x2, int y2);
int total_cnt = 0;
int main() {
	int case_t;
	int x1, y1;
	int x2, y2;
	int x, y, r;
	int n;
	cin >> case_t;
	for (int i = 0; i < case_t; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> x >> y >> r;
			if (Distance(x1, y1, x, y) < r ) {
				if(!(Distance(x2, y2, x, y) < r))
				total_cnt++;
			}
			if ((Distance(x2, y2, x, y) < r)) {
				if (!Distance(x1, y1, x, y) < r)
					total_cnt++;
			}
		}
		cout << total_cnt << endl;
		//system("pause");
	}
}

int Distance(int x1, int y1, int x2, int y2) {
	return sqrt(((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
}

/*
#include <iostream>
#include <math.h>
using namespace std;
int Distance(int x1, int y1, int x2, int y2);
int total_cnt = 0;
int main() {
	int case_t;
	int x1, y1;
	int x2, y2;
	int x, y, r;
	int n;

	cin >> case_t;
	for (int i = 0; i < case_t; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (-1000 <= x1 && -1000 <= x2 && -1000 <= y1 && -1000 <= y2 && x1 <= 1000 && x2 <= 1000 && y1 <= 1000 && y2 <= 1000) {
			cin >> n;
			if (1 <= n && n <= 50) {
				for (int j = 0; j < n; j++) {
					cin >> x >> y >> r;
					if (Distance(x1, y1, x, y) < r && Distance(x2,y2,x,y) > r){
						total_cnt++;
					}
					else if (Distance(x1, y1, x, y) > r && Distance(x2, y2, x, y) < r) {
						total_cnt++;
					}
				}
				cout << total_cnt << endl;
				//system("pause");
			}
			else {
				return 0;
			}
		}
	}
}

int Distance(int x1, int y1, int x2, int y2) {
	return sqrt(abs((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
}

*/
