#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
bool check[100001];
int convert(int n) {
	if (n == 0) return 0;
	int t = n,c=0;
	while (t) {
		t /= 10;
		c++;
	}
	return n - pow(10, c - 1);
}
int n, t, g, key;
void bfs(int s) {
	check[s] = 1;
	queue <int> q;
	q.push(s);
	int cnt = 0;
	while (1) {
		int len = q.size();
		if (!len) break;
		for (int i = 0; i < len; i++) {
			int n = q.front(), t;
			q.pop();
			if (n == g) {
				key = cnt;
				return;
			}
			if (n + 1 <= 99999 && !check[n + 1]) {
				q.push(n + 1);
				check[n + 1] = 1;
			}
			if (n * 2 <= 99999) {
				t = convert(n * 2);
				if (!check[t]) {
					q.push(t);
					check[t] = 1;
				}
			}
		}
		cnt++;
	}
}
int main() {
	cin >> n >> t >> g;
	if (n == g) {
		cout << key << "\n"; return 0;
	}
	bfs(n);
	if (key > t || !key) cout << "ANG" << "\n";
	else cout << key << "\n";
}

/*
#include<stdio.h>
const int MX=9999999;
int N, T, G, chk[101010], que[202020], fr, rr;
int f(int x){
	int a;
	x*=2;
	for(a=1; x>=a*10; a*=10);
	return x-a;
}
int main(){
	scanf("%d%d%d", &N, &T, &G);
	for(int i=0; i<100000; i++) chk[i]=MX;
	chk[N]=0, que[rr++]=N;
	for(; fr<rr; fr++){
		int a=que[fr], b=f(a);
		if(a<99999 && chk[a+1]==MX) chk[a+1]=chk[a]+1, que[rr++]=a+1;
		if(a && a<50000 && chk[b]==MX) chk[b]=chk[a]+1, que[rr++]=b;
	}
	if(chk[G]<=T) printf("%d\n", chk[G]);
	else puts("ANG");
	return 0;
}
*/