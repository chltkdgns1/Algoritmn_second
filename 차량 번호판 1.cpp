
/*
#include <iostream>
#include <string>
using namespace std;
int n[10], alpa[26], cnt;
string s, t;
bool check(int index) {
	if (!index)return true;
	else {
		if (t[index - 1] == t[index]) return false;
	}
	return true;
}

void dfs(int index) {
	if (index == s.length()) {
		cnt++;
		return;
	}
	if (s[index] == 'd') {
		for (int i = 0; i < 10; i++) {
			t += (i + 48);
			if (check(index)) dfs(index + 1);
			t.pop_back();
		}
	}
	else {
		for (int i = 0; i < 26; i++) {
			t += i + 65;
			if (check(index)) dfs(index + 1);
			t.pop_back();
		}
	}
}
int main() {
	cin >> s;
	dfs(0);
	cout << cnt << "\n";
}
*/

#include <iostream>
#include <string>
using namespace std;
int main(){
	long long res=1;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='c'){
			if (s[i + 1] == 'c') res *= 25 ;
			else res*=26;
		}
		else if(s[i]=='d'){
			if(s[i+1]=='d')res*=9;
			else res*=10;
		}
		res %= 1000000009;
	}
	cout<<res;
}
