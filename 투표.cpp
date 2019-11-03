#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int brr[1001];
int high_list[1001];
int main() {
	int n,m,number,max =0,key=0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= m; i++) cin >> brr[i];
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[j] <= brr[i]) {
				high_list[j]++;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (max < high_list[i]) {
			max = high_list[i];
			key = i;
		}
	}
	cout << key << endl;
}