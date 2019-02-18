vector<Point> interCircle(Point o1, Double r1, Point o2, Double r2) {
	Double d2 = abs2(o1 - o2);
	Double d = sqrt(d2);
	Point u = (o1+o2)*0.5 + (o1-o2)*(r2*r2-r1*r1)/(2.0*d2);
    if (abs((r1+r2)*(r1+r2) - d2) < 1e-6) return {u};
	if (d < fabs(r1-r2) || r1+r2 < d) return {};
	Double A = sqrt((r1+r2+d) * (r1-r2+d) * (r1+r2-d) * (-r1+r2+d));
	Point v = Point{o1.y-o2.y, -o1.x+o2.x} * A / (2.0*d2);
	return {u+v, u-v};
}
