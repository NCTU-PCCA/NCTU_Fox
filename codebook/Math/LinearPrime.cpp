const int MAXP = 100; //max prime 
vector<int> P;	// primes
void build_prime(){
	static bitset<MAXP> ok;
	int np=0;
	for (int i=2; i<MAXP; i++){
		if (ok[i]==0)P.push_back(i), np++;
		for (int j=0; j<np && i*P[j]<MAXP; j++){
			ok[ i*P[j] ] = 1;
			if ( i%P[j]==0 )break;
		}
	}
}
