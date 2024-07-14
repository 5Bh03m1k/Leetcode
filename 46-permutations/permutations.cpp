class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size(),fact=1;
        while(n>0)
            fact*=n,n--;

        
        for(int i=0 ; i<fact ; i++)
        {
            next_permutation(nums.begin() , nums.end());
            ans.push_back(nums);
        }
        return ans;
    }
};