#include <bits/stdc++.h>
using namespace std;

const long long INF = ( (1LL)<<60 );
bitset<250001> S;
int sum=0;
long long dd=0;

long long cal(long long a, long long b){
    long long ans = a*a + b*b - dd - a*b*2;
    if (ans<0)  ans = -ans;
    return ans/2;
}

int main(){
    S[0] = 1;
    int n;
    cin >> n;
    for (int i=0, hi; i<n; i++){
        cin >> hi;
        S |= (S<<hi);
        sum += hi;
        dd += hi*hi;
    }
    long long ans = INF;
    for (int i=0; i<=sum; i++){
        if ( S[i] ){
            ans = min( ans, cal(i,sum-i) );
        }
    }
    cout << ans << '\n';
}
