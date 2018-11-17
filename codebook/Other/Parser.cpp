using LL = long long;
const int MAXLEVEL = 2;
//  binary operators
const vector<char> Ops[MAXLEVEL] = {
    {'+', '-'}, // level 0
    {'*', '/'}  // level 1
};
//  unary operators
const vector<pair<char,int>> Op1s = {
    {'-', 0} // operator negative works on level 0
};
struct Node{
    ~Node(){ delete L; delete R; }
    enum { op, op1, num } type;
    LL val;
    Node *L, *R;
} *root;
char getOp1(int LEVEL, istream& is){
    is >>ws;
    for (auto& x : Op1s){
        auto& op = x.first;
        auto& lev = x.second;
        if (LEVEL == lev && is.peek() == op)
            return is.get();
    }
    return 0;
}
template <int LEVEL> void parse(Node*& x, istream& is){
    char op1 = getOp1(LEVEL, is);
    parse<LEVEL+1>(x, is);
    if (op1) x = new Node{Node::op1, op1, x, nullptr};
    auto& ops = Ops[LEVEL];
    while (is>>ws && count(ops.begin(), ops.end(), is.peek())){
        x = new Node{Node::op, is.get(), x, nullptr};
        parse<LEVEL+1>(x->R, is);
    }
}
template <> void parse<MAXLEVEL>(Node*& x, istream& is){
    char op1 = getOp1(MAXLEVEL, is);
    is>>ws;
    if (is.peek()>='0' && is.peek()<='9'){
        LL t; is >>t;
        x = new Node{Node::num, t, nullptr, nullptr};
    } else if (is.peek() == '('){
        is.get();
        parse<0>(x, is);
        is>>ws;
        if (is.get()!=')') throw 0;
    } else throw 0;
    if (op1) x = new Node{Node::op1, op1, x, nullptr};
}
//  throw when error occur !!!!!
void build(istream& is){
    parse<0>(root, is);
    if ((is>>ws).peek() != EOF) throw 0;
}
