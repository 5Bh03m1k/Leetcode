class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums;
        fn();
        return arr;
    }
private:
    vector<vector<int>> arr;
    vector<int> n;
    void fn(int i=0,vector<int> a={})
    {
        if(i == n.size())
        {
            arr.push_back(a);
            return;
        }
        for(int j=0 ; j<=a.size() ; j++ ){
        vector<int> tmp=a;
        tmp.insert(tmp.begin()+j,n[i]);
            fn(i+1,tmp);
        }
        return ; 
        
    }
};