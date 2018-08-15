#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

struct Mat{
    long long a, b, c, d;
    Mat operator * (const Mat &B) const {
        Mat re;
        re.a = ( (a*B.a)%MOD + (b*B.c)%MOD )%MOD;
        re.b = ( (a*B.b)%MOD + (b*B.d)%MOD )%MOD;
        re.c = ( (c*B.a)%MOD + (d*B.c)%MOD )%MOD;
        re.d = ( (c*B.b)%MOD + (d*B.d)%MOD )%MOD;
        return re;
    }
};

Mat pow(Mat a, int n){
    Mat re = {1,0,0,1};
    while (n>0){
        if (n&1) re = re * a;
        a = a*a;
        n>>=1;
    }
    return re;
}

pair<int,int> f(int n){
    Mat T = pow( {1,1,1,0}, n );
    return { (T.c+T.d)%MOD, T.c };
}

long long pow(long long a, long long n, long long mod){
    long long re = 1;
    while (n>0){
        if (n&1) re = re * a % mod;
        a = a*a %mod;
        n/=2;
    }
    return re;
}

long long inv(long long x){
    x %= MOD;
    return pow(x,MOD-2,MOD);
}

long long nor(long long x){
    x %= MOD;
    if (x<0) x+=MOD;
    return x;
}

bool check(int n, long long tar, long long u, long long v){
    if (n==0) return tar == u;
    if (n==1) return tar == u+v;
    v += u;
    for (int i=2; i<=n; i++){
        v += u;
        u = v - u;
        if ( v>tar ) return 0;
    }
    return tar == v;
}

int n, x, m, y, k;

int main(){
    int T; cin >> T;
    while (T--){
        cin >> n >> x >> m >> y >> k;
        
        pair<int,int> p1 = f(n);
        long long a1 = p1.first;
        long long b1 = p1.second;
        //printf("%lld %lld\n",a1,b1);

        pair<int,int> p2 = f(m);
        long long a2 = p2.first;
        long long b2 = p2.second;
        //printf("%lld %lld\n",a2,b2);

        if ( a2*b1 == a1*b2 ){
            puts("Impossible");
            continue;
        }

        long long v = (a2*x-a1*y)%MOD * inv(a2*b1-a1*b2) %MOD;
        long long u = (x-b1*v)%MOD * inv(a1) %MOD;
        v = nor(v);
        u = nor(u);
        if ( !check(n,x,u,v) || !check(m,y,u,v) ){
            puts("Impossible");
            continue;
        }
        pair<int,int> p = f(k);
        long long ans = (p.first*u%MOD + p.second*v%MOD)%MOD;
        cout << ans << '\n';
    }
}
