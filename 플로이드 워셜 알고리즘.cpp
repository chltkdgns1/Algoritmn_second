#include <iostream>
#include <algorithm>
using namespace std;

int number = 4;
int INF = 100000000;

int a[4][4] = {
	{0,5,INF,8},
    {7,0,9,INF},
	{2,INF,0,4},
	{INF,INF,3,0}
};
int main() {
	for (int mid = 0; mid < 4; mid++) {
		for (int from = 0; from < 4; from++) {
			for (int to = 0; to < 4; to++) {
				a[from][to] = min(a[from][to], a[from][mid] + a[mid][to]);
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	system("pause");
}