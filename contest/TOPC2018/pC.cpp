#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x, y;

    bool operator < (const Point &b) const {
        return atan2(y,x) < atan2(b.y,b.x);
    }
    Point operator + (const Point &b) const {
        return {x+b.x,y+b.y};
    }
    Point operator - (const Point &b) const {
        return {x-b.x,y-b.y};
    }
    double operator * (const Point &b) const {
        return x*b.x + y*b.y;
    }
    double operator % (const Point &b) const {
        return x*b.y - y*b.x;
    }


};

Point f(Point line, Point p){
    double r = sqrt(p.x*p.x + p.y*p.y);
    double t = 2*atan2(line.y,line.x) - atan2(p.y,p.x);
    return {r*cos(t),r*sin(t)};
}


const int MAXN = 10000;
int n;
Point p[MAXN], tar;

void init(){
    cin >> n;
    cin >> tar.x >> tar.y;
    for (int i=0; i<n; i++) cin >> p[i].x >> p[i].y; 
    sort(p,p+n);
    Point a = f(p[0],tar);
    Point b = f(p[n-1],tar);
    Point v = a-b;
    double len = sqrt(v.x*v.x + v.y*v.y);
    printf("%.10f\n",len);
}


void solve(){
    
}

int main(){
    int T; cin >> T;
    while (T--){
        init();
        solve();
    }

}
