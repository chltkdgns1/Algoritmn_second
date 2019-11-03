#include <iostream>
#include <set>
#include <string>
using namespace std;
int arr[10], d[10], n, k, che[10];
string s;
set <int> h;
void dfs2(int index,int cnt) {
	if (index == cnt) {
		h.insert(stoi(s));
		return;
	}
	for (int i = 0; i < cnt; i++) {
		if (!che[i]) {
			che[i] = 1;
			string t = to_string(d[i]);
			int len = t.length();
			s += t;
			dfs2(index + 1, cnt);
			while(len--) { s.pop_back(); }
			che[i] = 0;
		}
	}
}

void dfs(int index,int cnt) {
	if (cnt == k) {
		dfs2(0, cnt);
		s.clear();
		return;
	}
	if (index >= n) return;
	d[cnt] = arr[index];
	dfs(index + 1, cnt + 1);
	d[cnt] = 0;
	dfs(index + 1, cnt);
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> arr[i];
	dfs(0, 0);
	cout << h.size() << "\n";
}

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, K;
string a[11];
int main(){
	scanf("%d %d", &N, &K);
	set<string> st;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	sort(a, a + N);
	do{
		string temp;
		for(int i = 0; i < K; i++)
			temp += a[i];
		st.insert(temp);
	}while(next_permutation(a, a + N));
	printf("%d\n", (int)st.size());
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
map<string,bool> m;
int n,k,a;
string str_arr[11];
bool check[11];
void af(int nk,string str){
	if(nk==k){
		if(!m[str]){
			m[str]=true;
			a++;
		}
	}else{
		for(int i=0;i<n;i++){
			if(check[i]) continue;
			check[i]=true;
			af(nk+1,str+str_arr[i]);
			check[i]=false;
		}
	}
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>str_arr[i];
	af(0,"");
	cout<<a;
}
*/