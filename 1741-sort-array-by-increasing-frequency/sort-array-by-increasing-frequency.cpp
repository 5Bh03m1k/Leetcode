class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> table;
        int max=0;
        for(int i=0 ; i<nums.size() ; i++)
            table[nums[i]]++,max=table[nums[i]]>max ? table[nums[i]] : max;
        
        vector<vector<int>> arr(max);

        for(auto itr=table.begin() ; itr!=table.end() ; itr++)
            arr[itr->second-1].push_back(itr->first);
        nums.clear();
        for(int i=0 ; i<max ; i++){
            sort(arr[i].begin() , arr[i].end());
            for(int j=arr[i].size()-1 ; j>=0 ; j--){
                for(int k=0 ; k<=i ; k++)
                 nums.push_back(arr[i][j]);
            }
        }
        return nums;
    }
};