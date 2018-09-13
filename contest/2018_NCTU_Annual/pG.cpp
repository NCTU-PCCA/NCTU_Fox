#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

void build_KMP(int n, char *s, int *f){ // 1 base
    f[0]=-1, f[1]=0;
    for (int i=2; i<=n; i++){
        int w = f[i-1];
        while ( w>=0 && s[w+1] != s[i]) w = f[w];
        f[i] = w+1;
    }
}


const int MAXN = 1000006;
int n, k;
int f[MAXN];
char s[MAXN];
int tag[MAXN];
set<int> v[MAXN];

bool ok[MAXN];

bool check(int len){
    fill(ok,ok+n+1,0);
    ok[len] = true;
    for (int i=len+1; i<=n; i++){
        if ( ok[ f[i] ]  ){
            ok[i] = 1;
        }
    }
    int cnt = 1;
    for (int i=len+len; i<=n; i++){
        if ( ok[i]){
            cnt++;
            i+=len-1;
        }
    } 
    return cnt >=k ;
}

int main(){
    scanf("%d%s", &k, s+1);
    n = strlen(s+1);

    build_KMP(n,s,f);

    vector<int> temp;
    for (int w=n; w>0; w = f[w]){
        temp.push_back(w);
    }
    reverse(temp.begin(),temp.end());

    int l=0, r=(int)temp.size()-1;
    while (l!=r){
        int mid = (l+r)>>1;
        if ( !check(temp[mid]) ) r=mid;
        else l=mid+1;
    }

    if(r>0 && check(r)){
        cout << temp[r-1] << '\n';
    }
    else {
        cout << "-1" << '\n';
    }
}
