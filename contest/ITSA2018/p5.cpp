#include<bits/stdc++.h>
using namespace std;

const int MAXN = 50;
int n;
long long a[MAXN];

void init(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    long long ans=0;
    long long b = 1;
    for (int i=n-1; i>=0; i--){
        ans += a[i] * b;
        b*=2LL;
    }
    cout << ans << '\n';
}

void solve(){
}

int main (){
    int T; cin >> T;
    for (int ncase=1; ncase<=T; ncase++){
        init();
        solve();
    }
}
