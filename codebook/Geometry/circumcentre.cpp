#include "2Dpoint.cpp"

Point circumcentre(Point &p0, Point &p1, Point &p2){
	Point a = p1-p0;
	Point b = p2-p0;
	Double c1 = abs2(a)*0.5;
	Double c2 = abs2(b)*0.5;
	Double d = a % b;
	Double x = p0.x + ( c1*b.y - c2*a.y ) / d;
	Double y = p0.y + ( c2*a.x - c1*b.x ) / d;
	return {x,y};
}
