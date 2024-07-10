class Solution {
public:
    vector<vector<int>> arr;
    vector<int> s;
    int sum(vector<int> s)
    {
        int a=0;
        for(int i=0 ; i<s.size() ; i++)     a+=s[i];
        return a;
    }
    void fn(vector<int> k,int t,int i=0)
    {
        int a=sum(s);
        if(a > t)  return;
        if(a == t){ arr.push_back(s);   return;}
        if(i>=k.size()) return;
        s.push_back(k[i]);
        fn(k,t,i);
        s.pop_back();
        fn(k,t,i+1);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        fn(candidates,target);
        return arr;
    }
};