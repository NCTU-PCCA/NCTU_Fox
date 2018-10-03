string BWT(string); // by suffix array

string iBWT(string &s, int start=0){
    int n = (int) s.size();
    string ret(n,' ');
    vector<int> next(n,0), box[256];

    for (int i=0; i<n; i++) // bucket sort
        box[ (int)s[i] ].push_back(i);

    for (int i=0, j=0; i<256; i++)
        for (int x:box[i])
            next[j++] = x;

    for (int i=0, p=start; i<n; i++)
        ret[i] = s[ p=next[p] ];

    return ret;
}
