class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        for(int i=0 ; i<s.size() ; i++)
        {
            if(s[i]=='[' || s[i]==']'){
                if(stk.size() == 0) stk.push(s[i]);
                else if(stk.top() == '[' && s[i] == ']') stk.pop();
                else    stk.push(s[i]);
            }
        }
        return (stk.size()/2+1)/2;
    }
};