class Solution {
public:
    vector<vector<int>> arr;
    vector<int> s;
    vector<int> k;
    int sum(vector<int> s)
    {
        int a=0;
        for(int i=0 ; i<s.size() ; i++)     a+=s[i];
        return a;
    }
    void fn(int t,int i=0)
    {
        int a=sum(s);
        if(a > t)  return;
        if(a == t){ arr.push_back(s);   return;}
        if(i>=k.size()) return;
        s.push_back(k[i]);
        fn(t,i);
        s.pop_back();
        fn(t,i+1);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        k=candidates;
        fn(target);
        return arr;
    }
};