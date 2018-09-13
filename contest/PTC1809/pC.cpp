#include <bits/stdc++.h>


using namespace std;

const int MAXN = 10000+777;
char a[MAXN];
char b[MAXN];
int alen;
int blen;
int dp[2][MAXN];
int *pre = dp[0];
int *now = dp[1];

void init(){
    scanf("%s%s",a,b);
    alen=strlen(a);
    blen=strlen(b);
    for(int i = 0 ; i <= blen ; i ++){
        pre[i]=i;
        now[i]=0;
    }
}

void solve(){
    for(int i = 0 ; i < alen ; i ++){
        pre[0]=i;
        now[0]=i+1;
        for(int j = 0 ; j < blen ; j ++){
            now[j+1]=min({now[j],pre[j],pre[j+1]})+1;

            if(a[i]==b[j]){
                now[j+1]= min( now[j+1], pre[j]);
            }
        }
        swap(pre,now);
    }
    printf("%d\n",pre[blen]);

}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        solve();
    }
}
