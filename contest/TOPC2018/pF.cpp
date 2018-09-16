#include <bits/stdc++.h>
using namespace std;

int n, cnt[10];
string s;

void init(){
    fill(cnt,cnt+10,0);

    cin >> s;
    n = s.size();
    for (char c:s){
        cnt[ c-'0' ]++;
    }
}

int half(){
    for (int i=0; i<10; i++){
        if ( cnt[i]+cnt[i] >=n ){
            return i;
        }
    }
    return -1;
}

void solve(){
    vector<bool> pre(n), suf(n);

    {
        int mx=0;
        fill(cnt,cnt+10,0);
        for (int i=0; i<n; i++){
            int c = s[i]-'0';
            mx = max( mx, ++cnt[c] );
            if (mx+mx>i+1)pre[i]=0;
            else pre[i]=1;
        }
    }
    {
        int mx = 0;
        fill(cnt,cnt+10,0);
        for (int i=n-1; i>=0; i--){
            int c = s[i]-'0';
            mx = max( mx, ++cnt[c] );
            if ( mx+mx > n-i ) suf[i] = 0;
            else suf[i]=1;
        }
    }

    char c = '9'+1;
    for (int i=0; i<n; i+=2){
        bool ok = 1;
        if (i>0 && !pre[i-1]) ok=0;
        if (i<n-1 && !suf[i+1]) ok=0;
        if (ok) c = min(c,s[i]);
    }
    cout << c  << '\n';
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--){
        init();
        int d = half();
        if ( d==-1 ){
            if (n%2==0){
                cout << "0\n";
            }
            else {
                solve();
            }
        }
        else {
            int len = cnt[d] - (n-cnt[d]);
            if (d==0 || len==0) cout << 0 << '\n';
            else {
                for (int x=0; x<len; x++){
                    cout << d;
                }
                cout << '\n';
            }
        }
    }
}
