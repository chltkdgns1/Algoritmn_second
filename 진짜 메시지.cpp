#include <iostream>
#include <string.h>
using namespace std;
char arr[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		bool on_off = true;
		int index_cnt[26] = { 0, };
		cin >> arr;
		for (int j = 0; arr[j] != NULL; j++) {
			index_cnt[arr[j] - 65] ++;
			if (index_cnt[arr[j] - 65] % 4 == 3) {
				if (arr[j + 1] != NULL ) {
					if (arr[j + 1] != arr[j]) on_off = false;
				}
				else if (arr[j + 1] == NULL) {
					on_off = false;
				}
			}
		}
		if (on_off == false) cout << "FAKE" << endl;
		else cout << "OK" << endl;
	}
}



// abcdefghijklmnopqrstuvwxyz

// 3 + 1 3 + 1 