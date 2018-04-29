#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL al, be, ga;

LL l1, l2, l3;
array<LL,4> f, g, h;
void makel(LL l){
    l1 = l;
    l2 = l*l;
    l3 = l*l*l;
}
void makef(){
    f = {-l1, 1,0,0};
    for (int i=0;i<4;i++)f[i] *= 6*ga;
}
void makeg(){
    g = {l2-l1, -2*l1+1,1,0};
    for (int i=0;i<4;i++)g[i] *= 3*be;
}
void makeh(){
    h = {-2*l3+3*l2-l1, 6*l2-6*l1+1, -6*l1+3, 2};
    for (int i=0;i<4;i++)h[i] *= al;
}
void make(LL l){
    makel(l);
    makef();
    makeg();
    makeh();
}

LL ff(LL x){
    LL ret=0;
    LL now = 1;
    for (int i=0;i<4;i++){
        ret += f[i] * now;
        now *= x;
    }
    return ret;
}
LL gg(LL x){
    LL ret=0;
    LL now = 1;
    for (int i=0;i<4;i++){
        ret += g[i] * now;
        now *= x;
    }
    return ret;
}
LL hh(LL x){
    LL ret=0;
    LL now = 1;
    for (int i=0;i<4;i++){
        ret += h[i] * now;
        now *= x;
    }
    return ret;
}

array<LL,4> bitl, bitr;

void makebit(LL l, LL r){
    make(l);
    for (int i=0;i<4;i++){
        bitl[i] = f[i] + g[i] + h[i];
        bitr[i] = -bitl[i];
    }
    bitr[0] += ff(r) - ff(l) + gg(r) - gg(l) + hh(r) - hh(l);
}

const int MAXN = 100005;
void add(long long bit[], int pos, long long val){
    while (pos<MAXN){
        bit[pos] += val;
        pos += pos&(-pos);
    }
}
long long query(long long bit[], int pos){
    long long re=0;
    while (pos>0){
        re += bit[pos];
        pos -= pos&(-pos);
    }
    return re;
}

long long bit[4][MAXN];
void add(int l, int r){
    makebit(l,r);/*
    printf("bitl: "); for (int i=0; i<4; i++) printf("%lld ", bitl[i]); puts("");
    printf("bitr: "); for (int i=0; i<4; i++) printf("%lld ", bitr[i]); puts("");
    printf("f: "); for (int i=0; i<4; i++) printf("%lld ", f[i]); puts("");
    printf("g: "); for (int i=0; i<4; i++) printf("%lld ", g[i]); puts("");
    printf("h: "); for (int i=0; i<4; i++) printf("%lld ", h[i]); puts("");
        add(bit[0],l-1,bitl[0]);
        add(bit[0],r,bitr[0]);*/
    for (int i=0; i<4; i++){
        add(bit[i],l,bitl[i]);
        add(bit[i],r,bitr[i]);
    }
}
long long query(long long x){
    long long re=0;
    re += query(bit[0],x);
    re += x*query(bit[1],x);
    re += x*x*query(bit[2],x);
    re += x*x*x*query(bit[3],x);
    return re;
}
long long query(int l, int r){
    return query(r-1) - query(l-1);
}

int n;

void init(){
    memset(bit,0,sizeof(bit));

    cin >> n;
    cin >> al >> be >> ga;
    for (int i=1, ai; i<=n; i++){
        scanf("%d", &ai);
        add(bit[0],i,(long long)ai*6);
    }
}

int main(){
    int T; cin >> T;
    while (T--){
        init();
        int m; cin >> m;
        for (int i=0; i<m; i++){
            printf("BIT: "); for (int i=1; i<=n; i++)printf("%lld ", (query(i)-query(i-1))/6 ); puts("");
            int cmd, l, r; scanf("%d %d %d", &cmd, &l, &r);
            r++;

            if (cmd==1){
                add(l,r);
            }
            else {
                long long ans = query(l,r);
                const int MOD = 1e9+7;
                ans = (ans/6)%MOD;
                printf("%lld\n",ans);
            }
        }
    }
}

/*
1
3
1 2 3
17 239 999
4
2 1 3
1 2 3
2 2 3
2 1 2
*/
