#include <bits/stdc++.h>
using namespace std;


#define pushS(x) sa[--bkt[s[x]]] = x  
#define pushL(x) sa[bkt[s[x]]++] = x
#define induce_sort(v){\
	fill_n(sa,n,0);\
	copy_n(_bkt,A,bkt);\
	for(i=n1-1;~i;--i)pushS(v[i]);\
	copy_n(_bkt,A-1,bkt+1);\
	for(i=0;i<n;++i)if(sa[i]&&!t[sa[i]-1])pushL(sa[i]-1);\
	copy_n(_bkt,A,bkt);\
	for(i=n-1;~i;--i)if(sa[i]&&t[sa[i]-1])pushS(sa[i]-1);\
}
template<typename T>
void sais(const T s,int n,int *sa,int *_bkt,int *p,bool *t,int A){
	int *rnk=p+n,*s1=p+n/2,*bkt=_bkt+A;
	int n1=0,i,j,x=t[n-1]=1,y=rnk[0]=-1,cnt=-1;
	for(i=n-2;~i;--i)t[i]=(s[i]==s[i+1]?t[i+1]:s[i]<s[i+1]);
	for(i=1;i<n;++i)rnk[i]=t[i]&&!t[i-1]?(p[n1]=i,n1++):-1;
	fill_n(_bkt,A,0);
	for(i=0;i<n;++i)++_bkt[s[i]];
	for(i=1;i<A;++i)_bkt[i]+=_bkt[i-1];
	induce_sort(p);
	for(i=0;i<n;++i)if(~(x=rnk[sa[i]]))
		j=y<0||memcmp(s+p[x],s+p[y],(p[x+1]-p[x])*sizeof(s[0]))
		,s1[y=x]=cnt+=j;
	if(cnt+1<n1)sais(s1,n1,sa,bkt,rnk,t+n,cnt+1);
	else for(i=0;i<n1;++i)sa[s1[i]]=i;
	for(i=0;i<n1;++i)s1[i]=p[sa[i]];
	induce_sort(s1);
}

const int MAXN=200005,MAXA='z'+1;
int sa[MAXN],bkt[MAXN+MAXA],p[MAXN*2];
bool t[MAXN*2];










const int MAX = MAXN;

int ct[MAX], he[MAX], rk[MAX];
int tsa[MAX], tp[MAX][2];

void suffix_array(char *ip){
	int len = strlen(ip);
	int alp = 256;
	memset(ct, 0, sizeof(ct));
	for(int i=0;i<len;i++) ct[ip[i]+1]++;
	for(int i=1;i<alp;i++) ct[i]+=ct[i-1];
	for(int i=0;i<len;i++) rk[i]=ct[ip[i]];
	for(int i=1;i<len;i*=2){
		for(int j=0;j<len;j++){
			if(j+i>=len) tp[j][1]=0;
			else tp[j][1]=rk[j+i]+1;		
			tp[j][0]=rk[j];
		}
		memset(ct, 0, sizeof(ct));
		for(int j=0;j<len;j++) ct[tp[j][1]+1]++;
		for(int j=1;j<len+2;j++) ct[j]+=ct[j-1];
		for(int j=0;j<len;j++) tsa[ct[tp[j][1]]++]=j;
		memset(ct, 0, sizeof(ct));
		for(int j=0;j<len;j++) ct[tp[j][0]+1]++;
		for(int j=1;j<len+1;j++) ct[j]+=ct[j-1];
		for(int j=0;j<len;j++)
      sa[ct[tp[tsa[j]][0]]++]=tsa[j];
		rk[sa[0]]=0;
		for(int j=1;j<len;j++){
			if( tp[sa[j]][0] == tp[sa[j-1]][0] &&
				tp[sa[j]][1] == tp[sa[j-1]][1] )
				rk[sa[j]] = rk[sa[j-1]];
			else
				rk[sa[j]] = j;
		}
	}
	for(int i=0,h=0;i<len;i++){
		if(rk[i]==0) h=0;
		else{
			int j=sa[rk[i]-1];
			h=max(0,h-1);
			for(;ip[i+h]==ip[j+h];h++);
		}
		he[rk[i]]=h;
	}
}

char s[MAXN];

int main(){
    int T; cin >> T;
    while (T--){
        scanf("%s",s);
        suffix_array(s);
        int n = strlen(s);

        for (int i=0; i<n; i++) cout << sa[i] << ' '; cout << '\n';
        sais(s,n,sa,bkt,p,t,MAXA);
        for (int i=0; i<n; i++) cout << sa[i] << ' '; cout << '\n';
    }
}
