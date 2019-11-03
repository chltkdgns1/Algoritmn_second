#include <iostream>
#include <math.h>
using namespace std;

class Circle {
public:
	int xpos, ypos;
	int r;
	bool check;
	Circle() {}
};


void CircleSizeCompare(Circle *circle, int length, int *array);
int QuickSort(int first_left, int first_right, int *numbers);
int Distance(int x1, int y1, int x2, int y2);
void IntoCircleXyPrins(int x1, int y1, int x2, int y2, int *array, Circle *circle, int length);
void IntoCircleXyRose(int x, int y, int *array, Circle *circle, int length);

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
		if (-1000 <= x1 && -1000 <= x2 && -1000 <= y1 && -1000 <= y2 && x1 <= 1000 && x2 <= 1000 && y1 <= 1000 && y2 <= 1000 ) {
			cin >> n;
			if (1 <= n && n <= 50) {
				Circle *circle = new Circle[n + 1];
				int *array = new int[n + 1];
				for (int j = 0; j < n; j++) {
					cin >> x >> y >> r;
					if (-1000 <= x && -1000 <= y && x <= 1000 && y <= 1000 && 1<= r && r<=1000) {
						circle[j].xpos = x;
						circle[j].ypos = y;
						circle[j].r = r;
					}
					else {
						return 0;
					}
				}
				CircleSizeCompare(circle, n, array);
				IntoCircleXyPrins(x1, y1, x2, y2, array, circle, n);
				cout << total_cnt << endl;
				//system("pause");
			}
			else {
				return 0;
			}
		}
	}
}

void IntoCircleXyPrins(int x1,int y1,int x2,int y2,int *array,Circle *circle,int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (array[i] == circle[j].r) {
				if (Distance(x1, y1, circle[j].xpos, circle[j].ypos) < circle[j].r) {
					if (Distance(x1, y1, x2, y2) < 2 * circle[j].r) {
						circle[j].check = true;
						// 장미를 둘러싼 원의 개수만 찾으면 됨
						IntoCircleXyRose(x2, y2, array, circle, length);
						return;
					}
					else {
						// 장미를 둘러쌓지 않고 어린 왕자만 둘러싸고 있으므로 이탈 + 1
						circle[j].check = true;
						total_cnt++;
					}
				}
			}
		}
	}
	IntoCircleXyRose(x2, y2, array, circle, length);
}

void IntoCircleXyRose(int x, int y, int *array, Circle *circle, int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (circle[j].check == true) {
				continue;
			}
			if (array[i] == circle[j].r) {
				if (Distance(x, y, circle[j].xpos, circle[j].ypos) < circle[j].r) {
					total_cnt++;
					circle[j].check = true;
				}
			}		
		}
	}
}

int Distance(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

void CircleSizeCompare(Circle *circle,int length,int *array) {
	for (int i = 0; i < length; i++) {
		array[i] = circle[i].r;
	}
	QuickSort(0, length - 1, array);
}

int QuickSort(int first_left, int first_right, int *numbers) { // 치킨 거리 순위
	if (first_left >= first_right) {
		return 0;
	}
	int left = first_left;
	int right = first_right;
	int temp;
	int temp2;
	for (int i = left; i <= right; i++) {
		if (numbers[left] > numbers[i]) {
			if (i - left == 1) {
				temp = numbers[left];
				numbers[left] = numbers[i];
				numbers[i] = temp;
				left = i;
			}
			else {
				temp = numbers[left];
				temp2 = numbers[left + 1];
				numbers[left] = numbers[i];
				numbers[left + 1] = temp;
				numbers[i] = temp2;
				left = left + 1;
			}
		}
	}
	QuickSort(first_left, left - 1, numbers);
	QuickSort(left + 1, first_right, numbers);
}