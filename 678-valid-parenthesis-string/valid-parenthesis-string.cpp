class Solution {
public:
    bool checkValidString(string s) {
        vector<bool> st;
        int star = 0;

        for(auto i:s)
        {
            if(i == '(')st.push_back(true);
            if(i == ')')
            {
                if(st.size() > 0)   st.pop_back();
                else{
                    if(star > 0)    star -- ;
                    else    return false;
                }
            }
            if( i == '*')
                star ++;
            
        }
        
        if(st.size() > 0){
            //cout<<st.size()<<" "<<star;
            if(star == 0)   return false;
                star = 0 ;
                st.clear();
                for(int it = s.size()-1 ; it >= 0 ; it--)
                {
                    char i = s[it];
                    //cout<<i;
                    if(i == ')')st.push_back(true);
                    if(i == '(')
                    {
                        if(st.size() > 0)   st.pop_back();
                        
                        else{
                            if(star > 0)    star -- ;
                            else    return false;
                        }
                        //cout<<star;
                    }
                    if( i == '*')
                        star ++;
                    
                }
               cout<<st.size() ;
                if(st.size() > star)   return false;

        }
        
        return true;
    }
};