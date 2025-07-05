class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> table;

        for(auto i:arr)
            table[i]++;

        sort(arr.begin(),arr.end());

        for(int i = arr.size() -1 ; i >= 0 ; i--)
        {
            if(table[arr[i]] == arr[i]) return arr[i];
        } 

        return -1;
    }
};