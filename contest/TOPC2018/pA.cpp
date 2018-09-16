#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--){
        string s;
        cin >> s;

        
        for (auto &c:s) {
            if ( 'A' <= c  && c <= 'Z' ) c += 'z'-'Z';
        }
        bool done=0;
        for (char c:s){
            if (c=='n'){
                puts("No");
                done=1;
                break;
            }
        }
        for (int i=0; i<s.size() && !done; i++){
            if ( i+1<s.size() ){
                if ( s[i]=='a' && s[i+1]=='c' ){
                    puts("Yes");
                    done=1;
                    break;
                }
            }
            if ( i+2<s.size() ){
                if ( s[i]=='y' && s[i+1]=='e' && s[i+2]=='s'){
                    puts("Yes");
                    done=1;
                    break;
                }
            }
        }
        if (!done) puts("Unknown");
    }
}
