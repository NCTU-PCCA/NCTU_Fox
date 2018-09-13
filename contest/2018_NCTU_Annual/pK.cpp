#include <bits/stdc++.h>
using namespace std;
using LL = long long;

inline LL myabs(LL x){
    return max(x, -x);
}

LL ans = 1ll<<60;

void solve(size_t idx, const vector<LL>& a, const vector<LL>& b){
    LL x = a[idx];
    size_t p = 0;
    for (size_t i=0; i<a.size(); i++) if(i != idx){
        while (p+1 < b.size() && myabs(b[p+1]-x-a[i]) <= myabs(b[p]-x-a[i])) p++;
        ans = min(ans, myabs(b[p] - x - a[i]));
    }
}

int main(){
    vector<LL> a;
    vector<LL> b;
    int n; scanf("%d", &n);
    for (int i=0; i<n; i++){
        LL x;
        scanf("%lld", &x);
        if (x<0) b.push_back(-x);
        else a.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (!a.size()){
        cout <<b[0]+b[1]+b[2] <<'\n';
        return 0;
    }
    if (!b.size()){
        cout <<a[0]+a[1]+a[2] <<'\n';
        return 0;
    }
    for (size_t i=0; i<a.size(); i++)
        solve(i, a, b);
    for (size_t i=0; i<b.size(); i++)
        solve(i, b, a);
    cout <<ans <<'\n';
}
