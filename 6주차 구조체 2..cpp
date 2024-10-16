#include <stdio.h>
#include <math.h>
typedef struct point {  } POINT;

typedef struct circle{  }CIRCLE;

typedef struct rect{  }RECT;

double dist(POINT p1, POINT p2) {
	return sqrt(pow((p2.x - p1.x), 2)pow((p2.y - p1.y), 2));
}
int main() {
	CIRCLE c1 = { {10,10},4.5 };
	CIRCLE c2;
	c2.radius = 5.5;
	c2.center.x = 10;
	c2.center.y = 20;
	POINT point = { 10,15 };
	double distance;

	printf("CIRCLE1=(%d,%d),r:%lf\n", c1.center.x, c1.center.y, c1.radius);
	printf("CIRCLE2=(%d,%d),r:%lf\n", c2.center.x, c2.center.y, c2.radius);
	printf("point=(%d,%d)\n", point.x, point.y);

	distance = dist(c2.center, point);
	if (distance <= c2.radius) {
		printf("원 안에 있습니다.\n");
	}
	else {
		printf("원 안에 있습니다.\n");
	}

	return 0;
}