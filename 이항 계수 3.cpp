#include <iostream>
typedef long long e;
#define M 1000000007
using namespace std;e f[4000000];e poww(e a,e b){e c=1;while(b){if(b%2){c*=a;c %=M;}a*=a;a%=M;b/= 2;}return c;}int main(){f[1]=f[0]=1;int n, k;cin >>n>>k;for(int i=2;i<=n;i++)f[i]=f[i-1]*i%M;cout<<f[n]*poww(f[k]*f[n-k]%M,M-2)%M;}