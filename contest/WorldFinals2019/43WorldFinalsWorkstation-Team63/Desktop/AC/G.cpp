#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int sigma = 26;
const int MAXC = 1000006;

inline int idx(char c){
    return c - 'A';
}

// remember make_fail()!!!! @@ ssh
// notice MLE

const int MAXN = 1000006;
int ans[MAXN];

struct AC{
    struct Node{
        Node *next[sigma], *fail;
        Node() : next{}, fail{}, cnt{} {}
        int cnt;
    } buf[MAXC], *bufp, *ori, *root;

    vector<Node*> BFSord;

    void init(){
        bufp = buf;
        ori = new (bufp++) Node();
        root = new (bufp++) Node();
    }

    Node* insert(char *s){
        Node *ptr = root;
        for (int i=0; s[i]; i++){
            int c = idx(s[i]);
            if (!ptr->next[c])
                ptr->next[c] = new (bufp++) Node();
            ptr = ptr->next[c];
        }
        return ptr;
    }

    Node* trans(Node *o, int c){
        if ( o->next[c] ) return o->next[c];
        return o->next[c] = trans(o->fail,c);
    }

    void make_fail(){
        queue<Node*> que;
        
        for (int i=0; i<sigma; i++)
            ori->next[i] = root;
        root->fail = ori;
        que.push(root);
        while ( que.size() ){
            Node *u = que.front(); que.pop();
            BFSord.push_back(u);
            for (int i=0; i<sigma; i++){
                if (!u->next[i])continue;
                u->next[i]->fail = trans(u->fail,i);
                que.push(u->next[i]);
            }
        }
    }

    void collectFail(){
        reverse(BFSord.begin(), BFSord.end());
        for (auto u:BFSord){
            u->fail->cnt += u->cnt;
        }
    }
} ac;

int n, m;
pair<char,int> in[MAXN];
AC::Node *w[MAXN], *qid[MAXN];

char s[MAXN];


void init(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> in[i].first >> in[i].second;
    }
    ac.init();
    for (int i=0; i<m; i++){
        cin >> s;
        int l = strlen(s);
        reverse(s,s+l);
        qid[i] = ac.insert(s);
    } 
}

void solve(){
    ac.make_fail();

    w[1] = ac.trans( ac.root, idx(in[1].first) );

    for (int i=2; i<=n; i++){
        auto pre = w[ in[i].second ];
        w[i] = ac.trans( pre, idx(in[i].first) );
    }

    for (int i=1; i<=n; i++){
        w[i]->cnt++;
    }
    ac.collectFail();
    for (int i=0; i<m; i++){
        cout << qid[i]->cnt << '\n';
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);

    init();
    solve();
}
