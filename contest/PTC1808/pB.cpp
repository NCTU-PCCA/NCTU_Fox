#include <bits/stdc++.h>
using namespace std;

const int MAXN = 52;
const long long mod = 1e9+7;
int n, m;
char G[MAXN][MAXN];
int straw[MAXN][MAXN];
int tot;

long long dp[2][MAXN][MAXN][MAXN*MAXN];
auto *now = dp[0];
auto *pre = dp[1];

void init(){
    cin >> n >> m;
    for (int i=n; i>=1; i--){
        scanf("%s", G[i]+1 );
    }
    tot=0;
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= m ; j ++){
            straw[i][j]=straw[i][j-1];
            if(G[i][j]=='#'){
                straw[i][j]++;
                tot++;
            }
        }
    }
}

inline int a(int x,int y){
    if(G[x][y]=='#')return 1;
    return 0;
}

void clear(long long (*ptr)[MAXN][MAXN*MAXN]){
    for(int j = 0 ; j <= m ; j ++){
        for(int k = 0 ; k <= tot ; k ++){
            for(int l = 0 ; l <= n*m/2 ; l ++){
                ptr[j][k][l]=0;
            }
        }
    }
}

void solve(){
    clear(pre);
    clear(now);
    for(int j = 0 ; j <= m ; j ++){
        now[j][straw[1][j]][j]=1;
    }
    for(int i = 2 ; i <= n ; i ++){
        swap(pre,now);
        clear(now);
        for(int j = 0 ; j <= m ; j ++){
            for(int k = straw[i][j] ; k <= tot ; k ++){
                for(int l = j ; l <= n*m/2 ; l ++){
                    now[j][k][l]=pre[j][k-straw[i][j]][l-j];
                    if(l&&j){
                        now[j][k][l]+=now[j-1][k-a(i,j)][l-1];
                        now[j][k][l]%=mod;
                    }
                }
            }
        }
    }
    long long ans=0;
    for(int j = 0 ; j <= m ; j ++){
        ans+=now[j][tot][n*m/2];
        ans%=mod;
    }
    printf("%lld\n",ans);
}

int main(){
    int T; cin >> T;

    while (T--){
        init();
        if(tot%2==1)puts("0");
        else {
            tot/=2;
            solve();
        }
    }
}
