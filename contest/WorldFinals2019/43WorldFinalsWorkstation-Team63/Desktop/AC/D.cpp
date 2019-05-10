#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pci = pair<char,int>;
using pii = pair<int,int>;

const int MAXN = 1000004;
int n;
map<int,vector<pci>> m;

void init(){
    char buf[20];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> buf;
        int v = atoi(buf+1);
        m[v].push_back({buf[0],i+1});
    }
}

int ans[MAXN];

vector<pii> cal(const vector<pci>& v) {
    vector<pii> ret;
    vector<int> s(v.size());
    for (int i=0; i<(int)v.size(); i++) {
        if (v[i].first == 's') s[i]++;
        else s[i]--;
    }
    partial_sum(s.begin(), s.end(), s.begin());
    if (s.back()) return ret;

    auto it = min_element(s.begin(), s.end());
    while (it != s.end()) {
        int i = it-s.begin();
        if (i==(int)v.size()-1) {
            int a = v[i].second+1;
            ret.push_back({a, n+1});
            int b = v[0].second+1;
            ret.push_back({1, b});
        } else {
            int a = v[i].second+1;
            int b = v[i+1].second+1;
            ret.push_back({a,b});
        }
        
        it = find(it+1, s.end(), *it);
    }
    return ret;
}

void solve(){
    for (auto& p : m) {
        //cout << "type: " << p.first << endl;
        for (auto& q : cal(p.second)) {
            //cout << q.first << ' ' << q.second << endl;
            ans[ q.first ] ++;
            ans[ q.second ] --;
        }
    }
    partial_sum(ans+1, ans+n+1, ans+1);
    auto it = max_element(ans+1, ans+n+1);
    cout << it-ans << ' ' << *it << '\n';
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);

    init();
    solve();
}
