#include <iostream>
using namespace std;

int arr[101];
int brr[101];
int score[101];
int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> arr[i];
	for (int j = 1; j <= m; j++) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> brr[i];
			if (arr[j] == brr[i]) {
				cnt++;
				score[i]++;
			}
		}
		score[arr[j]] += n - cnt;
	}
	for (int i = 1; i <= n; i++) cout << score[i] << endl;
}