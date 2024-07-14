class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        ans.push_back(nums);
        dfs(nums);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void dfs(vector<int> nums , int i=0 )
    {
        int n=nums.size();
        if(i == n) return;
        for( int j=i ; j < n ; j++ )
        {
            swap(nums[i],nums[j]);
            dfs(nums,i+1);
            if(i!=j)
                ans.push_back(nums);
            swap(nums[i],nums[j]);
        }
    }

};