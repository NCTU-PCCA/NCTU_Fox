#include "circumcentre.cpp"
pair<Point,Double> SmallestCircle(int n, Point _p[]){
	Point *p = new Point[n];
	memcpy(p,_p,sizeof(Point)*n);
	random_shuffle(p,p+n);
	
	Double r2=0;
	Point cen;
	for (int i=0; i<n; i++){
		if ( abs2(cen-p[i]) <= r2)continue;
		cen = p[i], r2=0;
		for (int j=0; j<i; j++){
			if ( abs2(cen-p[j]) <= r2)continue;
			cen = (p[i]+p[j])*0.5;
			r2 = abs2(cen-p[i]);
			for (int k=0; k<j; k++){
				if ( abs2(cen-p[k]) <= r2)continue;
				cen = circumcentre(p[i],p[j],p[k]);
				r2 = abs2(cen-p[k]);
			}
		}
	}

	delete[] p;
	return {cen,r2};
}
// auto res = SmallestCircle(,);
