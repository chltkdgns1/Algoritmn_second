#include <iostream>
#include <math.h>
using namespace std;
int arr[1001];
bool visit[1001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int index = 1;
	for(int i=0;i< n;i++){
		cout << index << " ";
		if (i == n - 1) break;
		visit[index] = 1;
		int t = arr[index];
		if (t > 0) {
			int cnt = 0;
			while (1) {
				index++;
				if (index == n + 1) index = 1;
				if (!visit[index]) {
					cnt++;
					if (cnt == t) break;
				}
			}
		}
		else if(t <0){
			int cnt = 0;
			while (1) {
				index--;
				if (index == 0) index = n;
				if (!visit[index]) {
					cnt++;
					if (cnt == abs(t)) break;
				}
			}
		}
	}
}