typedef double Double;
struct Point {
	Double x,y;

	bool operator < (const Point &b)const{
		//return tie(x,y) < tie(b.x,b.y);
		//return atan2(y,x) < atan2(b.y,b.x);
		assert(0 && "choose compare");
	}
	Point operator + (const Point &b)const{
		return {x+b.x,y+b.y};
	}
	Point operator - (const Point &b)const{
		return {x-b.x,y-b.y};
	}
	Point operator * (const Double &d)const{
		return {d*x,d*y};
	}
	Point operator / (const Double &d)const{
		return {x/d,y/d};
	}
	Double operator * (const Point &b)const{
		return x*b.x + y*b.y;
	}
	Double operator % (const Point &b)const{
		return x*b.y - y*b.x;
	}
	friend Double abs2(const Point &p){
		return p.x*p.x + p.y*p.y;
	}
	friend Double abs(const Point &p){
		return sqrt( abs2(p) );
	}
};
typedef Point Vector;

struct Line{
	Point P; Vector v;
	bool operator < (const Line &b)const{
		return atan2(v.y,v.x) < atan2(b.v.y,b.v.x);
	}
};
