#include<bits/stdc++.h>
using namespace std;

void init(){
    char s[100];
    scanf("%s",s);
    int n = strlen(s);
    while(1){
        bool found=false;
        for(int i = 0 ; i  < n-1 ; i ++){
            if(s[i]<s[i+1]){
                s[i]++;
                found=true;
                for(int j = i+1 ; j < n ; j ++){
                    s[j]='0';
                }
                break;
            }
        }
        if(!found)break;
    }
    printf("%s\n",s);
}

void solve(){
}

int main (){
    int T; cin >> T;
    for (int ncase=1; ncase<=T; ncase++){
        init();
        solve();
    }
}
