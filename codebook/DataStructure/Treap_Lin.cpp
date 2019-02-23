#include <bits/stdc++.h>
using namespace std;
const int INF = 1<<30;
int ran(){
    static unsigned x = 20190223;
    return x = 0xdefaced*x+1;
}
struct Treap{
    Treap *l,*r;
    int num,m,sz,tag,ra,ad;
    Treap(int a){
        l=r=0; num=m=a; sz=1; tag=ad=0;
        ra = ran();
    }
};

int size(Treap *a){
    return a ? a->sz : 0;
}
int min(Treap *a){
    return a ? a->m+a->ad : INF;
}
void push(Treap *a){
    if(!a) return;
    if(a->tag){
        swap(a->l,a->r);
        if(a->l)a->l->tag ^= 1;
        if(a->r)a->r->tag ^= 1;
        a->tag=0;
    }
    if(a->l)a->l->ad += a->ad;
    if(a->r)a->r->ad += a->ad;
    a->num += a->ad;
    a->m += a->ad;
    a->ad = 0;
}
void pull(Treap *a){
    if(!a) return;
    a->sz=1+size(a->l)+size(a->r);
    a->m = min({ a->num, min(a->l), min(a->r) });
}

Treap* merge(Treap *a, Treap *b){
    if(!a || !b) return a ? a : b;
    if(a->ra > b->ra){
        push(a);
        a->r = merge(a->r,b);
        pull(a);
        return a;
    }else{
        push(b);
        b->l = merge(a,b->l);
        pull(b);
        return b;
    }
}
void split (Treap *o, Treap *&a, Treap *&b, int k){
    if(!k) a=0, b=o;
    else if(size(o)==k) a=o, b=0;
    else{
        push(o);
        if(k <= size(o->l)){
            b = o;
            split(o->l, a, b->l,k);
            pull(b);
        }else{
            a = o;
            split(o->r, a->r, b, k-size(o->l)-1);
            pull(a);
        }
    }
}
int main(){
    Treap *head=0, *ta, *tb, *tc, *td;
    int a, b, c, n; scanf("%d",&n);
    for(int i=0; i<n; i++){
        int t; scanf("%d",&t);
        head = merge(head,new Treap(t));
    }
    int Q; scanf("%d",&Q);
    char ss[50];
    while(Q--){
        scanf("%s",ss);
        if(strcmp(ss,"ADD")==0){
            scanf("%d%d%d",&a,&b,&c);
            split(head,tb,tc,b);
            split(tb,ta,tb,a-1);
            tb -> ad += c;
            head = merge(ta, merge(tb, tc));
        }else if(strcmp(ss,"REVERSE")==0){
            scanf("%d%d",&a,&b);
            split(head,tb,tc,b);
            split(tb,ta,tb,a-1);
            tb -> tag ^= 1;
            head = merge(ta, merge(tb, tc));
        }else if(strcmp(ss,"REVOLVE")==0){
            scanf("%d%d%d",&a,&b,&c);
            split(head,tb,tc,b);
            split(tb,ta,tb,a-1);
            int szz = size(tb);
            c %= szz;
            split(tb,tb,td,szz-c);
            tb=merge(td,tb);
            head = merge(ta, merge(tb, tc));
        }else if(strcmp(ss,"INSERT")==0){
            scanf("%d%d",&a,&b);
            split(head,ta,tc,a);
            tb = new Treap(b);
            head = merge(ta, merge(tb, tc));
        }else if(strcmp(ss,"DELETE")==0){
            scanf("%d",&a);
            split(head,ta,tc,a-1);
            split(tc,tb,tc,1);
            delete tb;
            head = merge(ta,tc);
        }else if(strcmp(ss,"MIN")==0){
            scanf("%d%d",&a,&b);
            split(head,tb,tc,b);
            split(tb,ta,tb,a-1);
            printf("%d\n",min(tb));
            head = merge(ta, merge(tb, tc));
        }
    }
}
