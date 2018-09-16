#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    int T; scanf("%d", &T);
    while (T--){
        LL n, a[3];
        scanf("%lld%lld%lld%lld", &n, a, a+1, a+2);
        sort(a, a+3);
        LL t;
        a[0] += (t = min(a[1] - a[0], n));
        n -= t;
        if (n){
            t = min(n, (a[2] - a[1])*2) / 2;
            a[1] += t;
            a[0] += t;
            n -= 2*t;
            if (a[0] != a[2] && n == 1){
                a[1] += 1;
                n --;
            }
        }
        if (n){
            t = n / 3;
            for (int i=0;i<3;i++) a[i] += t;
            n -= t*3;
            for (int i=2; i>=0;i--){
                if (n){
                    a[i] ++;
                    n--;
                }
            }
        }
        printf("%lld\n", a[0] * a[1] * a[2]);
    }
}
