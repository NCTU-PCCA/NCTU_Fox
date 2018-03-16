#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;

int dp[1010][1010][3];
char a[1010];
char b[1010];
int alen,blen;

// 0 first is empty
// 1 second is empty
// 2 using both

void init(){
    fill((int*)dp,(int*)dp+1010*1010*3,0);
    scanf("%s%s",a,b);
    alen=strlen(a);
    blen=strlen(b);
}

int match(int i,int j){
    if(a[i]==b[j])return 2;
    return -3;
}

void solve(){
    dp[0][0][2]=match(0,0);
    for(int i = 1 ; i < alen ; i ++){
        dp[i][0][2]=match(i,0);
    }
    for(int i = 1 ; i < blen ; i ++){
        dp[0][i][2]=match(0,i);
    }
    for(int i = 1 ; i < alen ; i ++){
        for(int j = 1 ; j < blen ; j ++){
            dp[i][j][2]=dp[i-1][j-1][2]+match(i,j);
            dp[i][j][2]=max(dp[i][j-1][0]+match(i,j),dp[i][j][2]);
            dp[i][j][2]=max(dp[i-1][j][1]+match(i,j),dp[i][j][2]);

            dp[i][j][0]=dp[i-1][j-1][2]-3;
            dp[i][j][0]=max(dp[i][j-1][0]-1,dp[i][j][0]);
            dp[i][j][0]=max(dp[i-1][j][1]-3,dp[i][j][0]);

            dp[i][j][1]=dp[i-1][j-1][2]-3;
            dp[i][j][1]=max(dp[i][j-1][0]-3,dp[i][j][1]);
            dp[i][j][1]=max(dp[i-1][j][1]-1,dp[i][j][1]);
        }
    }

}

int main (){
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        solve();
        int ans=0;
        for(int i = 0 ; i < alen ; i ++){
            ans=max(dp[i][blen-1][0],ans);
            ans=max(dp[i][blen-1][2],ans);
        }
        for(int i = 0 ; i < blen ; i ++){
            ans=max(dp[alen-1][i][1],ans);
            ans=max(dp[alen-1][i][2],ans);
        }
        printf("%d\n",ans);
    }
}
