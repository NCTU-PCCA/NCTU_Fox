#include <bits/stdc++.h>
using namespace std;

int ds[10004];

int boss(int x){
    if (x==ds[x]) return x;
    return ds[x] = boss(ds[x]);
}

struct yee{
    int u, v, w;
    bool operator<(const yee& y)const{
        return w > y.w;
    }
};

int n, m;
priority_queue<yee> pq1, pq2;

void init(){
    for (int i=0;i<10004;i++){
        ds[i] = i;
    }
    cin >>n >>m;
    for (int i=0;i<n;i++){
        int x; cin >>x;
        pq1.push({i, n, x});
    }
    for (int i=0;i<m;i++){
        int u, v, x;
        cin >>u >>v >>x;
        pq1.push({u, v, x});
        pq2.push({u, v, x});
    }
}

void solve(){
    long long ans1 = 0, ans2 = 0;
    while (!pq1.empty()){
        auto x = pq1.top(); pq1.pop();
        int ub = boss(x.u);
        int vb = boss(x.v);
        if (ub != vb){
            ds[ub] = vb;
            ans1 += x.w;
        }
    }
    for (int i=0;i<10004;i++){
        ds[i] = i;
    }
    while (!pq2.empty()){
        auto x = pq2.top(); pq2.pop();
        int ub = boss(x.u);
        int vb = boss(x.v);
        if (ub != vb){
            ds[ub] = vb;
            ans2 += x.w;
        }
    }
    cout <<min(ans1, ans2) <<'\n';
}

int main(){
    cin.tie(0);
    int T; cin >>T;
    while (T--){
        init();
        solve();
    }
}
