vector<Double> interCircle(Double o1, Double r1, Double o2, Double r2) {
	Double d2 = abs2(o1 - o2);
	Double d = sqrt(d2);
	if (d < fabs(r1-r2) || r1+r2 < d) return {};
	Double u = 0.5*(o1+o2) + ((r2*r2-r1*r1)/(2.0*d2))*(o1-o2);
	Double A = sqrt((r1+r2+d) * (r1-r2+d) * (r1+r2-d) * (-r1+r2+d));
	Double v = A / (2.0*d2) * Double(o1.S-o2.S, -o1.F+o2.F);
	return {u+v, u-v};
}