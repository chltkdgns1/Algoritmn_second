#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
vector <double> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		double c; cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	double t = 0;
	for (int i = b; i < v.size() - b; i++) t += v[i];
	t /= (v.size() - 2*b); 
	t *= 100; t = round(t); t /= 100; 
	printf("%.2lf\n", t); t = 0;
	for (int i = b; i < v.size() - b; i++) t += v[i];
	t += (v[b] * b + v[v.size() - b - 1] * b);
	t /= v.size();
	t *= 100; t = round(t); t /= 100;
	printf("%.2lf\n", t);
}