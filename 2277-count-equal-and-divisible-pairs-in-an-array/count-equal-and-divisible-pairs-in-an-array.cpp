class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
       /* unordered_map<int , vector<int>> table;

        for(int i=0 ; i<nums.size() ; i++)
            table[nums[i]].push_back(i);

        int count = 0;

        for(auto it = table.begin() ; it != table.end() ; it++){

            int s = it->second.size();

            for(int i=0 ; i < it->second.size()  ; i++){
                 if(it->second[i] % k == 0){
                    count += s-1;
                    s--;
                 }
            }
        }

        return count;*/
        int sum = 0;
        for(int i=0 ; i<nums.size() ; i++)
        {
            for(int j=i+1 ; j<nums.size() ; j++)
            if(nums[i] == nums[j] && (i*j)%k == 0)
                sum++;
        }
        return sum;

        
    }
};