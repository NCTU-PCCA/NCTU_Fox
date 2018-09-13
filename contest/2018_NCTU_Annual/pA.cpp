#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

int main(){
    int ans = 1;
    map<int,int> CC;

    int n;
    cin >> n;
    if ( n>1) ans = 2;
    if ( n==2 ){
        int a ,b;
        cin >> a >> b;
        if (a==0 && b!=0 ) cout << 1 << '\n';
        else cout << 2 << '\n';
        return 0;
    }

    int cnt_zero=0;

    for (int i=0, last=INF, cnt=0; i<n; i++){
        int ai = 0;
        scanf("%d", &ai);
        CC[ai]++;
        if (ai==0) cnt_zero++;
        ans = max(  ans, CC[ai] );
    }
    if (n==2 && n-cnt_zero==1 ) ans=1;
    cout << ans << '\n';
}
