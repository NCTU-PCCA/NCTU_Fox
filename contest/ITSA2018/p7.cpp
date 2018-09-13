#include<bits/stdc++.h>
using namespace std;

char buf[100];
long long k;
string s;
vector<pair<int,string> > v;

void init(){
    s = "";
    v.clear();
    scanf("%s", buf);
    scanf("%lld", &k);
    k--;
    stringstream ss;
    ss << buf;
    for (int i=0;;i++){
        int c = ss.get();
        if (c < 0) break;
        if (c >= 'a' && c <= 'z'){
            s.push_back(c);
        }
        else if (c == '*'){
            s.push_back('.');
            v.push_back({i,string("aeiou")});
        }
        else {
            string tmp;
            getline(ss, tmp, ']');
            sort(tmp.begin(),tmp.end());
            s.push_back('.');
            v.push_back({i,move(tmp)});
        }
    }
}

void solve(){
    reverse(v.begin(), v.end());
    for (auto & x : v){
        long long m = x.second.size();
        s[x.first] = x.second[k%m];
        k /= m;
    }
    if (k) cout << "*\n";
    else cout << s << '\n';
}

int main (){
    cin.tie(0);
    int T; cin >> T;
    for (int ncase=1; ncase<=T; ncase++){
        init();
        solve();
    }
}
