// from PEC
// does not work when n is prime
Int f(Int x, Int mod){
	return add(mul(x, x, mod), 1, mod);
}
Int pollard_rho(Int n) {
	if ( !(n & 1) ) return 2;
  while (true) {
    Int y = 2, x = rand()%(n-1) + 1, res = 1;
    for ( int sz = 2 ; res == 1 ; sz *= 2 ) {
      for ( int i = 0 ; i < sz && res <= 1 ; i++) {
        x = f(x, n);
        res = __gcd(abs(x-y), n);
      }
      y = x;
    }
    if ( res != 0 && res != n ) return res;
  }
}