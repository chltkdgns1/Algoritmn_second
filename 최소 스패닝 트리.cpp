#include <iostream>
#include <vector>
using namespace std;

/*

Prim MST 알고리즘

느낀점 :

일단 눈에 보이고 쉽게 구현할 수 있는 방법이다.
그리디 알고리즘은 최선의 방법으로 선택하는 것이지만 과연 그것이 될까하는
검증이 필요하다.
Prim 알고리즘은 일단 시간초과에 걸린다. 그 이유는 가장 적은 간선 비용을 선택하는데
걸리는 시간이 간선의 제곱에 해당하는 시간이 걸려서 시간초과다

따라서 

1. Kruskal MST 알고리즘

그리디 알고리즘을 사용한다. 검증이 필요하지만 이미 검증이 된 알고리즘이다.
실행 순서

1 맨 처음 시작 정점을 신장 트리 집합에 넣는다.

2. 신장 트리 집합 내부 정점들 중 가장 가중치가 낮은 정점을 연결한다.

3. 연결된 정점을 트리 집합 내부에 넣는다.

4 2 - 3 을 반복해서 실행하다가 간선의 개수가 n - 1 개가 되면 종료한다.

*/
vector <pair<int,int>> v[10001]; 
vector <int> e; // 정점들의 집합
bool visit[10001];
long long total;
void searchLowLine() {
	int min = 987654321;
	int b;
	for (int i = 0; i < e.size(); i++) {
		for (int k = 0; k < v[e[i]].size(); k++) {
			int y = v[e[i]][k].second; // 간선 비용
			int x = v[e[i]][k].first; // 도달 정점
			if (min > y && !visit[x]) { // 도달 정점이 이미 방문된 곳이면 안됨
				min = y; b = x;
			}
		}
	}
	visit[b] = 1;
	e.push_back(b);
	total += min;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, r;
	cin >> n >> r;
	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	e.push_back(1); // 맨 처음 시작 정점을 신장 트리 집합에 넣는다.
	visit[1] = 1;
	for (int i = 0; i < n - 1; i++) {
		searchLowLine();
	}
	cout << total << "\n";
}