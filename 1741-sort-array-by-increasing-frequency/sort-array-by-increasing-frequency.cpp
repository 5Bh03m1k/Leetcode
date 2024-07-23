class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int table[201];
        int max=0;
        for(int i=0 ; i<nums.size() ; i++)
            table[nums[i]+100]++,max=table[nums[i]+100]>max ? table[nums[i]+100] : max;
        
        vector<vector<int>> arr(max);

        for(auto itr=0 ; itr<201; itr++){
            if(table[itr]>0)
                arr[table[itr]-1].push_back(itr-100);
        }
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