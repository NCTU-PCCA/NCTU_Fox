#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int pop[1<<14];
int n, P, a[1<<14], cnt[1<<14], sum[1<<14];
int dp[1<<14];
int mU;

inline int trans(int U, int S){
    return pop[U^S];
}

void init(){
    cin >> P >> n;

    memset(a,0,sizeof(int)*(1<<P));
    memset(cnt,0,sizeof(int)*(1<<P));
    memset(sum,0,sizeof(int)*(1<<P));

    char s[20];
    for (int i=0; i<n; i++){
        scanf("%s", s);
        int ai=0;
        for (int j=0; j<P; j++){
            ai += (s[j]-'0') * (1<<j);
        }
        a[ai]++;
    }

    mU = 0;
    for (int S=(1<<P)-1; S>=0; S--){
        if ( a[S] ) mU |= S;
    }

    for (int U=mU; U>=0; U=(U-1)&mU){
        for (int S=U; S>=0; S=(S-1)&U){
            cnt[U] += a[S];
            sum[U] += a[S] * trans(U,S);
            if (S==0) break;
        }
        if (U==0)break;
    }
}

void solve(){
    const int INF = 1e9+7;
    dp[0] = 0;

    for (int U=1; U<(1<<P); U++) if ((U&mU)==U){
        dp[U] = INF;

        for (int S=U; S>=0; S=(S-1)&U){
            int tmp = dp[S];
            tmp += sum[U] - sum[S] - trans(U,S) * (cnt[S]);
            dp[U] = min(dp[U],tmp);
            if (S==0)break;
        }
    }
    cout << dp[ mU ] << '\n';
}

int main(){
    for (int i=(1<<14)-1; i>=0; i--){
        pop[i] = __builtin_popcount(i);
    }
    int T; cin >> T;
    while (T--){
        init();
        solve();
    }
}
