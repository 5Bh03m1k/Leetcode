class FindSumPairs {
unordered_map<int,int>  table;
vector<int> arr;
vector<int> arr1;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr = nums1;
        arr1 = nums2;

        for(auto i:nums2)
            table[i]++;
        
    }
    
    void add(int index, int val) {
        int n = arr1[index];
        arr1[index] += val;
        table[n]--;
        table[n+val]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        
        for(auto i:arr)
        {
            if(table.find(tot - i) != table.end())
                cnt += table[tot - i];
        }

        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */