class Solution {
public:
    
    string multiply(string num1, string num2) {
        vector<int> n1,n2;
        for(auto i:num1)   n1.push_back(i - '0');
        for(auto i:num2)   n2.push_back(i - '0');

       vector<vector<int>> arr;
       vector<int> s;

       for(int i=n2.size()-1 ; i>=0 ; i--)
       {    
            int c = 0;
            
            s.assign(n2.size()-1-i,0);
            for(int j=n1.size()-1 ; j>= 0 ; j--)
            {
                int a;
                a = (n1[j] * n2[i]) + c;
                c = a/10;
                a %= 10;
                s.push_back(a);
            }
            if(c)   s.push_back(c);
            arr.push_back(s);

            for(auto i:s)   cout<<i;
            cout<<endl;
            s.clear();
       }
        int carry = 0;
        string soln ="";
        for(int idx = 0 ; idx < arr.back().size() ; idx++)
        {
            int sum = 0;
            for(int i = 0 ; i < arr.size() ; i++)
            {
                
                if(idx < arr[i].size())
                {
                    sum +=  arr[i][idx];
                }
            }
            sum+=carry;
            carry = sum / 10;
            sum %= 10;
            soln = to_string(sum) + soln;
        }
        if(carry != 0 ) soln = to_string(carry) + soln;

        string sol;

        for(int i = 0  ; i < soln.size() ; i++)
        {
            if(soln[i] == '0' && sol.size() == 0 && i != soln.size()-1)
                goto tag;
            sol =  sol + soln[i];
            tag:
        }
       return sol;
    }
};