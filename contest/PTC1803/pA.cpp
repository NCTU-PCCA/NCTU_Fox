#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n;
long long d, a[MAXN];

bool check(int k){
    priority_queue<long long,vector<long long>,greater<long long>> pq; 
    for (int i=0; i<k; i++) pq.push(0);
    long long mx=0;
    for (int i=0; i<n; i++){
        long long u = pq.top(); pq.pop();
        u += a[i];
        pq.push(u);
        mx = max(mx,u);
    }
    return mx <= d;
}

int main(){
    scanf("%d %lld", &n, &d);
    for (int i=0; i<n; i++) scanf("%lld", a+i);

    int l=1, r=n;
    while (l!=r){
        int mid = (l+r)>>1;
        if ( check(mid) ) r=mid;
        else l=mid+1;
    }
    if ( check(n)==0 ) puts("-1");
    else printf("%d\n",r);
}
