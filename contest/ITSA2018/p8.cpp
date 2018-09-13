#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct str{
    int x, y, z;
    bool operator <  (const str &b) const {
        if (x!=b.x) return x<b.x;
        if (y!=b.y) return y>b.y;
        return z<b.z;
    }
}a[MAXN];

int n;
long long bit[MAXN];
long long pre[MAXN];
long long suf[MAXN];

void init(){
    vector<int> xs, ys;

    scanf("%d", &n);
    for (int i=0; i<n; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        xs.push_back(x);
        ys.push_back(y);
        a[i] = {x,y,z};
    }
    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());
    xs.resize( unique(xs.begin(),xs.end()) - xs.begin() );
    ys.resize( unique(ys.begin(),ys.end()) - ys.begin() );
    for (int i=0; i<n; i++){
        a[i].x = lower_bound(xs.begin(),xs.end(),a[i].x)-xs.begin()+1;
        a[i].y = lower_bound(ys.begin(),ys.end(),a[i].y)-ys.begin()+1;
    }
    sort(a,a+n);

    //for (int i=0; i<n; i++) printf("%d %d %d\n", a[i].x, a[i].y, a[i].z);
}

void build_pre(){
    memset(bit,0,sizeof(bit));
    for (int i=0; i<n; i++){
        // query(a[i].y,n) max
        // trans  ( 1,n+1-a[i].y )
        int w = n+1 - a[i].y;
        long long best = 0;
        while (w>0){
            best = max(best,bit[w]);
            w -= w&-w;
        }
        pre[i] = best + a[i].z;

        // update(a[i].y,pre[i])
        w = n+1 - a[i].y;
        while (w<MAXN){
            bit[w] = max(bit[w],pre[i]);
            w += w&-w;
        }
    }

    //for (int i=0; i<n; i++) printf("%lld ", pre[i]); puts("");
}

void build_suf(){
    memset(bit,0,sizeof(bit));
    for (int i=n-1; i>=0; i--){
        // query(1,a[i].y) max
        int w = a[i].y;
        long long best = 0;
        while (w>0){
            best = max(best,bit[w]);
            w -= w&-w;
        }
        suf[i] = best + a[i].z;
        // update(a[i].y,suf[i])
        w = a[i].y;
        while (w<MAXN){
            bit[w] = max(bit[w],suf[i]);
            w += w&-w;
        }
    }

    //for (int i=0; i<n; i++) printf("%lld ", suf[i]); puts("");
}

void solve(){
    build_pre();
    build_suf();

    for (int i=1; i<n; i++) pre[i] = max(pre[i],pre[i-1]);
    for (int i=n-2; i>=0; i--) suf[i] = max(suf[i],suf[i+1]);

    long long ans = 0;
    for (int i=1; i<n-1; i++){
        ans = max(ans, pre[i]+suf[i+1] );
    }
    for (int i=0; i<n; i++){
        ans = max(ans,pre[i]);
        ans = max(ans,suf[i]);
    }
    cout << ans << '\n';
}

int main (){
    int T; cin >> T;
    for (int ncase=1; ncase<=T; ncase++){
        init();
        solve();
    }
}
