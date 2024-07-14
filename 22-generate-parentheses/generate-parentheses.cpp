class Solution {
public:
    vector<string> s;
    
    void fn(int n ,string st={}, int open = 0 , int close  = 0)
    {
        if(st.size() == n*2){  
            s.push_back(st);  
            return ;
        }

        if( open < n)   st.append("(") , open++;

        else return;
        
        for(close ; close <= open ; close++)
        {
            fn(n, st , open , close);
            st.append(")");
        }
    }
    vector<string> generateParenthesis(int n) {
        fn(n);
       return s;
    }
};