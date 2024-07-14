class Solution {
public:
    vector<string> ans;
    
    void fn(int l, int r, string s="") {
        if (l == 0 && r == 0) {
            ans.push_back(s);
            return;
        }
        if (l > 0) {
            fn(l-1, r, s + "(");
        }
        if (r > l) {
            fn(l, r-1, s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        fn(n,n);
       return ans;
    }
};