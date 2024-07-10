class Solution {
public:
    vector<vector<int>> arr;
    vector<int> s;
    vector<int> k;
    int t;
    void fn(int i=0,int sum=0)
    { 
        if(sum > t)  return;
        if(sum == t){ arr.push_back(s);   return;}
        if(i>=k.size()) return;
        sum+=k[i];
        s.push_back(k[i]);
        fn(i,sum);
        int n=s[s.size()-1];
        s.pop_back();
        sum-=k[i];
        fn(i+1,sum);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        k=candidates;
        t=target;
        fn();
        return arr;
    }
};