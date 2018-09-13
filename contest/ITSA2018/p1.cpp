#include<bits/stdc++.h>
using namespace std;

set< pair<int,pair<int,int>> > S;

int mabs(int x){
    if (x<0)return -x;
    return x;
}

void build(){
    for (int x=-100; x<=100; x++){
        for (int y=x; y<=100; y++){
            int a = x+y;
            int b = mabs(x-y);
            int p = x*y;
            int c;
            if (p<0){
                p*=-1;
                if (p%100==50) c=p/100;
                else if (p%100>50) c = p/100+1;
                else c = p/100;
                c*=-1;
            }
            else {
                if (p%100>=50) c=p/100+1;
                else c=p/100;
            }
            S.insert( {a,{b,c}} );
        }
    }
}

void solve(){
    int a, b, c;
    scanf("%d%d%d", &a,&b,&c);

    int ans=0;
    ans += S.count( {a,{b,c}} );
    ans += S.count( {a,{c,b}} );
    ans += S.count( {b,{a,c}} );
    ans += S.count( {b,{c,a}} );
    ans += S.count( {c,{a,b}} );
    ans += S.count( {c,{b,a}} );
    puts(ans ? "Yes" : "No");
}

int main (){
    build();
    int T; cin >> T;
    for (int ncase=1; ncase<=T; ncase++){
        solve();
    }
}
