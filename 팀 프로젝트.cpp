#include <iostream>
#include <vector>
using namespace std;
vector <int> v[100001];
char check[100001];
int arr[100001];
int brr[100001];
int n, num;
void dfs(int num, int f, int ar[],int br[],int index) {
	if(br[num] == 1){
		int idx;
		for (int i = index; i >=0; i--) {
			check[ar[i]] = true;
			if (ar[i] == num) {
				idx = i;
				break;
			}
		}
		for (int i = idx -1; i >= 0; i--) {
			check[ar[i]] = -1;
		}
		return;
	}
	if (check[num] == false) {
		br[num] = 1;
		ar[index] = num;
		dfs(v[num][0], f, ar, br,index + 1);
		ar[index] = 0;
		br[num] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> num;
			v[i].push_back(num);
		}
		for (int i = 1; i <= n; i++) {
			if (check[i] == false) {
				arr[0] = i;
				brr[i] = 1;
				dfs(v[i][0],i,arr,brr,1);
				arr[0] = 0;
				brr[i] = 0;
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (check[i] == false || check[i] == -1) cnt++;
			check[i] = 0;
			v[i].clear();
		}
		cout << cnt << "\n";
	}
}