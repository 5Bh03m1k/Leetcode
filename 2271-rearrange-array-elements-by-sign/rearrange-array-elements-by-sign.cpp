class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      vector<int> sp;
      vector<int> sn;
      vector<int> ans;

      for(int i = nums.size()-1 ; i >= 0 ; i--)
        nums[i] > 0 ? sp.push_back(nums[i]) : sn.push_back(nums[i]);

        while(!sp.empty())
        {
            ans.push_back(sp.back());
            ans.push_back(sn.back());
            sp.pop_back();
            sn.pop_back();
        }
        return ans;
    }
};