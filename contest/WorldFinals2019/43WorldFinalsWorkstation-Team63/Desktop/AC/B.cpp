#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using LL = long double;

struct Point{
    long double x, y;
    Point operator - (const Point &b){
        return {x-b.x, y-b.y};
    }
};

const int MAXN = 10004;
const LL INF = 1e18; // enough or not?

int n, H; LL alpha, beta;
Point p[MAXN];
LL dp[MAXN];

void init(){
    cin >> n >> H >> alpha >> beta;
    for (int i=1; i<=n; i++){
        cin >> p[i].x >> p[i].y;
    }
}

inline LL Sqr(LL x){
    return x*x;
}

inline LL dis(const Point &a, const Point &b){
    return Sqr(a.x-b.x) + Sqr(a.y-b.x);
}

bool ok1(int l, int r){
    LL d = (p[r].x - p[l].x) / 2;
    Point o{ p[l].x+d, H-d };
    d = Sqr(d);
    for (int i=l; i<=r; i++){
        if ( p[i].y > o.y && dis(p[i],o) > d ){
            return false;
        }
    }
    return true;
}

inline LL w(int l, int r){
    return alpha * (H - p[r].y) + beta * Sqr(p[r].x - p[l].x);
}

void solve1(){
    dp[1] = alpha * ( H - p[1].y );
    for (int i=2; i<=n; i++){
        dp[i] = INF;
        for (int j=1; j<i; j++){
            if ( ok1(j,i) ){
                dp[i] = min( dp[i], dp[j] + w(j,i));
            }
        }
    }
    if ( dp[n]==INF ) cout << "impossible" << endl;
    else cout << dp[n] << '\n';
}

void solve(){
    dp[1] = alpha * ( H - p[1].y );
    for (int i=2; i<=n; i++){
        dp[i] = INF;
        Point o {p[i].x, (long double)H};

        LL gl = p[i].x - (H-p[i].y)*2, gr = p[i].x;
        for (int j=i-1; j>=1; j--){
            Point v = p[j] - o;
            LL x = v.x;
            LL y = v.y;
            LL r[2] = { -(x+y), sqrtl(2*x*y) };
            r[0] -= r[1];
            r[1] = r[0] + 2*r[1]; 
            LL lb = p[i].x - r[1] * 2;
            LL rb = p[i].x - r[0] * 2;
            if ( v.y < -r[0]  ){
                rb = p[i].x;
            }
            gl = max(gl,lb);
            gr = min(gr,rb);
            if ( gl<= p[j].x && p[j].x <=gr ){
                dp[i] = min( dp[i], dp[j] + w(j,i));
            }
        }
    }
    if ( dp[n]==INF ) cout << "impossible" << endl;
    else cout << (long long) roundl( dp[n] ) << '\n';
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);

    init();
    solve();
}
