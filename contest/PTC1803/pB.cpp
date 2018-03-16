#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 100005;
int n, a[MAXN];
vector<int> as;

int bit[MAXN];

void add(int pos, int val){
    while (pos<=n){
        bit[pos] = (bit[pos]+val)%MOD;
        pos += (pos&(-pos));
    }
}

int sum(int pos){
    int re=0;
    while (pos>0){
        re = (bit[pos]+re)%MOD;
        pos -= (pos&(-pos));
    }
    return re;
}

void build(int a[], int dp[]){
    memset(bit,0,sizeof(bit));
    for (int i=0; i<n; i++){
        dp[i]=0;
        dp[i] = ( dp[i] + sum(a[i]-1) )%MOD;
        add( a[i], (dp[i]+1)%MOD );
    }
}

void init(){
    as.clear();
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", a+i);
    for (int i=0; i<n; i++) as.push_back(a[i]);
    sort(as.begin(),as.end());
    for (int i=0; i<n; i++){
        a[i] = lower_bound(as.begin(),as.end(),a[i])-as.begin()+1;
    }
}

int f[MAXN], g[MAXN];

void solve(){
    build(a,f);
    reverse(a,a+n);
    build(a,g);
    reverse(g,g+n);

    int ans=0;
    for (int i=0; i<n; i++){
        ans = (ans + (long long)f[i]*g[i]%MOD)%MOD;
    }
    printf("%d\n",ans);
}

int main(){
    int T; cin >> T;
    while (T--){
        init();
        solve();
    }
}
