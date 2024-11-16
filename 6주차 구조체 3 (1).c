#include <stdio.h>
#include <math.h>
typedef struct point {
	int x;
	int y;
} POINT;

typedef struct {
	POINT center;
	double radius;
}CIRCLE;
typedef struct rect {
	POINT lb;
	POINT rt;
}RECT;

double dist(POINT p1, struct point p2) {
	return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}