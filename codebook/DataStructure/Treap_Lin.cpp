#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>
using namespace std;
const int INF = 999999999;
int ran(){
    static unsigned x = 20170928;
    return x = 0xdefaced*x+1;
}
struct Treap{
    Treap *l,*r;
    int num,m,sz,tag,ra,ad;
    Treap(int a){
        l=r=NULL;
        num=m=a;
        sz=1;
        tag=ad=0;
        ra = ran();
    }
}*head,*tp;

int size(Treap *a){
    return a ? a->sz : 0;
}
int min(Treap *a){
    return a ? a->m+a->ad : INF;
}
int add(Treap *a){
    return a ? a->ad : 0;
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
    a -> ad = 0;
}
void pull(Treap *a){
    if(!a) return;
    a->sz=1+size(a->l)+size(a->r);
    a->m = min( a->num, min( min(a->l), min(a->r) ) );
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
void split (Treap *o, Treap *&a, Treap *&b,int k){
    if(!k) a=NULL, b=o;
    else if(size(o)==k) a=o, b=NULL;
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
    int n,tmp;
    scanf("%d",&n);
    for(int i = 0 ;i < n ;i++){
        scanf("%d",&tmp);
        tp = new Treap(tmp);
        head = merge(head,tp);
    }
    int Q;
    scanf("%d\n",&Q);
    char ss[50];
    int a, b, c;
    Treap *ta, *tb, *tc, *td;
    while(Q--){
        scanf("%s",ss);
        if(strcmp(ss,"ADD")==0){
            scanf("%d %d %d",&a,&b,&c);
            split(head,tb,tc,b);
            split(tb,ta,tb,a-1);
            tb -> ad += c;
            head = merge(ta, merge(tb, tc));
        }else if(strcmp(ss,"REVERSE")==0){
            scanf("%d %d",&a,&b);
            split(head,tb,tc,b);
            split(tb,ta,tb,a-1);
            tb -> tag ^= 1;
            head = merge(ta, merge(tb, tc));
        }else if(strcmp(ss,"REVOLVE")==0){
            scanf("%d %d %d",&a,&b,&c);
            split(head,tb,tc,b);
            split(tb,ta,tb,a-1);
            int szz = size(tb);
            c %= szz;
            split(tb,tb,td,szz-c);
            tb=merge(td,tb);
            head = merge(ta, merge(tb, tc));
        }else if(strcmp(ss,"INSERT")==0){
            scanf("%d %d",&a,&b);
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
            scanf("%d %d",&a,&b);
            split(head,tb,tc,b);
            split(tb,ta,tb,a-1);
            printf("%d\n",min(tb));
            head = merge(ta, merge(tb, tc));
        }
    }
}
