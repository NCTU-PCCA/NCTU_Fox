#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAXN = 50004;
int n, k;
long long  a[MAXN], S[MAXN];
long long dp[MAXN];
int pos[MAXN];

void init(){
    scanf("%d %d", &n, &k);
    for (int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a+1,a+1+n);
    for (int i=1; i<=n; i++){
        S[i] = S[i-1]+a[i];
    }
}

long long cost(int l, int r){
    int mid = (l+r)/2;
    return (S[r]-S[mid]) - (r-mid)*a[mid] + (mid-l+1)*a[mid] - (S[mid]-S[l-1]);
}

void solve(){
    dp[0] = 0, pos[0] = 0;
    for (int i=1; i<k; i++) dp[i] = INF;
    dp[k] = cost(1,k), pos[k] = 0;

    for (int i=k+1; i<=n; i++){
        dp[i] = dp[i-k] + cost(i-k+1,i), pos[i] = i-k;
        for (int j=pos[i-1]; j<i-k; j++){ 
            long long v = dp[j] + cost(j+1,i);
            if ( v < dp[i] ){
                pos[i] = j;
                dp[i] = v;
            }
        }
    }
    cout << dp[n] << '\n';
}

int main(){
    int T; cin >> T;
    while (T--){
        init();
        solve();
        //for (int i=1; i<=n; i++) printf("%lld ", a[i]); puts("");
        //for (int i=1; i<=n; i++) printf("%lld ", dp[i]); puts("");
    }
}
