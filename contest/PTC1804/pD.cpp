#include<bits/stdc++.h>
using namespace std;

int n;
int x[100004], y[100004];
pair<int,int> p[100004];
int ox;
int oy;

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b,a%b);
}

int ABS(int z){return max(z,-z);}

void f(pair<int,int>& z){
    z.first -= ox;
    z.second -= oy;
    if (!z.first && !z.second) return;
    int g = gcd( ABS(z.first), ABS(z.second) );
    z.first /= g;
    z.second /= g;
}

bool check1(){
    for (int i=0;i<n;i++)
        if (!p[i].first && !p[i].second) return true;
    return false;
}

int m=0;
pair<int,int> q[100004];
typedef pair<int,int> pii;
bool cmp(const pii &a, const pii &b){
    return atan2(a.second,a.first) < atan2(b.second,b.first);
}
long long cross(const pii &a, const pii &b){
    return (long long)a.first*b.second - (long long)a.second*b.first;
}

bool check2(){
    m=0;
    for (int i=0; i<n; i++){
        if ( p[i].first==0 && p[i].second==0 )continue;
        q[m++] = p[i];
    }
    sort(q,q+m,cmp);

    if (m==1) return 1;
    for (int l=0, r=1, cnt=1; l<m; l++,cnt--){
        while ( l!=r && q[r]==q[l] ) r=(r+1)%m, cnt++;
        while ( cross(q[l],q[r]) > 0 ) r=(r+1)%m, cnt++;
        if (2*cnt>n) return 0;
    }

    return 1;
}

int main (){
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i=0;i<n;i++){
            int xi, yi;
            scanf("%d%d", &xi,&yi);
            p[i] = {xi,yi};
            x[i] = xi;
            y[i] = yi;
        }
        sort(x, x+n);
        sort(y, y+n);
        ox = x[n/2];
        oy = y[n/2];
        for_each (p, p+n, f);
        if (check1() && check2()) printf("%d %d\n", ox, oy);
        else printf("0\n");
    }
}
