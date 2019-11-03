#include <iostream>
using namespace std;
char arr[50][50];
char key[50][50];
int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) cin >> key[i];
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (arr[i][j] != key[i][j]) {
				cnt++;
				for (int k = i; k < i + 3; k++) {
					for (int l = j; l < j + 3; l++) {
						if (arr[k][l] == '1') arr[k][l] = '0';
						else if (arr[k][l] == '0') arr[k][l] = '1';
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != key[i][j]){
				cout << "-1" << endl;
			    return 0;
			}
		}
	}
	cout << cnt << endl;
}