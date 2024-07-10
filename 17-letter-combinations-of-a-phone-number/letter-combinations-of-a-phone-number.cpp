class Solution {
public:
    queue<string> q;
    vector<string> ans;

    string get(int n)
    {
        switch(n)
        {
            case 2: return "abc";break;
            case 3: return "def";break;
            case 4: return "ghi";break;
            case 5: return "jkl";break;
            case 6: return "mno";break;
            case 7: return "pqrs";break;
            case 8: return "tuv";break;
            case 9: return "wxyz";break;
            default:break;
        }
        return "";
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return ans;
        int n;
        n=stoi(digits);
        string a="";
        q.push(a);
        while(n>0)
        {
            int k=n%10;
            n/=10;
            int size = q.size();
            string r=get(k);
            for(int i=0 ; i<size ; i++)
            {
                for(int j=0 ; j<r.size() ; j++)
                {
                    string put = r[j]+q.front();
                    q.push(put);
                }
                q.pop();
            }

        }
        while(q.size()>0)
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};