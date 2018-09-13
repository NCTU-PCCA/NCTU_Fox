#include <bits/stdc++.h>
using namespace std;

using Double = double;
const Double EPS = 1e-9;


struct Point{
    Double x, y;
    bool operator < (const Point &b) const {
        if ( fabs( x-b.x ) > EPS ) return x < b.x;
        if ( fabs( y-b.y ) > EPS ) return y < b.y;
        return false;
    }

    Point operator -(const Point& b) const{
        return Point{x-b.x, y-b.y};
    }
    
    Double operator % (const Point &b) const {
        return x*b.y - y*b.x;
    }
};

Double abs2( Point p ){
    return p.x * p.x + p.y * p.y;
}

Point circumcentre(const Point& p0, const Point& p1, const Point& p2){
    Point a = p1 - p0;
    Point b = p2 - p0;
    Double c1 = abs2(a) * 0.5;
    Double c2 = abs2(b) * 0.5;
    Double d = a % b;
    Double x = p0.x + ( c1*b.y - c2*a.y ) / d;
    Double y = p0.y + ( c2*a.x - c1*b.x ) / d;
    return {x,y};
}

bool online(const Point &a, const Point &b, const Point &c){
    return fabs( (c-a)%(b-a) ) < EPS;
}

int n;
Point p[400];

int main(){
    scanf("%d", &n);
    if (n==1 || n==2){
        printf("%d\n", n);
        return 0;
    }
    for (int i=0; i<n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = {(Double)x,(Double)y};
    }
    random_shuffle(p,p+n);
    int k = min(n,50);
    int mx = 2;
    for (int i=0; i<k; i++){
        for (int j=i+1; j<k; j++){
            map< Point, int > cnt;
            for (int k=0; k<n; k++) if(k!=i && k!=j && !online(p[i], p[j], p[k])){
                Point o = circumcentre(p[i],p[j],p[k]);
                auto &dp = cnt[o];
                dp++;
                mx = max(mx,dp+2);
            }
        }
    }            
    if ( mx >= (n+1)/2 )
        cout << mx << '\n';
    else 
        cout << "i don't know\n";
}
