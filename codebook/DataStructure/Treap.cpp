#include<bits/stdc++.h>
using namespace std;
template<class T,unsigned seed>class treap{
	public:
		struct node{
			T data;
			int size;
			node *l,*r;
			node(T d){
				size=1;
				data=d;
				l=r=NULL;
			}
			inline void up(){
				size=1;
				if(l)size+=l->size;
				if(r)size+=r->size;
			}
			inline void down(){
			}
		}*root;
		inline int size(node *p){return p?p->size:0;}
		inline bool ran(node *a,node *b){
			static unsigned x=seed;
			x=0xdefaced*x+1;
			unsigned all=size(a)+size(b);
			return (x%all+all)%all<size(a);
		}
		void clear(node *&p){
			if(p)clear(p->l),clear(p->r),delete p,p=NULL;
		}
		~treap(){clear(root);}
		void split(node *o,node *&a,node *&b,int k){
			if(!k)a=NULL,b=o;
			else if(size(o)==k)a=o,b=NULL;
			else{
				o->down();
				if(k<=size(o->l)){
					b=o;
					split(o->l,a,b->l,k);
					b->up();
				}else{
					a=o;
					split(o->r,a->r,b,k-size(o->l)-1);
					a->up();
				}
			}
		}
		void merge(node *&o,node *a,node *b){
			if(!a||!b)o=a?a:b;
			else{
				if(ran(a,b)){
					a->down();
					o=a;
					merge(o->r,a->r,b);
				}else{
					b->down();
					o=b;
					merge(o->l,a,b->l);
				}
				o->up();
			}
		}
		void build(node *&p,int l,int r,T *s){
			if(l>r)return;
			int mid=(l+r)>>1;
			p=new node(s[mid]);
			build(p->l,l,mid-1,s);
			build(p->r,mid+1,r,s);
			p->up();
		}
		inline int rank(T data){
			node *p=root;
			int cnt=0;
			while(p){
				if(data<=p->data)p=p->l;
				else cnt+=size(p->l)+1,p=p->r;
			}
			return cnt;
		}
		inline void insert(node *&p,T data,int k){
			node *a,*b,*now;
			split(p,a,b,k);
			now=new node(data);
			merge(a,a,now);
			merge(p,a,b);
		}
};
treap<int ,20141223>bst;
int n,m,a,b;
int main(){
	//當成二分查找樹用 
	while(~scanf("%d",&a))bst.insert(bst.root,a,bst.rank(a));
	while(~scanf("%d",&a))printf("%d\n",bst.rank(a));
	bst.clear(bst.root);
	return 0;
}
