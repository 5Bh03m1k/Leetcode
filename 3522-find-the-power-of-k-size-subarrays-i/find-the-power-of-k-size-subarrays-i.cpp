class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> a;
        for(int i=0 ; i<(nums.size() - k)+1 ; i++ )
        {
            int tmp = nums[i] , val = nums[i];
            for(int j=1 ; j<k ; j++)
            {
                if(tmp != nums[i+j]-1)
                {
                    val = -1;
                    break;
                }
                else
                {
                    tmp = nums[i+j];
                    val = tmp;
                }
            }
            a.push_back(val);
        }
        return a;
    }
};