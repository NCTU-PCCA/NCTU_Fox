#include<bits/stdc++.h>
using namespace std;

vector<bool> vis;
string s;
set<long long> ss;

void init(){
    vis.resize(s.size());
    ss.clear();
    fill(vis.begin(), vis.end(), false);
}

void dfs(int dep){
    if (dep == (int)vis.size()){
        string t;
        long long c= 0 ;
        int cnt=0;
        for (size_t i=0; i<s.size(); i++) if (vis[i]){
            c = 10 * c + s[i]-'0';
            cnt++;
        }
        if (cnt==0)return;
        ss.insert(c);
        return;
    }
    vis[dep] = true;
    dfs(dep+1);
    vis[dep] = false;
    dfs(dep+1);
}

void solve(){
    dfs(0);
    cout << ss.size() << '\n';
}

int main (){
    cin.tie(0);
    while (cin >> s){
        init();
        solve();
    }
}
