#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 1e6+6;
int d[MAXN], dp[MAXN];
int n, k;

void build(){
    d[0] = 1;
    int sum=1;
    for (int i=1; i<MAXN; i++){
        d[i] = sum;
        sum = (sum+d[i])%MOD;
    }
}

void init(){
    cin >> n >> k;

    dp[0] = 1;
    int sum = 1;
    for (int i=1; i<=n; i++){
        dp[i] = sum;
        if (i>=k) dp[i] = (dp[i] + (long long)d[k]*dp[i-k]%MOD -dp[i-k])%MOD;
        if ( dp[i]<0 ) dp[i]+=MOD;
        sum = ( dp[i] + sum ) % MOD;
    }
}

void solve(){
    cout << dp[n] << '\n';
}

int main (){
    build();
    int T; cin >> T;
    for (int ncase=1; ncase<=T; ncase++){
        init();
        solve();
    }
}
