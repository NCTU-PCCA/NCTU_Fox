#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[105];

double cal(int a, int b, int c){
    int i = cnt[a];
    int j = cnt[b]-cnt[a];
    int k = cnt[c]-cnt[b];
    int l = n-cnt[c];
    
    double sum=0;
    sum += fabs( n/4.0 - i );
    sum += fabs( n/4.0 - j );
    sum += fabs( n/4.0 - k );
    sum += fabs( n/4.0 - l );

    return sum;
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        int ai; scanf("%d", &ai);
        cnt[ai]++;
    }
    for (int i=1; i<105; i++) cnt[i] += cnt[i-1];

    int a, b, c;
    double ans = 1e9;
    for (int i=0; i<=100; i++){
        for (int j=i+1; j<=100; j++){
            for (int k=j+1; k<100; k++){
                double d = cal(i,j,k);
                if (d<ans){
                    ans = d;
                    a=i;
                    b=j;
                    c=k;
                }
            }
        }
    }
    printf("%d %d %d\n", a, b, c);
}
