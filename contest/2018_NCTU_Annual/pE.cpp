#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

const int MAXN = 100005;
int n, m;
pair<int,int> tt[MAXN], s[MAXN];

bool cmp(pii a, pii b){
    return (double) a.first/a.second > (double)b.first/b.second;
}

int main(){
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &tt[i].second);
    }
    for (int i=0; i<n; i++){
        scanf("%d", &tt[i].first);
    }
    for (int i=0; i<n; i++){
        if ( tt[i].first !=0 && tt[i].second!=0 ){
            s[ m++ ] = tt[i];
        }
    }
    sort(s,s+m,cmp);
    
    long long ans = 0, sum=0;
    for (int i=0; i<m; i++){
        ans += sum * s[i].first;
        sum += s[i].second;
    }
    cout << ans << '\n';
}
