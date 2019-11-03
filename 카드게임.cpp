#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 2000;
int N;
int leftCard[MAX], rightCard[MAX];
int cache[MAX][MAX];
int maxScore(int leftIdx, int rightIdx)
{
	if (leftIdx >= N || rightIdx >= N)
		return 0;
	int &result = cache[leftIdx][rightIdx];
	if (result != -1)
		return result;
	result = 0;
	if (leftCard[leftIdx] > rightCard[rightIdx])
		result += max(rightCard[rightIdx] + maxScore(leftIdx, rightIdx + 1), max(maxScore(leftIdx + 1, rightIdx), maxScore(leftIdx + 1, rightIdx + 1)));
	else
		result += max(maxScore(leftIdx + 1, rightIdx), maxScore(leftIdx + 1, rightIdx + 1));
	return result;
}
int main(){
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> leftCard[i];
	for (int i = 0; i < N; i++)
		cin >> rightCard[i];
	memset(cache, -1, sizeof(cache));
	cout << maxScore(0, 0) << endl;
	return 0;
}