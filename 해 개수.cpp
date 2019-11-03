#include <iostream>
typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b, c, x1, x2, y1, y2;
	cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;

	if (-(a*b) < 0) {
		ll s = (a*x1 + c) / b, e = (a*x2 + c) / b;
		if ((s < y1 && s < y2) || (e > y1 && e > y2)) cout << 0 << "\n";
		// 범위 밖에 있는 경우
		else if (y2 >= s && e <= y1) {
			// 이럴 경우 범위 내부에 있는 경우
			// 범위 내의 b 의 배수들을 모조리 구하면 됨
		}
		else if (s > y2 && e >= y1) {// 범위에 걸쳐있는 경우
		  // y2 e범위 사이에 b 의 배수들
		}
		else if (s <= y2 && e < y1) {

		}

	}
	else if (a == 0) {
		if (!(c % b) && (y1 <= -(c / b) && -(c / b) <= y2)) cout << 1 << "\n";	
		else cout << 0 << "\n";
	}
	else {
		// 왼쪽 아래에서 오른쪽 위로 올라가는 직선
	}
	system("pause");
}

// 오른쪽 위에서 왼쪽 아래로 내려가는 직선
	// y = (-ax - c) /b 이렇게 한 다음 b 로 나누어서 0 인 부분을 찾고
	// 저 범위가 y 의 범위 안에 들어가면 오케이
	// 중요한 것은 x의 범위 둘다 시작부터 끝까지 만족하지 않는 경우
	// 여기서 겹치는 부분이 생기게 되는데 겹치는 부분을 찾아야함
	// 예를들어 x = 2 x = 10 이라고 했을 때
	// y = 3 y = 15 이고 실제 주어진 범위에서 얼마나 겹치는지 파악을 해야함
	// 