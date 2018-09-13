#include<bits/stdc++.h>
using namespace std;

string ins;
vector<string> cmds;

void init(){
    cmds.clear();
    getline(cin,ins);
    stringstream ss (ins);
    string s;
    while ( ss>>s )cmds.push_back(s);
}

long long dfs(){
    string cmd = cmds.back(); cmds.pop_back();
    if ( cmd[0]=='+' ){
        long long y = dfs();
        long long x = dfs();
        return x+y;
    }
    else if ( cmd[0]=='-' ){
        long long y = dfs();
        long long x = dfs();
        return x-y;
    }
    else if ( cmd[0]=='*' ){
        long long y = dfs();
        long long x = dfs();
        return x*y;
    }
    else {
        long long x = stoi(cmd);
        return x;
    }
}

void solve(){
    cout << dfs() << '\n';
}

int main (){
    int T; cin >> T;
    getline(cin,ins);
    for (int ncase=1; ncase<=T; ncase++){
        init();
        solve();
    }
}
