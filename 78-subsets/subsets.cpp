class Solution {
public:
    vector<vector<int>> res;
    vector<int> s={};
    void fn(int i,vector<int>& nums)
    {   
        if(i == nums.size()){
            res.push_back(s);
            return;
        }
        s.push_back(nums[i]);
        fn(i+1,nums);
        s.pop_back();
        fn(i+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        fn(0,nums);
        return res;
    }
};