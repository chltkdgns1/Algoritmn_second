#include <iostream>
using namespace std;

int arr[1001];
int idex = 1;
bool Go(int len, int sum,int m) {
	if (len == 3) {
		if (sum == m) {
			return true;
		}
		return false;
	}
	for (int i = 0; i < idex; i++) {
		if (sum + arr[i] > m) return false;
		if (Go(len + 1, sum + arr[i], m) == true) {
			return true;
		}
   }
   return false;
}
int main() {
	int n , m;
	cin >> n;
	arr[0] = 1;
	int i = 1, cnt = 2 ;
	while (1) {
		i += cnt;
		if (i > 1000) break;
		arr[idex] = i;
		cnt++;idex++;
	}
	for (int i = 0; i < n; i++) {
		cin >> m;
		cout<<Go(0, 0, m)<<endl;
	}
}