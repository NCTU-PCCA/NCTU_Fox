#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000006;
int n;
long long w[MAXN], h[MAXN];
long long psum[MAXN];
int dp[MAXN];

int solve(int L, int R){ // [l,r]
    psum[L-1]=0;
    for (int i=L; i<=R; i++) psum[i] = psum[i-1] + w[i];

    vector< pair<int,int> > que; // x, dp
    dp[L]=1;
    que.push_back( {L,dp[L]} );

    for (int i=L+1; i<=R; i++){
        if (psum[i-1]<=h[i]){
            dp[i]=1;
        }
        else if ( w[i-1]>h[i] ){
            dp[i]=dp[i-1]+1;
        }
        else {
            int l=L, r=i-1;
            while (l!=r){
                int mid=(l+r)/2;
                if ( psum[i-1]-psum[mid-1] <= h[i] )r=mid;
                else l=mid+1;
            }

            l--;
            dp[i] = dp[l]+1;
            int idx = que.size()-1;
            while ( idx>0 && que[idx].first>=l ) idx--;
            if ( que[idx].first<l ) idx++;
            dp[i] = min( dp[i], que[idx].second+1);
        }

        while ( que.size() && que.back().second >= dp[i] ) que.pop_back();
        que.push_back( {i,dp[i]} );
    }
    if (R==n && w[R]==n) return 0;
    if (R==n || w[R]==n) return dp[R];
    return dp[R]*2;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) scanf("%lld %lld", &w[i], &h[i]);

    w[0]=-1;
    int cnt_seg=0;
    int last=1;
    for (int i=2; i<=n; i++){
        if ( w[i] != w[i-1]+1 ){
            cnt_seg += solve(last,i-1);
            last=i;
        }
    }
    cnt_seg += solve(last,n);
    cout << cnt_seg << '\n';
}
/*
3
1 5
3 4
2 2

4
2 5
3 5
4 5
1 5

3
1 0
2 0
3 0
*/

