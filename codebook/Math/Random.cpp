inline int ran(){
  static int x = 20167122;
  return x = (x * 0xdefaced + 1) & INT_MAX;
}
