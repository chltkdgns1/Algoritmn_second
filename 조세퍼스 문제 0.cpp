#include <iostream>
using namespace std;
int result[1001];
bool check[1001];
int index = 1;
int main() {
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	while(1){
		for (int j = 1; j <= n; j++) {
			if (check[j] == false) {
				cnt++;
				if (cnt == m) {
					check[j] = true;
					result[index++] = j;
					if (index == n + 1) {
						cout << "<";
						for (int i = 1; i <= n; i++) {
							if (i == n) cout << result[i];
							else cout << result[i] << ", ";
						}
						cout << ">";
						return 0;
					}
					cnt = 0;
				}
			}
		}
	}
}