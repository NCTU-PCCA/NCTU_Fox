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
//  throw when error occur !!!!!
struct Parser{
    struct Node{
        ~Node(){ delete L; delete R; }
        enum { op, op1, num } type;
        LL val;
        Node *L, *R;
    } *root;
    Parser(): root(nullptr){}
    ~Parser(){ delete root; }
    void build(istream& is) try{
        delete root;
        root = nullptr;
        parse(0, root, is);
        if ((is>>ws).peek() != EOF) throw 0;
    } catch(...){ throw; }
    void build(const string& s){
        istringstream ss(s);
        build(ss);
    }
    void parse(int LEVEL, Node*& x, istream& is){
        if (LEVEL == MAXLEVEL){
            is>>ws;
            if (is.peek()>='0' && is.peek()<='9'){
                LL t; is >>t;
                x = new Node{Node::num, t, nullptr, nullptr};
            } else if (is.peek() == '('){
                is.get();
                parse(0, x, is);
                is>>ws;
                if (is.get()!=')') throw 0;
            } else throw 0;
        } else {
            is >>ws;
            char op1 = 0;
            for (auto& x : Op1s){
                auto& op = x.first;
                auto& lev = x.second;
                if (LEVEL == lev && is.peek() == op)
                    op1 = is.get();
            }
            parse(LEVEL+1, x, is);
            if (op1) x = new Node{Node::op1, op1, x, nullptr};
            auto& ops = Ops[LEVEL];
            while (is>>ws && count(ops.begin(), ops.end(), is.peek())){
                x = new Node{Node::op, is.get(), x, nullptr};
                parse(LEVEL+1, x->R, is);
            }
        }
    }
};
