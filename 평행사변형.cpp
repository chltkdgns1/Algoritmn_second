#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int ax, ay, bx, by, cx, cy;
int main() {
	scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);
	double a = hypot(bx - cx, by - cy), b = hypot(cx - ax, cy - ay), c = hypot(ax - bx, ay - by);
	if ((bx - ax)*(cy - ay) == (by - ay)*(cx - ax)) puts("-1");
	else printf("%.10lf", (max(a, max(b, c)) - min(a, min(b, c))) * 2);
	return 0;
}