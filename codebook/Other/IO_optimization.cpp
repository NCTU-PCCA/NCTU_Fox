#include <stdio.h>

char getc(){
	static const int bufsize = 1<<16;
	static char B[bufsize], *S=B, *T=B;
	return (S==T&&(T=(S=B)+fread(B,1,bufsize,stdin),S==T)?0:*S++);
}

template <class T>
bool input(T& a){
	a=(T)0;
	register char p;
	while ((p = getc()) < '-')
		if (p==0 || p==EOF) return false;
	if (p == '-')
		while ((p = getc()) >= '0') a = a*10 - (p^'0');
	else {
		a = p ^ '0';
		while ((p = getc()) >= '0') a = a*10 + (p^'0');
	}
	return true;
}

template <class T, class... U>
bool input(T& a, U&... b){
	if (!input(a)) return false; 
	return input(b...);
}
