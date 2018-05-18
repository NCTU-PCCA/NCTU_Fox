int dfs(int pos, int state1, int state2 ....., bool limit, bool zero) {  
    if ( pos == -1 ) return 是否符合條件;
    int &ret = dp[pos][state1][state2][....];
    if ( ret != -1 && !limit ) return ret;
    int ans = 0;
    int upper = limit ? digit[pos] : 9;
    for ( int i = 0 ; i <= upper ; i++ ) {
        ans += dfs(pos - 1, new_state1, new_state2, limit & ( i == upper), ( i == 0) && zero);
    }
    if ( !limit ) ret = ans;
    return ans;
}

int solve(int n) {  
    int it = 0;
    for ( ; n ; n /= 10 ) digit[it++] = n % 10;
    return dfs(it - 1, 0, 0, 1, 1);
}
