void init(){
    std::random_device rd;
    std::default_random_engine gen( rd() );
    std::uniform_int_distribution <unsigned long long> dis(0,ULLONG_MAX);

    for (int i=0; i<MAXN; i++){
        h[i] = dis(gen);
    }
}
