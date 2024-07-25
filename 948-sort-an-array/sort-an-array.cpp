class Solution {
public:
    int n[100001]={0};
    vector<int> sortArray(vector<int>& nums) {
        int max = INT_MIN , min = INT_MAX;
        for(int i=0 ; i<nums.size() ; i++)
        {
            int indx = nums[i]+50000;
           max = indx>max?indx:max;
           min = indx < min ? indx : min;
           n[indx]++;
        }
        nums.clear();
        for(int i = min ; i<=max ; i++)
        {
            while(n[i]--)
            nums.push_back(i-50000);
        }
        return nums;
    }
};